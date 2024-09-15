cmake_minimum_required(VERSION 3.10)
project(DICOMTestApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add DCMTK package
find_package(DCMTK REQUIRED)

# Add Google Test
enable_testing()
add_subdirectory(test)

# Include directories
include_directories(${DCMTK_INCLUDE_DIRS})

# Add source files
add_executable(DICOMTestApp src/main.cpp src/dicom_utils.cpp)

# Link DCMTK libraries
target_link_libraries(DICOMTestApp ${DCMTK_LIBRARIES})
