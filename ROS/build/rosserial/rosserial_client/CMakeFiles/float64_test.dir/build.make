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
CMAKE_SOURCE_DIR = /home/kaaninan/ProjectX/ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kaaninan/ProjectX/ROS/build

# Include any dependencies generated for this target.
include rosserial/rosserial_client/CMakeFiles/float64_test.dir/depend.make

# Include the progress variables for this target.
include rosserial/rosserial_client/CMakeFiles/float64_test.dir/progress.make

# Include the compile flags for this target's objects.
include rosserial/rosserial_client/CMakeFiles/float64_test.dir/flags.make

rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o: rosserial/rosserial_client/CMakeFiles/float64_test.dir/flags.make
rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o: /home/kaaninan/ProjectX/ROS/src/rosserial/rosserial_client/test/float64_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kaaninan/ProjectX/ROS/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o"
	cd /home/kaaninan/ProjectX/ROS/build/rosserial/rosserial_client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/float64_test.dir/test/float64_test.cpp.o -c /home/kaaninan/ProjectX/ROS/src/rosserial/rosserial_client/test/float64_test.cpp

rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/float64_test.dir/test/float64_test.cpp.i"
	cd /home/kaaninan/ProjectX/ROS/build/rosserial/rosserial_client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kaaninan/ProjectX/ROS/src/rosserial/rosserial_client/test/float64_test.cpp > CMakeFiles/float64_test.dir/test/float64_test.cpp.i

rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/float64_test.dir/test/float64_test.cpp.s"
	cd /home/kaaninan/ProjectX/ROS/build/rosserial/rosserial_client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kaaninan/ProjectX/ROS/src/rosserial/rosserial_client/test/float64_test.cpp -o CMakeFiles/float64_test.dir/test/float64_test.cpp.s

rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o.requires:
.PHONY : rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o.requires

rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o.provides: rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o.requires
	$(MAKE) -f rosserial/rosserial_client/CMakeFiles/float64_test.dir/build.make rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o.provides.build
.PHONY : rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o.provides

rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o.provides.build: rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o

# Object files for target float64_test
float64_test_OBJECTS = \
"CMakeFiles/float64_test.dir/test/float64_test.cpp.o"

# External object files for target float64_test
float64_test_EXTERNAL_OBJECTS =

/home/kaaninan/ProjectX/ROS/devel/lib/rosserial_client/float64_test: rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o
/home/kaaninan/ProjectX/ROS/devel/lib/rosserial_client/float64_test: rosserial/rosserial_client/CMakeFiles/float64_test.dir/build.make
/home/kaaninan/ProjectX/ROS/devel/lib/rosserial_client/float64_test: gtest/libgtest.so
/home/kaaninan/ProjectX/ROS/devel/lib/rosserial_client/float64_test: rosserial/rosserial_client/CMakeFiles/float64_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/kaaninan/ProjectX/ROS/devel/lib/rosserial_client/float64_test"
	cd /home/kaaninan/ProjectX/ROS/build/rosserial/rosserial_client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/float64_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rosserial/rosserial_client/CMakeFiles/float64_test.dir/build: /home/kaaninan/ProjectX/ROS/devel/lib/rosserial_client/float64_test
.PHONY : rosserial/rosserial_client/CMakeFiles/float64_test.dir/build

rosserial/rosserial_client/CMakeFiles/float64_test.dir/requires: rosserial/rosserial_client/CMakeFiles/float64_test.dir/test/float64_test.cpp.o.requires
.PHONY : rosserial/rosserial_client/CMakeFiles/float64_test.dir/requires

rosserial/rosserial_client/CMakeFiles/float64_test.dir/clean:
	cd /home/kaaninan/ProjectX/ROS/build/rosserial/rosserial_client && $(CMAKE_COMMAND) -P CMakeFiles/float64_test.dir/cmake_clean.cmake
.PHONY : rosserial/rosserial_client/CMakeFiles/float64_test.dir/clean

rosserial/rosserial_client/CMakeFiles/float64_test.dir/depend:
	cd /home/kaaninan/ProjectX/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kaaninan/ProjectX/ROS/src /home/kaaninan/ProjectX/ROS/src/rosserial/rosserial_client /home/kaaninan/ProjectX/ROS/build /home/kaaninan/ProjectX/ROS/build/rosserial/rosserial_client /home/kaaninan/ProjectX/ROS/build/rosserial/rosserial_client/CMakeFiles/float64_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rosserial/rosserial_client/CMakeFiles/float64_test.dir/depend

