#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    system("cls");
    int n, i, j;
    cout << "Enter the order of the matrix: ";
    cin >> n;
    float a[n][n], x[n], y[n], max = 0, temp;
    cout << "Enter the Matrix: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    }
    cout << "Enter the initial approximation X:\n";
    for (i = 0; i < n; i++)
        cin >> x[i];
    do
    {
        temp = max;
        // Multiplying Matrices
        for (i = 0; i < n; i++)
        {
            y[i] = 0;
            for (j = 0; j < n; j++)
            {
                y[i] += a[i][j] * x[j];
            }
        }

        // Finding Largest Element
        max = y[0];
        for (i = 0; i < n; i++)
        {
            max = fabs(y[i]) > fabs(max) ? y[i] : max;
        }

        // Dividing by Largest Element
        for (i = 0; i < n; i++)
        {
            y[i] /= max;
        }

        // Updating x for the next iteration
        for (i = 0; i < n; i++)
        {
            x[i] = y[i];
        }

    } while (fabs(max - temp) > 0.0001);

    cout << "\nLargest Eigen value: " << max << '\n';
    cout << "Corresponding Eigen vector:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << x[i] << '\n';
    }
    return 0;
}
