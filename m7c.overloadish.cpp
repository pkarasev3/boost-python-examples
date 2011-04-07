#include <boost/python.hpp>
#include <iostream>
#include "Position.h"

namespace bp = boost::python;

std::string handle_pyerror();

int main(int argc, char** argv)
{
  try {

    char* configfile_name = argv[1];
  
    Py_Initialize();
    bp::object main = bp::import("__main__");
    bp::object py_ = main.attr("__dict__");
    bp::exec_file(argv[1], py_, py_);

    bp::object fn = py_["fn"];

    Position p(3,4,5);
    bp::object rv = fn(p);
    std::cout << "it returned: " << bp::extract<float>(rv) << "\n";

  } catch(const bp::error_already_set& e) {

    std::cerr << handle_pyerror();

  }
  
}
