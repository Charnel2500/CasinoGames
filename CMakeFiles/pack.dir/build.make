# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jakub/C++/Kasyno/Casino

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakub/C++/Kasyno/Casino

# Utility rule file for pack.

# Include any custom commands dependencies for this target.
include CMakeFiles/pack.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pack.dir/progress.make

CMakeFiles/pack:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Creating source archive"
	/usr/local/bin/cmake -E tar cfv /home/jakub/C++/Kasyno/Casino/CasinoGames_Source.zip /home/jakub/C++/Kasyno/Casino/main.cpp /home/jakub/C++/Kasyno/Casino/dicePoker.cpp /home/jakub/C++/Kasyno/Casino/gameInfo.cpp /home/jakub/C++/Kasyno/Casino/hangman.cpp /home/jakub/C++/Kasyno/Casino/playerType.cpp /home/jakub/C++/Kasyno/Casino/tarot.cpp /home/jakub/C++/Kasyno/Casino/ticTacToe.cpp

pack: CMakeFiles/pack
pack: CMakeFiles/pack.dir/build.make
.PHONY : pack

# Rule to build all files generated by this target.
CMakeFiles/pack.dir/build: pack
.PHONY : CMakeFiles/pack.dir/build

CMakeFiles/pack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pack.dir/clean

CMakeFiles/pack.dir/depend:
	cd /home/jakub/C++/Kasyno/Casino && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakub/C++/Kasyno/Casino /home/jakub/C++/Kasyno/Casino /home/jakub/C++/Kasyno/Casino /home/jakub/C++/Kasyno/Casino /home/jakub/C++/Kasyno/Casino/CMakeFiles/pack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pack.dir/depend

