#include "jetplane.h"
#include <string>

Jet_Plane::Jet_Plane(std::string name, int number_of_passengers, int number_of_turbines, int size_in_meters, float autonomy_in_kilometers, float top_speed, std::string company) {
	this->company = company;
	this->number_of_turbines = number_of_turbines;
	this->size_in_meters = size_in_meters;
	this->autonomy_in_kilometers = autonomy_in_kilometers;
	this->top_speed = top_speed;
	this->number_of_passengers = number_of_passengers;
	this->current_speed = 0;
	this->name = name;
}

void Jet_Plane::stop_and_get_passengers(int number_of_extra_passengers) {
	number_of_passengers += number_of_extra_passengers;
}

std::string Jet_Plane::get_company() {
	return this->company;
}

void Jet_Plane::fly_with_max_capacity() {
	current_speed = top_speed/3;
}

int Jet_Plane::fly() {
	current_speed = number_of_turbines*(300+size_in_meters)*(number_of_passengers/500);
	if (current_speed > top_speed) {
		current_speed = top_speed;
	}

	return current_speed;
}

