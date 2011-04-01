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
    m2c.udtpass
    )

  string(REGEX REPLACE "\\..*$" ""
    base
    ${lib})
  message(STATUS ".. ${base}")
    

  pybindings(${base} ${lib}.cpp)

endforeach()