cmake_minimum_required(VERSION 3.10)

project(DesignPatterns)

# Set C++ standard (change to your desired version)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)
# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(
    /usr/lib/boost_1_83_0
)
link_directories(
    /usr/lib/boost_1_83_0/stage/lib
)
add_subdirectory("00_SolidDesignPrinciples")
add_subdirectory("01_Builder")
add_subdirectory("02_Factory")
add_subdirectory("03_Prototype")
add_subdirectory("04_Singleton")
add_subdirectory("05_Adapter")
add_subdirectory("06_Bridge")
add_subdirectory("07_Composite")
add_subdirectory("08_Decorator")
add_subdirectory("09_Façade")
add_subdirectory("10_Flyweight")
add_subdirectory("11_Proxy")
add_subdirectory("12_ChainOfResponsability")
add_subdirectory("13_Command")
add_subdirectory("14_Interpreter")
add_subdirectory("15_Iterator")
add_subdirectory("16_Mediator")
add_subdirectory("17_Memento")
add_subdirectory("18_Observer")
add_subdirectory("19_State")
add_subdirectory("20_Strategy")
add_subdirectory("21_TemplateMethod")
add_subdirectory("22_Visitor")