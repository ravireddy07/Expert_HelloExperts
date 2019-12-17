# BankSimulation

Implementation of an event-driven simulation of a bank. A queue of arrival events represents the line of customers in the bank. The arrival events and departure events are maintained in a priority queue, sorted by the time of the event. A link-based implementation is used for the event list.

The input is a text file of arrival and transaction times. Each line of the file contains the arrival time and required transaction time for a customer. The arrival times are ordered by increasing time.

The program counts customers and keeps track of their cumulative waiting time. It also computes the average waiting time after the last event has been processed and prints a summary of the computed statistics:
- total number of arrivals
- average wait time
- maximum wait time
- average line length
- maximum line length

The simulation supports a user-defined number of tellers and associated teller lines to process customers.

The BankSimulation has an accompanying graphical browser-based demonstration. Simulation state is serialized in the [ProtocolBuffer 3.0](https://developers.google.com/protocol-buffers/) format at critical points during simulation execution and sent via [GRPC](http://www.grpc.io/) to the main [Go](golang.org) server application.

The Go server is a static file server, serving up HTML/JS/CSS to connected browser clients. When a browser client starts the simulation through a button click, the server launches a WebSocket connection to the client that lasts for the duration of the simulation. The WebSocket connection is used to forward the ProtocolBuffer serialized simulator state data to the browser client, which decodes the payload using [ProtoBuf.js](https://github.com/dcodeIO/ProtoBuf.js/wiki).

The JavaScript executed by the browser client uses the [Famous Engine](famous.org) frontend library to drive the animation based on received state data.

## Building
Depends on the GRPC C++ library and Go 1.4. Install instructions for GRPC at https://github.com/grpc/grpc/blob/master/INSTALL
Afterwards:
```
cd simulator
make
cd ../server
go build
```

## Running
```
cd server
./server
```
Launch browser and connect to localhost:1618

## Known issues
Currently the ProtocolBuffers generated Go code needs to be manually patched to pass through the raw payload bytes from the wire. The correct source file is pre-generated in protos/AnimationTrigger.pb.go
If `go generate` is run from the server directory, the _BankSimulatorStateProxy_SendState_Handler function (last function in the file) needs to be replaced with the following:
```
func _BankSimulatorStateProxy_SendState_Handler(srv interface{}, ctx context.Context, codec grpc.Codec, buf []byte) (interface{}, error) {
	in := new(BankSimulatorState)
	if err := codec.Unmarshal(buf, in); err != nil {
		return nil, err
	}
	out, err := srv.(BankSimulatorStateProxyServer).SendState(ctx, buf, in)
	if err != nil {
		return nil, err
	}
	return out, nil
}
```
## Directory Structure
- /
  - /simulator : C++ bank simulator source
  - /webapp/src : JavaScript web animation source
  - /server : Go server source
  - /protos : ProtocolBuffer data serialization definitions
