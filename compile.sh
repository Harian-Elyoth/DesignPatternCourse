#!/bin/bash

# Change to the script's directory
pushd "$(dirname "$0")" > /dev/null 2>&1 || exit

# Function to display usage information
show_help() {
    echo "Usage: $0 [--help]"
}


# Check if the --install-boost command is provided
if [[ "$1" == "--help" ]]; then
    show_help
    exit 0
fi

# Check if clang-format is installed
if ! command -v clang-format &> /dev/null; then
    echo "clang-format not found. Do you want to install it? (y/n)"
    read -r response
    if [[ "$response" =~ ^[Yy]$ ]]; then
        # Install clang-format (you may need to adjust this based on your system)
        # For example, on Ubuntu, you can use: sudo apt-get install clang-format
        echo "Installing clang-format..."
        sudo apt-get install clang-format
    else
        echo "Aborted. Please install clang-format before proceeding."
        exit 1
    fi
fi


# Verify the existence of the 'build/' directory
if [ ! -d "build/" ]; then
    echo "Warning: The 'build/' directory does not exist. Creating it..."
    mkdir build || { echo "Error: Unable to create the 'build/' directory."; exit 1; }
fi

# Run Clang-Format
find . -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -exec clang-format -i -style=llvm -fallback-style=none {} \;

# Change to the 'build/' directory
pushd build || { echo "Error: Unable to change to the 'build/' directory."; exit 1; }

# Run CMake
cmake .. || { echo "Error: CMake configuration failed."; popd; exit 1; }

# Run Make
make || { echo "Error: Compilation failed."; popd; exit 1; }

# Return to the previous directory
popd

echo "Build successful! The executable is located in the 'bin/' folder of each design pattern folders."

popd > /dev/null 2>&1