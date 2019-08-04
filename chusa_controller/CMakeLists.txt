cmake_minimum_required(VERSION 2.8.3)
project(cmd2ard)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  roscpp
  std_msgs
)

add_message_files(FILES arduino.msg)

add_executable(cmd2ard src/cmd2ard.cpp)
target_link_libraries(cmd2ard ${catkin_LIBRARIES})
add_dependencies(cmd2ard ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

generate_messages(DEPENDENCIES std_msgs)

add_dependencies(cmd2ard my_package_generate_message_cpp)

## Generate added messages and services with any dependencies listed here
#generate_messages(
#   DEPENDENCIES geometry_msgs std_msgs
# )
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES cmd2ard
  CATKIN_DEPENDS geometry_msgs roscpp std_msgs message_runtime
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations

include_directories(
  ${catkin_INCLUDE_DIRS} ./include
)

#install(DIRECTORY include/${PROJECT_NAME}/DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
#install(TARGETS cmd2ard RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
