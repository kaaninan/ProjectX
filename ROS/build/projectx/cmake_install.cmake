# Install script for directory: /home/ubuntu/ProjectX/ROS/src/projectx

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/ubuntu/ProjectX/ROS/install")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/projectx/srv" TYPE FILE FILES
    "/home/ubuntu/ProjectX/ROS/src/projectx/srv/SensorTemp.srv"
    "/home/ubuntu/ProjectX/ROS/src/projectx/srv/MotorBoost.srv"
    "/home/ubuntu/ProjectX/ROS/src/projectx/srv/Speech.srv"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/projectx/msg" TYPE FILE FILES
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/Sensor.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/Hash.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/MotorIn.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/MotorInArray.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/MotorOut.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/DataControl.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/IntArray.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/Gyro.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/OscData.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/Label.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/MultiButton.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/MultiFader.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/ScalableControl.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/Tabpage.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg"
    "/home/ubuntu/ProjectX/ROS/src/projectx/msg/XYPad.msg"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/projectx/cmake" TYPE FILE FILES "/home/ubuntu/ProjectX/ROS/build/projectx/catkin_generated/installspace/projectx-msg-paths.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/ubuntu/ProjectX/ROS/devel/include/projectx")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/ubuntu/ProjectX/ROS/devel/share/common-lisp/ros/projectx")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/ubuntu/ProjectX/ROS/devel/lib/python2.7/dist-packages/projectx")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/ubuntu/ProjectX/ROS/devel/lib/python2.7/dist-packages/projectx")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

