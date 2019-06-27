#!/bin/bash

# Set up
PATH_NAME=${PWD}
echo "Set up arduino"

cd ../../../rasberry
echo "Connect the board to your PC"
./arduino-cli core update-index

echo "Connecting board list"
./arduino-cli board list

echo "Find the right core"
./arduino-cli core search arduino



