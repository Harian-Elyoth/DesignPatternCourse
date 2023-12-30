#include "Person.hpp"

struct Person::PersonImpl {
  void greet(Person *p);
};

void Person::PersonImpl::greet(Person *p) {
  printf("hello %s", p->name.c_str());
}

Person::Person() : impl(new PersonImpl) {}

Person::~Person() { delete impl; }

void Person::greet() { impl->greet(this); }

int main() {
  // pimpl
  // binary interfaces are fragile; this removes most of the internals to a
  // separate class prevents recompilation of sources reliant on the header

  Person p;
  p.greet();

  getchar();
  return 0;
}
