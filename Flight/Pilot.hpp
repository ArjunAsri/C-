#ifndef PILOT_HPP
#define PILOT_HPP

#include "Employee.hpp"

class Pilot : public Employee {
public:
    enum Level {
        CAPTAIN = 0,
        CO_PILOT
    };

    Pilot(const std::string &name, int ID);
    Level getLevel() const;
    bool promote();
    bool demote();
	virtual ~Pilot();
private:
    Pilot& operator=(const Pilot& other);
    Pilot(const Pilot& other);

    // TODO add members as needed
	Level pilotLevel; //pilot level for the following class
};

#endif
