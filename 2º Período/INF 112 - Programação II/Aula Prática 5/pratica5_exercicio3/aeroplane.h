#ifndef AEROPLANE_H_
#define AEROPLANE_H_
#include <string>

class Aeroplane {
	public:
		virtual int fly();
		int get_number_of_passengers();
		float get_top_speed();
		int get_number_of_turbines();
		float get_autonomy();
		int get_size();
		std::string get_name();

	protected:
		int number_of_turbines;
		int size_in_meters;
		float autonomy_in_kilometers;
		float top_speed;
		int number_of_passengers;
		double current_speed;
		std::string name;

};

#endif /* AEROPLANE_H_ */
