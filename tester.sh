#!/bin/bash

RESET="\033[0m"
BOLD="\033[1m"
RED="\033[0;31m"
V_GREEN="\e[0;38;5;82m"
P_GREEN="\e[0;38;5;23m"

DIFF=diff --collor
if [ "$(eval uname)" == "Darwin" ]
then
    DIFF=diff
    V_GREEN="\033[32m"
fi


LOGSDIR=./logs/
VECTORDIR=./tests/vector/

echo -e "\n${V_GREEN} ----------making std version----------\n${RESET}"

make -C ${VECTORDIR} original

echo -e "\n${V_GREEN} ----------making ft version----------\n${RESET}"

make -C ${VECTORDIR} 

echo -e "\n${V_GREEN} ----------executing and comparing----------\n${RESET}"

mkdir -p ${LOGSDIR}

${VECTORDIR}original > ${LOGSDIR}std.txt 2> ${LOGSDIR}exceptions.txt
${VECTORDIR}ft.out > ${LOGSDIR}ft.txt 2>> ${LOGSDIR}exceptions.txt

${DIFF} ${LOGSDIR}std.txt ${LOGSDIR}ft.txt
