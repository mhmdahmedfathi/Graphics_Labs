# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\cmake\cmake-3.23.0-rc3-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = D:\cmake\cmake-3.23.0-rc3-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Third year Second term\Graphics\labs\lab7\Example5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Third year Second term\Graphics\labs\lab7\Example5\build"

# Include any dependencies generated for this target.
include CMakeFiles/Example5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Example5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Example5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Example5.dir/flags.make

CMakeFiles/Example5.dir/main.cpp.obj: CMakeFiles/Example5.dir/flags.make
CMakeFiles/Example5.dir/main.cpp.obj: CMakeFiles/Example5.dir/includes_CXX.rsp
CMakeFiles/Example5.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Example5.dir/main.cpp.obj: CMakeFiles/Example5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Third year Second term\Graphics\labs\lab7\Example5\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Example5.dir/main.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Example5.dir/main.cpp.obj -MF CMakeFiles\Example5.dir\main.cpp.obj.d -o CMakeFiles\Example5.dir\main.cpp.obj -c "D:\Third year Second term\Graphics\labs\lab7\Example5\main.cpp"

CMakeFiles/Example5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Example5.dir/main.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Third year Second term\Graphics\labs\lab7\Example5\main.cpp" > CMakeFiles\Example5.dir\main.cpp.i

CMakeFiles/Example5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Example5.dir/main.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Third year Second term\Graphics\labs\lab7\Example5\main.cpp" -o CMakeFiles\Example5.dir\main.cpp.s

CMakeFiles/Example5.dir/vendor/glad/src/gl.c.obj: CMakeFiles/Example5.dir/flags.make
CMakeFiles/Example5.dir/vendor/glad/src/gl.c.obj: CMakeFiles/Example5.dir/includes_C.rsp
CMakeFiles/Example5.dir/vendor/glad/src/gl.c.obj: ../vendor/glad/src/gl.c
CMakeFiles/Example5.dir/vendor/glad/src/gl.c.obj: CMakeFiles/Example5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Third year Second term\Graphics\labs\lab7\Example5\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Example5.dir/vendor/glad/src/gl.c.obj"
	C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Example5.dir/vendor/glad/src/gl.c.obj -MF CMakeFiles\Example5.dir\vendor\glad\src\gl.c.obj.d -o CMakeFiles\Example5.dir\vendor\glad\src\gl.c.obj -c "D:\Third year Second term\Graphics\labs\lab7\Example5\vendor\glad\src\gl.c"

CMakeFiles/Example5.dir/vendor/glad/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Example5.dir/vendor/glad/src/gl.c.i"
	C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Third year Second term\Graphics\labs\lab7\Example5\vendor\glad\src\gl.c" > CMakeFiles\Example5.dir\vendor\glad\src\gl.c.i

CMakeFiles/Example5.dir/vendor/glad/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Example5.dir/vendor/glad/src/gl.c.s"
	C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Third year Second term\Graphics\labs\lab7\Example5\vendor\glad\src\gl.c" -o CMakeFiles\Example5.dir\vendor\glad\src\gl.c.s

# Object files for target Example5
Example5_OBJECTS = \
"CMakeFiles/Example5.dir/main.cpp.obj" \
"CMakeFiles/Example5.dir/vendor/glad/src/gl.c.obj"

# External object files for target Example5
Example5_EXTERNAL_OBJECTS =

../bin/Example5.exe: CMakeFiles/Example5.dir/main.cpp.obj
../bin/Example5.exe: CMakeFiles/Example5.dir/vendor/glad/src/gl.c.obj
../bin/Example5.exe: CMakeFiles/Example5.dir/build.make
../bin/Example5.exe: vendor/glfw/src/libglfw3.a
../bin/Example5.exe: CMakeFiles/Example5.dir/linklibs.rsp
../bin/Example5.exe: CMakeFiles/Example5.dir/objects1.rsp
../bin/Example5.exe: CMakeFiles/Example5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Third year Second term\Graphics\labs\lab7\Example5\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ..\bin\Example5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Example5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Example5.dir/build: ../bin/Example5.exe
.PHONY : CMakeFiles/Example5.dir/build

CMakeFiles/Example5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Example5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Example5.dir/clean

CMakeFiles/Example5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Third year Second term\Graphics\labs\lab7\Example5" "D:\Third year Second term\Graphics\labs\lab7\Example5" "D:\Third year Second term\Graphics\labs\lab7\Example5\build" "D:\Third year Second term\Graphics\labs\lab7\Example5\build" "D:\Third year Second term\Graphics\labs\lab7\Example5\build\CMakeFiles\Example5.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Example5.dir/depend
