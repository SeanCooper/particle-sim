/*
 * particle.hpp
 *
 *  Created on: May 22, 2015
 *      Author: Sean Cooper
 */

#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include "cartesian.hpp"

class Particle{
	public:
		// Default Constructor
		Particle(): pos(0., 0., 0.), vel(0., 0., 0.), m(0.), r(0.), T(0.), Q(0.), s(0.) {;}

		// Generic Constructor
		template <typename TYPE>
		Particle(const TYPE & posx = 0., const TYPE & posy = 0., const TYPE & posz = 0.,
				const TYPE & velx = 0., const TYPE & vely = 0., const TYPE & velz = 0.,
				const TYPE & mass = 0., const TYPE & radius = 0., const TYPE & temperature = 0.,
				const TYPE & charge = 0., const TYPE & spin = 0.):
		pos(posx, posy, posz), vel(velx, vely, velz),
		m(mass), r(radius), T(temperature), Q(charge), s(spin) {;}

		template <typename TYPE>
		Particle(const TYPE & object) {
			*this = object; // Assignment operator
		}

		~Particle() {;}

		// Defining get and set methods
		Cartesian getpos() {
			return pos;
		}
		void setpos(Cartesian newposition) {
			pos = newposition;
		}
		double getposx() {
			return pos.getx();
		}
		double getposy() {
			return pos.gety();
		}
		double getposz() {
			return pos.getz();
		}
		Cartesian getvel() {
			return vel;
		}
		void setvel(Cartesian newvelocity) {
			vel = newvelocity;
		}
		double getvelx() {
			return vel.getx();
		}
		double getvely() {
			return vel.gety();
		}
		double getvelz() {
			return vel.getz();
		}
		double getm() {
			return m;
		}
		void setm(double newm) {
			m = newm;
		}
		double getr() {
			return r;
		}
		void setr(double newr) {
			r = newr;
		}
		double getT() {
			return T;
		}
		void setT(double newT) {
			T = newT;
		}
		double getQ() {
			return Q;
		}
		void setQ(double newQ) {
			Q = newQ;
		}
		double gets() {
			return s;
		}
		void sets(double news) {
			s = news;
		}

		// Output Functionality
		void Print(std::ostream & os) const;

	protected:
		Cartesian pos, vel;
		double m, r, T, Q, s;
};

// Allow overloading of << and >> operators in particle.cpp
std::ostream & operator<<(std::ostream & os, const Particle & var);

#endif /* PARTICLE_HPP_ */
