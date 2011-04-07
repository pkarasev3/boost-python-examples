#include <boost/python.hpp>
#include "std_map_indexing_suite.hpp"
#include <map>
#include <stdlib.h>

using namespace boost::python;

void dumpmap(const std::map<std::string, double>& m)
{
  for (std::map<std::string, double>::const_iterator it = m.begin(), end = m.end();
       it != end;
       ++it)
    {
      std::cout << it->first << " ==> " << it->second << "\n";
    }
}

BOOST_PYTHON_MODULE(m4b)
{
  class_<std::map<std::string, double> >("map_string_double")
    .def(std_map_indexing_suite<std::map<std::string, double> >())
    ;

  def("dumpmap", &dumpmap);
}


