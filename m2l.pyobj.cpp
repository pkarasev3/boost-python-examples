#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

void takes_obj(object o) 
{ 
  extract<int> extractor(o);
  bool convertible = extractor.check();
  std::cout << "convertible=" << convertible << "\n";
  if (convertible)
    std::cout << "extracted=" << extractor() << "\n";
}

BOOST_PYTHON_MODULE(m2l)
{
  def("takes_obj", &takes_obj);
}

