#!/usr/bin/bash

DEF_COLOR="\033[0;39m"
BOLD="\033[1;39m"
RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
MAGENTA="\033[1;35m"
CYAN="\033[1;36m"
WHITE="\033[1;37m"

function ProgressBar {
# Process data
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*4)/10
    let _left=40-$_done
# Build progressbar string lengths
    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")

# 1.2 Build progressbar strings and print the ProgressBar line
# 1.2.1 Output example:                           
# 1.2.1.1 Progress : [########################################] 100%
printf "\rProgress : [${_fill// /#}${_empty// /-}] ${_progress}%%"

}

exec_set ()
{
	for i in $(eval echo "{1..$1}")
	do
		ARG=$(< 10k.txt shuf | head -n $2); 
		if ../push_swap $ARG | ./checker_linux $ARG | grep OK > /dev/null; then
			ProgressBar $i $1
		else
			printf "KO\n"
			return 0
		fi
	done
}

exec_all ()
{
	for i in $(eval echo "{$1..$2}")
	do
		printf "${BOLD}===Test===${DEF_COLOR}\n"
		printf "Stacksize=$i Amount=$3\n"
		exec_set $3 $i
		printf "\n"
	done
}

exec_all $1 $2 $3