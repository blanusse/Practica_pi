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
include CMakeFiles/binarySearchTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binarySearchTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binarySearchTree.dir/flags.make

CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.o: CMakeFiles/binarySearchTree.dir/flags.make
CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.o: ../TPE/bstADT.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.o   -c /tmp/Practica/TPE/bstADT.c

CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/TPE/bstADT.c > CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.i

CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/TPE/bstADT.c -o CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.s

# Object files for target binarySearchTree
binarySearchTree_OBJECTS = \
"CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.o"

# External object files for target binarySearchTree
binarySearchTree_EXTERNAL_OBJECTS =

binarySearchTree: CMakeFiles/binarySearchTree.dir/TPE/bstADT.c.o
binarySearchTree: CMakeFiles/binarySearchTree.dir/build.make
binarySearchTree: CMakeFiles/binarySearchTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable binarySearchTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binarySearchTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binarySearchTree.dir/build: binarySearchTree

.PHONY : CMakeFiles/binarySearchTree.dir/build

CMakeFiles/binarySearchTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binarySearchTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binarySearchTree.dir/clean

CMakeFiles/binarySearchTree.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/binarySearchTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binarySearchTree.dir/depend
