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
  Pin.srv
  SensorTemp.srv
  AddTwoInts.srv
)

add_message_files(
  FILES
  Sensor.msg
  MotorIn.msg
  MotorOut.msg
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

add_executable(chat_server src/chat_server.cpp)
target_link_libraries(chat_server ${catkin_LIBRARIES})
add_dependencies(chat_server chat_server_generate_messages_cpp)

add_executable(arduino_sicaklik src/arduino_sicaklik.cpp)
target_link_libraries(arduino_sicaklik ${catkin_LIBRARIES})
add_dependencies(arduino_sicaklik arduino_sicaklik_generate_messages_cpp)

add_executable(service_test src/service_test.cpp)
target_link_libraries(service_test ${catkin_LIBRARIES})
add_dependencies(service_test beginner_tutorials_gencpp)

add_executable(service_client src/service_client.cpp)
target_link_libraries(service_client ${catkin_LIBRARIES})
add_dependencies(service_client beginner_tutorials_gencpp)

add_executable(motorSubscriber src/motorSubscriber.cpp)
target_link_libraries(motorSubscriber ${catkin_LIBRARIES})
add_dependencies(motorSubscriber beginner_tutorials_gencpp)