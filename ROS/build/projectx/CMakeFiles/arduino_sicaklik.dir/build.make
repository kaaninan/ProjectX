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
CMAKE_SOURCE_DIR = /home/rock/ProjectX/ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rock/ProjectX/ROS/build

# Include any dependencies generated for this target.
include projectx/CMakeFiles/arduino_sicaklik.dir/depend.make

# Include the progress variables for this target.
include projectx/CMakeFiles/arduino_sicaklik.dir/progress.make

# Include the compile flags for this target's objects.
include projectx/CMakeFiles/arduino_sicaklik.dir/flags.make

projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o: projectx/CMakeFiles/arduino_sicaklik.dir/flags.make
projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o: /home/rock/ProjectX/ROS/src/projectx/src/arduino_sicaklik.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rock/ProjectX/ROS/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o"
	cd /home/rock/ProjectX/ROS/build/projectx && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o -c /home/rock/ProjectX/ROS/src/projectx/src/arduino_sicaklik.cpp

projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.i"
	cd /home/rock/ProjectX/ROS/build/projectx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rock/ProjectX/ROS/src/projectx/src/arduino_sicaklik.cpp > CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.i

projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.s"
	cd /home/rock/ProjectX/ROS/build/projectx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rock/ProjectX/ROS/src/projectx/src/arduino_sicaklik.cpp -o CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.s

projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o.requires:
.PHONY : projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o.requires

projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o.provides: projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o.requires
	$(MAKE) -f projectx/CMakeFiles/arduino_sicaklik.dir/build.make projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o.provides.build
.PHONY : projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o.provides

projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o.provides.build: projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o

# Object files for target arduino_sicaklik
arduino_sicaklik_OBJECTS = \
"CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o"

# External object files for target arduino_sicaklik
arduino_sicaklik_EXTERNAL_OBJECTS =

/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: projectx/CMakeFiles/arduino_sicaklik.dir/build.make
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /opt/ros/indigo/lib/libroscpp.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /opt/ros/indigo/lib/librosconsole.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/liblog4cxx.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /opt/ros/indigo/lib/librostime.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /opt/ros/indigo/lib/libcpp_common.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik: projectx/CMakeFiles/arduino_sicaklik.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik"
	cd /home/rock/ProjectX/ROS/build/projectx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arduino_sicaklik.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
projectx/CMakeFiles/arduino_sicaklik.dir/build: /home/rock/ProjectX/ROS/devel/lib/projectx/arduino_sicaklik
.PHONY : projectx/CMakeFiles/arduino_sicaklik.dir/build

projectx/CMakeFiles/arduino_sicaklik.dir/requires: projectx/CMakeFiles/arduino_sicaklik.dir/src/arduino_sicaklik.cpp.o.requires
.PHONY : projectx/CMakeFiles/arduino_sicaklik.dir/requires

projectx/CMakeFiles/arduino_sicaklik.dir/clean:
	cd /home/rock/ProjectX/ROS/build/projectx && $(CMAKE_COMMAND) -P CMakeFiles/arduino_sicaklik.dir/cmake_clean.cmake
.PHONY : projectx/CMakeFiles/arduino_sicaklik.dir/clean

projectx/CMakeFiles/arduino_sicaklik.dir/depend:
	cd /home/rock/ProjectX/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rock/ProjectX/ROS/src /home/rock/ProjectX/ROS/src/projectx /home/rock/ProjectX/ROS/build /home/rock/ProjectX/ROS/build/projectx /home/rock/ProjectX/ROS/build/projectx/CMakeFiles/arduino_sicaklik.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projectx/CMakeFiles/arduino_sicaklik.dir/depend
