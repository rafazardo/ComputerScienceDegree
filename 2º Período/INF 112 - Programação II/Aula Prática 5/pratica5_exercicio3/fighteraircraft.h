#ifndef FIGHTERAIRCRAFT_H_
#define FIGHTERAIRCRAFT_H_
#include "aeroplane.h"
#include <string>

class Fighter_Aircraft: public Aeroplane {
	public:
		Fighter_Aircraft(std::string name, int number_of_passengers, int number_of_turbines, int size_in_meters, float autonomy_in_kilometers, float top_speed, int number_of_missiles);
		void shoot();
		virtual int fly() override;
		void fly_at_max_speed();
		int get_number_of_missiles();
		void shoot(int number_of_missiles_to_fire) ;

	private:
		int number_of_missiles;

};


#endif /* FIGHTERAIRCRAFT_H_ */
