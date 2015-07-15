/*
 * cartesian.hpp
 *
 *  Created on: May 9, 2015
 *      Author: Sean Cooper
 */

/*
 * Last modified: 22nd May 2015
 * Still need to implement input methods from the console.
 */

#ifndef CARTESIAN_HPP_
#define CARTESIAN_HPP_

#include <iostream>
#include <cmath>

/*
 * Simple Cartesian coordinates system
 * Should behave as a vector in 3D
 *
 * This is purely numerical however extending
 * this to take general polynomials as functions
 * would be an interesting project indeed.
 *
 * It would also be interesting to write
 * a polar coordinates class as well as
 * a method of converting from one to the other
 */

class Cartesian {

	public:
		// Default Constructor
		Cartesian(): x(0.), y(0.), z(0.) {;}

		// Generic Constructor
		template <typename TYPE>
		Cartesian(const TYPE & x = 0., const TYPE & y = 0., const TYPE & z = 0.): x(x), y(y), z(z) {;}

		template <typename TYPE>
		Cartesian(const TYPE & in) {
			*this = in; // Assignment operator
		}

		~Cartesian() {;}

		// Allow return of specific parameters to non-member functions
		double getx() {
			return x;
		}
		double gety() {
			return y;
		}
		double getz() {
			return z;
		}

		// Assignment
		Cartesian & operator=(const Cartesian & in) {
			x = in.x;
			y = in.y;
			z = in.z;
			return *this;
		}

		// Addition
		Cartesian & operator+=(const Cartesian & in) {
			x += in.x;
			y += in.y;
			z += in.z;
			return *this;
		}
		Cartesian operator+(const Cartesian & in) {
					Cartesian a(*this);
					a += in;
					return a;
				}

		// Subtraction
		Cartesian & operator-=(const Cartesian & in) {
			x -= in.x;
			y -= in.y;
			z -= in.z;
			return *this;
		}
		Cartesian operator-(const Cartesian & in) {
					Cartesian a(*this);
					a -= in;
					return a;
				}

		/*
		 * Defining vector multiplication as a cross product
		 * This preserves the usability of the class
		 * Later on dot product will be a function
		 */
		Cartesian & operator*=(const Cartesian & in) {
			double i = (y * in.z) - (z * in.y);
			double j = -1*( (x * in.z) - (z * in.x) );
			double k = (x * in.y) - (y * in.x);
			x = i; y = j; z = k;
			return *this;
		}
		Cartesian operator*(const Cartesian & in) {
			Cartesian a(*this);
			a *= in;
			return a;
		}


		/*
		 * Scalar multiplication
		 * Note: This does not have commutativity
		 * Here vector * scalar is defined
		 * scalar * vector is implemented as a non-member
		 * function directly after this class closes
		 */
		template <typename scalar>
		Cartesian & operator*=(const scalar & var) {
			double i = x*var;
			double j = y*var;
			double k = z*var;
			x = i; y = j; z = k;
			return *this;
		}
		template <typename scalar>
		Cartesian operator*(const scalar & var) {
			Cartesian a(*this);
			a *= var;
			return a;
		}

		/*
		 * Scalar division
		 * Note: This does not have commutativity
		 * Here vector / scalar is defined
		 * scalar / vector is implemented as a non-member
		 * function directly after this class closes
		 */
		template <typename scalar>
		Cartesian & operator/=(const scalar & var) {
			double i = x/(double)var;
			double j = y/(double)var;
			double k = z/(double)var;
			x = i; y = j; z = k;
			return *this;
		}
		template <typename scalar>
		Cartesian operator/(const scalar & var) {
			Cartesian a(*this);
			a /= var;
			return a;
		}

		// Vector-Vector division is not defined here.


		// The following functions can be found in cartesian.cpp:

		// Output Functionality
		void Print(std::ostream & os) const;


	protected:
		double x;
		double y;
		double z;
};

// Commutativity fix for scalar multiplication & division
template <typename scalar>
Cartesian operator*(scalar var, Cartesian vect) {
	return vect*var;
}
template <typename scalar>
Cartesian operator/(scalar var, Cartesian vect) {
	double i = var / (double)vect.getx();
	double j = var / (double)vect.gety();
	double k = var / (double)vect.getz();
	Cartesian output(i,j,k);
	return output;
}

// Allow overloading of << operators in cartesian.cpp
std::ostream & operator<<(std::ostream & os, const Cartesian & var);

// Define dot product of two vectors
double dot(Cartesian var1, Cartesian var2);

// Define absolute (norm) value of a vector
double abs(Cartesian var);

// Get versor of vector
Cartesian versor(Cartesian var);

#endif /* CARTESIAN_HPP_ */
