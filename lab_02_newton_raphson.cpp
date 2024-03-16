#include <iostream>
#include <cmath>
#define e 0.000001
#define f(x) cos(x) + x *x - 4
#define fd(x) 2 * x - sin(x)
using namespace std;
int main()
{
    system("cls");
    double x0, x = 0, fx0, fdx0;
    cout << "Enter Initial Guess: ";
    cin >> x0;
    do
    {
        fx0 = f(x0);
        fdx0 = fd(x0);
        x = x0 - (fx0 / fdx0);
        x0 = x;
    } while (fabs(f(x)) > e);
    cout << "Root = " << x;
    return 0;
}