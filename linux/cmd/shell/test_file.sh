#!/bin/bash

test_file () {

    # test-file: Evaluate the status of a file
    
    file=~/.bashrc
    
    if [ -e "$file" ]; then
        if [ -f "$file" ]; then
            echo "$file is a regular file";
        fi
        if [ -d "$file" ]; then
            echo "$file is a directory"
        fi
        if [ -r "$file" ]; then
            echo "$file is readable"
        fi
        if [ -w "$file" ]; then
            echo "$file is writable"
        fi
        if [ -x "$file" ]; then
            echo "$file is executable/searchable"
        fi
    else
        echo "$file does not exist"
        return 1
    fi
    
}

test_file 
