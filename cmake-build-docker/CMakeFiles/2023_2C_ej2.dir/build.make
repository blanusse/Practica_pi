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
include CMakeFiles/2023_2C_ej2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2023_2C_ej2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2023_2C_ej2.dir/flags.make

CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.o: CMakeFiles/2023_2C_ej2.dir/flags.make
CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.o: ../Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.o   -c /tmp/Practica/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c

CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Practica/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c > CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.i

CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Practica/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c -o CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.s

# Object files for target 2023_2C_ej2
2023_2C_ej2_OBJECTS = \
"CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.o"

# External object files for target 2023_2C_ej2
2023_2C_ej2_EXTERNAL_OBJECTS =

2023_2C_ej2: CMakeFiles/2023_2C_ej2.dir/Parciales_Viejos/Segundos_Parciales/jokesADT/jokesADT.c.o
2023_2C_ej2: CMakeFiles/2023_2C_ej2.dir/build.make
2023_2C_ej2: CMakeFiles/2023_2C_ej2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Practica/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 2023_2C_ej2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2023_2C_ej2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2023_2C_ej2.dir/build: 2023_2C_ej2

.PHONY : CMakeFiles/2023_2C_ej2.dir/build

CMakeFiles/2023_2C_ej2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2023_2C_ej2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2023_2C_ej2.dir/clean

CMakeFiles/2023_2C_ej2.dir/depend:
	cd /tmp/Practica/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Practica /tmp/Practica /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker /tmp/Practica/cmake-build-docker/CMakeFiles/2023_2C_ej2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2023_2C_ej2.dir/depend

