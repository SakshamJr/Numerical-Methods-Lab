/* Linear curve fitting for the curve y=a+bx+cx^2+...+kx^n */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    system("cls");
    int n, d;
    cout << "Enter the number of data: ";
    cin >> n;

    cout << "Enter the degree of the polynomial: ";
    cin >> d;

    if (n < d)
    {
        cout << "Number of Data Points Must Be Greater than Degree of Polynomial!\n";
        exit(0);
    }
    float x[n], y[n];
    float a[d + 1][d + 2] = {}; /* Normal equations' matrix */
    cout << "\nEnter the data points (x, y):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    /*Form the Augmented Normal Equations Matrix*/
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d; j++)
            for (int k = 0; k < n; k++)
                a[i][j] += pow(x[k], i + j);

        for (int j = 0; j < n; j++)
        {
            a[i][d + 1] += pow(x[j], i) * y[j];
        }
    }

    /* Convert the augmented matrix to diagonal matrix */
    for (int i = 0; i <= d; i++)
    {
        if (fabs(a[i][i]) <= 0.0005)
        {
            cout << "Mathematical Error: Pivot element is zero\n";
            return -1;
        }

        for (int j = 0; j <= d; j++)
        {
            if (i != j)
            {
                float ratio = a[j][i] / a[i][i];

                for (int k = 0; k <= d + 1; ++k)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }

    cout << "\nFor polynomial curve is \ny = a0 + a1x + a2x^2 + ... + anx^n\n";
    for (int i = 0; i <= d; ++i)
    {
        cout.precision(5);
        cout << "a" << i << " = " << a[i][d + 1] / a[i][i] << endl;
    }
    return 0;
}