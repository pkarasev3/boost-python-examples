#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

struct Base 
{
  virtual ~Base();
  virtual void foo() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
};
Base::~Base() { }

void takes_base(Base& b) { std::cout << __PRETTY_FUNCTION__ << " base @ " << &b << "\n"; b.foo(); }

struct BaseWrap : Base, wrapper<Base>
{
  void foo() 
  { 
    if (override fn = this->get_override("foo"))
      fn();
    else
      Base::foo();
  }
};

BOOST_PYTHON_MODULE(m2kb)
{
  class_<BaseWrap, boost::noncopyable>("Base")
    .def("foo", &Base::foo)
    ;
  
  def("takes_base", &takes_base);
}

