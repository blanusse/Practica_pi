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
include CMakeFiles/Taller5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Taller5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Taller5.dir/flags.make

CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.o: CMakeFiles/Taller5.dir/flags.make
CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.o: ../Taller/Taller5/Taller5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.o   -c /tmp/Practica/Taller/Taller5/Taller5.c

CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Taller/Taller5/Taller5.c > CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.i

CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Taller/Taller5/Taller5.c -o CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.s

CMakeFiles/Taller5.dir/Lib/getnum.c.o: CMakeFiles/Taller5.dir/flags.make
CMakeFiles/Taller5.dir/Lib/getnum.c.o: ../Lib/getnum.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Taller5.dir/Lib/getnum.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Taller5.dir/Lib/getnum.c.o   -c /tmp/Practica/Lib/getnum.c

CMakeFiles/Taller5.dir/Lib/getnum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Taller5.dir/Lib/getnum.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Lib/getnum.c > CMakeFiles/Taller5.dir/Lib/getnum.c.i

CMakeFiles/Taller5.dir/Lib/getnum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Taller5.dir/Lib/getnum.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Lib/getnum.c -o CMakeFiles/Taller5.dir/Lib/getnum.c.s

CMakeFiles/Taller5.dir/Lib/random.c.o: CMakeFiles/Taller5.dir/flags.make
CMakeFiles/Taller5.dir/Lib/random.c.o: ../Lib/random.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Taller5.dir/Lib/random.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Taller5.dir/Lib/random.c.o   -c /tmp/Practica/Lib/random.c

CMakeFiles/Taller5.dir/Lib/random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Taller5.dir/Lib/random.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Lib/random.c > CMakeFiles/Taller5.dir/Lib/random.c.i

CMakeFiles/Taller5.dir/Lib/random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Taller5.dir/Lib/random.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Lib/random.c -o CMakeFiles/Taller5.dir/Lib/random.c.s

# Object files for target Taller5
Taller5_OBJECTS = \
"CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.o" \
"CMakeFiles/Taller5.dir/Lib/getnum.c.o" \
"CMakeFiles/Taller5.dir/Lib/random.c.o"

# External object files for target Taller5
Taller5_EXTERNAL_OBJECTS =

Taller5: CMakeFiles/Taller5.dir/Taller/Taller5/Taller5.c.o
Taller5: CMakeFiles/Taller5.dir/Lib/getnum.c.o
Taller5: CMakeFiles/Taller5.dir/Lib/random.c.o
Taller5: CMakeFiles/Taller5.dir/build.make
Taller5: CMakeFiles/Taller5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Taller5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Taller5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Taller5.dir/build: Taller5

.PHONY : CMakeFiles/Taller5.dir/build

CMakeFiles/Taller5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Taller5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Taller5.dir/clean

CMakeFiles/Taller5.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/Taller5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Taller5.dir/depend

