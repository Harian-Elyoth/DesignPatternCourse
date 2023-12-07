project(InterfaceSegregationPrincple)

add_executable(${PROJECT_NAME} interfaceSegregationPrincple.cpp)

# Set the output directory for this target
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)