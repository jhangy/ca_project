# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/min/a/chen3836/ca_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/min/a/chen3836/ca_project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/min/a/chen3836/ca_project/CMakeFiles /home/min/a/chen3836/ca_project/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/min/a/chen3836/ca_project/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

cpp/path_generator.o: cpp/path_generator.cpp.o
.PHONY : cpp/path_generator.o

# target to build an object file
cpp/path_generator.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/path_generator.cpp.o
.PHONY : cpp/path_generator.cpp.o

cpp/path_generator.i: cpp/path_generator.cpp.i
.PHONY : cpp/path_generator.i

# target to preprocess a source file
cpp/path_generator.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/path_generator.cpp.i
.PHONY : cpp/path_generator.cpp.i

cpp/path_generator.s: cpp/path_generator.cpp.s
.PHONY : cpp/path_generator.s

# target to generate assembly for a file
cpp/path_generator.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/path_generator.cpp.s
.PHONY : cpp/path_generator.cpp.s

cpp/predictor.o: cpp/predictor.cpp.o
.PHONY : cpp/predictor.o

# target to build an object file
cpp/predictor.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/predictor.cpp.o
.PHONY : cpp/predictor.cpp.o

cpp/predictor.i: cpp/predictor.cpp.i
.PHONY : cpp/predictor.i

# target to preprocess a source file
cpp/predictor.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/predictor.cpp.i
.PHONY : cpp/predictor.cpp.i

cpp/predictor.s: cpp/predictor.cpp.s
.PHONY : cpp/predictor.s

# target to generate assembly for a file
cpp/predictor.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/predictor.cpp.s
.PHONY : cpp/predictor.cpp.s

cpp/simulator.o: cpp/simulator.cpp.o
.PHONY : cpp/simulator.o

# target to build an object file
cpp/simulator.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/simulator.cpp.o
.PHONY : cpp/simulator.cpp.o

cpp/simulator.i: cpp/simulator.cpp.i
.PHONY : cpp/simulator.i

# target to preprocess a source file
cpp/simulator.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/simulator.cpp.i
.PHONY : cpp/simulator.cpp.i

cpp/simulator.s: cpp/simulator.cpp.s
.PHONY : cpp/simulator.s

# target to generate assembly for a file
cpp/simulator.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cpp/simulator.cpp.s
.PHONY : cpp/simulator.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... rebuild_cache"
	@echo "... cpp/path_generator.o"
	@echo "... cpp/path_generator.i"
	@echo "... cpp/path_generator.s"
	@echo "... cpp/predictor.o"
	@echo "... cpp/predictor.i"
	@echo "... cpp/predictor.s"
	@echo "... cpp/simulator.o"
	@echo "... cpp/simulator.i"
	@echo "... cpp/simulator.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

