# Google Test: Find package
find_package(GTest REQUIRED)

set(TESTED_SOURCES
    ../CSVReader.cpp
)

set(TEST_SOURCES
    CSVReaderTests.cpp
    #MonteCarloSimulatorTests.cpp
)

add_executable(utests 
    ${TEST_SOURCES}
    ${TESTED_SOURCES}
)

target_link_libraries(utests PRIVATE GTest::GTest GTest::Main)

target_include_directories(utests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/.
)


include(GoogleTest)
gtest_discover_tests(utests)

# Copy test data to build directory
set(TEST_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/small_data.csv
    ${CMAKE_CURRENT_SOURCE_DIR}/csv_with_whitespace.csv
    ${CMAKE_CURRENT_SOURCE_DIR}/data_with_empty_lines.csv
)

set(TEST_DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR}/test_data
)

add_custom_command(
    TARGET utests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${TEST_DESTINATION}
    COMMAND ${CMAKE_COMMAND} -E copy ${TEST_FILES} ${TEST_DESTINATION}
)
