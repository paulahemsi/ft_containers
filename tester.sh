#!/bin/bash

RESET="\033[0m"
BOLD="\033[1m"
RED="\033[0;31m"
CYAN="\033[0;36m"
V_GREEN="\e[0;38;5;82m"
P_GREEN="\e[0;38;5;23m"

usage()
{
	echo -e "usage:"
	echo -e "bash tester.sh vector"
	echo -e "bash tester.sh map"
	echo -e "bash tester.sh stack"
	echo -e "bash tester.sh set"
	exit
}

if (( $# != 1 )); then
    usage
fi

ARG=$1
if [ ${ARG} == "vector" ]; then
    DIR=./tests/vector/
elif [ ${ARG} == "map" ]; then
    DIR=./tests/map/
elif [ ${ARG} == "stack" ]; then
    DIR=./tests/stack/
elif [ ${ARG} == "set" ]; then
    DIR=./tests/set/
elif [ ${ARG} == "intra" ]; then
    DIR=./tests/intra/
else
	echo -e "\""$1"\" is not a valid argument."
    usage
fi

if [ "$(eval uname)" == "Darwin" ]; then
    DIFF=diff
    V_GREEN="\033[32m"
else
    DIFF="diff --color"
fi

LOGSDIR=./logs/
echo -e "\n${CYAN} ********************** ${ARG} ******************\n${RESET}"

echo -e "\n${V_GREEN} ----------making std version----------\n${RESET}"

make -C ${DIR} original

echo -e "\n${V_GREEN} ----------making ft version----------\n${RESET}"

make -C ${DIR}

echo -e "\n${V_GREEN} ----------executing and comparing----------\n${RESET}"

mkdir -p ${LOGSDIR}

${DIR}original 33 > ${LOGSDIR}std.txt 2> ${LOGSDIR}exceptions.txt
${DIR}ft.out 33 > ${LOGSDIR}ft.txt 2>> ${LOGSDIR}exceptions.txt

${DIFF} ${LOGSDIR}std.txt ${LOGSDIR}ft.txt

exit 0