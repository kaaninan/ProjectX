# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/ProjectX/ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ProjectX/ROS/build

# Include any dependencies generated for this target.
include projectx/CMakeFiles/motor_boost_server.dir/depend.make

# Include the progress variables for this target.
include projectx/CMakeFiles/motor_boost_server.dir/progress.make

# Include the compile flags for this target's objects.
include projectx/CMakeFiles/motor_boost_server.dir/flags.make

projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o: projectx/CMakeFiles/motor_boost_server.dir/flags.make
projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o: /home/ubuntu/ProjectX/ROS/src/projectx/src/motor_boost_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/ProjectX/ROS/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o"
	cd /home/ubuntu/ProjectX/ROS/build/projectx && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o -c /home/ubuntu/ProjectX/ROS/src/projectx/src/motor_boost_server.cpp

projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.i"
	cd /home/ubuntu/ProjectX/ROS/build/projectx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/ProjectX/ROS/src/projectx/src/motor_boost_server.cpp > CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.i

projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.s"
	cd /home/ubuntu/ProjectX/ROS/build/projectx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/ProjectX/ROS/src/projectx/src/motor_boost_server.cpp -o CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.s

projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o.requires:
.PHONY : projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o.requires

projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o.provides: projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o.requires
	$(MAKE) -f projectx/CMakeFiles/motor_boost_server.dir/build.make projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o.provides.build
.PHONY : projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o.provides

projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o.provides.build: projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o

# Object files for target motor_boost_server
motor_boost_server_OBJECTS = \
"CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o"

# External object files for target motor_boost_server
motor_boost_server_EXTERNAL_OBJECTS =

/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: projectx/CMakeFiles/motor_boost_server.dir/build.make
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /opt/ros/indigo/lib/libroscpp.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /opt/ros/indigo/lib/librosconsole.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/liblog4cxx.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /opt/ros/indigo/lib/librostime.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /opt/ros/indigo/lib/libcpp_common.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server: projectx/CMakeFiles/motor_boost_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server"
	cd /home/ubuntu/ProjectX/ROS/build/projectx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motor_boost_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
projectx/CMakeFiles/motor_boost_server.dir/build: /home/ubuntu/ProjectX/ROS/devel/lib/projectx/motor_boost_server
.PHONY : projectx/CMakeFiles/motor_boost_server.dir/build

projectx/CMakeFiles/motor_boost_server.dir/requires: projectx/CMakeFiles/motor_boost_server.dir/src/motor_boost_server.cpp.o.requires
.PHONY : projectx/CMakeFiles/motor_boost_server.dir/requires

projectx/CMakeFiles/motor_boost_server.dir/clean:
	cd /home/ubuntu/ProjectX/ROS/build/projectx && $(CMAKE_COMMAND) -P CMakeFiles/motor_boost_server.dir/cmake_clean.cmake
.PHONY : projectx/CMakeFiles/motor_boost_server.dir/clean

projectx/CMakeFiles/motor_boost_server.dir/depend:
	cd /home/ubuntu/ProjectX/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ProjectX/ROS/src /home/ubuntu/ProjectX/ROS/src/projectx /home/ubuntu/ProjectX/ROS/build /home/ubuntu/ProjectX/ROS/build/projectx /home/ubuntu/ProjectX/ROS/build/projectx/CMakeFiles/motor_boost_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projectx/CMakeFiles/motor_boost_server.dir/depend

