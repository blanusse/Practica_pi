# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /tmp/Practica

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/Practica/cmake-build-docker

# Include any dependencies generated for this target.
include CMakeFiles/Prac4.15.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prac4.15.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prac4.15.dir/flags.make

CMakeFiles/Prac4.15.dir/Practica4/ej15.c.o: CMakeFiles/Prac4.15.dir/flags.make
CMakeFiles/Prac4.15.dir/Practica4/ej15.c.o: ../Practica4/ej15.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Prac4.15.dir/Practica4/ej15.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Prac4.15.dir/Practica4/ej15.c.o   -c /tmp/Practica/Practica4/ej15.c

CMakeFiles/Prac4.15.dir/Practica4/ej15.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Prac4.15.dir/Practica4/ej15.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Practica4/ej15.c > CMakeFiles/Prac4.15.dir/Practica4/ej15.c.i

CMakeFiles/Prac4.15.dir/Practica4/ej15.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Prac4.15.dir/Practica4/ej15.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Practica4/ej15.c -o CMakeFiles/Prac4.15.dir/Practica4/ej15.c.s

# Object files for target Prac4.15
Prac4_15_OBJECTS = \
"CMakeFiles/Prac4.15.dir/Practica4/ej15.c.o"

# External object files for target Prac4.15
Prac4_15_EXTERNAL_OBJECTS =

Prac4.15: CMakeFiles/Prac4.15.dir/Practica4/ej15.c.o
Prac4.15: CMakeFiles/Prac4.15.dir/build.make
Prac4.15: CMakeFiles/Prac4.15.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Prac4.15"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prac4.15.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prac4.15.dir/build: Prac4.15

.PHONY : CMakeFiles/Prac4.15.dir/build

CMakeFiles/Prac4.15.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Prac4.15.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Prac4.15.dir/clean

CMakeFiles/Prac4.15.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/Prac4.15.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Prac4.15.dir/depend

