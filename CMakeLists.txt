cmake_minimum_required(VERSION 3.5)

project(cmake-project-template)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# use gnu in windows environment
# set(CMAKE_CXX_COMPILER g++)
# set(CMAKE_C_COMPILER gcc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall -g")

include(GoogleTest)
enable_testing()
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/googletest/googletest/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/googletest)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)