/*
 * cartesian.cpp
 *
 *  Created on: May 10, 2015
 *      Author: Sean Cooper
 */

#include "cartesian.hpp"

void Cartesian::Print(std::ostream & os) const {
	os << "(" << x << "," << y << "," << z << ")";
}

std::ostream & operator<<(std::ostream & os, const Cartesian & var) {
	var.Print(os);
	return os;
}

double dot(Cartesian var1, Cartesian var2) {
	double xdot = var1.getx() * var2.getx();
	double ydot = var1.gety() * var2.gety();
	double zdot = var1.getz() * var2.getz();
	return xdot+ydot+zdot;
}

double abs(Cartesian var) {
	return std::pow(dot(var,var), 0.5);
}

Cartesian versor(Cartesian var) {
	return var/abs(var);
}
