/*
 * particle.cpp
 *
 *  Created on: May 22, 2015
 *      Author: Sean Cooper
 */

#include "particle.hpp"

void Particle::Print(std::ostream & os) const {
	Particle var(*this);
	os 	<< "Position: (" << var.getposx() << "," << var.getposy() << "," << var.getposz() << ")\n"
		<< "Velocity: (" << var.getvelx() << "," << var.getvely() << "," << var.getvelz() << ")\n"
		<< "Mass: " << m << "\n"
		<< "Radius: " << r << "\n"
		<< "Temperature: " << T << "\n"
		<< "Charge: " << Q << "\n"
		<< "Spin: " << s;
}

std::ostream & operator<<(std::ostream & os, const Particle & var) {
	var.Print(os);
	return os;
}
