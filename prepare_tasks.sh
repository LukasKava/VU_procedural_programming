#!/bin/bash

LIGHT_GRAY="\e[90m"
RESET_COLOR="\e[0m"
LIGHT_CYAN_BOLD_UNDERLINE="\e[1;4;96m"

echo -e "${LIGHT_GRAY}###################################################################################${RESET_COLOR}\n"
echo "Welcome to the helping bash script"
echo -e "This script is created to help automate creation of directories\nand their main.c files as it takes time to create them each time from the start"
echo -e "${LIGHT_CYAN_BOLD_UNDERLINE}And time is too valuable ${RESET_COLOR}\n"
echo -e "${LIGHT_GRAY}###################################################################################${RESET_COLOR}\n"

# $# means the command line argument
# -gt means the greater than
# shift means that it goes to the next argument
while [ "$#" -gt 0 ]; do
	echo "Processing argument: $1"
	shift
done