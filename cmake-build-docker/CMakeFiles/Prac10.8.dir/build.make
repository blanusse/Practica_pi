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
include CMakeFiles/Prac10.8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prac10.8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prac10.8.dir/flags.make

CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.o: CMakeFiles/Prac10.8.dir/flags.make
CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.o: ../Practica10/ej8/ej8.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.o   -c /tmp/Practica/Practica10/ej8/ej8.c

CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Practica10/ej8/ej8.c > CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.i

CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Practica10/ej8/ej8.c -o CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.s

CMakeFiles/Prac10.8.dir/Lib/getnum.c.o: CMakeFiles/Prac10.8.dir/flags.make
CMakeFiles/Prac10.8.dir/Lib/getnum.c.o: ../Lib/getnum.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Prac10.8.dir/Lib/getnum.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Prac10.8.dir/Lib/getnum.c.o   -c /tmp/Practica/Lib/getnum.c

CMakeFiles/Prac10.8.dir/Lib/getnum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Prac10.8.dir/Lib/getnum.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Lib/getnum.c > CMakeFiles/Prac10.8.dir/Lib/getnum.c.i

CMakeFiles/Prac10.8.dir/Lib/getnum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Prac10.8.dir/Lib/getnum.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Lib/getnum.c -o CMakeFiles/Prac10.8.dir/Lib/getnum.c.s

CMakeFiles/Prac10.8.dir/Lib/random.c.o: CMakeFiles/Prac10.8.dir/flags.make
CMakeFiles/Prac10.8.dir/Lib/random.c.o: ../Lib/random.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Prac10.8.dir/Lib/random.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Prac10.8.dir/Lib/random.c.o   -c /tmp/Practica/Lib/random.c

CMakeFiles/Prac10.8.dir/Lib/random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Prac10.8.dir/Lib/random.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Lib/random.c > CMakeFiles/Prac10.8.dir/Lib/random.c.i

CMakeFiles/Prac10.8.dir/Lib/random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Prac10.8.dir/Lib/random.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Lib/random.c -o CMakeFiles/Prac10.8.dir/Lib/random.c.s

# Object files for target Prac10.8
Prac10_8_OBJECTS = \
"CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.o" \
"CMakeFiles/Prac10.8.dir/Lib/getnum.c.o" \
"CMakeFiles/Prac10.8.dir/Lib/random.c.o"

# External object files for target Prac10.8
Prac10_8_EXTERNAL_OBJECTS =

Prac10.8: CMakeFiles/Prac10.8.dir/Practica10/ej8/ej8.c.o
Prac10.8: CMakeFiles/Prac10.8.dir/Lib/getnum.c.o
Prac10.8: CMakeFiles/Prac10.8.dir/Lib/random.c.o
Prac10.8: CMakeFiles/Prac10.8.dir/build.make
Prac10.8: CMakeFiles/Prac10.8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Prac10.8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prac10.8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prac10.8.dir/build: Prac10.8

.PHONY : CMakeFiles/Prac10.8.dir/build

CMakeFiles/Prac10.8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Prac10.8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Prac10.8.dir/clean

CMakeFiles/Prac10.8.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/Prac10.8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Prac10.8.dir/depend

