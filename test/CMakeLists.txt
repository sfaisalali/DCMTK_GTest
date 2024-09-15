cmake_minimum_required(VERSION 3.10)
project(DICOMTestAppTests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Google Test
# FetchContent module to download and include Google Test
include(FetchContent)

FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0  # or the latest release
)

FetchContent_MakeAvailable(gtest)

include_directories(${GTEST_INCLUDE_DIRS})

# Add test source files
add_executable(runTests test_dicom_utils.cpp)

# Link Google Test and DCMTK libraries
target_link_libraries(runTests ${GTEST_LIBRARIES} ${DCMTK_LIBRARIES} pthread)

# Add tests
add_test(NAME runTests COMMAND runTests)
