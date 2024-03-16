#include <iostream>
#include <cmath>
#define f(x) x *x *x + 3 * x *log10(x)
#define e 0.000001

using namespace std;
int main()
{
    system("cls");
    double a, b, c;
    double fa, fb, fc;
    cout << "Enter Intervals a and b: ";
    cin >> a >> b;
    do
    {
        fa = f(a);
        fb = f(b);
        if (fa * fb > 0)
        {
            cout << "Invalid Intervals! They donot Bracket the root!" << endl;
            return 0;
        }
        c = (a + b) / 2;
        fc = f(c);
        if (fc * fa < 0)
            b = c;
        else if (fb * fc < 0)
            a = c;
        else 
        cout << "ERROR!! \n";
    } while (fabs((b-a)/a) > e);
    cout << "Root = " << c << endl;
    return 0;
}