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
include CMakeFiles/claseTeo_10.2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/claseTeo_10.2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/claseTeo_10.2.dir/flags.make

CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.o: CMakeFiles/claseTeo_10.2.dir/flags.make
CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.o: ../ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.o   -c /tmp/Practica/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c

CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c > CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.i

CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c -o CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.s

# Object files for target claseTeo_10.2
claseTeo_10_2_OBJECTS = \
"CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.o"

# External object files for target claseTeo_10.2
claseTeo_10_2_EXTERNAL_OBJECTS =

claseTeo_10.2: CMakeFiles/claseTeo_10.2.dir/ClasesTeoricas/ClaseTeo22_10/dateADT/dateADTTester.c.o
claseTeo_10.2: CMakeFiles/claseTeo_10.2.dir/build.make
claseTeo_10.2: CMakeFiles/claseTeo_10.2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable claseTeo_10.2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/claseTeo_10.2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/claseTeo_10.2.dir/build: claseTeo_10.2

.PHONY : CMakeFiles/claseTeo_10.2.dir/build

CMakeFiles/claseTeo_10.2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/claseTeo_10.2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/claseTeo_10.2.dir/clean

CMakeFiles/claseTeo_10.2.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/claseTeo_10.2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/claseTeo_10.2.dir/depend

