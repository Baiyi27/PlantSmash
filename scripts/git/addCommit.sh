#!/bin/bash

# Commit current changes with the message "temp"
# git stash

git add -A 
git commit -am "temp"

read -p "-- Index Keywords: " KEYWORDS
# Display the commit log
git --no-pager log --oneline --reverse -55 | GREP_COLOR='1;31' grep --color=always -C 1 "$KEYWORDS"