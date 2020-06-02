#include "Transformation.h"

//////////////////////////////////////////////////////////////////////////////////////
Vector::Vector(double x, double y, double z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = 1.0f;
}

void Vector::Set(int i, double val)
{
	data[i] = val;
}

double Vector::Get(int i) const
{
	return data[i];
}

double Vector::Length() const
{
	return sqrt(pow(data[0], 2) + pow(data[1], 2) + pow(data[2], 2));
}

//////////////////////////////////////////////////////////////////////////////////////
Matrix::Matrix()
{
	data[0][0] = 0.0f; data[0][1] = 0.0f; data[0][2] = 0.0f; data[0][3] = 0.0f;
	data[1][0] = 0.0f; data[1][1] = 0.0f; data[1][2] = 0.0f; data[1][3] = 0.0f;
	data[2][0] = 0.0f; data[2][1] = 0.0f; data[2][2] = 0.0f; data[2][3] = 0.0f;
	data[3][0] = 0.0f; data[3][1] = 0.0f; data[3][2] = 0.0f; data[3][3] = 1.0f;
}

void Matrix::Set(int i, int j, double val)
{
	data[i][j] = val;
}

double Matrix::Get(int i, int j) const
{
	return data[i][j];
}

Matrix Matrix::operator*(const Matrix& mat) const
{
	Matrix result;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.data[i][j] = 0.0f;
			for (int k = 0; k < 4; ++k)
			{
				result.data[i][j] += data[i][k] * mat.data[k][j];
			}
		}
	}

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////
Vector operator*(const Matrix& mat, const Vector& vec)
{
	Vector result;

	for (int i = 0; i < 4; ++i)
	{
		result.Set(i, 0.0f);
		for (int j = 0; j < 4; ++j)
		{
			result.Set(i, result.Get(i) + mat.Get(i, j) * vec.Get(j));
		}
	}

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////
Matrix Rotate(const Vector& vec, double angle)
{
	Matrix rotate;
	angle = angle * M_PI / 180.0f;
	double u = vec.Get(0);
	double v = vec.Get(1);
	double w = vec.Get(2);
	double u2 = pow(u, 2);
	double v2 = pow(v, 2);
	double w2 = pow(w, 2);
	double L = u2 + v2 + w2;
	rotate.Set(0, 0, (u2 + (v2 + w2) * cos(angle)) / L);
	rotate.Set(0, 1, (u * v * (1 - cos(angle)) - w * sqrt(L) * sin(angle)) / L);
	rotate.Set(0, 2, (u * w * (1 - cos(angle)) + v * sqrt(L) * sin(angle)) / L);
	rotate.Set(1, 0, (u * v * (1 - cos(angle)) + w * sqrt(L) * sin(angle)) / L);
	rotate.Set(1, 1, (v2 + (u2 + w2) * cos(angle)) / L);
	rotate.Set(1, 2, (v * w * (1 - cos(angle)) - u * sqrt(L) * sin(angle)) / L);
	rotate.Set(2, 0, (u * w * (1 - cos(angle)) - v * sqrt(L) * sin(angle)) / L);
	rotate.Set(2, 1, (v * w * (1 - cos(angle)) + u * sqrt(L) * sin(angle)) / L);
	rotate.Set(2, 2, (w2 + (u2 + v2) * cos(angle)) / L);

	return rotate;
}

Matrix Perspective(double width, double height, double depth)
{
	Matrix mat1;
	Matrix mat2;

	mat1.Set(0, 0, 1.0f);
	mat1.Set(1, 1, 1.0f);
	mat1.Set(3, 2, 1.0f / -depth);

	mat2.Set(0, 0, width / 2.0f);
	mat2.Set(0, 3, width / 2.0f);
	mat2.Set(1, 1, -height / 2.0f);
	mat2.Set(1, 3, height / 2.0f);

	return mat2 * mat1;
}

