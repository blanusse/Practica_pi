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
include CMakeFiles/Taller1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Taller1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Taller1.dir/flags.make

CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.o: CMakeFiles/Taller1.dir/flags.make
CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.o: ../Taller/Taller1/Taller1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.o   -c /tmp/Practica/Taller/Taller1/Taller1.c

CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Taller/Taller1/Taller1.c > CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.i

CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Taller/Taller1/Taller1.c -o CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.s

CMakeFiles/Taller1.dir/Lib/utillist.c.o: CMakeFiles/Taller1.dir/flags.make
CMakeFiles/Taller1.dir/Lib/utillist.c.o: ../Lib/utillist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Taller1.dir/Lib/utillist.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Taller1.dir/Lib/utillist.c.o   -c /tmp/Practica/Lib/utillist.c

CMakeFiles/Taller1.dir/Lib/utillist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Taller1.dir/Lib/utillist.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Lib/utillist.c > CMakeFiles/Taller1.dir/Lib/utillist.c.i

CMakeFiles/Taller1.dir/Lib/utillist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Taller1.dir/Lib/utillist.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Lib/utillist.c -o CMakeFiles/Taller1.dir/Lib/utillist.c.s

# Object files for target Taller1
Taller1_OBJECTS = \
"CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.o" \
"CMakeFiles/Taller1.dir/Lib/utillist.c.o"

# External object files for target Taller1
Taller1_EXTERNAL_OBJECTS =

Taller1: CMakeFiles/Taller1.dir/Taller/Taller1/Taller1.c.o
Taller1: CMakeFiles/Taller1.dir/Lib/utillist.c.o
Taller1: CMakeFiles/Taller1.dir/build.make
Taller1: CMakeFiles/Taller1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Taller1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Taller1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Taller1.dir/build: Taller1

.PHONY : CMakeFiles/Taller1.dir/build

CMakeFiles/Taller1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Taller1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Taller1.dir/clean

CMakeFiles/Taller1.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/Taller1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Taller1.dir/depend

