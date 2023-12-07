project(DependencyInversionPrinciple)

add_executable(${PROJECT_NAME} dependencyInversionPrinciple.cpp)

# Set the output directory for this target
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)