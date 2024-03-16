/*Solution of First Order Ordinary Differential Equation*/
// Also called Initial Value Problem
// Approximate Value is found out
// yi+1 = yi + h*f(xi,yi)
// Tabular form output
// define f(x,y)
// Input x0,y0,h,xn
// s =f(x0,y0)
// y1 = y0 + h * s
// x1 = x0 + h
// x0 = x1
// y0 = y1
// print in tablular form

#include <iostream>
#include <cmath>
#include <iomanip>
#define f(x, y) 6*x - 3
using namespace std;
int main()
{
    system("cls");
    float x0, y0, x1, y1, xn, h, m1, m2, m3, m4, m;
    cout << "Enter x0 and y0: ";
    cin >> x0 >> y0;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter incremental value: ";
    cin >> h;
    cout << "Solution: \n\n";
    cout << "  x\t  y\n";
    cout << "---------------\n";
    cout << setw(4) << x0 << "\t" << setw(6) << y0 << endl;
    while (x0 < xn)
    {
        m1 = f(x0, y0);
        m2 = f(x0 + h / 2, y0 + m1 * h / 2);
        m3 = f(x0 + h / 2, y0 + m2 * h / 2);
        m4 = f(x0 + h, y0 + m3 * h);
        m = (m1 + 2 * m2 + 2 * m3 + m4) / 6;
        x1 = x0 + h;
        y1 = y0 + h * m;
        x0 = x1;
        y0 = y1;
        cout << setw(4) << x0 << "\t" << setw(6) << y0 << endl;
    }
    return 0;
}