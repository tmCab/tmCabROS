cmake_minimum_required(VERSION 2.8.3)
project(tm_cab)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  pluginlib
  cmake_modules
  moveit_core
  moveit_ros_move_group
  joint_state_publisher
  robot_state_publisher
  kdl_parser
  roscpp
  rospy
  std_msgs
  message_generation
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   Num.msg
   SYS_STATUS.msg
   TOPIC_STATUS.msg
   TOPIC_VARIABLES.msg
   POS_CART.msg
   POS_REF.msg
#   Message1.msg
#   Message2.msg
)

## Generate services in the 'srv' folder
 add_service_files(
   FILES
   AddTwoInts.srv
   CTL_MODE.srv
   SAFE_FORCE.srv
   SAFE_CURR.srv
   SAFE_POS_E.srv
   SAFE_POS.srv
   SAFE_PWM.srv
   SAFE_SPEED.srv
   SELECT_CTL.srv
   SET_INTER.srv
   SET_PAR_PID.srv
   START.srv
   STOP.srv
   SET_SYS_FS.srv
   SAFE_STATE.srv
   PTP_TM_CTL.srv
   START_TM_CTL.srv
   STOP_TM_CTL.srv
   set_par.srv
   jnt_traj.srv
   set_pwm_pars.srv
#   Service1.srv
#   Service2.srv
 )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include src/DriverFsm src/sflash
  LIBRARIES tm_cab
   CATKIN_DEPENDS kdl_parser message_runtime roscpp rospy std_msgs
   moveit_core
   moveit_ros_move_group
   joint_state_publisher
   robot_state_publisher
)
find_package(Eigen REQUIRED)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
	include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(tm_cab
#   src/${PROJECT_NAME}/tm_cab.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(tm_cab ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
# add_executable(tm_cab_node src/tm_cab_node.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(tm_cab_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(tm_cab_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS tm_cab tm_cab_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_tm_cab.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

add_executable(tm_manager src/tm_manager.cpp)
target_link_libraries(tm_manager ${catkin_LIBRARIES})
add_dependencies(tm_manager tm_cab_gencpp)

add_executable(tm_action src/tm_action.cpp)
target_link_libraries(tm_action ${catkin_LIBRARIES})
add_dependencies(tm_action tm_cab_gencpp)

add_executable(joint_driver src/joint_driver.cpp)

add_library( DriverFsm src/DriverFsm/ComCmds.cpp
			  src/DriverFsm/ComPort.cpp
			  src/DriverFsm/SysClk.cpp
			  src/DriverFsm/SysFsm.cpp)
			  
add_library( sflash src/sflash/sflash.c
				src/sflash/packet_handler.c
				src/sflash/uart_handler.c)

target_link_libraries(joint_driver ${catkin_LIBRARIES} DriverFsm sflash rt)
add_dependencies(joint_driver tm_cab_gencpp)

add_library( ForceSensor src/ForceSensor/tm_force_sensor.cpp)

add_executable(force_sensor src/force_sensor.cpp)
target_link_libraries(force_sensor ${catkin_LIBRARIES} ForceSensor mccusb  m  hidapi-libusb usb-1.0 rt)
add_dependencies(force_sensor tm_cab_gencpp)

add_executable(Controller src/Controller.cpp)
target_link_libraries(Controller ${catkin_LIBRARIES} rt)
add_dependencies(Controller tm_cab_gencpp)

add_executable(joint_tray_interp src/joint_tray_interp.cpp)
target_link_libraries(joint_tray_interp ${catkin_LIBRARIES} rt)
add_dependencies(joint_tray_interp tm_cab_gencpp)
