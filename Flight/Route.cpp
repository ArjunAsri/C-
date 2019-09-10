#include "Route.hpp"

Route::Route(Country* source, Country* destination, int hours) : source(source), destination(destination), hours(hours){
}

Country* Route::getSource() const{
    return source;
}

Country* Route::getDestination() const{
    return destination;
}

int Route::getHours() const{
    return hours;
}

Route::~Route(){
    delete source;
    delete destination;
}
