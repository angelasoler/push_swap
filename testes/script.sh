#!/bin/bash

DARKGRAY='\033[1;30m'
RED='\033[0;31m'    
LIGHTRED='\033[1;31m'
GREEN='\033[0;32m'    
YELLOW='\033[1;33m'
BLUE='\033[0;34m'    
PURPLE='\033[0;35m'    
LIGHTPURPLE='\033[1;35m'
CYAN='\033[0;36m'    
WHITE='\033[1;37m'
SET='\033[0m'

filename='five_elements'
OK=1
while read line; do
	NUMBER=`../push_swap $line | wc -l`
	if [ $NUMBER -ge 13 ]; then
		OK=0;
		echo -e "${BLUE}------- 5 ELEMENTS ALL POSSIBLE COMBINATIONS ----------${SET}"

		echo -e "${LIGHTPURPLE}ARGS: ${SET}${CYAN}$line${SET}"
		echo -e "${RED}[KO]${SET} ${LIGHTRED}$NUMBER steps${SET}"
	fi
done < $filename

if [ $OK -ge 1 ]; then
	echo -e "${BLUE}------- 5 ELEMENTS ALL POSSIBLE COMBINATIONS ----------${SET}"
	echo -e "${GREEN}[OK]${SET}"
fi

filename='three_elements'
OK=1
while read line; do
	NUMBER=`../push_swap $line | wc -l`
	if [ $NUMBER -ge 13 ]; then
		OK=0;
		echo -e "${BLUE}------- 3 ELEMENTS ALL POSSIBLE COMBINATIONS ----------${SET}"
		echo -e "${LIGHTPURPLE}ARGS: ${SET}${CYAN}$line${SET}"
		echo -e "${RED}[KO]${SET} ${LIGHTRED}$NUMBER steps${SET}"
	fi
done < $filename

if [ $OK -ge 1 ]; then
	echo -e "${BLUE}------- 3 ELEMENTS ALL POSSIBLE COMBINATIONS ----------${SET}"
	echo -e "${GREEN}[OK]${SET}"
fi