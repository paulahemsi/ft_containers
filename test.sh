#!/bin/bash

RESET="\033[0m"
V_GREEN="\e[0;38;5;82m"
P_GREEN="\e[0;38;5;23m"

echo -e "\n${V_GREEN} ----------making std version----------\n${RESET}"

make -s original

echo -e "\n${V_GREEN} ----------making ft version----------\n${RESET}"
make -s

echo -e "\n${V_GREEN} ----------executing and comparing----------\n${RESET}"
./original > std.txt
./ft.out > ft.txt

diff --color std.txt ft.txt

echo -e "\n${V_GREEN} ----------cleaning up----------\n${RESET}"

rm std.txt
rm ft.txt
make -s fclean
