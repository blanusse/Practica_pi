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
include CMakeFiles/Prac4.13a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prac4.13a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prac4.13a.dir/flags.make

CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.o: CMakeFiles/Prac4.13a.dir/flags.make
CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.o: ../Practica4/tp4_13a.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.o   -c /tmp/Practica/Practica4/tp4_13a.c

CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Practica4/tp4_13a.c > CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.i

CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Practica4/tp4_13a.c -o CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.s

# Object files for target Prac4.13a
Prac4_13a_OBJECTS = \
"CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.o"

# External object files for target Prac4.13a
Prac4_13a_EXTERNAL_OBJECTS =

Prac4.13a: CMakeFiles/Prac4.13a.dir/Practica4/tp4_13a.c.o
Prac4.13a: CMakeFiles/Prac4.13a.dir/build.make
Prac4.13a: CMakeFiles/Prac4.13a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Prac4.13a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prac4.13a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prac4.13a.dir/build: Prac4.13a

.PHONY : CMakeFiles/Prac4.13a.dir/build

CMakeFiles/Prac4.13a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Prac4.13a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Prac4.13a.dir/clean

CMakeFiles/Prac4.13a.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/Prac4.13a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Prac4.13a.dir/depend

