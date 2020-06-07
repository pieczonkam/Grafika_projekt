#include "Transformation.h"

/**************************************_Vector_**************************************/
Vector::Vector(double x, double y, double z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = 1.0f;
}

Vector::Vector(const Vector& v) : data{ v.data } 
{}

double& Vector::operator()(int a) 
{
	return data[a];
}

double Vector::operator()(int a) const
{
	return data[a];
}

Vector& Vector::operator=(const Vector& v)
{
	data = std::array<double, 4>{v.data};
	return *this;
}

Vector& Vector::operator=(Vector&& v) 
{
	data = std::move(v.data);
	return *this;
}

void Vector::Normalize()
{
	for (int i = 0; i < 3; ++i)
		data[i] /= data[3];
}

/***************************************_Matrix_***************************************/
Matrix::Matrix(double diag)
{
	data[0][0] = diag; data[0][1] = 0.0f; data[0][2] = 0.0f; data[0][3] = 0.0f;
	data[1][0] = 0.0f; data[1][1] = diag; data[1][2] = 0.0f; data[1][3] = 0.0f;
	data[2][0] = 0.0f; data[2][1] = 0.0f; data[2][2] = diag; data[2][3] = 0.0f;
	data[3][0] = 0.0f; data[3][1] = 0.0f; data[3][2] = 0.0f; data[3][3] = 1.0f;
}

Matrix::Matrix(const Matrix& m) : data{ m.data } 
{}

double& Matrix::operator()(int a, int b) 
{
	return data[a][b];
}

double Matrix::operator()(int a, int b) const
{
	return data[a][b];
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

Matrix& Matrix::operator=(const Matrix& m) 
{
	data = std::array<std::array<double, 4>, 4>{m.data};
	return *this;
}

Matrix& Matrix::operator=(Matrix&& m) 
{
	data = std::move(m.data);
	return *this;
}

bool Matrix::operator==(const Matrix& mat) const
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			if (data[i][j] != mat.data[i][j])
				return false;
	}

	return true;
}

/**************************************_UTILITY_**************************************/
Vector operator*(const Matrix& mat, const Vector& vec)
{
	Vector result;

	for (int i = 0; i < 4; ++i)
	{
		result(i) = 0.0f;
		for (int j = 0; j < 4; ++j)
			result(i) = result(i) + mat(i, j) * vec(j);
	}

	return result;
}

Matrix Rotate(const Vector& vec, double angle)
{
	Matrix rotate;
	angle = angle * M_PI / 180.0f;
	double u = vec(0);
	double v = vec(1);
	double w = vec(2);
	double u2 = pow(u, 2);
	double v2 = pow(v, 2);
	double w2 = pow(w, 2);
	double L = u2 + v2 + w2;
	rotate(0, 0) = (u2 + (v2 + w2) * cos(angle)) / L;
	rotate(0, 1) = (u * v * (1 - cos(angle)) - w * sqrt(L) * sin(angle)) / L;
	rotate(0, 2) = (u * w * (1 - cos(angle)) + v * sqrt(L) * sin(angle)) / L;
	rotate(1, 0) = (u * v * (1 - cos(angle)) + w * sqrt(L) * sin(angle)) / L;
	rotate(1, 1) = (v2 + (u2 + w2) * cos(angle)) / L;
	rotate(1, 2) = (v * w * (1 - cos(angle)) - u * sqrt(L) * sin(angle)) / L;
	rotate(2, 0) = (u * w * (1 - cos(angle)) - v * sqrt(L) * sin(angle)) / L;
	rotate(2, 1) = (v * w * (1 - cos(angle)) + u * sqrt(L) * sin(angle)) / L;
	rotate(2, 2) = (w2 + (u2 + v2) * cos(angle)) / L;

	return rotate;
}

Matrix Perspective(double width, double height, double depth)
{
	Matrix mat1;
	Matrix mat2;

	mat1(0, 0) = 1.0f;
	mat1(1, 1) = 1.0f;
	mat1(3, 2) = 1.0f / -depth;

	mat2(0, 0) = width / 2.0f;
	mat2(0, 3) = width / 2.0f;
	mat2(1, 1) = -height / 2.0f;
	mat2(1, 3) = height / 2.0f;

	return mat2 * mat1;
}

