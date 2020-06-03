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
		
		Vector(double x = 0.0f, double y = 0.0f, double z = 0.0f);

		void Set(int i,  double val);

		double Get(int i) const;

		Vector operator=(const Vector&) const ;

	private:

		std::array<double, 4> data;
};

//////////////////////////////////////////////////////////////////////////////////////
class Matrix
{
	public:

		Matrix();

		void Set(int i, int j, double val);

		double Get(int i, int j) const;

		Matrix operator*(const Matrix &mat) const;

		Matrix operator=(const Matrix&) const ;

	private:

		std::array<std::array<double, 4>, 4> data;
};

//////////////////////////////////////////////////////////////////////////////////////
Vector operator*(const Matrix& mat, const Vector& vec);

Matrix Rotate(double rotate_x, double rotate_y, double rotate_z);

Matrix Perspective(double width, double height, double depth);