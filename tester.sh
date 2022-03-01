#!/bin/bash

RESET="\033[0m"
V_GREEN="\e[0;38;5;82m"
P_GREEN="\e[0;38;5;23m"

LOGSDIR=./logs/

echo -e "\n${V_GREEN} ----------making std version----------\n${RESET}"

make original

echo -e "\n${V_GREEN} ----------making ft version----------\n${RESET}"

make

echo -e "\n${V_GREEN} ----------executing and comparing----------\n${RESET}"

mkdir -p ${LOGSDIR}

./original > ${LOGSDIR}std.txt 2> ${LOGSDIR}exceptions.txt
./ft.out > ${LOGSDIR}ft.txt 2>> ${LOGSDIR}exceptions.txt

diff --color ${LOGSDIR}std.txt ${LOGSDIR}ft.txt
