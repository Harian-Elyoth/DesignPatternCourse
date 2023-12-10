#!/bin/bash

echo "Cleaning up..."

# Change to the script's directory
pushd "$(dirname "$0")" > /dev/null 2>&1 || exit 

# Verify the existence of the 'build/' directory
if [ -d "build/" ]; then
    # Remove the 'build/' directory
    rm -rf build
fi

# Remove all the bin directories
find . -type d -name "bin" -exec rm -r {} +

echo "Clean-up complete."

popd > /dev/null 2>&1