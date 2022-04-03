#ifndef FLEET_H_
#define FLEET_H_
#include "aeroplane.h"
#include "fighteraircraft.h"
#include "jetplane.h"
#include <vector>

class Fleet {
	public:
		std::vector<Aeroplane*> instantiate_fleet(int number_of_planes);
		void print_fleet_data(std::vector<Aeroplane*>);
};


#endif /* FIGHTERAIRCRAFT_H_ */
