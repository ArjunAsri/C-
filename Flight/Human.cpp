#include "Human.hpp"

Human::Human(const std::string &name) {
	this->name = name;
}

std::string Human::getName() const {
    return this->name;
}

Human::~Human() {
}
