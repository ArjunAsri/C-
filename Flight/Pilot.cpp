#include "Pilot.hpp"

Pilot::Pilot(const std::string &name, int ID):Employee::Employee(name,ID){
	this->pilotLevel = CO_PILOT;
}

Pilot::Level Pilot::getLevel() const {
	return this->pilotLevel;
}

bool Pilot::promote() {
	if (this->pilotLevel == CO_PILOT) {
		this->pilotLevel = CAPTAIN;
		return true;
	}
	return false;
}

bool Pilot::demote() {
	if (this->pilotLevel == CAPTAIN) {
		this->pilotLevel = CO_PILOT;
		return true;
	}
	return false;
}

Pilot::~Pilot(){}
