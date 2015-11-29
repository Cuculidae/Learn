wordcount: wordcount.cpp
	g++ -o wordcount wordcount.cpp -std=c++11
pair: pair.cpp
	g++ -o pair pair.cpp -std=c++11
map: map.cpp
	g++ -o map map.cpp -std=c++11
set: set.cpp
	g++ -o set set.cpp -std=c++11
multiset: multiset.cpp Sales_data.o
	g++ -o multiset multiset.cpp -std=c++11
Sales_data.o: Sales_data.hpp Sales_data.cpp
	g++ -c Sales_data.cpp -std=c++11
insert: insert.cpp
	g++ -o insert insert.cpp -std=c++11
erase: erase.cpp
	g++ -o erase erase.cpp -std=c++11
subscript: subscript.cpp
	g++ -o subscript subscript.cpp -std=c++11
find: find.cpp
	g++ -o find find.cpp -std=c++11
lower_bound: lower_bound.cpp
	g++ -o lower_bound lower_bound.cpp -std=c++11
equal_range: equal_range.cpp
	g++ -o $@ $@.cpp -std=c++11
word_transform: word_transform.cpp
	g++ -o word_transform word_transform.cpp -std=c++11
unordered_map: unordered_map.cpp
	g++ -o unordered_map unordered_map.cpp -std=c++11
unordered_multiset: unordered_multiset.cpp
	g++ -o unordered_multiset unordered_multiset.cpp Sales_data.o -std=c++11
