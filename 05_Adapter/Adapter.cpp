#include <iostream>
#include <memory>

// Existing interface
class LegacyInterface {
public:
  virtual void legacyOperation() const {
    std::cout << "Legacy Operation" << std::endl;
  }
};

// New interface expected by the client
class ModernInterface {
public:
  virtual void modernOperation() const = 0;
};

// Adapter to make the existing interface compatible with the new one
class Adapter : public ModernInterface {
private:
  std::unique_ptr<LegacyInterface> legacy;

public:
  Adapter(std::unique_ptr<LegacyInterface> legacyObj)
      : legacy(std::move(legacyObj)) {}

  void modernOperation() const override { legacy->legacyOperation(); }
};

// Client code that expects the modern interface
void clientCode(const ModernInterface &modernObj) {
  modernObj.modernOperation();
}

int main() {
  // Using the legacy code with the help of the adapter
  std::unique_ptr<LegacyInterface> legacyObj =
      std::make_unique<LegacyInterface>();
  std::unique_ptr<Adapter> adapter =
      std::make_unique<Adapter>(std::move(legacyObj));

  // Client code works with the modern interface
  clientCode(*adapter);

  return 0;
}
