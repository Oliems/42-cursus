#!/bin/bash

GREEN='\033[0;32m'
BLUE='\033[0;34m'
BOLD='\033[0;1m'
END='\033[0m'

test() {
	./replace tests/$1 "$2" "$3"
	echo -e "\n$GREEN$1: replace $2 $3 $END"
	echo -e "$BLUE"Original file:$END
	cat tests/$1
	echo -e "$BLUE"Replaced file:$END
	cat tests/$1.replace
}

test no_newline e 42
test newline "sent
ence" 42
test multiple a 42

