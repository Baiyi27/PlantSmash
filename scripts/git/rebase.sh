#!/bin/bash
scriptDir=$(dirname "$0")
# echo "-- Current directory: $scriptDir"

preScript=$scriptDir/addCommit.sh

if [ ! -f "$preScript" ]; then
  echo "Pre script 'addCommit' not found."
  exit 1
fi

source $preScript
# Prompt user for the commit ID to edit
read -p "-- Please enter the commit ID to edit:" commitID

# Validate the commit ID
if ! git rev-parse "$commitID" >/dev/null 2>&1; then
  echo "The input is not a valid commit ID"
  exit 1
fi

# Perform an interactive rebase to the specified commit ID
git rebase -i "$commitID"

# Revert the "temp" commit while keeping changes in the working directory
# git reset --soft HEAD^