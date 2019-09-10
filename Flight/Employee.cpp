#include "Employee.hpp"
#include "Human.hpp"

//employee class uses inheritance from the human class

//TODO - check how many fields constructor should have
Employee::Employee(const std::string &name, int employeeNumber) :Human::Human(name) {
	this->employeeNumber = employeeNumber;
}

std::string Employee::getName() const {
	return this->name;
}
int Employee::getID() const {
	return this->employeeNumber;
}

Employee:: ~Employee(){}
