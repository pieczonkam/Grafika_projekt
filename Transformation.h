#pragma once

#include <array>
#include <cmath>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

//////////////////////////////////////////////////////////////////////////////////////
class Vector
{
	public:
		
		/// constructors
		Vector(double x = 0.0f, double y = 0.0f, double z = 0.0f);
		Vector(const Vector&) ;

		/// overloaded operators
		Vector& operator=(const Vector&)  ;
		Vector& operator=(Vector&&) ;

		/// setting one value in vector
		void Set(int i, double val);

		/// get value from vector
		double Get(int i) const;


	private:

		std::array<double, 4> data;

};

//////////////////////////////////////////////////////////////////////////////////////
class Matrix
{
	public:

		/// constructors
		Matrix();
		Matrix(const Matrix&) ;

		/// overloaded operators
		Matrix operator*(const Matrix &mat) const;
		Matrix& operator=(const Matrix&) ;
		Matrix& operator=(Matrix&&) ;

		/// setting one value in matrix
		void Set(int i, int j, double val);

		/// get value from matrix
		double Get(int i, int j) const;

	private:

		std::array<std::array<double, 4>, 4> data;
};

//////////////////////////////////////////////////////////////////////////////////////

/// overloaded Matrix*Vector operation
Vector operator*(const Matrix& mat, const Vector& vec);

/// function constructing rotation matrix
Matrix Rotate(double rotate_x, double rotate_y, double rotate_z);

/// function constructing perspective matrix
Matrix Perspective(double width, double height, double depth);