#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    system("cls");
    int n, i;
    float sumx = 0, sumlny = 0, sumxlny = 0, sumx2 = 0, a, b;
    cout << "Enter Number of Data Points: ";
    cin >> n;
    float x[n], y[n];

    // Enter Values of X and Y
    cout << "Enter Values of x and y: " << endl;
    for (i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    // Calculate the Summations
    for (i = 0; i < n; i++)
    {
        sumx += x[i];
        sumlny += log(y[i]);
        sumxlny += x[i] * log(y[i]);
        sumx2 += x[i] * x[i];
    }

    if ((sumx * sumx - sumx2 * n) != 0)
    {
        b = (sumlny * sumx - sumxlny * n) / (sumx * sumx - sumx2 * n);
        a = (sumx * sumxlny - sumx2 * sumlny) / (sumx * sumx - sumx2 * n);
        a = exp(a);
        cout << "The Equation of Curve is: \n";
        cout << fixed;
        cout << "y = " << setw(5) << setprecision(4) << a << "e^" << setw(5) << b << "x";
    }
    else
    {
        cout << "Determinant is Zero!";
        exit(0);
    }
    return 0;
}