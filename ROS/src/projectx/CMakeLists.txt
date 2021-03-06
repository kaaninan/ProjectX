cmake_minimum_required(VERSION 2.8.3)
project(projectx)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  rosparam
  message_generation
)

add_service_files(
  FILES
  SensorTemp.srv
  MotorBoost.srv
  Speech.srv
)

add_message_files(
  FILES
  Sensor.msg
  Hash.msg
  MotorIn.msg
  MotorInArray.msg
  MotorOut.msg
  DataControl.msg
  IntArray.msg
  Gyro.msg
  OscData.msg
  CommonProperties.msg
  Label.msg
  MultiButton.msg
  MultiFader.msg
  MultiXYPad.msg
  ScalableControl.msg
  Tabpage.msg
  TouchOSC_Common.msg
  XYPad.msg
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
## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

include_directories(
  ${catkin_INCLUDE_DIRS}
  src/${PROJECT_NAME}/include
)


# add_library(projectx
#   src/${PROJECT_NAME}/projectx.cpp
# )


#add_executable(motor_boost_server src/motor_boost_server.cpp)
#target_link_libraries(motor_boost_server ${catkin_LIBRARIES})
#add_dependencies(motor_boost_server projectx_gencpp)

