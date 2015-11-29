#!/bin/bash

# test-string: evaluate the value of a string

answer=maybe

if [ -z "$answer" ]; then
    echo "There is no answer." >&2
    exit 1
fi
if [ "$answer" = "yes" ]; then
    echo "The answer is YES."
elif [ "$answer" = "no" ]; then
    echo "The answer is NO."
elif [ "$answer" = "maybe" ]; then
    echo "The answer is MAYBE."
else
    echo "The answer is UNKNOWN."
fi
