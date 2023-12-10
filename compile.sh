#!/bin/bash

# Change to the script's directory
pushd "$(dirname "$0")" > /dev/null 2>&1 || exit 

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

echo "Build successful! The executable is located in 'build/'."

popd > /dev/null 2>&1