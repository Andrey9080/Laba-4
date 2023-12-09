#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
class rabochiy
{
private:
	int size;
	double** matrix;
	double* B;
	double* X;
	
public:

	rabochiy(int sizee, double** matrixx, double answers[])
	{
		size = sizee;
		double** matrix = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}
		double* B = new double[size];
		double* X = new double[size];

		for (int i = 0; i < size; i++)
		{
			for (int b = 0; b < size; b++)
			{
				matrix[i][b] = matrixx[i][b];
			}
			B[i] = answers[i];
		}

		
	}
	~rabochiy()
	{
		for (int i = 0; i < 2; i++) 
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



		for (int i = 0; i < size; i++)
		{
			if (max < matrix[i][1])
			{
				max = matrix[i][1];
				y = i;
			}
		}


		for (int i = 0; i < size; i++)
		{
			swap(matrix[y][i], matrix[0][i]);
		}


		
		for (int line=0,column=0;line < size && column == line;line++, column++)
		{
			
			for (int i = 1; i < size; ++i)
			{
				double time_x = matrix[i][column];

				for (int b = 0; b < size; b++)
				{
					matrix[i][b] = matrix[i][b] / time_x;
				}

				B[i] = B[i] / time_x;

				for (int b = 0; b < size; b++)
				{
					matrix[i][b] *= max;
					matrix[i][b] -= matrix[line][b];
				}

				B[i] *= max;
				B[i] -= B[line];
				for (int b = 0; b < size; b++)
				{
					matrix[line][b]/= time_x;
				}
				B[line] /= time_x;
			}

		}

		for (int i = size-1; i > 0; i--)
		{
			double time_x=0;
			for (int b = size-1 ;b > i ;b--)
			{
				time_x += matrix[i][b]*X[size-b];
			}
			X[i] = B[i] - time_x;
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
		for (int i = 0; i < size; i++)
		{
			cout << setw(10) << "|";
			for (int b = 0; b < size; b++)
			{
				cout << setw(10) << matrix[i][b];
			}
			cout << setw(10) << "|"<<setw(5)<<"|"<<setw(10)<<B[i]<<setw(5) << "|";

		}
	}
};