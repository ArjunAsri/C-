#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include "Pilot.hpp"
#include "Route.hpp"
#include "FlightAttendant.hpp"
#include "Airplane.hpp"
#include "Date.hpp"

class Flight{
private:
	// TODO add instance members
	int availableSeats;
	std::vector<Pilot *> pilotVector;			// vector for containing the flight pilots for the respective flight
	std::vector<FlightAttendant *> flightAttendantVector;	//vector for containing the flight attendants for the respective flight
	Route *flightRoute; //flight route
	Airplane* flightAirplane; // flight airplane
	bool pilotTeamAlreadyAssigned; // boolean to check if the pilot team has already been assigned or not
	bool flightAttendantsAlreadyAssigned; // boolean to check if the flight attendants have already been assigned or not
	
    Flight& operator=(const Flight& other);
    Flight(const Flight& other);
public:
    Flight(Route *route, Airplane* airplane);

    bool setFlightAttendants(vector<FlightAttendant*> flightAttendants);
    bool setPilots(vector<Pilot*> pilots);

    bool bookTicket(int quantity);
    int getAvailableSeats() const;
	void setAvailableSeats(int seats);
    Route* getRoute() const;
    Airplane* getAirplane() const;
    vector<Pilot *> getPilots() const;
    vector<FlightAttendant *> getFlightAttendants() const;

    virtual ~Flight();
};

#endif
