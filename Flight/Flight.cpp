#include "Flight.hpp"


#include <string>
#include <iostream>
// TODO implement the constructor, destructor and methods
Flight::Flight(Route *route, Airplane* airplane) {
	this->flightRoute = route;		//saving flight route pointer;
	this->flightAirplane = airplane;	//saving the airplane of type airplane pointer
	this->pilotTeamAlreadyAssigned = false; // intialising the status of the cockpit crew assignment for the flight
	this->flightAttendantsAlreadyAssigned = false; //initailising the status of the crew assignemnt for the flight

	if (flightRoute->getHours() >= 8) {
		this->availableSeats = airplane->getCapacity()-8; // reducing the plane capacity based on if the flight route is long or short
	}
	else {
		this->availableSeats = airplane->getCapacity() - 3; // reducing the plane capacity based on if the flight route is long or short
	}
}

bool Flight::setFlightAttendants(vector<FlightAttendant*> flightAttendants) {

	//int previousIndex = -1; //index value is set to -1 so that when the vector is tested from index 0 it will not create problems


	int englishSpeakersCount = 0;
	int sourceSpeakersCount = 0;
	int destinationSpeakersCount = 0;

	int sum = 0;
	Country::Language languageToCheck1 = (flightRoute->getSource())->getLanguage();	//source language
	Country::Language languageToCheck2 = (flightRoute->getDestination())->getLanguage(); //destination language

	//check if the flight is long route or short route and if the flight attendants have already been assigned or not
	if ((flightRoute->getHours() >= 8) && (!(this->flightAttendantsAlreadyAssigned))) {
		
		//this is a long flight: 2 cabin crew needed for each language 
		//check if the size of the provided flight attendant vector is 6
		if (flightAttendants.size() == 6){
			int array[6] = {0};
			//cout << "6 flgiht attendants process" << endl;
			for (unsigned int i = 0; i < flightAttendants.size(); i++) {
				//if flight attendant can speak english then increase english speakers count by 1
				if ((flightAttendants[i]->canSpeak(Country::ENGLISH))){
					array[i] += 1;
					englishSpeakersCount++;
				}
				//if the flight attendant can speak the source language then increase the count by 1
				if ((flightAttendants[i]->canSpeak(languageToCheck1))) {
					//cout << "CAN SPEAK " << languageToCheck1 <<endl;
					array[i] += 10;
					sourceSpeakersCount++;
				}
				//if the flight attendant can speak the destination language then increase the count by 1
				if ((flightAttendants[i]->canSpeak(languageToCheck2))) {
					array[i] += 20;	//this part not used for long flight crew language check
					destinationSpeakersCount++;
				}
			}


			//if there are 2 speakers for each of the required languages then the flight attendants are good for the flight
			if ((englishSpeakersCount >= 2) && (sourceSpeakersCount >= 2) && (destinationSpeakersCount >= 2)) {
				this->flightAttendantsAlreadyAssigned = true;
				this->flightAttendantVector = flightAttendants;
				return true;
			}
		}
	}
	//if the flight is short flight then check that the provided vector is of the right size and that the flight attendant have already been assigned or not
	else {
		if ((flightAttendants.size() == 3) && (!(this->flightAttendantsAlreadyAssigned))) {
			int array[3] = { 0 };
			
			//this is short flight: 1 cabin crew needed for each language
			for (unsigned int i = 0; i < flightAttendants.size(); i++) {
				//check to see if the flight attendant can speak english
				if (flightAttendants[i]->canSpeak(Country::ENGLISH)) {
					array[i] += 1; //each language has a different amount of value assigned to it, this is used to tell which combination is right after the for loop
					englishSpeakersCount++; 
				}
				//different languages to be checked
				if (flightAttendants[i]->canSpeak(languageToCheck1)) {
					array[i] += 10;
					sourceSpeakersCount++;
				}
				if (flightAttendants[i]->canSpeak(languageToCheck2)) {
					array[i] += 20;
					destinationSpeakersCount++;
				}
				
			}

			
			//check if the scores for the different language match these combinations or not: if they do then return false
			if (((array[0] == 10) && (array[1] == 10) && (array[2] == 21)) || ((array[0] == 10) && (array[1] == 21) && (array[2] == 10)) 
				|| ((array[0] == 21) && (array[1] == 10) && (array[2] == 10)) || ((array[0] ==20) && (array[1] == 20) && (array[2] ==11))
				||((array[0] == 20) && (array[1] == 11) && (array[2] == 20)) || ((array[0] == 11) && (array[1] == 20) && (array[2] == 20))) {
				return false;
			}// check if the array combination for the languages matches anyone of these: if yes then return true
			else if (((array[0] >= 1)&& (array[1] >= 10) && (array[2] >= 20))|| ((array[0] >= 10) && (array[1] >= 1) && (array[2] >= 20))
				|| ((array[0] >= 10) && (array[1] >= 20) && (array[2] >= 1))|| ((array[0] >= 20) && (array[1] >= 10) && (array[2] >= 1))
				|| ((array[0] >= 1) && (array[1] >= 20) && (array[2] >= 10))||((array[0] >= 20) && (array[1] >= 1) && (array[2] >= 10)) ){
				//cout << "STATEMENT EVALUATED TO TRUE" << endl;
				this->flightAttendantsAlreadyAssigned = true;
				this->flightAttendantVector = flightAttendants; //asign the flight attendant vector
				return true;
			}
		}
	}
	if (flightAttendantsAlreadyAssigned) {
		return false;
	}
	return false;
}

/*setPilots function is used to check if the pilots assigned to the flight are right or not*/
bool Flight::setPilots(vector<Pilot*> pilots) {
	//check to see if the flight is 8 hours long and that the pilots have not already been assigned
	if ((flightRoute->getHours() >= 8) && !(this->pilotTeamAlreadyAssigned)){
		if (pilots.size() == 4) {
			int captainCount = 0; int copilotCount = 0;
			//check the number of captains in the provided pilot vector
			for (unsigned int i = 0; i < pilots.size(); i++) {
				if (Pilot::CAPTAIN == pilots[i]->getLevel()) {
					captainCount++;
				}
			}
			//check the number of cop pilots in the provided pilot vector
			for (unsigned int i = 0; i < pilots.size(); i++) {
				if (Pilot::CO_PILOT == pilots[i]->getLevel()) {
					copilotCount++;
				}
			}
			//if there are 2 of them each then the pilot vector is correct: it is then assigned
			if ((copilotCount == 2) && (captainCount == 2)) {
				this->pilotTeamAlreadyAssigned = true;
				this->pilotVector = pilots;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		//check if the pilot vector is 2 and that it already has not been assigned
		if ((pilots.size() == 2) &&(!(this->pilotTeamAlreadyAssigned))) {
			int captainCount = 0; int copilotCount = 0;
			for (unsigned int i = 0; i < pilots.size(); i++) {			//check using a loop the number of captains on the flight
				if (Pilot::CAPTAIN == pilots[i]->getLevel()) {
					captainCount++;
				}
			}
			for (unsigned int i = 0; i < pilots.size(); i++) {	//check using a loop the number of co-pilots on the flight
				if (Pilot::CO_PILOT == pilots[i]->getLevel()) {
					copilotCount++;
				}
			}
			if ((copilotCount == 1) && (captainCount == 1)) {	//if the registered count of captains and co-pilots is equal to 1 each
				this->pilotTeamAlreadyAssigned = true;
				this->pilotVector = pilots;
				return true;									//then return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	
	}
	if (pilotTeamAlreadyAssigned) {
		return false;
	}
}

bool Flight::bookTicket(int quantity) {
	return false;
}



int Flight::getAvailableSeats() const {

	return this->availableSeats;
}

void Flight::setAvailableSeats(int seats) {
	this->availableSeats = seats; 
}


Route* Flight::getRoute() const {
	return this->flightRoute; // returing the flight route
}
Airplane* Flight::getAirplane() const {
	return this->flightAirplane;			//return Airplane vector
}
vector<Pilot *> Flight::getPilots() const {
	return this->pilotVector;		//return pilot vector
}
vector<FlightAttendant *> Flight::getFlightAttendants() const {
	return this->flightAttendantVector;
}

Flight::~Flight() {}
