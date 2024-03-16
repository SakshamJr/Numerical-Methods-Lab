#include <iostream>

using namespace std;
int main()
{
    system("cls");
    int i, j, n;
    cout << "Enter Number of Data Points: ";
    cin >> n;
    float x[n], y[n], xp, yp, sum = 0, xin;
    cout << "Enter the Data Points (x,y): ";
    for (i = 0; i < n; cin >> x[i] >> y[i], i++)
        ;
    cout << "Enter Value to be interpolated: ";
    cin >> xin;
    for (i = 0; i < n; i++)
    {
        xp = x[i];
        yp = y[i];
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if ((xp - x[j]) == 0)
            {
                cout << "Divide By Zero Occured! \n";
                exit(0);
            }
            yp *= (xin - x[j]) / (xp - x[j]);
        }
        sum += yp;
    }
    cout << "Interpolated Value of y is: " << sum;
    return 0;
}

// try
// {
// throw runtime_error("CANNOT DIVIDE BY ZERO!");
// }
// catch (runtime_error &e)
// {
//     cerr << e.what() << '\n';
//     exit(0);
// }