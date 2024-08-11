#!/bin/bash
# Function to find the project root directory
FindProjRoot() {
    local rootDir

    # Attempt to find the Git repository root
    rootDir=$(git rev-parse --show-toplevel 2>/dev/null)

    # If not in a git repository, fallback to finding `CMakeLists.txt`
    if [ -z "$rootDir" ]; then
        rootDir=$(dirname "$(find "$(pwd)" -type f -name "CMakeLists.txt" | head -n 1)")
    fi

    echo "$rootDir"
}

#!!! use `source` instead of `bash` !!! example: `source toBuild.sh`
# Get the project root directory
rootDir=$(FindProjRoot)
# echo "Detected project root directory: $rootDir"

# Check if the root directory was found
if [ -z "$rootDir" ]; then
    echo "Error: Could not find the project root directory."
    exit 1
fi

# Check if the current directory is not 'build'
currentDir=$(basename "$PWD")
if [ "$currentDir" != "build" ]; then
    # Change to the build directory in the project root
    if [ -d "$rootDir/build" ]; then
        cd "$rootDir/build" || { echo "Error: Could not change directory to 'build'."; exit 1; }
        echo "Switched to build directory: $(pwd)"
    else
        echo "Error: 'build' directory does not exist in the project root."
        exit 1
    fi
else
    echo "Already in the 'build' directory."
fi

# Determine the current shell
currentShell=$(basename "$SHELL")
# echo "Current shell: $currentShell"

# If the current shell is Zsh, switch to Bash using exec
if [ "$currentShell" = "zsh" ]; then
    exec zsh
elif [ "$currentShell" = "bash" ]; then
    exec bash
else
    echo "Current shell is '$currentShell', not switching."
fi