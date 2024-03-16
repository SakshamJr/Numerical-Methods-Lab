#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return x * exp(x);
}

void trapezoidal(double x0, int n, double h)
{
    cout << endl
         << "Trapezoidal: ";
    double sum = 0;
    double x;
    for (int i = 1; i < n; i++)
    {
        x = x0 + i * h;
        sum += f(x);
    }
    sum = sum * 2;
    sum += (f(x0) + f(x0 + n * h));
    sum = sum * h / 2;
    cout << sum << endl;
}

void simpson1_3(double x0, int n, double h)
{
    cout << endl
         << "Simpson 1/3: ";
    double sum = 0;
    double x;
    for (int i = 1; i < n; i++)
    {
        x = x0 + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }
    sum += (f(x0) + f(x0 + n * h));
    sum = sum * h / 3;
    cout << sum << endl;
}

void simpson3_8(double x0, int n, double h)
{
    cout << endl
         << "Simpson 3/8: ";
    double sum = 0;
    double x;
    for (int i = 1; i < n; i++)
    {
        x = x0 + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }
    sum += (f(x0) + f(x0 + n * h));
    sum = (sum * 3 * h) / 8;
    cout << sum << endl;
}

int main()
{
    system("cls");
    int n;
    double h, x0, xn;
    cout << "Enter x0: ";
    cin >> x0;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter Number of strips n: ";
    cin >> n;
    h = (xn - x0) / n;
    trapezoidal(x0, n, h);
    if (n % 2 == 0)
        simpson1_3(x0, n, h);
    if (n % 3 == 0)
        simpson3_8(x0, n, h);
    return 0;
}