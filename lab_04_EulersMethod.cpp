/*Solution of First Order Ordinary Differential Equation*/
// Also called Initial Value Problem
// Approximate Value is found out

#include <iostream>
#include <cmath>
#include <iomanip>
#define f(x, y) 6 * x - 3
using namespace std;
int main()
{
    system("cls");
    float x0, y0, x1, y1, xn, h, s;
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
        s = f(x0, y0);
        x1 = x0 + h;
        y1 = y0 + h * s;
        x0 = x1;
        y0 = y1;
        cout << setw(4) << x0 << "\t" << setw(6) << y0 << endl;
    }
    return 0;
}