
#ifndef FLIGHTATTENDANT_HPP
#define FLIGHTATTENDANT_HPP

#include "Employee.hpp"
#include "Country.hpp"
#include <vector>

class FlightAttendant : public Employee {
private:
	std::vector<Country::Language> languageCollection; // vector for every flight attendant instance using enum language from Country class

public:
	FlightAttendant(const std::string &name, int employeeNumber);
	bool canSpeak(Country::Language language)const;
	void addLanguage(Country::Language Language) ; //push_back to the language vector
	virtual ~FlightAttendant();
};

#endif
