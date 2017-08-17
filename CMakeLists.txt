cmake_minimum_required (VERSION 3.6)
project (RevisedGhostshell)

set (CMAKE_CXX_STANDARD 11)
set (SOURCE_FILES src/utilities.cpp src/generalTools.cpp src/match.cpp src/otm.cpp src/irisEncoding.cpp src/ghostshell.cpp src/authGroup.cpp)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Configuration Profile
set (CMAKE_CXX_FLAGS_PROFILE "${CMAKE_CXX_FLAGS} -pg")
set (CMAKE_EXE_LINKER_FLAGS_PROFILE "${CMAKE_EXE_LINKER_FLAGS} -pg")
set (OpenMP_CXX_FLAGS "-fopenmp")

# Enable OpenMP if available
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set (HELIB_SOURCE_DIRECTORY "/Users/heewon/Documents/_SourceCode/Library/HElib-master/src/")
 
include_directories(${HELIB_SOURCE_DIRECTORY})
include_directories(include)
include_directories(lib)

add_subdirectory(lib)

add_library(RevisedGhostshell ${SOURCE_FILES})
target_link_libraries(RevisedGhostshell HElib NTL GMP GF2X -lm -O2)

add_executable(test_matching test/matchingTest.cpp)
target_link_libraries(test_matching RevisedGhostshell -pthread)
add_executable(test_otm test/otmTest.cpp)
target_link_libraries(test_otm RevisedGhostshell HElib)
add_executable(test_ghostshell test/ghostshellTest.cpp)
target_link_libraries(test_ghostshell RevisedGhostshell -pthread)
add_executable(test_poly test/polyTest.cpp)
target_link_libraries(test_poly RevisedGhostshell -pthread)