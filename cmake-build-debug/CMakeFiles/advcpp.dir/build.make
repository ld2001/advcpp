# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\LDin21\Documents\GitHub\advcpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\LDin21\Documents\GitHub\advcpp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/advcpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/advcpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/advcpp.dir/flags.make

CMakeFiles/advcpp.dir/maze/maze.cpp.obj: CMakeFiles/advcpp.dir/flags.make
CMakeFiles/advcpp.dir/maze/maze.cpp.obj: CMakeFiles/advcpp.dir/includes_CXX.rsp
CMakeFiles/advcpp.dir/maze/maze.cpp.obj: ../maze/maze.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LDin21\Documents\GitHub\advcpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/advcpp.dir/maze/maze.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\advcpp.dir\maze\maze.cpp.obj -c C:\Users\LDin21\Documents\GitHub\advcpp\maze\maze.cpp

CMakeFiles/advcpp.dir/maze/maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advcpp.dir/maze/maze.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LDin21\Documents\GitHub\advcpp\maze\maze.cpp > CMakeFiles\advcpp.dir\maze\maze.cpp.i

CMakeFiles/advcpp.dir/maze/maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advcpp.dir/maze/maze.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LDin21\Documents\GitHub\advcpp\maze\maze.cpp -o CMakeFiles\advcpp.dir\maze\maze.cpp.s

CMakeFiles/advcpp.dir/maze/solve.cpp.obj: CMakeFiles/advcpp.dir/flags.make
CMakeFiles/advcpp.dir/maze/solve.cpp.obj: CMakeFiles/advcpp.dir/includes_CXX.rsp
CMakeFiles/advcpp.dir/maze/solve.cpp.obj: ../maze/solve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LDin21\Documents\GitHub\advcpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/advcpp.dir/maze/solve.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\advcpp.dir\maze\solve.cpp.obj -c C:\Users\LDin21\Documents\GitHub\advcpp\maze\solve.cpp

CMakeFiles/advcpp.dir/maze/solve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advcpp.dir/maze/solve.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LDin21\Documents\GitHub\advcpp\maze\solve.cpp > CMakeFiles\advcpp.dir\maze\solve.cpp.i

CMakeFiles/advcpp.dir/maze/solve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advcpp.dir/maze/solve.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LDin21\Documents\GitHub\advcpp\maze\solve.cpp -o CMakeFiles\advcpp.dir\maze\solve.cpp.s

# Object files for target advcpp
advcpp_OBJECTS = \
"CMakeFiles/advcpp.dir/maze/maze.cpp.obj" \
"CMakeFiles/advcpp.dir/maze/solve.cpp.obj"

# External object files for target advcpp
advcpp_EXTERNAL_OBJECTS =

advcpp.exe: CMakeFiles/advcpp.dir/maze/maze.cpp.obj
advcpp.exe: CMakeFiles/advcpp.dir/maze/solve.cpp.obj
advcpp.exe: CMakeFiles/advcpp.dir/build.make
advcpp.exe: CMakeFiles/advcpp.dir/linklibs.rsp
advcpp.exe: CMakeFiles/advcpp.dir/objects1.rsp
advcpp.exe: CMakeFiles/advcpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\LDin21\Documents\GitHub\advcpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable advcpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\advcpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/advcpp.dir/build: advcpp.exe

.PHONY : CMakeFiles/advcpp.dir/build

CMakeFiles/advcpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\advcpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/advcpp.dir/clean

CMakeFiles/advcpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\LDin21\Documents\GitHub\advcpp C:\Users\LDin21\Documents\GitHub\advcpp C:\Users\LDin21\Documents\GitHub\advcpp\cmake-build-debug C:\Users\LDin21\Documents\GitHub\advcpp\cmake-build-debug C:\Users\LDin21\Documents\GitHub\advcpp\cmake-build-debug\CMakeFiles\advcpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/advcpp.dir/depend

