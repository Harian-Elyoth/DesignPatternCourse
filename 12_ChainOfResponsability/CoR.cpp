#include <iostream>

// Handler Interface
class Handler {
protected:
  Handler *nextHandler;

public:
  Handler() : nextHandler(nullptr) {}

  void setNextHandler(Handler *handler) { nextHandler = handler; }

  virtual void handleRequest(int request) {
    if (nextHandler != nullptr) {
      nextHandler->handleRequest(request);
    }
  }
};

// ConcreteHandler1 Class
class ConcreteHandler1 : public Handler {
public:
  void handleRequest(int request) override {
    if (request == 1) {
      std::cout << "ConcreteHandler1 handled the request.\n";
    } else if (nextHandler != nullptr) {
      nextHandler->handleRequest(request);
    }
  }
};

// ConcreteHandler2 Class
class ConcreteHandler2 : public Handler {
public:
  void handleRequest(int request) override {
    if (request == 2) {
      std::cout << "ConcreteHandler2 handled the request.\n";
    } else if (nextHandler != nullptr) {
      nextHandler->handleRequest(request);
    }
  }
};

// Client code
int main() {
  ConcreteHandler1 handler1;
  ConcreteHandler2 handler2;

  handler1.setNextHandler(&handler2);

  handler1.handleRequest(1);
  handler1.handleRequest(2);
  handler1.handleRequest(3);

  return 0;
}