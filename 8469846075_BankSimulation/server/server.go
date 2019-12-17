//go:generate protoc -I ../protos ../protos/AnimationTrigger.proto --go_out=plugins=grpc:../protos/

package main

import (
	//"fmt"
	"log"
	"net"
	"net/http"
	"os"
	"os/exec"

	gContext "github.com/gorilla/context"
	"github.com/gorilla/mux"
	"github.com/gorilla/sessions"
	"github.com/gorilla/websocket"
	pb "github.com/imheresamir/BankSimulation/protos"
	"golang.org/x/net/context"
	"google.golang.org/grpc"
)

const (
	port = ":50051"
)

var store = sessions.NewCookieStore([]byte("something-very-secret"))

//var stateChanMap map[int]chan *pb.BankSimulatorState = make(map[int]chan *pb.BankSimulatorState)
var stateChanMap map[int]chan []byte = make(map[int]chan []byte)

// server is used to implement banksimulation.BankSimulatorStateProxyServer
type server struct{}

// SendState implements banksimulation.BankSimulatorStateProxyServer
func (s *server) SendState(ctx context.Context, buf []byte, in *pb.BankSimulatorState) (*pb.ServerAck, error) {
	stateChanMap[int(in.Pid)] <- buf

	return &pb.ServerAck{Ack: true}, nil
}

func main() {
	lis, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer()
	pb.RegisterBankSimulatorStateProxyServer(s, &server{})
	go s.Serve(lis)

	r := mux.NewRouter()
	r.PathPrefix("/").Handler(http.FileServer(http.Dir("../webapp/public")))
	http.Handle("/", r)

	http.HandleFunc("/ws", wsHandler)

	log.Panic(http.ListenAndServe(":1618", gContext.ClearHandler(http.DefaultServeMux)))

}

var upgrader = websocket.Upgrader{
	ReadBufferSize:  1024,
	WriteBufferSize: 1024,
	CheckOrigin:     func(r *http.Request) bool { return true },
}

func wsHandler(w http.ResponseWriter, r *http.Request) {
	conn, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		log.Println(err)
		return
	}

	os.Chdir("../simulator")
	cmd := exec.Command("./BankSimulation")

	/*cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr*/
	err = cmd.Start()
	if err != nil {
		log.Println(err)
	}

	pid := cmd.Process.Pid

	stateChanMap[pid] = make(chan []byte)

	for {
		_, _, err := conn.ReadMessage()
		if err != nil {
			break
		}

		stateBuf := <-stateChanMap[pid]

		if err = conn.WriteMessage(websocket.BinaryMessage, stateBuf); err != nil {
			break
		}
	}

	close(stateChanMap[pid])

}
