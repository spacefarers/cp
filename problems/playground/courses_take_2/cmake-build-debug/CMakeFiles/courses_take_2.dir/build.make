# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michael/Documents/比赛/USACO/练习/courses_take_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michael/Documents/比赛/USACO/练习/courses_take_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/courses_take_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/courses_take_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/courses_take_2.dir/flags.make

CMakeFiles/courses_take_2.dir/J.cpp.o: CMakeFiles/courses_take_2.dir/flags.make
CMakeFiles/courses_take_2.dir/J.cpp.o: ../J.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michael/Documents/比赛/USACO/练习/courses_take_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/courses_take_2.dir/J.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/courses_take_2.dir/J.cpp.o -c /Users/michael/Documents/比赛/USACO/练习/courses_take_2/J.cpp

CMakeFiles/courses_take_2.dir/J.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/courses_take_2.dir/J.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/michael/Documents/比赛/USACO/练习/courses_take_2/J.cpp > CMakeFiles/courses_take_2.dir/J.cpp.i

CMakeFiles/courses_take_2.dir/J.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/courses_take_2.dir/J.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/michael/Documents/比赛/USACO/练习/courses_take_2/J.cpp -o CMakeFiles/courses_take_2.dir/J.cpp.s

# Object files for target courses_take_2
courses_take_2_OBJECTS = \
"CMakeFiles/courses_take_2.dir/J.cpp.o"

# External object files for target courses_take_2
courses_take_2_EXTERNAL_OBJECTS =

courses_take_2: CMakeFiles/courses_take_2.dir/J.cpp.o
courses_take_2: CMakeFiles/courses_take_2.dir/build.make
courses_take_2: CMakeFiles/courses_take_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michael/Documents/比赛/USACO/练习/courses_take_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable courses_take_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/courses_take_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/courses_take_2.dir/build: courses_take_2

.PHONY : CMakeFiles/courses_take_2.dir/build

CMakeFiles/courses_take_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/courses_take_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/courses_take_2.dir/clean

CMakeFiles/courses_take_2.dir/depend:
	cd /Users/michael/Documents/比赛/USACO/练习/courses_take_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michael/Documents/比赛/USACO/练习/courses_take_2 /Users/michael/Documents/比赛/USACO/练习/courses_take_2 /Users/michael/Documents/比赛/USACO/练习/courses_take_2/cmake-build-debug /Users/michael/Documents/比赛/USACO/练习/courses_take_2/cmake-build-debug /Users/michael/Documents/比赛/USACO/练习/courses_take_2/cmake-build-debug/CMakeFiles/courses_take_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/courses_take_2.dir/depend

