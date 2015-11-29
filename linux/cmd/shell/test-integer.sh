#!/bin/bash

# test-integer: evaluate the value of an integer

int=-5

if [ -z "$int" ]; then
    echo "int is empty." >&2
    exit 1
fi
if [ $int -eq 0 ]; then
    echo "int is zero"
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
