cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS python)
find_package(PythonLibs)

include_directories(
  ${PYTHON_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  )

macro(pybindings libname)

  add_library(${libname} SHARED ${ARGN})

  target_link_libraries(${libname}
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    )

  set_target_properties(${libname}
    PROPERTIES
    PREFIX "" # remove the 'lib'
    )
endmacro()




  

foreach(lib 
    m1a.helloworld
    m1b.modnameerror
    m2a.helloint
    m2b.udt
    m2bb.staticmethod
    m2bc.enums
    m2c.udtpass
    m2cb.udt
    m2d.datamember
    m2e.readonly
    m2f.constructor
    m2g.constructors
    m2h.properties
    m2i.inheritance
    m2j.virtual1
    m2k.virtual2
    m2ka.masquerade
    m2kb.virtual_with_default
    m2l.pyobj
    m2m.pyobj_udt
    m2n.holder
    m2o.holder2
    m3a.pose
    m3b.pose
    m3c.position
    m3e.position
    m4a.vector
    m4b.map
    )

  string(REGEX REPLACE "\\..*$" ""
    base
    ${lib})
  message(STATUS ".. ${base}")
    

  pybindings(${base} ${lib}.cpp)

endforeach()