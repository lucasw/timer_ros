cmake_minimum_required(VERSION 3.0)
project(timer_test VERSION 0.0.1)

find_package(catkin REQUIRED COMPONENTS
  ddynamic_reconfigure
  dynamic_reconfigure
  message_generation
  # nodelet
  roscpp
  roslint
  rospy
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
  CATKIN_DEPENDS
  ddynamic_reconfigure
  dynamic_reconfigure
  std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
add_executable(${PROJECT_NAME}_cpp src/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME}_cpp
  ${catkin_LIBRARIES}
)

add_executable(bad_time src/bad_time.cpp)
target_link_libraries(bad_time
  ${catkin_LIBRARIES}
)

install(TARGETS bad_time
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(PROGRAMS
  scripts/${PROJECT_NAME}.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
