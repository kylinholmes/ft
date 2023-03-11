## Project Info
cmake_minimum_required(VERSION 3.12)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_CMAKE} CACHE STRING "Vcpkg toolchain file")
project(CXXTemplate VERSION 0.0.1 LANGUAGES C CXX)


## Compile Config
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)
if( NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    message("Setting default build type to Debug")
endif()


## Include dir
include_directories(
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)
file(GLOB_RECURSE SOURCE "src/*.cpp")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

##  Exec and Link
add_executable(${PROJECT_NAME} ${SOURCE})

## Unit Test
enable_testing()
add_executable(
  test_ipv4
  test/test_ipv4.cpp
)
target_link_libraries(
  test_ipv4
  GTest::gtest_main
)
## Dependencies
include(GoogleTest)
gtest_discover_tests(test_ipv4)
