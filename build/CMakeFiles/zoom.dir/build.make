# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/build"

# Include any dependencies generated for this target.
include CMakeFiles/zoom.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zoom.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zoom.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zoom.dir/flags.make

CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o: CMakeFiles/zoom.dir/flags.make
CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o: ../estudiante/src/zoom.cpp
CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o: CMakeFiles/zoom.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o -MF CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o.d -o CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o -c "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/estudiante/src/zoom.cpp"

CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/estudiante/src/zoom.cpp" > CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.i

CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/estudiante/src/zoom.cpp" -o CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.s

# Object files for target zoom
zoom_OBJECTS = \
"CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o"

# External object files for target zoom
zoom_EXTERNAL_OBJECTS =

zoom: CMakeFiles/zoom.dir/estudiante/src/zoom.cpp.o
zoom: CMakeFiles/zoom.dir/build.make
zoom: libimage.a
zoom: CMakeFiles/zoom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zoom"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zoom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zoom.dir/build: zoom
.PHONY : CMakeFiles/zoom.dir/build

CMakeFiles/zoom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zoom.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zoom.dir/clean

CMakeFiles/zoom.dir/depend:
	cd "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes" "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes" "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/build" "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/build" "/home/jesus/ED/Material Práctica 2 - Abstracción.TDA Imagen (Minipráctica)-20231002/ej01_imagenes/build/CMakeFiles/zoom.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zoom.dir/depend

