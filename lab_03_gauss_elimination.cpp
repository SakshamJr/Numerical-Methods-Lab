#include <iostream>
using namespace std;

int main()
{
    int n, i, j, k;
    cout << "Enter number of unknowns: ";
    cin >> n;

    float a[n][n + 1], x[n], ratio;

    cout << "Enter Coefficients of Augmented Matrix: " << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
            cin >> a[i][j];

    /* Gaussian Elimination */
    for (i = 0; i < n - 1; i++)
    {
        if (a[i][i] == 0.0)
        {
            cout << "Mathematical Error!";
            return 0;
        }
        for (j = i + 1; j < n; j++)
        {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k <= n; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    /* Back Substitution */
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    /* Display Solution */
    cout << endl
         << "Solution: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }

    return 0;
}
