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

# Include any dependencies generated for this target.
include CMakeFiles/CasinoGames.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CasinoGames.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CasinoGames.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CasinoGames.dir/flags.make

CMakeFiles/CasinoGames.dir/main.cpp.o: CMakeFiles/CasinoGames.dir/flags.make
CMakeFiles/CasinoGames.dir/main.cpp.o: main.cpp
CMakeFiles/CasinoGames.dir/main.cpp.o: CMakeFiles/CasinoGames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CasinoGames.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CasinoGames.dir/main.cpp.o -MF CMakeFiles/CasinoGames.dir/main.cpp.o.d -o CMakeFiles/CasinoGames.dir/main.cpp.o -c /home/jakub/C++/Kasyno/Casino/main.cpp

CMakeFiles/CasinoGames.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CasinoGames.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/C++/Kasyno/Casino/main.cpp > CMakeFiles/CasinoGames.dir/main.cpp.i

CMakeFiles/CasinoGames.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CasinoGames.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/C++/Kasyno/Casino/main.cpp -o CMakeFiles/CasinoGames.dir/main.cpp.s

CMakeFiles/CasinoGames.dir/dicePoker.cpp.o: CMakeFiles/CasinoGames.dir/flags.make
CMakeFiles/CasinoGames.dir/dicePoker.cpp.o: dicePoker.cpp
CMakeFiles/CasinoGames.dir/dicePoker.cpp.o: CMakeFiles/CasinoGames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CasinoGames.dir/dicePoker.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CasinoGames.dir/dicePoker.cpp.o -MF CMakeFiles/CasinoGames.dir/dicePoker.cpp.o.d -o CMakeFiles/CasinoGames.dir/dicePoker.cpp.o -c /home/jakub/C++/Kasyno/Casino/dicePoker.cpp

CMakeFiles/CasinoGames.dir/dicePoker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CasinoGames.dir/dicePoker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/C++/Kasyno/Casino/dicePoker.cpp > CMakeFiles/CasinoGames.dir/dicePoker.cpp.i

CMakeFiles/CasinoGames.dir/dicePoker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CasinoGames.dir/dicePoker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/C++/Kasyno/Casino/dicePoker.cpp -o CMakeFiles/CasinoGames.dir/dicePoker.cpp.s

CMakeFiles/CasinoGames.dir/gameInfo.cpp.o: CMakeFiles/CasinoGames.dir/flags.make
CMakeFiles/CasinoGames.dir/gameInfo.cpp.o: gameInfo.cpp
CMakeFiles/CasinoGames.dir/gameInfo.cpp.o: CMakeFiles/CasinoGames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CasinoGames.dir/gameInfo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CasinoGames.dir/gameInfo.cpp.o -MF CMakeFiles/CasinoGames.dir/gameInfo.cpp.o.d -o CMakeFiles/CasinoGames.dir/gameInfo.cpp.o -c /home/jakub/C++/Kasyno/Casino/gameInfo.cpp

CMakeFiles/CasinoGames.dir/gameInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CasinoGames.dir/gameInfo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/C++/Kasyno/Casino/gameInfo.cpp > CMakeFiles/CasinoGames.dir/gameInfo.cpp.i

CMakeFiles/CasinoGames.dir/gameInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CasinoGames.dir/gameInfo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/C++/Kasyno/Casino/gameInfo.cpp -o CMakeFiles/CasinoGames.dir/gameInfo.cpp.s

CMakeFiles/CasinoGames.dir/hangman.cpp.o: CMakeFiles/CasinoGames.dir/flags.make
CMakeFiles/CasinoGames.dir/hangman.cpp.o: hangman.cpp
CMakeFiles/CasinoGames.dir/hangman.cpp.o: CMakeFiles/CasinoGames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CasinoGames.dir/hangman.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CasinoGames.dir/hangman.cpp.o -MF CMakeFiles/CasinoGames.dir/hangman.cpp.o.d -o CMakeFiles/CasinoGames.dir/hangman.cpp.o -c /home/jakub/C++/Kasyno/Casino/hangman.cpp

CMakeFiles/CasinoGames.dir/hangman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CasinoGames.dir/hangman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/C++/Kasyno/Casino/hangman.cpp > CMakeFiles/CasinoGames.dir/hangman.cpp.i

CMakeFiles/CasinoGames.dir/hangman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CasinoGames.dir/hangman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/C++/Kasyno/Casino/hangman.cpp -o CMakeFiles/CasinoGames.dir/hangman.cpp.s

CMakeFiles/CasinoGames.dir/opponent.cpp.o: CMakeFiles/CasinoGames.dir/flags.make
CMakeFiles/CasinoGames.dir/opponent.cpp.o: opponent.cpp
CMakeFiles/CasinoGames.dir/opponent.cpp.o: CMakeFiles/CasinoGames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CasinoGames.dir/opponent.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CasinoGames.dir/opponent.cpp.o -MF CMakeFiles/CasinoGames.dir/opponent.cpp.o.d -o CMakeFiles/CasinoGames.dir/opponent.cpp.o -c /home/jakub/C++/Kasyno/Casino/opponent.cpp

CMakeFiles/CasinoGames.dir/opponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CasinoGames.dir/opponent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/C++/Kasyno/Casino/opponent.cpp > CMakeFiles/CasinoGames.dir/opponent.cpp.i

CMakeFiles/CasinoGames.dir/opponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CasinoGames.dir/opponent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/C++/Kasyno/Casino/opponent.cpp -o CMakeFiles/CasinoGames.dir/opponent.cpp.s

CMakeFiles/CasinoGames.dir/player.cpp.o: CMakeFiles/CasinoGames.dir/flags.make
CMakeFiles/CasinoGames.dir/player.cpp.o: player.cpp
CMakeFiles/CasinoGames.dir/player.cpp.o: CMakeFiles/CasinoGames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CasinoGames.dir/player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CasinoGames.dir/player.cpp.o -MF CMakeFiles/CasinoGames.dir/player.cpp.o.d -o CMakeFiles/CasinoGames.dir/player.cpp.o -c /home/jakub/C++/Kasyno/Casino/player.cpp

CMakeFiles/CasinoGames.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CasinoGames.dir/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/C++/Kasyno/Casino/player.cpp > CMakeFiles/CasinoGames.dir/player.cpp.i

CMakeFiles/CasinoGames.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CasinoGames.dir/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/C++/Kasyno/Casino/player.cpp -o CMakeFiles/CasinoGames.dir/player.cpp.s

CMakeFiles/CasinoGames.dir/tarot.cpp.o: CMakeFiles/CasinoGames.dir/flags.make
CMakeFiles/CasinoGames.dir/tarot.cpp.o: tarot.cpp
CMakeFiles/CasinoGames.dir/tarot.cpp.o: CMakeFiles/CasinoGames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CasinoGames.dir/tarot.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CasinoGames.dir/tarot.cpp.o -MF CMakeFiles/CasinoGames.dir/tarot.cpp.o.d -o CMakeFiles/CasinoGames.dir/tarot.cpp.o -c /home/jakub/C++/Kasyno/Casino/tarot.cpp

CMakeFiles/CasinoGames.dir/tarot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CasinoGames.dir/tarot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/C++/Kasyno/Casino/tarot.cpp > CMakeFiles/CasinoGames.dir/tarot.cpp.i

CMakeFiles/CasinoGames.dir/tarot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CasinoGames.dir/tarot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/C++/Kasyno/Casino/tarot.cpp -o CMakeFiles/CasinoGames.dir/tarot.cpp.s

CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o: CMakeFiles/CasinoGames.dir/flags.make
CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o: ticTacToe.cpp
CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o: CMakeFiles/CasinoGames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o -MF CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o.d -o CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o -c /home/jakub/C++/Kasyno/Casino/ticTacToe.cpp

CMakeFiles/CasinoGames.dir/ticTacToe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CasinoGames.dir/ticTacToe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/C++/Kasyno/Casino/ticTacToe.cpp > CMakeFiles/CasinoGames.dir/ticTacToe.cpp.i

CMakeFiles/CasinoGames.dir/ticTacToe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CasinoGames.dir/ticTacToe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/C++/Kasyno/Casino/ticTacToe.cpp -o CMakeFiles/CasinoGames.dir/ticTacToe.cpp.s

# Object files for target CasinoGames
CasinoGames_OBJECTS = \
"CMakeFiles/CasinoGames.dir/main.cpp.o" \
"CMakeFiles/CasinoGames.dir/dicePoker.cpp.o" \
"CMakeFiles/CasinoGames.dir/gameInfo.cpp.o" \
"CMakeFiles/CasinoGames.dir/hangman.cpp.o" \
"CMakeFiles/CasinoGames.dir/opponent.cpp.o" \
"CMakeFiles/CasinoGames.dir/player.cpp.o" \
"CMakeFiles/CasinoGames.dir/tarot.cpp.o" \
"CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o"

# External object files for target CasinoGames
CasinoGames_EXTERNAL_OBJECTS =

CasinoGames: CMakeFiles/CasinoGames.dir/main.cpp.o
CasinoGames: CMakeFiles/CasinoGames.dir/dicePoker.cpp.o
CasinoGames: CMakeFiles/CasinoGames.dir/gameInfo.cpp.o
CasinoGames: CMakeFiles/CasinoGames.dir/hangman.cpp.o
CasinoGames: CMakeFiles/CasinoGames.dir/opponent.cpp.o
CasinoGames: CMakeFiles/CasinoGames.dir/player.cpp.o
CasinoGames: CMakeFiles/CasinoGames.dir/tarot.cpp.o
CasinoGames: CMakeFiles/CasinoGames.dir/ticTacToe.cpp.o
CasinoGames: CMakeFiles/CasinoGames.dir/build.make
CasinoGames: CMakeFiles/CasinoGames.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakub/C++/Kasyno/Casino/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable CasinoGames"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CasinoGames.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CasinoGames.dir/build: CasinoGames
.PHONY : CMakeFiles/CasinoGames.dir/build

CMakeFiles/CasinoGames.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CasinoGames.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CasinoGames.dir/clean

CMakeFiles/CasinoGames.dir/depend:
	cd /home/jakub/C++/Kasyno/Casino && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakub/C++/Kasyno/Casino /home/jakub/C++/Kasyno/Casino /home/jakub/C++/Kasyno/Casino /home/jakub/C++/Kasyno/Casino /home/jakub/C++/Kasyno/Casino/CMakeFiles/CasinoGames.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CasinoGames.dir/depend
