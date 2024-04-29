cmake_minimum_required(VERSION 3.10)

# Add executable
add_executable(studentai v1.2_vektoriai.cpp vektoriu_funkcijos.cpp studentas.cpp)

# Include directories
target_include_directories(studentai PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Include header files
target_sources(studentai PRIVATE funkcijos.h studentas.h)

# Set compiler options
target_compile_options(studentai PRIVATE /O1)
