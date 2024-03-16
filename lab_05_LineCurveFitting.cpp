#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    system("cls");
    int n, i;
    float sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0, a, b, *y, *x;
    cout << "Enter Number of Data Points: ";
    cin >> n;
    x = new float[n];
    y = new float[n];

    // Enter Values of X and Y
    cout << "Enter Values of x and y: " << endl;
    for (i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    // Calculate the Summations
    for (i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }
    if ((sumx * sumx - sumx2 * n) != 0)
    {
        a = (sumy * sumx - sumxy * n) / (sumx * sumx - sumx2 * n);
        b = (sumx * sumxy - sumx2 * sumy) / (sumx * sumx - sumx2 * n);
        cout << "The Equation of line is: \n";
        cout << fixed;
        if (b > 0)
            cout << "y = " << setw(5) << setprecision(4) << a << "x + " << setw(5) << b;
        else if (b < 0)
            cout << "y = " << setw(5) << setprecision(4) << a << "x " << setw(5) << b;
        else
            cout << "y = " << setw(5) << setprecision(4) << a << "x";
    }
    else
    {
        cout << "Determinant is Zero!";
        exit(0);
    }
    return 0;
}