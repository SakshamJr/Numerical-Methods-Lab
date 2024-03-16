#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    system("cls");
    int size, i, j, k;
    cout << "Enter no. of Unknowns: ";
    cin >> size;
    float a[size][size], inv[size][size], ratio;

    /*Initializing Identity Matrix*/
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
                inv[i][j] = 1;
            else
                inv[i][j] = 0;
        }
    }

    /*Input the Matrix to be Inversed*/
    cout << "Enter Matrix to be Inversed: ";
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            cin >> a[i][j];

    /*Gauss Jordan Method*/
    for (i = 0; i < size; i++)
    {
        if (a[i][i] == 0)
        {
            cout << "Diagonal Element Cannot Be Zero!";
            exit(0);
        }
        for (j = 0; j < size; j++)
        {
            ratio = a[j][i] / a[i][i];
            if (i != j)
            {
                for (k = 0; k < size; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                    inv[j][k] -= ratio * inv[i][k]; // simultaneously applying row transformation to the identity matrix
                }
            }
        }
    }

    /*Display the Inverse*/
    cout << endl
         << "Inverse of Matrix is: " << endl;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            inv[i][j] /= a[i][i];
            cout << setw(5) << inv[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}