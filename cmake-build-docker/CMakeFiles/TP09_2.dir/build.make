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
include CMakeFiles/TP09_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP09_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP09_2.dir/flags.make

CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.o: CMakeFiles/TP09_2.dir/flags.make
CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.o: ../TP/TP09/TP09_02.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.o   -c /tmp/Practica/TP/TP09/TP09_02.c

CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/TP/TP09/TP09_02.c > CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.i

CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/TP/TP09/TP09_02.c -o CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.s

CMakeFiles/TP09_2.dir/lib/getnum.c.o: CMakeFiles/TP09_2.dir/flags.make
CMakeFiles/TP09_2.dir/lib/getnum.c.o: ../lib/getnum.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TP09_2.dir/lib/getnum.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TP09_2.dir/lib/getnum.c.o   -c /tmp/Practica/lib/getnum.c

CMakeFiles/TP09_2.dir/lib/getnum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP09_2.dir/lib/getnum.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/lib/getnum.c > CMakeFiles/TP09_2.dir/lib/getnum.c.i

CMakeFiles/TP09_2.dir/lib/getnum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP09_2.dir/lib/getnum.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/lib/getnum.c -o CMakeFiles/TP09_2.dir/lib/getnum.c.s

CMakeFiles/TP09_2.dir/lib/random.c.o: CMakeFiles/TP09_2.dir/flags.make
CMakeFiles/TP09_2.dir/lib/random.c.o: ../lib/random.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TP09_2.dir/lib/random.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TP09_2.dir/lib/random.c.o   -c /tmp/Practica/lib/random.c

CMakeFiles/TP09_2.dir/lib/random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP09_2.dir/lib/random.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/lib/random.c > CMakeFiles/TP09_2.dir/lib/random.c.i

CMakeFiles/TP09_2.dir/lib/random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP09_2.dir/lib/random.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/lib/random.c -o CMakeFiles/TP09_2.dir/lib/random.c.s

# Object files for target TP09_2
TP09_2_OBJECTS = \
"CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.o" \
"CMakeFiles/TP09_2.dir/lib/getnum.c.o" \
"CMakeFiles/TP09_2.dir/lib/random.c.o"

# External object files for target TP09_2
TP09_2_EXTERNAL_OBJECTS =

TP09_2: CMakeFiles/TP09_2.dir/TP/TP09/TP09_02.c.o
TP09_2: CMakeFiles/TP09_2.dir/lib/getnum.c.o
TP09_2: CMakeFiles/TP09_2.dir/lib/random.c.o
TP09_2: CMakeFiles/TP09_2.dir/build.make
TP09_2: CMakeFiles/TP09_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable TP09_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP09_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP09_2.dir/build: TP09_2

.PHONY : CMakeFiles/TP09_2.dir/build

CMakeFiles/TP09_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP09_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP09_2.dir/clean

CMakeFiles/TP09_2.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/TP09_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP09_2.dir/depend

