#include <iostream>
#include <vector>

// Command Interface
class Command {
public:
    virtual void execute() = 0;
};

// Receiver Class
class Receiver {
public:
    void action1() {
        std::cout << "Receiver: Executing action 1.\n";
    }

    void action2() {
        std::cout << "Receiver: Executing action 2.\n";
    }
};

// ConcreteCommand1 Class
class ConcreteCommand1 : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand1(Receiver* receiver) : receiver(receiver) {}

    void execute() override {
        receiver->action1();
    }
};

// ConcreteCommand2 Class
class ConcreteCommand2 : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand2(Receiver* receiver) : receiver(receiver) {}

    void execute() override {
        receiver->action2();
    }
};

// Invoker Class
class Invoker {
private:
    std::vector<Command*> commandList;

public:
    void storeAndExecute(Command* command) {
        commandList.push_back(command);
        command->execute();
    }
};

// Client code
int main() {
    Receiver receiver;
    ConcreteCommand1 command1(&receiver);
    ConcreteCommand2 command2(&receiver);

    Invoker invoker;
    invoker.storeAndExecute(&command1);
    invoker.storeAndExecute(&command2);

    return 0;
}