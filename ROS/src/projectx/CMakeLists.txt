cmake_minimum_required(VERSION 2.8.3)
project(projectx)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  rosparam
  message_generation
)

add_service_files(
  FILES
  Pin.srv
  SensorTemp.srv
  AddTwoInts.srv
)

add_message_files(
  FILES
  Sensor.msg
  MotorIn.msg
  MotorInArray.msg
  MotorOut.msg
  MotorOutArray.msg
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



add_executable(motor_boost_client src/motor_boost_client.cpp)
target_link_libraries(motor_boost_client ${catkin_LIBRARIES})
add_dependencies(motor_boost_client projectx_gencpp)

add_executable(motor_boost_server src/motor_boost_server.cpp)
target_link_libraries(motor_boost_server ${catkin_LIBRARIES})
add_dependencies(motor_boost_server projectx_gencpp)




add_executable(arduino_sicaklik src/arduino_sicaklik.cpp)
target_link_libraries(arduino_sicaklik ${catkin_LIBRARIES})
add_dependencies(arduino_sicaklik projectx_gencpp)


add_executable(service_client src/service_client.cpp)
target_link_libraries(service_client ${catkin_LIBRARIES})
add_dependencies(service_client projectx_gencpp)

add_executable(service_server src/service_server.cpp)
target_link_libraries(service_server ${catkin_LIBRARIES})
add_dependencies(service_server projectx_gencpp)