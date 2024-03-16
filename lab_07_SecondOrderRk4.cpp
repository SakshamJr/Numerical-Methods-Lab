#include <iostream>
#include <cmath>

float g(float x, float y, float z)
{
    return 36 * x + 18 - 4 * z - 3 * y;
}

using namespace std;
int main()
{
    system("cls");
    float x0, y0, z0, h, xn;
    float k, k1, k2, k3, k4, l, l1, l2, l3, l4;
    cout << "Enter x0, y0, (dy/dx)(x0): ";
    cin >> x0 >> y0 >> z0;
    cout << "Enter x at which you want the solution: ";
    cin >> xn;
    cout << "Enter Step Size: ";
    cin >> h;

    // Applying RK4
    while (fabs(xn - x0) > 0.005)
    {
        k1 = h * z0;
        l1 = h * g(x0, y0, z0);

        k2 = h * (z0 + l1 / 2);
        l2 = h * g(x0 + h / 2, y0 + k1 / 2, z0 + l1 / 2);

        k3 = h * (z0 + l2 / 2);
        l3 = h * g(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);

        k4 = h * (z0 + l3);
        l4 = h * g(x0 + h, y0 + k3, z0 + l3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        x0 = x0 + h;
        y0 = y0 + k;
        z0 = z0 + l;
    }
    cout << "x1, y1, z1 = " << x0 << " , " << y0 << " , " << z0 << endl;
    return 0;
}