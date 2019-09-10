#ifndef ROUTE_HPP
#define ROUTE_HPP

#include "Country.hpp"

class Route{
public:
    Route(Country *source, Country *destination, int distance);
    Country* getSource() const;
    Country* getDestination() const;
    int getHours() const;
    virtual ~Route();
private:
    Country* source;
    Country* destination;
    unsigned int hours;
    Route& operator=(const Route& other);
    Route(const Route& other);
};

#endif
