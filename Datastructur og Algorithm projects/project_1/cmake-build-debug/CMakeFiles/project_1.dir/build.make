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
CMAKE_COMMAND = C:\Users\jpalb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\jpalb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/project_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/project_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_1.dir/flags.make

CMakeFiles/project_1.dir/main.c.obj: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project_1.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\project_1.dir\main.c.obj -c "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\main.c"

CMakeFiles/project_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project_1.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\main.c" > CMakeFiles\project_1.dir\main.c.i

CMakeFiles/project_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project_1.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\main.c" -o CMakeFiles\project_1.dir\main.c.s

# Object files for target project_1
project_1_OBJECTS = \
"CMakeFiles/project_1.dir/main.c.obj"

# External object files for target project_1
project_1_EXTERNAL_OBJECTS =

project_1.exe: CMakeFiles/project_1.dir/main.c.obj
project_1.exe: CMakeFiles/project_1.dir/build.make
project_1.exe: CMakeFiles/project_1.dir/linklibs.rsp
project_1.exe: CMakeFiles/project_1.dir/objects1.rsp
project_1.exe: CMakeFiles/project_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable project_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_1.dir/build: project_1.exe
.PHONY : CMakeFiles/project_1.dir/build

CMakeFiles/project_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/project_1.dir/clean

CMakeFiles/project_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1" "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1" "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\cmake-build-debug" "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\cmake-build-debug" "C:\Users\jpalb\Algorithms and Datastructure\projects\project_1\cmake-build-debug\CMakeFiles\project_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/project_1.dir/depend

