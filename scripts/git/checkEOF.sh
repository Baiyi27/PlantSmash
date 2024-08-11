#!/bin/bash

# File path to check
read -p "Enter the file path: " filePath
# Get all commits for the file
commits=$(git log --reverse --pretty=format:%h -- $filePath)

# Create a temporary folder to store the file content
mkdir -p tmp

for commit in $commits; do
    # Get the file content at a specific commit
    git show $commit:$filePath >  tmp/$commit.eof

    # Check the file's line ending type
    eol=$(file tmp/$commit.eof)

    # Output the commit ID and line ending type
    echo "$commit: $eol"
done

# Clean up the temporary folder
rm -rf tmp
