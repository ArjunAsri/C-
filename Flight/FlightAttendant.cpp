#include "FlightAttendant.hpp"
#include "Country.hpp"


//flight attendant constructor uses employee constructor to set the employee numane and employee number
FlightAttendant::FlightAttendant(const std::string &name, int employeeNumber):  Employee::Employee(name,employeeNumber) {
}
bool FlightAttendant::canSpeak(Country::Language language)const {
	for (unsigned int i = 0; i < languageCollection.size(); i++) {
		if (language == languageCollection[i]) {
			return true;
		}
	}
	return false;
}
void FlightAttendant::addLanguage(Country::Language language)  {
	this->languageCollection.push_back(language);//push_back to the language vector
} 
FlightAttendant:: ~FlightAttendant() {}

