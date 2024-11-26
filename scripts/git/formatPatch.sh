#!/bin/sh

outputFolder="patches"
arFile="patches.tgz"

# Check if the output folder exists, create it if it doesn't
if [ ! -d "$outputFolder" ]; then
  echo "--Output folder does not exist. Creating folder: $outputFolder"
  mkdir -p "$outputFolder"
else
  echo "--Output folder already exists: $outputFolder"
fi

# Generate patch files
read -p "Input index:" index
git format-patch "$index" -o "$outputFolder" --filename-max-length 255

# Compress the patches folder
echo "--Compressing '$outputFolder' to '$arFile'"
tar -cJf "$arFile" "$outputFolder"

# Check if the compression was successful
if [ $? -eq 0 ]; then
  echo "--Compression successful. Deleting original folder: '$outputFolder'"
  rm -rf "$outputFolder"
else
  echo "--Compression failed. Original folder not deleted."
fi