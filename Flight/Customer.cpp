#include "Customer.hpp"

Customer::Customer(const std::string &name, const std::string &passportNumber) : Human(name) {
	this->passportNumber = passportNumber;
	this->loyaltyPoints = 0;
}

void Customer::addLoyaltyPoints(int points) {
	this->loyaltyPoints += points;
}

void Customer::decreaseLoyaltyPoints(int points) {
	this->loyaltyPoints -= points;
	if (this->loyaltyPoints < 0) {
		this->loyaltyPoints = 0; // if the loyality points go below 0 they will be reset to 0
	}
}

int Customer::getLoyaltyPoints() const {
	return this->loyaltyPoints;
}

std::string Customer::getPassportNumber() const {
    return this->passportNumber;
}


Customer:: ~Customer(){}

