# The linux command line
# Chapter 19	Regular Expressions

# phonelist.sh:
# Every time this script is executed, 
# it will append 10 random phone number of the form '(000) 000-0000'
# to the file phonelist.txt, each phone number in a line.

for i in {1..10}
do
    echo "(${RANDOM:0:3}) ${RANDOM:0:3}-${RANDOM:0:4}" >> phonelist.txt;
done
