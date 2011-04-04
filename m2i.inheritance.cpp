#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct Base 
{
  virtual ~Base();
};
Base::~Base() { }

struct Derived : Base 
{
  virtual ~Derived();
};
Derived::~Derived() { }

void takes_base(Base& b) { std::cout << __PRETTY_FUNCTION__ << " base @ " << &b << "\n"; }
void takes_derived(Derived& d) { std::cout << __PRETTY_FUNCTION__ << " derived @ " << &d << "\n"; }

BOOST_PYTHON_MODULE(m2i)
{
  class_<Base>("Base");
  class_<Derived, bases<Base> >("Derived");
  def("takes_base", &takes_base);
  def("takes_derived", &takes_derived);
}

