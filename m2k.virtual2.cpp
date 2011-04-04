#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

struct Base 
{
  virtual ~Base();
  virtual void foo() = 0; // pure virtual
};
Base::~Base() { }

struct Derived : Base 
{
  virtual ~Derived();
  virtual void foo();
};
Derived::~Derived() { }
void Derived::foo() { std::cout << __PRETTY_FUNCTION__<< "\n"; }

void takes_base(Base& b) { std::cout << __PRETTY_FUNCTION__ << " base @ " << &b << "\n"; b.foo(); }
void takes_derived(Derived& d) { std::cout << __PRETTY_FUNCTION__ << " derived @ " << &d << "\n"; d.foo(); }

struct BaseWrap : Base, wrapper<Base>
{
  void foo() { this->get_override("foo")(); }
};

BOOST_PYTHON_MODULE(m2k)
{
  class_<BaseWrap, boost::noncopyable>("Base")
    .def("foo", pure_virtual(&Base::foo))
    ;
  
  class_<Derived, bases<Base> >("Derived")
    .def("foo", &Derived::foo)
    ;

  def("takes_base", &takes_base);
  def("takes_derived", &takes_derived);
}

