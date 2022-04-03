#include "fighteraircraft.h"
#include <iostream>
#include <string>

Fighter_Aircraft::Fighter_Aircraft(std::string name, int number_of_passengers, int number_of_turbines, int size_in_meters, float autonomy_in_kilometers, float top_speed, int number_of_missiles) {
	this->number_of_missiles = number_of_missiles;
	this->name = name;
	this->number_of_turbines = number_of_turbines;
	this->size_in_meters = size_in_meters;
	this->autonomy_in_kilometers = autonomy_in_kilometers;
	this->top_speed = top_speed;
	this->number_of_passengers = number_of_passengers;
	this->current_speed = 0;
}


void Fighter_Aircraft::shoot() {
	number_of_missiles = number_of_missiles-1;
}

int Fighter_Aircraft::get_number_of_missiles() {
	return number_of_missiles;
}

void Fighter_Aircraft::shoot(int number_of_missiles_to_fire) {
	number_of_missiles = number_of_missiles-number_of_missiles_to_fire;
}


void Fighter_Aircraft::fly_at_max_speed() {
	current_speed = top_speed;
}

int Fighter_Aircraft::fly() {
	current_speed = number_of_turbines*(700 + size_in_meters);
	if (current_speed > top_speed) {
		current_speed = top_speed;
	}

	return current_speed;
}


