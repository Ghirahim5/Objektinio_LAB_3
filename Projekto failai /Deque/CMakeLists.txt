cmake_minimum_required(VERSION 3.16)

project(Studentu_Pazymiai)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
  v1.0_deque.cpp
  1deque_funkcijos.cpp
  funkcijos.h
  studentas.h
)

set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Studentu_Pazymiai ${SOURCE_FILES})

target_link_libraries(Studentu_Pazymiai)

set_target_properties(Studentu_Pazymiai PROPERTIES
    OUTPUT_NAME "Studentu_Pazymiai"
)

install(TARGETS Studentu_Pazymiai DESTINATION bin)