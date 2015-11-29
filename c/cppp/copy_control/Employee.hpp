#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#
#include <string>
#

class Employee {
public:
    using id_type = std::size_t;
    Employee();
    Employee(const std::string s);
private:
    std::string name;
    id_type id;
    static id_type nextId; 
};

Employee::Employee(): id(nextId++) { }
Employee::Employee(const std::string s):
    name(s), id(nextId++) { }

#endif
