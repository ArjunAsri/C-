#ifndef FLIGHTMANAGEMENTSYSTEM_HPP
#define FLIGHTMANAGEMENTSYSTEM_HPP

#include <vector>
#include <string>

#include "Flight.hpp"
#include "Customer.hpp"

class FlightManagementSystem {

private:
	std::vector <Customer*> customerVector; //this vector collection is uesd to loop up customer loyality points
	std::vector<Flight *> flightsVector;	//this vector stores flight instances' pointers

	std::vector<Date *> dateVector; //dateVector stores date instance pointers: can be used to get the day and hour knowledge

public:
    FlightManagementSystem();

    static std::string author();
    bool bookTicket(Route* route, Date *time, const std::string &passportNumber, int quantity);
    bool addCustomer(Customer *customer);

    int getCapacity(const Route* route, const Date* time) const;
    void addFlight(Flight* flight, Date* time);
    int getCustomerPoints(const std::string &passportNumber) const;

    std::vector<Flight *> getFlights() const;
    std::vector<Customer *> getCustomers() const;

    virtual ~FlightManagementSystem();
};

#endif
