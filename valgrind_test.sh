#!/bin/bash

echo "Executing valgrind:"
sleep 2s

# valgrind ./so_long "tests/invalid/map-empty-line1.ber"
# valgrind ./so_long "tests/invalid/map-empty-line2.ber"
# valgrind ./so_long tests/invalid/map-empty-line3.ber
# valgrind ./so_long tests/invalid/map-empty-line4.ber
# valgrind ./so_long tests/invalid/map-extra-E-1.ber
# valgrind ./so_long tests/invalid/map-extra-E-2.ber
# valgrind ./so_long tests/invalid/map-extra-E-3.ber
# valgrind ./so_long tests/invalid/map-extra-E-4.ber
# valgrind ./so_long tests/invalid/map-extra-P-1.ber
# valgrind ./so_long tests/invalid/map-extra-P-2.ber
# valgrind ./so_long tests/invalid/map-extra-P-3.ber
# valgrind ./so_long tests/invalid/map-extra-P-4.ber
# valgrind ./so_long tests/invalid/map-extra-parameter-1.ber
# valgrind ./so_long tests/invalid/map-extra-parameter-2.ber
# valgrind ./so_long tests/invalid/map-extra-parameter-3.ber
# valgrind ./so_long tests/invalid/map-extra-parameter-4.ber
# valgrind ./so_long tests/invalid/map-extra-parameter-5.ber
# valgrind ./so_long tests/invalid/map-invalid-extension
# valgrind ./so_long tests/invalid/map-missing-C-1.ber
# valgrind ./so_long tests/invalid/map-missing-C-2.ber
# valgrind ./so_long tests/invalid/map-missing-C-3.ber
# valgrind ./so_long tests/invalid/map-missing-E-1.ber
# valgrind ./so_long tests/invalid/map-missing-E-2.ber
# valgrind ./so_long tests/invalid/map-missing-E-3.ber
# valgrind ./so_long tests/invalid/map-missing-P-1.ber
# valgrind ./so_long tests/invalid/map-missing-P-2.ber
# valgrind ./so_long tests/invalid/map-missing-P-3.ber
# valgrind ./so_long tests/invalid/map-missing-P-4.ber
# valgrind ./so_long tests/invalid/map-missing-W-1.ber
# valgrind ./so_long tests/invalid/map-missing-W-2.ber
# valgrind ./so_long tests/invalid/map-missing-W-3.ber
# valgrind ./so_long tests/invalid/map-missing-W-4.ber
# valgrind ./so_long tests/invalid/map-missing-W-5.ber
# valgrind ./so_long tests/invalid/map-not-rectangular-1.ber
# valgrind ./so_long tests/invalid/map-not-rectangular-2.ber
# valgrind ./so_long tests/invalid/map-not-rectangular-3.ber
# valgrind ./so_long tests/invalid/map-not-rectangular-4.ber
# valgrind ./so_long tests/valid/map_small.ber
# valgrind ./so_long tests/valid/map-square.ber
# valgrind ./so_long tests/valid/map1.ber
# valgrind ./so_long tests/valid/map2.ber
# valgrind ./so_long tests/valid/map3.ber
# valgrind ./so_long tests/valid/map4.ber
# valgrind ./so_long tests/valid/map5.ber

valgrind_commands=(
    "./so_long \"tests/invalid/map-empty-line1.ber\""
    "./so_long \"tests/invalid/map-empty-line2.ber\""
    "./so_long tests/invalid/map-empty-line3.ber"
    "./so_long tests/invalid/map-empty-line4.ber"
    "./so_long tests/invalid/map-extra-E-1.ber"
    "./so_long tests/invalid/map-extra-E-2.ber"
    "./so_long tests/invalid/map-extra-E-3.ber"
    "./so_long tests/invalid/map-extra-E-4.ber"
    "./so_long tests/invalid/map-extra-P-1.ber"
    "./so_long tests/invalid/map-extra-P-2.ber"
    "./so_long tests/invalid/map-extra-P-3.ber"
    "./so_long tests/invalid/map-extra-P-4.ber"
    "./so_long tests/invalid/map-extra-parameter-1.ber"
    "./so_long tests/invalid/map-extra-parameter-2.ber"
    "./so_long tests/invalid/map-extra-parameter-3.ber"
    "./so_long tests/invalid/map-extra-parameter-4.ber"
    "./so_long tests/invalid/map-extra-parameter-5.ber"
    "./so_long tests/invalid/map-invalid-extension"
    "./so_long tests/invalid/map-missing-C-1.ber"
    "./so_long tests/invalid/map-missing-C-2.ber"
    "./so_long tests/invalid/map-missing-C-3.ber"
    "./so_long tests/invalid/map-missing-E-1.ber"
    "./so_long tests/invalid/map-missing-E-2.ber"
    "./so_long tests/invalid/map-missing-E-3.ber"
    "./so_long tests/invalid/map-missing-P-1.ber"
    "./so_long tests/invalid/map-missing-P-2.ber"
    "./so_long tests/invalid/map-missing-P-3.ber"
    "./so_long tests/invalid/map-missing-P-4.ber"
    "./so_long tests/invalid/map-missing-W-1.ber"
    "./so_long tests/invalid/map-missing-W-2.ber"
    "./so_long tests/invalid/map-missing-W-3.ber"
    "./so_long tests/invalid/map-missing-W-4.ber"
    "./so_long tests/invalid/map-missing-W-5.ber"
    "./so_long tests/invalid/map-not-rectangular-1.ber"
    "./so_long tests/invalid/map-not-rectangular-2.ber"
    "./so_long tests/invalid/map-not-rectangular-3.ber"
    "./so_long tests/invalid/map-not-rectangular-4.ber"
    "./so_long tests/valid/map_small.ber"
	"./so_long tests/valid/map-square.ber"
	"./so_long tests/valid/map1.ber"
	"./so_long tests/valid/map2.ber"
	"./so_long tests/valid/map3.ber"
	"./so_long tests/valid/map4.ber"
    "./so_long tests/valid/map5.ber"
)

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

for cmd in "${valgrind_commands[@]}"; do
    echo "Running: $cmd"
    valgrind_output=$(valgrind --leak-check=full $cmd 2>&1)
    if  echo "$valgrind_output" | grep -q 'definitely lost'; then
        echo -e "${RED}LEAKS KO (Definitely lost)${NC}"
    elif  echo "$valgrind_output" | grep -q 'indirectly lost'; then
        echo -e "${RED}LEAKS KO (Indirectly lost)${NC}"
    elif  echo "$valgrind_output" | grep -q 'possibly lost'; then
        echo -e "${RED}LEAKS KO (Possibly lost) ${NC}"
    elif  echo "$valgrind_output" | grep -q 'still reachable'; then
        echo -e "${RED}LEAKS KO (Still reachable) ${NC}"
    else
        echo -e "${GREEN}LEAKS OK${NC}"
    fi
done

