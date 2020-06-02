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

		double Length() const;

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

	private:

		std::array<std::array<double, 4>, 4> data;
};

//////////////////////////////////////////////////////////////////////////////////////
Vector operator*(const Matrix& mat, const Vector& vec);

Matrix Rotate(const Vector &vec, double angle);

Matrix Perspective(double width, double height, double depth);