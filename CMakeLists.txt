cmake_minimum_required(VERSION 3.0)
project(timer_test VERSION 0.0.1)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  ddynamic_reconfigure
  message_generation
  nodelet
  roscpp
  rospy
  roslint
  std_msgs
)

set(
  ROSLINT_CPP_OPTS
  "--extensions=cpp,h,hpp" "--filter=-whitespace/braces"
)
roslint_cpp()
roslint_python()

catkin_package(
  # INCLUDE_DIRS include
  CATKIN_DEPENDS ddynamic_reconfigure
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
add_executable(timer_test_cpp src/timer_test.cpp)
target_link_libraries(timer_test_cpp
  ${catkin_LIBRARIES}
)

install(PROGRAMS
  scripts/timer_test.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
