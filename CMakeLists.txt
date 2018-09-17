cmake_minimum_required(VERSION 3.12)
project(RpiClock)

set(CMAKE_CXX_STANDARD 17)
# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)

PKG_CHECK_MODULES(GTK3 REQUIRED gtkmm-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

add_executable(RpiClock main.cpp MainWindow.cpp MainWindow.h ClockGrid.cpp ClockGrid.h ClockPixel.cpp ClockPixel.h)

TARGET_LINK_LIBRARIES(RpiClock ${GTK3_LIBRARIES})