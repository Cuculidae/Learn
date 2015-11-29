#!/bin/bash

# generate random string

N=$1
i=0;
declare -a arr
for c in {A..Z}; do arr[i]=$c; i=$((++i)); done
for c in {a..z}; do arr[i]=$c; i=$((++i)); done

# generate random string of length N
for ((i=0; i<N; ++i))
do
   d=$(($RANDOM % 52))
   printf ${arr[$d]};
done
printf "\n"
