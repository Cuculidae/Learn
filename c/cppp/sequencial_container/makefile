array: array.cpp
	g++ -o array array.cpp -std=c++11
swap: swap.cpp
	g++ -o swap swap.cpp -std=c++11
assign: assign.cpp
	g++ -o assign assign.cpp -std=c++11
capacity: capacity.cpp
	g++ -o capacity capacity.cpp -std=c++11

erase: erase.cpp
	g++ -o erase erase.cpp -std=c++11

resize: resize.cpp
	g++ -o resize resize.cpp -std=c++11

push_front: push_front.cpp
	g++ -o push_front push_front.cpp -std=c++11
emplace: emplace.cpp Sales_data.o
	g++ -o emplace emplace.cpp Sales_data.o -std=c++11
Sales_data.o: Sales_data.hpp Sales_data.cpp
	g++ -c Sales_data.cpp

stack: stack.cpp
	g++ -o $@ $@.cpp 

queue: queue.cpp
	g++ -o $@ $@.cpp

priority_queue: priority_queue.cpp
	g++ -o $@ $@.cpp 
