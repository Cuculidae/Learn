#!/bin/bash

# test-integer2: evaluate the value of an integer.

int=-5

if [[ "$int" =~ ^-?[0-9]+$ ]]; then
    if [ $int -eq 0 ]; then
        echo "int is zero."
    else
        if [ $int -lt 0 ]; then
            echo "int is negative"
        else
            echo "int is positive"
        fi
        if [ $((int % 2)) -eq 0 ]; then
            echo "int is even."
        else
            echo "int is odd."
        fi
    fi
else
    echo "int is not an integer." >&2
    exit 1
fi
