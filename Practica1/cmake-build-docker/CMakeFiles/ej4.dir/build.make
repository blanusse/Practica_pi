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
CMAKE_SOURCE_DIR = /tmp/Practica_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/Practica_1/cmake-build-docker

# Include any dependencies generated for this target.
include CMakeFiles/ej4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej4.dir/flags.make

CMakeFiles/ej4.dir/ej4.c.o: CMakeFiles/ej4.dir/flags.make
CMakeFiles/ej4.dir/ej4.c.o: ../ej4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica_1/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ej4.dir/ej4.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ej4.dir/ej4.c.o   -c /tmp/Practica_1/ej4.c

CMakeFiles/ej4.dir/ej4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ej4.dir/ej4.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica_1/ej4.c > CMakeFiles/ej4.dir/ej4.c.i

CMakeFiles/ej4.dir/ej4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ej4.dir/ej4.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica_1/ej4.c -o CMakeFiles/ej4.dir/ej4.c.s

# Object files for target ej4
ej4_OBJECTS = \
"CMakeFiles/ej4.dir/ej4.c.o"

# External object files for target ej4
ej4_EXTERNAL_OBJECTS =

ej4: CMakeFiles/ej4.dir/ej4.c.o
ej4: CMakeFiles/ej4.dir/build.make
ej4: CMakeFiles/ej4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica_1/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ej4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej4.dir/build: ej4

.PHONY : CMakeFiles/ej4.dir/build

CMakeFiles/ej4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej4.dir/clean

CMakeFiles/ej4.dir/depend:
	cd /tmp/Practica_1/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica_1 /tmp/Practica_1 /tmp/Practica_1/cmake-build-docker /tmp/Practica_1/cmake-build-docker /tmp/Practica_1/cmake-build-docker/CMakeFiles/ej4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej4.dir/depend

