#include "Transformation.h"

//////////////////////////////////////////////////////////////////////////////////////
Vector::Vector(double x, double y, double z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = 1.0f;
}

Vector::Vector(const Vector& v) : data{v.data} {}


void Vector::Set(int i, double val)
{
	data[i] = val;
}

double Vector::Get(int i) const
{
	return data[i];
}

Vector& Vector::operator=(const Vector& v) {
	data = std::array<double,4>{v.data};
	return *this;
}

Vector& Vector::operator=(Vector&& v) {
	data = std::move(v.data);
	return *this;
}

//////////////////////////////////////////////////////////////////////////////////////
Matrix::Matrix()
{
	data[0][0] = 0.0f; data[0][1] = 0.0f; data[0][2] = 0.0f; data[0][3] = 0.0f;
	data[1][0] = 0.0f; data[1][1] = 0.0f; data[1][2] = 0.0f; data[1][3] = 0.0f;
	data[2][0] = 0.0f; data[2][1] = 0.0f; data[2][2] = 0.0f; data[2][3] = 0.0f;
	data[3][0] = 0.0f; data[3][1] = 0.0f; data[3][2] = 0.0f; data[3][3] = 1.0f;
}

Matrix::Matrix(const Matrix& m) : data{m.data} {}


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

Matrix& Matrix::operator=(const Matrix& m) {
	data = std::array<std::array<double, 4>, 4>{m.data};
	return *this;
}

Matrix& Matrix::operator=(Matrix&& m) {
	data = std::move(m.data);
	return *this;
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
Matrix Rotate(double rotation_x, double rotation_y, double rotation_z)
{
	Matrix rotateX;
	Matrix rotateY;
	Matrix rotateZ;

	double alpha = -rotation_x * M_PI / 180.0f;
	rotateX.Set(0, 0, 1.0f);
	rotateX.Set(1, 1, cos(alpha));
	rotateX.Set(1, 2, -sin(alpha));
	rotateX.Set(2, 1, sin(alpha));
	rotateX.Set(2, 2, cos(alpha));

	alpha = -rotation_y * M_PI / 180.0f;
	rotateY.Set(0, 0, cos(alpha));
	rotateY.Set(0, 2, sin(alpha));
	rotateY.Set(1, 1, 1.0f);
	rotateY.Set(2, 0, -sin(alpha));
	rotateY.Set(2, 2, cos(alpha));

	alpha = -rotation_z * M_PI / 180.0f;
	rotateZ.Set(0, 0, cos(alpha));
	rotateZ.Set(0, 1, -sin(alpha));
	rotateZ.Set(1, 0, sin(alpha));
	rotateZ.Set(1, 1, cos(alpha));
	rotateZ.Set(2, 2, 1.0f);

	Matrix rotate = rotateX * rotateY * rotateZ;
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

