# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrebrahin/Computing_Science/IceSlidingPuzzle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build

# Include any dependencies generated for this target.
include CMakeFiles/IceSlidingPuzzle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/IceSlidingPuzzle.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IceSlidingPuzzle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IceSlidingPuzzle.dir/flags.make

CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o: CMakeFiles/IceSlidingPuzzle.dir/flags.make
CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o: /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/main.cpp
CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o: CMakeFiles/IceSlidingPuzzle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o -MF CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o.d -o CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o -c /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/main.cpp

CMakeFiles/IceSlidingPuzzle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IceSlidingPuzzle.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/main.cpp > CMakeFiles/IceSlidingPuzzle.dir/main.cpp.i

CMakeFiles/IceSlidingPuzzle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IceSlidingPuzzle.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/main.cpp -o CMakeFiles/IceSlidingPuzzle.dir/main.cpp.s

# Object files for target IceSlidingPuzzle
IceSlidingPuzzle_OBJECTS = \
"CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o"

# External object files for target IceSlidingPuzzle
IceSlidingPuzzle_EXTERNAL_OBJECTS =

main: CMakeFiles/IceSlidingPuzzle.dir/main.cpp.o
main: CMakeFiles/IceSlidingPuzzle.dir/build.make
main: CMakeFiles/IceSlidingPuzzle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IceSlidingPuzzle.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copying files to output directory"
	/opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E copy_directory /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/files/ /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build

# Rule to build all files generated by this target.
CMakeFiles/IceSlidingPuzzle.dir/build: main
.PHONY : CMakeFiles/IceSlidingPuzzle.dir/build

CMakeFiles/IceSlidingPuzzle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IceSlidingPuzzle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IceSlidingPuzzle.dir/clean

CMakeFiles/IceSlidingPuzzle.dir/depend:
	cd /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrebrahin/Computing_Science/IceSlidingPuzzle /Users/andrebrahin/Computing_Science/IceSlidingPuzzle /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build /Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build/CMakeFiles/IceSlidingPuzzle.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/IceSlidingPuzzle.dir/depend

