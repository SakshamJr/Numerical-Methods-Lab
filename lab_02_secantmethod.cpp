#include <iostream>
#include <cmath>
#define e 0.0001
#define f(x) x*x-3*x*log(x)
using namespace std;
int main()
{
    system("cls");
    double a, b, c, fa, fb, fc;
    int iterations;
    cout << "Enter Initial Guesses a and b: ";
    cin >> a >> b;
    do
    {
        fa = f(a);
        fb = f(b);
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);
        a = b;
        b = c;
    } while (fabs(fc) > e);
    cout << "Root: " << c;
    return 0;
}