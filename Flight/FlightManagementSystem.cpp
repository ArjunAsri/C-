#include "FlightManagementSystem.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool FlightManagementSystem::bookTicket(Route* route, Date *time, const std::string &passportNumber, int quantity) {
	bool customerFound = false;
	int availableSeats = 0;
	int indexValue = 0;
	for (unsigned int i = 0; i < customerVector.size(); i++) {
		if (customerVector[i]->getPassportNumber() == passportNumber) { //check for the customer passport number
			customerFound = true;
			indexValue = i;
			break;
		}
	}
	//cout << "customer status for customer " << customerFound << endl;
	if (customerFound) {
		for (unsigned int i = 0; i < dateVector.size(); i++) {
			if ((dateVector[i]->getDay() == time->getDay()) && (dateVector[i]->getHour() == time->getHour())) { //if the right date has been found
				if (flightsVector[i]->getRoute()->getHours() == route->getHours()) {	//then check if the correct route is present
					indexValue = i;
					//then return the available seats on the flight
				}
			}
		}
		availableSeats = this->flightsVector[indexValue]->getAvailableSeats(); // getcapacity function used to get available seats on the fight
	}

	if (availableSeats >= quantity) {
		for (unsigned int i = 0; i < dateVector.size(); i++) {
			if ((dateVector[i]->getDay() == time->getDay()) && (dateVector[i]->getHour() == time->getHour())) { //if the right date has been found
				if ((flightsVector[i]->getRoute()->getDestination() == route->getDestination())&&(flightsVector[i]->getRoute()->getSource() == route->getSource())) {	//then check if the correct route is present
					if ((flightsVector[i]->getRoute()->getHours() == 15)) {
						//cout << "//////////////////////////////////////" << endl;
						//cout << flightsVector[i]->getRoute()->getHours() << endl;
						//cout << "//////////////////////////////////////" << endl;
					}
					indexValue = i;
						//then return the available seats on the flight
				}
			}
		}
		flightsVector[indexValue]->setAvailableSeats((flightsVector[indexValue]->getAvailableSeats()) - quantity); //updating flight seats
		
		//cout << flightsVector[indexValue]->getAvailableSeats() << endl;
		int numberOfPoints = flightsVector[indexValue]->getRoute()->getHours() * quantity;
		//cout << "These are the number of points " <<numberOfPoints << endl;

		for (unsigned int i = 0; i < customerVector.size(); i++) {
			if (customerVector[i]->getPassportNumber() == passportNumber) { //check for the customer passport number
				//cout << i << "    these are customer points" << customerVector[i]->getLoyaltyPoints() << endl;
				customerVector[i]->addLoyaltyPoints(numberOfPoints); // use this to add points to right customer instance
				//cout <<i << "  these are customer points" << customerVector[i]->getLoyaltyPoints() << endl;
			}
		}
	
		//customerVector[indexValue]->addLoyaltyPoints(numberOfPoints);
		return true;
	}

	//int numberOfPoints = route->getHours() * quantity;
	//customerVector[indexValue]->addLoyaltyPoints(numberOfPoints);
	return false;
}
//add customer method,each customer must have a unique id 
//the function checks for the customer id before addin to the vector
bool FlightManagementSystem::addCustomer(Customer *customer) {
	for (unsigned int i = 0; i < customerVector.size(); i++) {
		Customer* customerToCheck = customerVector[i];
		if (customer->getPassportNumber() == customerToCheck->getPassportNumber()) {
			return false;
		}
	}
	this->customerVector.push_back(customer); //if customer id is found to be unique it is then added to the vector
	return true;
}


//This function returns the capacity of the flight based on the flight route and time
int FlightManagementSystem::getCapacity(const Route* route, const Date* time) const {
	for (unsigned int i = 0; i < dateVector.size(); i++) {
		if ((dateVector[i]->getDay() == time->getDay()) && (dateVector[i]->getHour() == time->getHour())) { //if the right date has been found
			if ((flightsVector[i]->getRoute()->getDestination() == route->getDestination())&& (flightsVector[i]->getRoute()->getSource() == route->getSource())) {	//then check if the correct route is present
				//cout << flightsVector[i]->getAvailableSeats() << endl;
				return flightsVector[i]->getAvailableSeats();	//then return the available seats on the flight
			}
		}
	}
	
	return -1;
}
void FlightManagementSystem::addFlight(Flight* flight, Date* time) {
	if (flightsVector.size() == dateVector.size()) {
		this->flightsVector.push_back(flight);
		this->dateVector.push_back(time);
	}
	else if (flightsVector.size() > dateVector.size()) {
		flightsVector.pop_back();
		this->flightsVector.push_back(flight);
		this->dateVector.push_back(time);
	}
	else {
		dateVector.pop_back();
		this->flightsVector.push_back(flight);
		this->dateVector.push_back(time);
	}

}
int FlightManagementSystem::getCustomerPoints(const std::string &passportNumber) const{

	for (unsigned int i = 0; i < customerVector.size(); i++) {
		if (customerVector[i]->getPassportNumber() == passportNumber) { //check for the customer passport number
			//cout << i << "customer found and their points" << customerVector[i]->getLoyaltyPoints() << endl;
			return customerVector[i]->getLoyaltyPoints();
		}
	}
	return -1;
}

std::vector<Flight *>  FlightManagementSystem::getFlights() const{
	return this->flightsVector;
}
std::vector<Customer *>  FlightManagementSystem::getCustomers() const {
	return this->customerVector;
}


FlightManagementSystem::FlightManagementSystem() {
}

std::string FlightManagementSystem::author() {

    return "akmu999";
}

//destructor to delete all the instances created of various classes: for loops used to delete the instances
FlightManagementSystem::~FlightManagementSystem() {
	for (unsigned int i = 0; i < flightsVector.size(); i++) {
		Flight* flight = flightsVector[i]; // the returned value is of type pointer
		Airplane* airplane= flight->getAirplane();
		//Route* route = flight->getRoute();
		//delete route;
		//route = 0;
		delete airplane;
		airplane = 0;
		delete flight; //reclaiming memory from heap
		flight = 0; // pointer now points to null
	}

	for (unsigned int i = 0; i < dateVector.size(); i++) {
		Date* date = dateVector[i]; // the returned value is of type pointer
		delete date; //reclaiming memory from heap
		date = 0; // pointer now points to null
	}

	for (unsigned int i = 0; i < customerVector.size(); i++) {
		Customer* customer = customerVector[i]; // the returned value is of type pointer
		delete customer; //reclaiming memory from heap
		customer = 0; // pointer now points to null
	}


}




