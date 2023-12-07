#!/bin/bash

# Function to display help
function show_help {
    echo "Usage: $0 [OPTIONS]"
    echo "Options:"
    echo "  -h, --help     Display this help message"
    echo "  -b, --build    Build the project"
}

# Check for command-line options
while [[ $# -gt 0 ]]; do
    case "$1" in
        -h|--help)
            show_help
            exit 0
            ;;
        *)
            echo "Error: Unknown option $1"
            show_help
            exit 1
            ;;
    esac
done

# Create a build directory if it doesn't exist
mkdir -p build

# Navigate to the build directory
pushd build

# Run CMake to generate build files
cmake ..

# Build the project using make
make

popd
