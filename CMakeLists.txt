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
    mod1
    mod2)
  pybindings(${lib} ${lib}.cpp)
endforeach()