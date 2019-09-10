
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Human.hpp"

class Employee : public Human {
protected:
	int employeeNumber;
public:
	Employee(const std::string &name, int employeeNumber);
	enum EmployeeType {PILOT,FLIGHT_ATTENDANTS};
	std::string getName() const;
	int getID() const;
	virtual ~Employee();
};

#endif
