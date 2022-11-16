cmake_minimum_required(VERSION 3.0.0)
project(Lab09 VERSION 0.1.0)

# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_compile_options(-std=c++17)
set (CMAKE_CXX_STANDARD 17)
 
add_library (applibrary SHARED Graph.cpp)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread applibrary) 

add_executable(runMain main.cpp)
target_link_libraries(runMain applibrary)
