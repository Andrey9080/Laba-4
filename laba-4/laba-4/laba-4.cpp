#include "Header.h"
double f11(double x1, double x2)
{
    return cos(x1+1);
}
double f12(double x1, double x2)
{
    return (-1);
}
double f21(double x1, double x2)
{
    return 2;
}
double f22(double x1, double x2)
{
    return -sin(x2);
}
double function1(double x1, double x2)
{
    return (sin(x1) + x1 * x2 - 1);
}
double function2(double x1, double x2) 
{
    return (2 * x1 + cos(x2) - 2);
}
double f1derivative11(double x1, double x2, double dif) {
    cout << ((function1(x1 + dif, x2) - function1(x1, x2)) / (dif));
    return((function1(x1 + dif, x2) - function1(x1, x2)) / (dif));
}
double f1derivative12(double x1, double x2, double dif) {
    cout << ((function1(x1, x2 + dif) - function1(x1, x2)) / (dif));
    return((function1(x1, x2 + dif) - function1(x1, x2)) / (dif));
}
double f2derivative21(double x1, double x2, double dif) {
    cout << ((function2(x1 + dif, x2) - function2(x1, x2)) / (dif));
    return((function2(x1 + dif, x2) - function2(x1, x2)) / (dif));
}
double f2derivative22(double x1, double x2, double dif) {
    cout << ((function2(x1, x2 + dif) - function2(x1, x2)) / (dif));
    return((function2(x1, x2 + dif) - function2(x1, x2)) / (dif));
}
int main()
{

    setlocale(0, "");

    double* x = new double[2];
    x[0] = 1;
    x[1] = 1;
    double M = 0.01;
    double** Jac = new double* [2];
    for (int i = 0; i < 2; ++i) 
    {
        Jac[i] = new double[2];
    }
    double  F[2];
    int NIT = 5;
    while (NIT > 0)
    {


        Jac[0][0] = f1derivative11(x[0], x[1], M);
        Jac[0][1] = f1derivative12(x[0], x[1], M);
        Jac[1][0] = f2derivative21(x[0], x[1], M);
        Jac[1][1] = f2derivative22(x[0], x[1], M);

      /*  out(x, Jac, F);*/
        rabochiy gauss(2, Jac, x);
        gauss.work();
        gauss.out();
        x = gauss.unknown_out();
        
        --NIT;
        
    }
    cout<<"\n" << "------------------------------------------------------------------------------------------------------------------------" << "\n";
    while (NIT > 0)
    {


        Jac[0][0] = f11(x[0], x[1]);
        Jac[0][1] = f12(x[0], x[1]);
        Jac[1][0] = f21(x[0], x[1]);
        Jac[1][1] = f22(x[0], x[1]);

        /*  out(x, Jac, F);*/
        rabochiy gauss(2, Jac, x);
        gauss.work();
        gauss.out();
        x = gauss.unknown_out();

        --NIT;

    }
       

    cout << "\n" << x[0] << " " << x[1] << "\n";
    for (int i = 0; i < 2; ++i) 
    {
        delete[] Jac[i];
    }
    delete[] Jac;
}
