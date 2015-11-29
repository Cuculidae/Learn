#!/bin/bash

# generate random pattern and random string
# as testing input for SubstrCMP

M=$1
N=$2
i=0;
declare -a arr
for c in {A..Z}; do arr[i]=$c; i=$((++i)); done
for c in {a..z}; do arr[i]=$c; i=$((++i)); done

# generate pattern string
for ((i=0; i<M; ++i))
do
   d=$(($RANDOM % 52))
   printf ${arr[$d]};
done
printf "\n"
   
# generate text string
for ((i=0; i<N; ++i))
do
   d=$(($RANDOM % 52))
   printf ${arr[$d]};
done
