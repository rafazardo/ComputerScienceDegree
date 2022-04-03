#ifndef JETPLANE_H_
#define JETPLANE_H_
#include <string>
#include "aeroplane.h"

class Jet_Plane: public Aeroplane {
	public:
	    Jet_Plane(std::string name, int number_of_passengers, int number_of_turbines, int size_in_meters, float autonomy_in_kilometers, float top_speed, std::string company);
		virtual int fly() override;
		void stop_and_get_passengers(int number_of_extra_passengers);
		std::string get_company();
		void fly_with_max_capacity();

	private:
		std::string company;
};

#endif /* JETPLANE_H_ */
