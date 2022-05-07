#include <conio.h>
#include <graphics.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void bezier(int x[4], int y[4])
{
  for (double t = 0.0; t < 1.0; t += 0.00005)
  {
    double xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
    double yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
    putpixel(xt, yt, WHITE);
  }

  for (int i = 0; i < 4; i++)
  {
    circle(x[i], y[i], 3);
  }

  getch();
  closegraph();
  return;
}

void main()
{
  int i;
  int x[4], y[4];
  int gd = DETECT, gm, errorcode;

  initgraph(&gd, &gm, "..\\bgi");

  for (i = 0; i < 4; i++)
  {
    cout << "Enter Point " << i + 1 << " (x, y): ";
    cin >> x[i] >> y[i];
  }

  bezier(x, y);
  return;
}
