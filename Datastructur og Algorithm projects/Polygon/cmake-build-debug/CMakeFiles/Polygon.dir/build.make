# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\jpalb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\jpalb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Polygon.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Polygon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Polygon.dir/flags.make

CMakeFiles/Polygon.dir/main.cpp.obj: CMakeFiles/Polygon.dir/flags.make
CMakeFiles/Polygon.dir/main.cpp.obj: CMakeFiles/Polygon.dir/includes_CXX.rsp
CMakeFiles/Polygon.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Polygon.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Polygon.dir\main.cpp.obj -c "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\main.cpp"

CMakeFiles/Polygon.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Polygon.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\main.cpp" > CMakeFiles\Polygon.dir\main.cpp.i

CMakeFiles/Polygon.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Polygon.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\main.cpp" -o CMakeFiles\Polygon.dir\main.cpp.s

# Object files for target Polygon
Polygon_OBJECTS = \
"CMakeFiles/Polygon.dir/main.cpp.obj"

# External object files for target Polygon
Polygon_EXTERNAL_OBJECTS =

Polygon.exe: CMakeFiles/Polygon.dir/main.cpp.obj
Polygon.exe: CMakeFiles/Polygon.dir/build.make
Polygon.exe: C:/SFML/lib/libsfml-system-s-d.a
Polygon.exe: C:/SFML/lib/libsfml-window-s-d.a
Polygon.exe: C:/SFML/lib/libsfml-graphics-s-d.a
Polygon.exe: C:/SFML/lib/libsfml-audio-s-d.a
Polygon.exe: C:/SFML/lib/libsfml-window-s-d.a
Polygon.exe: C:/SFML/lib/libfreetype.a
Polygon.exe: C:/SFML/lib/libsfml-system-s-d.a
Polygon.exe: C:/SFML/lib/libopenal32.a
Polygon.exe: C:/SFML/lib/libvorbisfile.a
Polygon.exe: C:/SFML/lib/libvorbisenc.a
Polygon.exe: C:/SFML/lib/libvorbis.a
Polygon.exe: C:/SFML/lib/libogg.a
Polygon.exe: C:/SFML/lib/libFLAC.a
Polygon.exe: CMakeFiles/Polygon.dir/linklibs.rsp
Polygon.exe: CMakeFiles/Polygon.dir/objects1.rsp
Polygon.exe: CMakeFiles/Polygon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Polygon.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Polygon.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Polygon.dir/build: Polygon.exe
.PHONY : CMakeFiles/Polygon.dir/build

CMakeFiles/Polygon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Polygon.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Polygon.dir/clean

CMakeFiles/Polygon.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon" "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon" "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\cmake-build-debug" "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\cmake-build-debug" "C:\Users\jpalb\Algorithms and Datastructure\projects\Polygon\cmake-build-debug\CMakeFiles\Polygon.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Polygon.dir/depend
