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
include CMakeFiles/getnum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/getnum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/getnum.dir/flags.make

CMakeFiles/getnum.dir/Lib/getnum.c.o: CMakeFiles/getnum.dir/flags.make
CMakeFiles/getnum.dir/Lib/getnum.c.o: ../Lib/getnum.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/getnum.dir/Lib/getnum.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/getnum.dir/Lib/getnum.c.o   -c /tmp/Practica/Lib/getnum.c

CMakeFiles/getnum.dir/Lib/getnum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/getnum.dir/Lib/getnum.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Lib/getnum.c > CMakeFiles/getnum.dir/Lib/getnum.c.i

CMakeFiles/getnum.dir/Lib/getnum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/getnum.dir/Lib/getnum.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Lib/getnum.c -o CMakeFiles/getnum.dir/Lib/getnum.c.s

# Object files for target getnum
getnum_OBJECTS = \
"CMakeFiles/getnum.dir/Lib/getnum.c.o"

# External object files for target getnum
getnum_EXTERNAL_OBJECTS =

getnum: CMakeFiles/getnum.dir/Lib/getnum.c.o
getnum: CMakeFiles/getnum.dir/build.make
getnum: CMakeFiles/getnum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable getnum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/getnum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/getnum.dir/build: getnum

.PHONY : CMakeFiles/getnum.dir/build

CMakeFiles/getnum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/getnum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/getnum.dir/clean

CMakeFiles/getnum.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/getnum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/getnum.dir/depend
