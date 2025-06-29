#!/bin/bash

# some colors for FUN
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m'

if [ "$1" == "mem" ]; then
    RUN="valgrind --leak-check=full --show-leak-kinds=all ./push_swap"
else
    RUN="./push_swap"
fi

# test error cases
echo -e "${YELLOW}Testing error cases, all of these should print 'Error' on standard error${NC}"
echo -e "${RED}Only one empty string:${NC}"
$RUN ""
echo -e "${RED}Mixed numbers and letters:${NC}"
$RUN 1 9 5 a 2 b 93
echo -e "${RED}Mixed numbers and letters as a single string:${NC}"
$RUN "abc 9 5 a 2 b 93"
echo -e "${RED}Numbers with an empty string at the end:${NC}"
$RUN 888 39 0 2 ""
echo -e "${RED}Numbers with a space (as a string) at the end:${NC}"
$RUN 1 3 2 " "
echo -e "${RED}Arguments contain duplicates:${NC}"
$RUN 88 1000 7 13 99 4 2 7 1
echo -e "${RED}Arguments contain duplicates as a single string:${NC}"
$RUN "88 1000 7 13 99 4 2 7 1"
echo -e "${RED}Over max int:${NC}"
$RUN 80 2 77 -1 99999999999
echo -e "${RED}Under min int:${NC}"
$RUN -1 -800000 78 -99999999999 33 100
echo -e "${YELLOW}push swap with no parameters ${RED}(this should print nothing):${NC}"
$RUN

################ TESTING PUSH_SWAP ################
# variables used
total_wc=0 # used to calculate average of operations printed
max_wc=0 # used to update the current maximum wc
	# modify these to run different tests
	runs=20 # control amount of runs
	values=100 # control amount of values for each run
	max_random_value=501 # control max value

for ((j=1; j<=runs; j++)) # run outer loop for 'runs' times
do
    unique_values=() # initialize array for random values

    while [ ${#unique_values[@]} -lt ${values} ] # loop runs until 'unique values' matches desired amount of values
    do
        random_value=$((RANDOM % (max_random_value + 1) - 250)) # generate random value between 0 and 'max_random_value', then offset it by -250 and assign it to 'random_value'

        # check for duplicates
        if [[ ! " ${unique_values[@]} " =~ " $random_value " ]]; then
            unique_values+=($random_value) # if random value is not part of 'unique_values', it gets added
        fi
    done

    echo -e "${YELLOW}Running $RUN ${NC}${unique_values[@]}"
    current_wc=$($RUN "${unique_values[@]}" 2>&1 | wc -l)
    echo "operations: $current_wc"

    if [ $current_wc -gt $max_wc ]; then
        max_wc=$current_wc
    fi

    total_wc=$((total_wc + current_wc))
done

average_wc=$((total_wc / (runs)))

echo -e "${YELLOW}Average amount of operations using ${RED}$values${YELLOW} different values (out of ${RED}$runs${YELLOW} runs): ${GREEN}$average_wc${NC}"
echo -e "${YELLOW}Maximum amount of operations observed: ${GREEN}$max_wc${NC}"
