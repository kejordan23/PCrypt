# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kyliejordan/desktop/CRCP5301/PCrypt/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/build

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/main.cpp.o: /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/main.cpp
CMakeFiles/project.dir/main.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyliejordan/desktop/CRCP5301/PCrypt/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/main.cpp.o -MF CMakeFiles/project.dir/main.cpp.o.d -o CMakeFiles/project.dir/main.cpp.o -c /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/main.cpp

CMakeFiles/project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/main.cpp > CMakeFiles/project.dir/main.cpp.i

CMakeFiles/project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/main.cpp -o CMakeFiles/project.dir/main.cpp.s

CMakeFiles/project.dir/Function.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/Function.cpp.o: /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/Function.cpp
CMakeFiles/project.dir/Function.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyliejordan/desktop/CRCP5301/PCrypt/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project.dir/Function.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/Function.cpp.o -MF CMakeFiles/project.dir/Function.cpp.o.d -o CMakeFiles/project.dir/Function.cpp.o -c /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/Function.cpp

CMakeFiles/project.dir/Function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/Function.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/Function.cpp > CMakeFiles/project.dir/Function.cpp.i

CMakeFiles/project.dir/Function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/Function.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/Function.cpp -o CMakeFiles/project.dir/Function.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/main.cpp.o" \
"CMakeFiles/project.dir/Function.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/main.cpp.o
project: CMakeFiles/project.dir/Function.cpp.o
project: CMakeFiles/project.dir/build.make
project: /usr/X11R6/lib/libSM.dylib
project: /usr/X11R6/lib/libICE.dylib
project: /usr/X11R6/lib/libX11.dylib
project: /usr/X11R6/lib/libXext.dylib
project: /usr/local/lib/libpng.dylib
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kyliejordan/desktop/CRCP5301/PCrypt/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project
.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kyliejordan/desktop/CRCP5301/PCrypt/project /Users/kyliejordan/desktop/CRCP5301/PCrypt/project /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/build /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/build /Users/kyliejordan/desktop/CRCP5301/PCrypt/project/build/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend

