# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/peterleyden/projects/Chess-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/peterleyden/projects/Chess-Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/Bitboard.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Bitboard.cpp.o: /Users/peterleyden/projects/Chess-Engine/Bitboard.cpp
CMakeFiles/test.dir/Bitboard.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/peterleyden/projects/Chess-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/Bitboard.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/Bitboard.cpp.o -MF CMakeFiles/test.dir/Bitboard.cpp.o.d -o CMakeFiles/test.dir/Bitboard.cpp.o -c /Users/peterleyden/projects/Chess-Engine/Bitboard.cpp

CMakeFiles/test.dir/Bitboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test.dir/Bitboard.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/peterleyden/projects/Chess-Engine/Bitboard.cpp > CMakeFiles/test.dir/Bitboard.cpp.i

CMakeFiles/test.dir/Bitboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test.dir/Bitboard.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/peterleyden/projects/Chess-Engine/Bitboard.cpp -o CMakeFiles/test.dir/Bitboard.cpp.s

CMakeFiles/test.dir/Gamestate.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Gamestate.cpp.o: /Users/peterleyden/projects/Chess-Engine/Gamestate.cpp
CMakeFiles/test.dir/Gamestate.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/peterleyden/projects/Chess-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/Gamestate.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/Gamestate.cpp.o -MF CMakeFiles/test.dir/Gamestate.cpp.o.d -o CMakeFiles/test.dir/Gamestate.cpp.o -c /Users/peterleyden/projects/Chess-Engine/Gamestate.cpp

CMakeFiles/test.dir/Gamestate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test.dir/Gamestate.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/peterleyden/projects/Chess-Engine/Gamestate.cpp > CMakeFiles/test.dir/Gamestate.cpp.i

CMakeFiles/test.dir/Gamestate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test.dir/Gamestate.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/peterleyden/projects/Chess-Engine/Gamestate.cpp -o CMakeFiles/test.dir/Gamestate.cpp.s

CMakeFiles/test.dir/Test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Test.cpp.o: /Users/peterleyden/projects/Chess-Engine/Test.cpp
CMakeFiles/test.dir/Test.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/peterleyden/projects/Chess-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/Test.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/Test.cpp.o -MF CMakeFiles/test.dir/Test.cpp.o.d -o CMakeFiles/test.dir/Test.cpp.o -c /Users/peterleyden/projects/Chess-Engine/Test.cpp

CMakeFiles/test.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test.dir/Test.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/peterleyden/projects/Chess-Engine/Test.cpp > CMakeFiles/test.dir/Test.cpp.i

CMakeFiles/test.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test.dir/Test.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/peterleyden/projects/Chess-Engine/Test.cpp -o CMakeFiles/test.dir/Test.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/Bitboard.cpp.o" \
"CMakeFiles/test.dir/Gamestate.cpp.o" \
"CMakeFiles/test.dir/Test.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/Bitboard.cpp.o
test: CMakeFiles/test.dir/Gamestate.cpp.o
test: CMakeFiles/test.dir/Test.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/peterleyden/projects/Chess-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /Users/peterleyden/projects/Chess-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/peterleyden/projects/Chess-Engine /Users/peterleyden/projects/Chess-Engine /Users/peterleyden/projects/Chess-Engine/build /Users/peterleyden/projects/Chess-Engine/build /Users/peterleyden/projects/Chess-Engine/build/CMakeFiles/test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test.dir/depend

