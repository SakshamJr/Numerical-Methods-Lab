#include <iostream>

using namespace std;
int main()
{
    system("cls");
    int size, i, j, k;
    cout << "Enter Size of a: ";
    cin >> size;
    float a[size][size + 1], x[size];
    float ratio;
    cout << "Enter Coefficients of Augmented a: ";
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size + 1; j++)
        {
            cin >> a[i][j];
        }
    }

    // Calculating the Identity a
    for (i = 0; i < size; i++)
    {
        if (a[i][i] == 0)
        {
            cout << "Gauss Jordan Method Fails! ";
            exit(0);
        }
        for (j = 0; j < size; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < size + 1; k++)
                    a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Assigning and Displaying the Result
    for (i = 0; i < size; i++)
    {
        x[i] = a[i][size] / a[i][i];
        cout << "x" << i << " = " << x[i] << endl;
    }

    return 0;
}