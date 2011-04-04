#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

struct WrappedClass { };
struct UnWrappedClass { };

void takes_obj(object o) 
{ 
  extract<int> extractor(o);
  bool convertible = extractor.check();
  std::cout << "convertible=" << convertible << "\n";
  if (convertible)
    std::cout << "extracted=" << extractor() << "\n";
}

void pass_unwrapped() {
  UnWrappedClass uc;
  takes_obj(object(uc));
}

BOOST_PYTHON_MODULE(m2m)
{
  class_<WrappedClass>("WrappedClass")
    ;

  def("takes_obj", &takes_obj);
  def("pass_unwrapped", &pass_unwrapped);
}

