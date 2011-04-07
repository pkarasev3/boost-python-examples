#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

struct grasp_failure : std::exception 
{
  const char* msg_;
  grasp_failure(const char* msg) : msg_(msg) { }
  const char* what() { return msg_; }
};

void grasp_spoon() 
{
  throw grasp_failure("[[[ grasp failure: there is no spoon ]]]");
}

void throws_logic_error() {
  throw std::logic_error("[[[ thrown logic error ]]]");
}

namespace {
  PyObject* graspfailure_class_pyobj;
}


void translate(const grasp_failure& e)
{
  PyErr_SetObject(graspfailure_class_pyobj, object(e).ptr());
}

BOOST_PYTHON_MODULE(m2gb)
{
  def("grasp_spoon", &grasp_spoon);
  def("throws_logic_error", &throws_logic_error);

  class_<grasp_failure> 
    graspfailure_class("GraspFailure", init<const char*>());
  graspfailure_class.def("__str__", &grasp_failure::what);

  graspfailure_class_pyobj = graspfailure_class.ptr();
  register_exception_translator<grasp_failure>(&translate);
}
