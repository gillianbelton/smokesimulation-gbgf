# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build

# Include any dependencies generated for this target.
include CMakeFiles/a3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a3.dir/flags.make

CMakeFiles/a3.dir/src/main.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a3.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/src/main.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/main.cpp

CMakeFiles/a3.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/main.cpp > CMakeFiles/a3.dir/src/main.cpp.i

CMakeFiles/a3.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/main.cpp -o CMakeFiles/a3.dir/src/main.cpp.s

CMakeFiles/a3.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/src/main.cpp.o.requires

CMakeFiles/a3.dir/src/main.cpp.o.provides: CMakeFiles/a3.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/src/main.cpp.o.provides

CMakeFiles/a3.dir/src/main.cpp.o.provides.build: CMakeFiles/a3.dir/src/main.cpp.o


CMakeFiles/a3.dir/src/starter3_util.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/starter3_util.cpp.o: ../src/starter3_util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a3.dir/src/starter3_util.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/src/starter3_util.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/starter3_util.cpp

CMakeFiles/a3.dir/src/starter3_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/starter3_util.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/starter3_util.cpp > CMakeFiles/a3.dir/src/starter3_util.cpp.i

CMakeFiles/a3.dir/src/starter3_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/starter3_util.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/starter3_util.cpp -o CMakeFiles/a3.dir/src/starter3_util.cpp.s

CMakeFiles/a3.dir/src/starter3_util.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/src/starter3_util.cpp.o.requires

CMakeFiles/a3.dir/src/starter3_util.cpp.o.provides: CMakeFiles/a3.dir/src/starter3_util.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/src/starter3_util.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/src/starter3_util.cpp.o.provides

CMakeFiles/a3.dir/src/starter3_util.cpp.o.provides.build: CMakeFiles/a3.dir/src/starter3_util.cpp.o


CMakeFiles/a3.dir/src/camera.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a3.dir/src/camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/src/camera.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/camera.cpp

CMakeFiles/a3.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/camera.cpp > CMakeFiles/a3.dir/src/camera.cpp.i

CMakeFiles/a3.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/camera.cpp -o CMakeFiles/a3.dir/src/camera.cpp.s

CMakeFiles/a3.dir/src/camera.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/src/camera.cpp.o.requires

CMakeFiles/a3.dir/src/camera.cpp.o.provides: CMakeFiles/a3.dir/src/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/src/camera.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/src/camera.cpp.o.provides

CMakeFiles/a3.dir/src/camera.cpp.o.provides.build: CMakeFiles/a3.dir/src/camera.cpp.o


CMakeFiles/a3.dir/src/vertexrecorder.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/vertexrecorder.cpp.o: ../src/vertexrecorder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a3.dir/src/vertexrecorder.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/src/vertexrecorder.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/vertexrecorder.cpp

CMakeFiles/a3.dir/src/vertexrecorder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/vertexrecorder.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/vertexrecorder.cpp > CMakeFiles/a3.dir/src/vertexrecorder.cpp.i

CMakeFiles/a3.dir/src/vertexrecorder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/vertexrecorder.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/vertexrecorder.cpp -o CMakeFiles/a3.dir/src/vertexrecorder.cpp.s

CMakeFiles/a3.dir/src/vertexrecorder.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/src/vertexrecorder.cpp.o.requires

CMakeFiles/a3.dir/src/vertexrecorder.cpp.o.provides: CMakeFiles/a3.dir/src/vertexrecorder.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/src/vertexrecorder.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/src/vertexrecorder.cpp.o.provides

CMakeFiles/a3.dir/src/vertexrecorder.cpp.o.provides.build: CMakeFiles/a3.dir/src/vertexrecorder.cpp.o


CMakeFiles/a3.dir/src/fluidsystem.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/src/fluidsystem.cpp.o: ../src/fluidsystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/a3.dir/src/fluidsystem.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/src/fluidsystem.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/fluidsystem.cpp

CMakeFiles/a3.dir/src/fluidsystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/src/fluidsystem.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/fluidsystem.cpp > CMakeFiles/a3.dir/src/fluidsystem.cpp.i

CMakeFiles/a3.dir/src/fluidsystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/src/fluidsystem.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/src/fluidsystem.cpp -o CMakeFiles/a3.dir/src/fluidsystem.cpp.s

CMakeFiles/a3.dir/src/fluidsystem.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/src/fluidsystem.cpp.o.requires

CMakeFiles/a3.dir/src/fluidsystem.cpp.o.provides: CMakeFiles/a3.dir/src/fluidsystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/src/fluidsystem.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/src/fluidsystem.cpp.o.provides

CMakeFiles/a3.dir/src/fluidsystem.cpp.o.provides.build: CMakeFiles/a3.dir/src/fluidsystem.cpp.o


CMakeFiles/a3.dir/ray_tracer/stb.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/stb.cpp.o: ../ray_tracer/stb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/a3.dir/ray_tracer/stb.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/stb.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/stb.cpp

CMakeFiles/a3.dir/ray_tracer/stb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/stb.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/stb.cpp > CMakeFiles/a3.dir/ray_tracer/stb.cpp.i

CMakeFiles/a3.dir/ray_tracer/stb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/stb.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/stb.cpp -o CMakeFiles/a3.dir/ray_tracer/stb.cpp.s

CMakeFiles/a3.dir/ray_tracer/stb.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/stb.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/stb.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/stb.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/stb.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/stb.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/stb.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/stb.cpp.o


CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o: ../ray_tracer/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Camera.cpp

CMakeFiles/a3.dir/ray_tracer/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Camera.cpp > CMakeFiles/a3.dir/ray_tracer/Camera.cpp.i

CMakeFiles/a3.dir/ray_tracer/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Camera.cpp -o CMakeFiles/a3.dir/ray_tracer/Camera.cpp.s

CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o


CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o: ../ray_tracer/CubeMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/CubeMap.cpp

CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/CubeMap.cpp > CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.i

CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/CubeMap.cpp -o CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.s

CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o


CMakeFiles/a3.dir/ray_tracer/Image.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/Image.cpp.o: ../ray_tracer/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/a3.dir/ray_tracer/Image.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/Image.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Image.cpp

CMakeFiles/a3.dir/ray_tracer/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/Image.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Image.cpp > CMakeFiles/a3.dir/ray_tracer/Image.cpp.i

CMakeFiles/a3.dir/ray_tracer/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/Image.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Image.cpp -o CMakeFiles/a3.dir/ray_tracer/Image.cpp.s

CMakeFiles/a3.dir/ray_tracer/Image.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/Image.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/Image.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/Image.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/Image.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/Image.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/Image.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/Image.cpp.o


CMakeFiles/a3.dir/ray_tracer/Light.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/Light.cpp.o: ../ray_tracer/Light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/a3.dir/ray_tracer/Light.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/Light.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Light.cpp

CMakeFiles/a3.dir/ray_tracer/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/Light.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Light.cpp > CMakeFiles/a3.dir/ray_tracer/Light.cpp.i

CMakeFiles/a3.dir/ray_tracer/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/Light.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Light.cpp -o CMakeFiles/a3.dir/ray_tracer/Light.cpp.s

CMakeFiles/a3.dir/ray_tracer/Light.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/Light.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/Light.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/Light.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/Light.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/Light.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/Light.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/Light.cpp.o


CMakeFiles/a3.dir/ray_tracer/Material.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/Material.cpp.o: ../ray_tracer/Material.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/a3.dir/ray_tracer/Material.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/Material.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Material.cpp

CMakeFiles/a3.dir/ray_tracer/Material.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/Material.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Material.cpp > CMakeFiles/a3.dir/ray_tracer/Material.cpp.i

CMakeFiles/a3.dir/ray_tracer/Material.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/Material.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Material.cpp -o CMakeFiles/a3.dir/ray_tracer/Material.cpp.s

CMakeFiles/a3.dir/ray_tracer/Material.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/Material.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/Material.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/Material.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/Material.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/Material.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/Material.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/Material.cpp.o


CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o: ../ray_tracer/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Mesh.cpp

CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Mesh.cpp > CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.i

CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Mesh.cpp -o CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.s

CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o


CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o: ../ray_tracer/Object3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Object3D.cpp

CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Object3D.cpp > CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.i

CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Object3D.cpp -o CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.s

CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o


CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o: ../ray_tracer/Octree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Octree.cpp

CMakeFiles/a3.dir/ray_tracer/Octree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/Octree.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Octree.cpp > CMakeFiles/a3.dir/ray_tracer/Octree.cpp.i

CMakeFiles/a3.dir/ray_tracer/Octree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/Octree.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Octree.cpp -o CMakeFiles/a3.dir/ray_tracer/Octree.cpp.s

CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o


CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o: ../ray_tracer/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Renderer.cpp

CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Renderer.cpp > CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.i

CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/Renderer.cpp -o CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.s

CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o


CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o: CMakeFiles/a3.dir/flags.make
CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o: ../ray_tracer/VecUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o -c /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/VecUtils.cpp

CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/VecUtils.cpp > CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.i

CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/ray_tracer/VecUtils.cpp -o CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.s

CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o.requires:

.PHONY : CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o.requires

CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o.provides: CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o.requires
	$(MAKE) -f CMakeFiles/a3.dir/build.make CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o.provides.build
.PHONY : CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o.provides

CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o.provides.build: CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o


# Object files for target a3
a3_OBJECTS = \
"CMakeFiles/a3.dir/src/main.cpp.o" \
"CMakeFiles/a3.dir/src/starter3_util.cpp.o" \
"CMakeFiles/a3.dir/src/camera.cpp.o" \
"CMakeFiles/a3.dir/src/vertexrecorder.cpp.o" \
"CMakeFiles/a3.dir/src/fluidsystem.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/stb.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/Image.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/Light.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/Material.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o" \
"CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o"

# External object files for target a3
a3_EXTERNAL_OBJECTS =

a3: CMakeFiles/a3.dir/src/main.cpp.o
a3: CMakeFiles/a3.dir/src/starter3_util.cpp.o
a3: CMakeFiles/a3.dir/src/camera.cpp.o
a3: CMakeFiles/a3.dir/src/vertexrecorder.cpp.o
a3: CMakeFiles/a3.dir/src/fluidsystem.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/stb.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/Image.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/Light.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/Material.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o
a3: CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o
a3: CMakeFiles/a3.dir/build.make
a3: 3rd_party/glfw/src/libglfw3.a
a3: vecmath/libvecmath.a
a3: CMakeFiles/a3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable a3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a3.dir/build: a3

.PHONY : CMakeFiles/a3.dir/build

CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/src/main.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/src/starter3_util.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/src/camera.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/src/vertexrecorder.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/src/fluidsystem.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/stb.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/Camera.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/CubeMap.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/Image.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/Light.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/Material.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/Mesh.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/Object3D.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/Octree.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/Renderer.cpp.o.requires
CMakeFiles/a3.dir/requires: CMakeFiles/a3.dir/ray_tracer/VecUtils.cpp.o.requires

.PHONY : CMakeFiles/a3.dir/requires

CMakeFiles/a3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a3.dir/clean

CMakeFiles/a3.dir/depend:
	cd /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build /Users/Gillian/Desktop/School/MIT17_18/6.837/FinalProject/smokesimulation-gbgf/build/CMakeFiles/a3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a3.dir/depend

