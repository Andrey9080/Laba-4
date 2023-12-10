#include "Header.h"


double sum_pow(int N, double* x, int P)
{
    double sum=0;
    if (P == 0)
    {
        return 5;
    }
    if (P != 0)
    {
        for (int i = 0; i < N; i++)
        {
            sum += pow(x[i], P);
           
        }
        return sum;
    }
    return false;
}

double sum_pow_2 (int N,double* y, double* x, int P)
{
    double sum = 0;
    if (P == 0)
    {
        for (int i = 0; i < N; i++)
        {
            sum +=  y[i];

        }
        return sum;
    }
    if (P != 0)
    {
        for (int i = 0; i < N; i++)
        {
            sum += (pow(x[i], P) * y[i]);

        }
        return sum;
    }
    return false;
}

int main()
{
    //инициализируем переменные которые понадабятся в дальнейшем
    int M = 1;
    int N = 5;
    double* x = new double[N];
    double* y = new double[N];
    double** A = new double* [N];
    for (int i = 0; i < N; ++i)
    {
        A[i] = new double[N-1];
    }
    double* B = new double[N-1];
    double* ankoun = new double[1];

    //инициализируем в ручные полученные данные
    x[0] = 2.4;
    x[1] = 3.5;
    x[2] = 5;
    x[3] = 6.89;
    x[4] = 10;

    y[0] = 0.0141;
    y[1] = 0.0281;
    y[2] = 0.0562;
    y[3] = 0.1125;
    y[4] = 0.2250;

    double* x2 = new double[N-1];
    for (int i = 0; i < N; ++i)
    {
        x2[i] = pow(x[i], 2);
    }
    for (int i = 0; i < N; ++i)
    {
        int m = 0+ i;
        for (int b = 0; b < N; ++b)
        {
            A[b][i] = sum_pow(N, x2, m);
            ++m;
        }

    }
    //вывод полученной матрицы
    for (int i = 0; i < N; ++i)
    {
        for (int b = 0; b < N; ++b)
        {
            cout<<setw(15) << A[b][i];
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < N; ++i)
    {
        B[i] = sum_pow_2(N, y, x2, i);
    }
    rabochiy gauss(2, A, B);
    gauss.work();
    gauss.out();
    ankoun = gauss.unknown_out();
    double a, b;
    a = ankoun[0];
    b = ankoun[1];

}
