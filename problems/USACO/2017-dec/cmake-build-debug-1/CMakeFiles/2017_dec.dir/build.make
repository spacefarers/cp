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
CMAKE_COMMAND = /cygdrive/c/Users/Michael/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Michael/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/cmake-build-debug-1

# Include any dependencies generated for this target.
include CMakeFiles/2017_dec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2017_dec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2017_dec.dir/flags.make

CMakeFiles/2017_dec.dir/g-2.cpp.o: CMakeFiles/2017_dec.dir/flags.make
CMakeFiles/2017_dec.dir/g-2.cpp.o: ../g-2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/cmake-build-debug-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2017_dec.dir/g-2.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2017_dec.dir/g-2.cpp.o -c /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/g-2.cpp

CMakeFiles/2017_dec.dir/g-2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2017_dec.dir/g-2.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/g-2.cpp > CMakeFiles/2017_dec.dir/g-2.cpp.i

CMakeFiles/2017_dec.dir/g-2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2017_dec.dir/g-2.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/g-2.cpp -o CMakeFiles/2017_dec.dir/g-2.cpp.s

# Object files for target 2017_dec
2017_dec_OBJECTS = \
"CMakeFiles/2017_dec.dir/g-2.cpp.o"

# External object files for target 2017_dec
2017_dec_EXTERNAL_OBJECTS =

2017_dec.exe: CMakeFiles/2017_dec.dir/g-2.cpp.o
2017_dec.exe: CMakeFiles/2017_dec.dir/build.make
2017_dec.exe: CMakeFiles/2017_dec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/cmake-build-debug-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2017_dec.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2017_dec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2017_dec.dir/build: 2017_dec.exe

.PHONY : CMakeFiles/2017_dec.dir/build

CMakeFiles/2017_dec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2017_dec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2017_dec.dir/clean

CMakeFiles/2017_dec.dir/depend:
	cd /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/cmake-build-debug-1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/cmake-build-debug-1 /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/cmake-build-debug-1 /cygdrive/c/Users/Michael/Documents/Documents/比赛/USACO/真题/2017-dec/cmake-build-debug-1/CMakeFiles/2017_dec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2017_dec.dir/depend

