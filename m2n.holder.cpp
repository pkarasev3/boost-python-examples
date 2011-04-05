#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

struct T 
{ 
  T() { 
    std::cout << __PRETTY_FUNCTION__ << "\n"; 
  }
  T(const T& rhs) { 
    std::cout << __PRETTY_FUNCTION__ << "\n"; 
  }
  std::string foo() { return "T::foo() !!!"; }
};

std::string takes_tptr(boost::shared_ptr<T> tptr)
{ 
  std::cout << "shared_ptr to " << tptr.get() << " has refcount " << tptr.use_count() << "\n";
  return tptr->foo();
}

std::string takes_trawptr(T* tptr)
{ 
  return tptr->foo();
}

std::string takes_tref(T& tref)
{ 
  return tref.foo();
}

boost::shared_ptr<T> make_t()
{
  static boost::shared_ptr<T> t(new T);
  return t;
}


BOOST_PYTHON_MODULE(m2n)
{
  class_<T>("T")
    .def("foo", &T::foo)
    ;

  def("takes_trawptr", &takes_trawptr);
  def("takes_tptr", &takes_tptr);
  def("takes_tref", &takes_tref);
  def("make_t", &make_t);
}

