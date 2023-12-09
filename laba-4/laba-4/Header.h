#pragma once
#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

void out(double x[], double** Jac, double F[])
{
	cout << setw(10) << x[0] << setw(10) << x[1] << "\n";

	for (int i = 0; i < 2; ++i)
	{
		for (int b = 0; b < 2; ++b)
		{
			cout << setw(10) << Jac[i][b];
		}
		cout << "\n";
	}
}

void out_matrix(double** matrix, int size, double* B)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "|";
		for (int b = 0; b < size; ++b)
		{
			cout << setw(10) << matrix[i][b];
		}
		cout << setw(5) << "|" << setw(5) << "|" << setw(5) << B[i] << setw(5) << "|" << "\n";

	}
	cout << "\n";
}

using namespace std;
class rabochiy
{
private:
	int size;
	double** matrix;
	double* B;
	double* X;

public:

	rabochiy(int sizee, double** matrixx, double* answers)
	{
		size = sizee;
		matrix = new double* [size];
		for (int i = 0; i < size; ++i)
		{
			matrix[i] = new double[size];
		}
		B = new double[size];
		X = new double[size];

		for (int i = 0; i < size; ++i)
		{
			for (int b = 0; b < size; ++b)
			{
				matrix[i][b] = matrixx[i][b];
			}
			B[i] = answers[i];
		}
	}
	~rabochiy()
	{
		for (int i = 0; i < 2; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		delete[] B;
		delete[] X;
	}
	void work()
	{
		int y;
		double max = matrix[0][0];
		out_matrix(matrix, size, B);


		for (int i = 0; i < size; ++i)
		{
			if (max < matrix[i][0])
			{
				max = matrix[i][0];
				y = i;
			}
		}

		out_matrix(matrix, size, B);
		for (int i = 0; i < size; ++i)
		{
			swap(matrix[y][i], matrix[0][i]);
		}
		swap(B[y], B[0]);

		out_matrix(matrix, size, B);

		for (int line = 0, column = 0; line < size - 1 && column == line; ++line, ++column)
		{

			for (int i = 1; i < size; ++i)
			{
				double time_x = matrix[i][column];

				for (int b = 0; b < size; ++b)
				{
					matrix[i][b] = matrix[i][b] / time_x;
				}

				B[i] = B[i] / time_x;
				/*out_matrix(matrix, size, B);*/
				for (int b = 0; b < size; ++b)
				{
					matrix[i][b] *= max;
					matrix[i][b] -= matrix[line][b];
				}

				B[i] *= max;
				B[i] -= B[line];
				/*out_matrix(matrix, size, B);*/
				for (int b = 0; b < size; ++b)
				{
					matrix[line][b] /= time_x;
				}
				B[line] /= time_x;
				/*out_matrix(matrix, size, B);*/
			}

		}
		out_matrix(matrix, size, B);
		for (int i = size - 1; i >= 0; --i)
		{
			double time_x = 0;

			for (int b = size - 1; b > i; --b)
			{
				time_x += matrix[i][b] * X[size - b];
			}


			X[i] = B[i] / matrix[i][i] - time_x / matrix[i][i];
		}
	}
	double** matrix_out()
	{

		return matrix;
	}
	double* unknown_out()
	{
		return X;

	}
	double* answers_out()
	{
		return B;
	}
	void out()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << "|";
			for (int b = 0; b < size; ++b)
			{
				cout << setw(10) << matrix[i][b];
			}
			cout << setw(5) << "|" << setw(5) << "|" << setw(5) << B[i] << setw(5) << "|" << "\n";

		}
		cout << "\n";
		cout << "Значение x:" << "\n";
		for (int i = 0; i < size; ++i)
		{
			cout << setw(3) << "|" << setw(12) << X[i] << setw(3) << "|" << "\n";
		}
	}


};