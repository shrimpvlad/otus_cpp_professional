# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vladislav/Documents/otus_cpp_professional/01_helloWorld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build

# Include any dependencies generated for this target.
include GTests/CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include GTests/CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include GTests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include GTests/CMakeFiles/tests.dir/flags.make

GTests/CMakeFiles/tests.dir/test_version.cpp.o: GTests/CMakeFiles/tests.dir/flags.make
GTests/CMakeFiles/tests.dir/test_version.cpp.o: ../GTests/test_version.cpp
GTests/CMakeFiles/tests.dir/test_version.cpp.o: GTests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GTests/CMakeFiles/tests.dir/test_version.cpp.o"
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT GTests/CMakeFiles/tests.dir/test_version.cpp.o -MF CMakeFiles/tests.dir/test_version.cpp.o.d -o CMakeFiles/tests.dir/test_version.cpp.o -c /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/GTests/test_version.cpp

GTests/CMakeFiles/tests.dir/test_version.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test_version.cpp.i"
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/GTests/test_version.cpp > CMakeFiles/tests.dir/test_version.cpp.i

GTests/CMakeFiles/tests.dir/test_version.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test_version.cpp.s"
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/GTests/test_version.cpp -o CMakeFiles/tests.dir/test_version.cpp.s

GTests/CMakeFiles/tests.dir/__/lib.cpp.o: GTests/CMakeFiles/tests.dir/flags.make
GTests/CMakeFiles/tests.dir/__/lib.cpp.o: ../lib.cpp
GTests/CMakeFiles/tests.dir/__/lib.cpp.o: GTests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object GTests/CMakeFiles/tests.dir/__/lib.cpp.o"
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT GTests/CMakeFiles/tests.dir/__/lib.cpp.o -MF CMakeFiles/tests.dir/__/lib.cpp.o.d -o CMakeFiles/tests.dir/__/lib.cpp.o -c /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/lib.cpp

GTests/CMakeFiles/tests.dir/__/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/lib.cpp.i"
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/lib.cpp > CMakeFiles/tests.dir/__/lib.cpp.i

GTests/CMakeFiles/tests.dir/__/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/lib.cpp.s"
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/lib.cpp -o CMakeFiles/tests.dir/__/lib.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test_version.cpp.o" \
"CMakeFiles/tests.dir/__/lib.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

GTests/tests: GTests/CMakeFiles/tests.dir/test_version.cpp.o
GTests/tests: GTests/CMakeFiles/tests.dir/__/lib.cpp.o
GTests/tests: GTests/CMakeFiles/tests.dir/build.make
GTests/tests: lib/libgtest.a
GTests/tests: lib/libgtest_main.a
GTests/tests: lib/libgtest.a
GTests/tests: GTests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tests"
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
GTests/CMakeFiles/tests.dir/build: GTests/tests
.PHONY : GTests/CMakeFiles/tests.dir/build

GTests/CMakeFiles/tests.dir/clean:
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : GTests/CMakeFiles/tests.dir/clean

GTests/CMakeFiles/tests.dir/depend:
	cd /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vladislav/Documents/otus_cpp_professional/01_helloWorld /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/GTests /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests /home/vladislav/Documents/otus_cpp_professional/01_helloWorld/build/GTests/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : GTests/CMakeFiles/tests.dir/depend
