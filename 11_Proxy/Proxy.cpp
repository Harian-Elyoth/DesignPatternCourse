// Subject Interface
class Subject {
public:
    virtual void request() = 0;
};

// RealSubject Class
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: Handling request.\n";
    }
};

// Proxy Class
class Proxy : public Subject {
private:
    RealSubject* realSubject;

    bool checkAccess() const {
        // Some real checks should go here.
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }

    void logAccess() const {
        std::cout << "Proxy: Logging the time of request.\n";
    }

public:
    Proxy(RealSubject* realSubject) : realSubject(new RealSubject(*realSubject)) {}

    ~Proxy() {
        delete realSubject;
    }

    void request() override {
        if (this->checkAccess()) {
            this->realSubject->request();
            this->logAccess();
        }
    }
};

// Client code
int main() {
    std::cout << "Client: Executing the client code with a real subject:\n";
    RealSubject* realSubject = new RealSubject;
    realSubject->request();

    std::cout << "\n";

    std::cout << "Client: Executing the same client code with a proxy:\n";
    Proxy* proxy = new Proxy(realSubject);
    proxy->request();

    delete realSubject;
    delete proxy;

    return 0;
}