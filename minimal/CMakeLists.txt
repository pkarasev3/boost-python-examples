cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS python)
find_package(PythonLibs)

include_directories(
  ${PYTHON_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  )

add_library(mylib SHARED lib.cpp)

add_library(mypy SHARED module.cpp)

target_link_libraries(mypy
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES}
  mylib
  )

set_target_properties(mypy
  PROPERTIES
  PREFIX "" # remove the 'lib'
  )
