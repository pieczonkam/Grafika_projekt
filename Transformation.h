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
		Vector(const Vector&);

		/// overloaded operators
		double& operator()(int);
		double operator()(int) const;
		Vector& operator=(const Vector&);
		Vector& operator=(Vector&&);

		/// function normalizing given vector
		void Normalize();

	private:

		std::array<double, 4> data;
};

//////////////////////////////////////////////////////////////////////////////////////
class Matrix
{
	public:

		// constructors
		Matrix(double diag = 0.0f);
		Matrix(const Matrix&);

		/// overloaded operators
		double& operator()(int, int);
		double operator()(int, int) const;
		Matrix operator*(const Matrix&) const;
		Matrix& operator=(const Matrix&);
		Matrix& operator=(Matrix&&);
		bool operator==(const Matrix&) const;

	private:

		std::array<std::array<double, 4>, 4> data;
};

//////////////////////////////////////////////////////////////////////////////////////

/// overloaded Matrix*Vector operation
Vector operator*(const Matrix&, const Vector&);

/// function constructing rotation matrix
Matrix Rotate(const Vector&, double);

/// function constructing perspective matrix
Matrix Perspective(double, double, double);
