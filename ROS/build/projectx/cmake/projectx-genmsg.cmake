# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "projectx: 14 messages, 3 services")

set(MSG_I_FLAGS "-Iprojectx:/home/rock/ProjectX/ROS/src/projectx/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(projectx_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/XYPad.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/XYPad.msg" "std_msgs/Header:projectx/CommonProperties"
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Sensor.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/Sensor.msg" ""
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg" "std_msgs/Header:projectx/CommonProperties"
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiButton.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/MultiButton.msg" "std_msgs/Header:projectx/CommonProperties"
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg" "std_msgs/Header:projectx/CommonProperties"
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MotorOut.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/MotorOut.msg" ""
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/ScalableControl.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/ScalableControl.msg" "std_msgs/Header:projectx/CommonProperties"
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Tabpage.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/Tabpage.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Label.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/Label.msg" "std_msgs/Header:projectx/CommonProperties"
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Gyro.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/Gyro.msg" ""
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/SensorTemp.srv" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/srv/SensorTemp.srv" ""
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MotorIn.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/MotorIn.msg" ""
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg" ""
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiFader.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/MultiFader.msg" "std_msgs/Header:projectx/CommonProperties"
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/Pin.srv" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/srv/Pin.srv" ""
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/AddTwoInts.srv" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/srv/AddTwoInts.srv" ""
)

get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/OscData.msg" NAME_WE)
add_custom_target(_projectx_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projectx" "/home/rock/ProjectX/ROS/src/projectx/msg/OscData.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/XYPad.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Tabpage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiButton.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/ScalableControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MotorOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Label.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/OscData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Gyro.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MotorIn.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_msg_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiFader.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)

### Generating Services
_generate_srv_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/Pin.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_srv_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)
_generate_srv_cpp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/SensorTemp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
)

### Generating Module File
_generate_module_cpp(projectx
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(projectx_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(projectx_generate_messages projectx_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/XYPad.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Sensor.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiButton.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MotorOut.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/ScalableControl.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Tabpage.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Label.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Gyro.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/SensorTemp.srv" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MotorIn.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiFader.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/Pin.srv" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/OscData.msg" NAME_WE)
add_dependencies(projectx_generate_messages_cpp _projectx_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(projectx_gencpp)
add_dependencies(projectx_gencpp projectx_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS projectx_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/XYPad.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Tabpage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiButton.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/ScalableControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MotorOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Label.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/OscData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Gyro.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MotorIn.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_msg_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiFader.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)

### Generating Services
_generate_srv_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/Pin.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_srv_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)
_generate_srv_lisp(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/SensorTemp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
)

### Generating Module File
_generate_module_lisp(projectx
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(projectx_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(projectx_generate_messages projectx_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/XYPad.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Sensor.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiButton.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MotorOut.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/ScalableControl.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Tabpage.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Label.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Gyro.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/SensorTemp.srv" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MotorIn.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiFader.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/Pin.srv" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/OscData.msg" NAME_WE)
add_dependencies(projectx_generate_messages_lisp _projectx_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(projectx_genlisp)
add_dependencies(projectx_genlisp projectx_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS projectx_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/XYPad.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Tabpage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiButton.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/ScalableControl.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MotorOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Label.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/OscData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/Gyro.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MotorIn.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_msg_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/msg/MultiFader.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)

### Generating Services
_generate_srv_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/Pin.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_srv_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)
_generate_srv_py(projectx
  "/home/rock/ProjectX/ROS/src/projectx/srv/SensorTemp.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
)

### Generating Module File
_generate_module_py(projectx
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(projectx_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(projectx_generate_messages projectx_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/XYPad.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Sensor.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiXYPad.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiButton.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/TouchOSC_Common.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MotorOut.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/ScalableControl.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Tabpage.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Label.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/Gyro.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/SensorTemp.srv" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MotorIn.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/CommonProperties.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/MultiFader.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/Pin.srv" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rock/ProjectX/ROS/src/projectx/msg/OscData.msg" NAME_WE)
add_dependencies(projectx_generate_messages_py _projectx_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(projectx_genpy)
add_dependencies(projectx_genpy projectx_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS projectx_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projectx
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(projectx_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projectx
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(projectx_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projectx
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(projectx_generate_messages_py std_msgs_generate_messages_py)
