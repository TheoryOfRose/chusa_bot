cmake_minimum_required(VERSION 2.8.3)
project(chusa_odom)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  sensor_msgs
  tf
  nav_msgs
  roscpp
  std_msgs
)

add_executable(chusa_odom src/chusa_odom.cpp)
target_link_libraries(chusa_odom ${catkin_LIBRARIES})
add_dependencies(chusa_odom ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Generate added messages and services with any dependencies listed here
#generate_messages(
#   DEPENDENCIES geometry_msgs std_msgs
# )
catkin_package(
  INCLUDE_DIRS include
  #LIBRARIES chusa_odom
  CATKIN_DEPENDS geometry_msgs roscpp std_msgs sensor_msgs nav_msgs tf
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
