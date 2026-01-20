#!/bin/bash
/**
 * @file delete_executables.sh
 * @brief Recursively finds and deletes C++ executables matching compiled .cpp files.
 *
 * This script searches for all .cpp source files in the current directory
 * and its subdirectories. For each .cpp file found, it checks if a corresponding
 * executable exists (with the same name but no extension) and deletes it.
 *
 * Usage:
 *   chmod +x delete_executables.sh
 *   ./delete_executables.sh
 *
 * @author Suman
 * @date January 20, 2026
 */

# Base folder (current directory)
BASE_DIR="."

# Find all .cpp files recursively
find "$BASE_DIR" -type f -name "*.cpp" | while read -r cpp_file; do
    # Get the directory and filename without extension
    dir=$(dirname "$cpp_file")
    filename=$(basename "$cpp_file" .cpp)

    # Construct the executable path
    exe_path="$dir/$filename"

    # Check if the executable exists and is a file
    if [ -f "$exe_path" ]; then
        echo "Deleting executable: $exe_path"
        rm "$exe_path"
    fi
done
echo "Cleanup complete."