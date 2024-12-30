cmake_minimum_required(VERSION 3.16)
project(run_mc_simulations)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Detect the architecture (ARM64 for Apple Silicon or x86_64 for Intel)
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
    message(STATUS "Building for Apple Silicon (ARM64)")
    set(HOMEBREW_INCLUDE_DIR "/opt/homebrew/include")
    set(HOMEBREW_LIBRARY_DIR "/opt/homebrew/lib")
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
    message(STATUS "Building for Intel (x86_64)")
    set(HOMEBREW_INCLUDE_DIR "/usr/local/include")
    set(HOMEBREW_LIBRARY_DIR "/usr/local/lib")
else()
    message(FATAL_ERROR "Unsupported architecture: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

# Include directories
include_directories(
    ${HOMEBREW_INCLUDE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Add executable target
add_executable(run_mc_simulations 
    main.cpp 
    CSVReader.cpp
    MonteCarloSimulator.cpp
)

# Link libraries (if required, e.g., if argparse depends on libraries)
target_link_directories(run_mc_simulations PRIVATE ${HOMEBREW_LIBRARY_DIR})

enable_testing()
add_subdirectory(unit_tests)
