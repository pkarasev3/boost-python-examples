#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <vector>
#include <stdlib.h>

using namespace boost::python;

std::vector<int> makevector(unsigned len) {
  std::vector<int> v(len);
  for (unsigned j=0; j<len; ++j)
    v[j] = random();
  return v;
}

BOOST_PYTHON_MODULE(m4a)
{
  class_<std::vector<int> >("vector_int")
    .def(vector_indexing_suite<std::vector<int> >())
    ;
  
  def("makevector", &makevector);

}
