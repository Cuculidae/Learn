#!/bin/bash

# read-ifs: read fields from a file

file=/etc/passwd

read -p "Enter a username > " user_name

file_info=$(grep "^$user_name:" $file)

if [ -n "$file_info" ]; then
    IFS=':' read usr pw uid gid name home shell <<< "$file_info"
    echo "User =        '$usr'"
    echo "UID =         '$uid'"
    echo "GID =         '$gid'"
    echo "Full Name =   '$name'"
    echo "Home Dir. =   '$home'"
    echo "Shell =       '$shell'"
else
    echo "No such user '$user_name'" >&2
    exit 1
fi
