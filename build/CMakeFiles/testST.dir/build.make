# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/build

# Include any dependencies generated for this target.
include CMakeFiles/testST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testST.dir/flags.make

CMakeFiles/testST.dir/tests/single-threaded.cpp.o: CMakeFiles/testST.dir/flags.make
CMakeFiles/testST.dir/tests/single-threaded.cpp.o: ../tests/single-threaded.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testST.dir/tests/single-threaded.cpp.o"
	/usr/local/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testST.dir/tests/single-threaded.cpp.o -c /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/tests/single-threaded.cpp

CMakeFiles/testST.dir/tests/single-threaded.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testST.dir/tests/single-threaded.cpp.i"
	/usr/local/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/tests/single-threaded.cpp > CMakeFiles/testST.dir/tests/single-threaded.cpp.i

CMakeFiles/testST.dir/tests/single-threaded.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testST.dir/tests/single-threaded.cpp.s"
	/usr/local/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/tests/single-threaded.cpp -o CMakeFiles/testST.dir/tests/single-threaded.cpp.s

CMakeFiles/testST.dir/tests/single-threaded.cpp.o.requires:

.PHONY : CMakeFiles/testST.dir/tests/single-threaded.cpp.o.requires

CMakeFiles/testST.dir/tests/single-threaded.cpp.o.provides: CMakeFiles/testST.dir/tests/single-threaded.cpp.o.requires
	$(MAKE) -f CMakeFiles/testST.dir/build.make CMakeFiles/testST.dir/tests/single-threaded.cpp.o.provides.build
.PHONY : CMakeFiles/testST.dir/tests/single-threaded.cpp.o.provides

CMakeFiles/testST.dir/tests/single-threaded.cpp.o.provides.build: CMakeFiles/testST.dir/tests/single-threaded.cpp.o


# Object files for target testST
testST_OBJECTS = \
"CMakeFiles/testST.dir/tests/single-threaded.cpp.o"

# External object files for target testST
testST_EXTERNAL_OBJECTS =

testST: CMakeFiles/testST.dir/tests/single-threaded.cpp.o
testST: CMakeFiles/testST.dir/build.make
testST: CMakeFiles/testST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testST.dir/build: testST

.PHONY : CMakeFiles/testST.dir/build

CMakeFiles/testST.dir/requires: CMakeFiles/testST.dir/tests/single-threaded.cpp.o.requires

.PHONY : CMakeFiles/testST.dir/requires

CMakeFiles/testST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testST.dir/clean

CMakeFiles/testST.dir/depend:
	cd /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/build /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/build /Users/chrisroman/CornellWork/Fall_2018/Derecho/slab-allocator/build/CMakeFiles/testST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testST.dir/depend
