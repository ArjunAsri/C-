#include "Date.hpp"
#include <iostream>
#include <string>
Date::Date(int day, int hour) {
	if (day >= 0) {						//if day is a positive number only then save the value, else set it to 0
		this->day = day;
	}
	else {
		this->day = 0;
	}
	if ((hour >= 0) && (hour <= 23)) { // if hour is a valid value only then save the value else set it to 0
		this->hour = hour;
	}
	else {
		this->hour = 0;
	}
}

int Date::getHour() const {
	return this->hour;
}

int Date::getDay() const {
	return this->day;
}

//function updates the values for day and hour
void Date::changeDateTo(int day, int hour) {
	if ((day >= 0) && (hour >= 0) && (hour < 24)) {
	this->day = day;
	this->hour = hour;
	}
}

// this function calculates the new date based on the sum of the previous date value and the new added time
void Date::addTime(int count) {
	int totalNumbeOfHours = 0;
	int newDay, newHour = 0;
	totalNumbeOfHours = (this->day * 24) + this->hour;
 	if (count >= 0) {
		totalNumbeOfHours += count;
		newDay = totalNumbeOfHours / 24;
		newHour = totalNumbeOfHours % 24;
		this->changeDateTo(newDay, newHour);
	}
	//std::cout << this->day << std::endl; used to test the code
}

bool Date::isLessThan(const Date &other) const {
	if (this->day < other.day) {// if the respective day is less than the other day  value return true
		return true;
	}
	else if (this->day == other.day) { // if day is same then compare the hour value
		if (this->hour < other.hour) {  //if the hour value of the respective is less than the hour of the other then return true
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;   // all other cases return false/
	}
}


Date:: ~Date() {}
