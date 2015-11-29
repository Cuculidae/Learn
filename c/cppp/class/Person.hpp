#ifndef PERSON_HPP
#
#define PERSON_HPP
#
#include <iostream>
#include <string>

class Person
{
    friend std::istream &read(std::istream &is, Person &p);
    friend std::ostream &print(std::ostream &os, const Person &p);

    public:
        Person();
        Person(const std::string &n, const std::string &a);
        std::string getName() const;
        std::string getAddress() const;

    private:
        std::string name;
        std::string addr;
};

std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

#endif
