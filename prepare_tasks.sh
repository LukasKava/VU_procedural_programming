#!/bin/bash

LIGHT_GRAY="\e[90m"
SUCCESS="\e[32m"	#GREEN
WARNING="\e[33m"		#YELLOW
ERROR="\e[31m"		#RED
RESET="\e[0m"
LIGHT_CYAN_BOLD_UNDERLINE="\e[1;4;96m"

echo -e "${LIGHT_GRAY}###################################################################################${RESET}\n"
echo "Welcome to the helping bash script"
echo -e "This script is created to help automate creation of directories\nand their main.c files as it takes time to create them each time from the start"
echo -e "${LIGHT_CYAN_BOLD_UNDERLINE}And time is too valuable ${RESET}\n"
echo -e "${LIGHT_GRAY}###################################################################################${RESET}\n"


# isUserInputCorrect() {
	

# 	return 0
# }


# $# means the command line argument
# -gt means the greater than
# shift means that it goes to the next argument
FOLDER_NAME=""
while [ "$#" -gt 0 ]; do
	echo "Processing argument: $1"

	#I need to create the folders
	FOLDER_NAME=$1

	#CHECKING IF THE FOLDER ALREADY EXISTS
	if [ ! -d "${FOLDER_NAME}" ]; then
		mkdir "${FOLDER_NAME}"
		echo "[${SUCCESS}SUCCESS${RESET}]	New folder: ${FOLDER_NAME} has been created"
	else
		echo "[${WARNING}WARNING${RESET}]	Directory already exists"
	fi

	if [ -d "${FOLDER_NAME}" ]; then
		cd "${FOLDER_NAME}"
		echo -e "[${SUCCESS}SUCCESS${RESET}]	Succesfully cd into: ${FOLDER_NAME}"
	else
		echo -e "[${ERROR}ERROR${RESET}]	THERE IS NO FOLDER NAMED: ${FOLDER_NAME}"
		echo -e "					Exiting the bash script"
		exit 1
	fi

	#create main.c files
	if [ ! -f "main.c" ]; then
		touch main.c
		echo -e "[${SUCCESS}SUCCESS${RESET}]	File main.c was created"
	else 
		echo -e "[${WARNING}WARNING${RESET}]	File main.c already exists"
		#FURTHER WORK NEEDS TO BE DONE FOR VALIDATION!!!
		echo -e "Do you want to overwrite the main.c file with template.c? Yes/No"
	fi

	#and fill them in with predefined code
	if [ -f "../template.c" ]; then
		#cp command was used because its the start of the file and I dont need a functionallity of cat template.c >> main.c
		cp "../template.c" "./main.c"
		echo "[${SUCCESS}SUCCESS${RESET}]	Transfered template.c boiler plate to main.c"
	else
		echo "[${ERROR}ERROR${RESET}]	template.c does not exist please check the original git repo"
		echo "			Exiting the bash script"
		exit 1
	fi

	#come out of the folder
	if [ -d ".." ]; then
		cd ".."
		echo -e "[${SUCCESS}SUCCESS${RESET}]	Succesfully cd back"
	else
		echo -e "[${ERROR}ERROR${RESET}]	Cannot cd back"
		echo -e "					Exiting the bash script"
		exit 1
	fi
	echo -e "\n"
	shift
done

