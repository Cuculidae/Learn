X: X.cpp
	g++ -o X X.cpp -std=c++11
HasPtr: HasPtr.hpp HasPtr.cpp
	g++ -c HasPtr.cpp -std=c++11
numbered: numbered.cpp
	g++ -o numbered numbered.cpp
Foo: Foo.cpp
	g++ -o Foo Foo.cpp -std=c++11
Sales_data.o: Sales_data.cpp Sales_data.hpp
	g++ -c Sales_data.cpp -std=c++11
Employee.o: Employee.cpp Employee.hpp
	g++ -c Employee.cpp -std=c++11
HasPtrP: HasPtrP.cpp HasPtrP.cpp
	g++ -c HasPtrP.cpp -std=c++11
Message.o: Message.cpp Message.hpp
	g++ -c Message.cpp -std=c++11
delete: delete.cpp
	g++ -o $@ $@.cpp -std=c++11
rref: rref.cpp
	g++ -o $@ $@.cpp -std=c++11
move: move.cpp
	g++ -o $@ $@.cpp -std=c++11
StrVec.o: StrVec.hpp StrVec.cpp
	g++ -c StrVec.cpp -std=c++11
test_StrVec: test_StrVec.cpp StrVec.o
	g++ -o $@ $@.cpp StrVec.o -std=c++11
