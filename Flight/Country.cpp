
#include "Country.hpp"


//constructor stores name of the country as string and language as enum; currently can only store one language
Country::Country(const string &name, Language language): Name(name), countryLanguage(language) {

}

//return function to return the language type which is enum
Country::Language Country::getLanguage() const {
    return this->countryLanguage; 
}

//return function to return the name of the country; return type is string
std::string Country::getName() const {
    return this->Name;
}

Country::~Country() {
}
