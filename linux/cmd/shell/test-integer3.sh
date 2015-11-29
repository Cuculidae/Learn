#!/bin/bash

# test-integer2: evaluate the value of an integer.

min=1
max=100

int=50

if [[ "$int" =~ ^-?[0-9]+$ ]]; then
    if [[ int -ge min && int -le max ]]; then
        echo "$int is within $min to $max."
    else
        echo "$int is out of range."
    fi
else
    echo "int is not an integer." >&2
    exit 1
fi
