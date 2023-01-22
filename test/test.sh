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

function ProgressBar
{
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*4)/10
    let _left=40-$_done
    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")
	printf "\rProgress : [${_fill// /#}${_empty// /-}] ${_progress}%%"
}

exec_set ()
{
	for i in $(eval echo "{1..$1}")
	do
		$(< 10k.txt shuf | head -n $2 > test_case.txt)
		ARG=$(< test_case.txt)
		if ../push_swap $ARG | ./checker_linux $ARG | grep OK > /dev/null; then
			ProgressBar $i $1
		else
			printf "Status : ${RED}KO${DEF_COLOR} with list:\n"
			cat test_case.txt
			return 0
		fi
	done
		printf "\nStatus : ${GREEN}OK${DEF_COLOR}\n"
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