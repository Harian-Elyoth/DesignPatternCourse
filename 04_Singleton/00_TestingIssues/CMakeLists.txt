project(TestingIssues)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLDUE_DIRS})

add_executable(${PROJECT_NAME} SingletonTesting.cpp)

# Set the output directory for this target
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

target_link_libraries(${PROJECT_NAME} 
    ${GTEST_BOTH_LIBRARIES}
    pthread
)

