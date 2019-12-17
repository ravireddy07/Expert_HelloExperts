#ifndef _GREETER_CLIENT
#define _GREETER_CLIENT

#include <iostream>
#include <memory>
#include <string>

#include <sys/types.h>
#include <unistd.h>

#include <grpc/grpc.h>
#include <grpc++/channel_arguments.h>
#include <grpc++/channel_interface.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/credentials.h>
#include <grpc++/status.h>
#include "AnimationTrigger.grpc.pb.h"

using grpc::ChannelArguments;
using grpc::ChannelInterface;
using grpc::ClientContext;
using grpc::Status;
using banksimulation::BankSimulatorState;
using banksimulation::ServerAck;
using banksimulation::BankSimulatorStateProxy;

class StateProxyClient {
private:
  BankSimulatorState state;

public:
  StateProxyClient(std::shared_ptr<ChannelInterface> channel)
      : stub_(BankSimulatorStateProxy::NewStub(channel)) {}

  void populateEventList(BankEvent arr[], int size) {
    for(int i = 0; i < size; i++) {
      BankSimulatorState::BankEvent* currentEvent = state.add_arrivalevent();

      currentEvent->set_arrivaltime(arr[i].getTime());
      currentEvent->set_duration(arr[i].getDuration());
    }

  }

  void setTellerNum(int tellerNum) {
    state.set_tellernum(tellerNum);
  }

  void setTellerCount(int tellerCount) {
    state.set_tellercount(tellerCount);
  }

  void setCurrentTime(int currentTime) {
    state.set_currenttime(currentTime);
  }

  void setAction(BankSimulatorState::Action action) {
    state.set_currentaction(action);
  }

  bool SendState() {
    ServerAck reply;
    ClientContext context;

    state.set_pid((int)getpid());

    Status status = stub_->SendState(&context, state, &reply);

    state.clear_arrivalevent();
    state.clear_tellernum();
    state.clear_tellercount();
    state.clear_currenttime();
    state.clear_currentaction();

    if (status.IsOk()) {
      return reply.ack();
    } else {
      std::cout << "Rpc failed" << endl;
    }
  }

 private:
  std::unique_ptr<BankSimulatorStateProxy::Stub> stub_;
};

#endif