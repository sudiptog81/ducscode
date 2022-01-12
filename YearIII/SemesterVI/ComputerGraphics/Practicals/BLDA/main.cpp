/**
 * Write a program to implement Bresenham's line drawing algorithm.
 *
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cmath>
#include <cstdlib>
#include <graphics.h>
#include <iostream>

using namespace std;

void bresenhamLine(int x0, int y0, int x1, int y1, int val)
{
  if (x0 == x1 && y0 == y1)
  {
    putpixel(x1, y1, val);
  }
  else
  {
    int dx = x1 - x0;
    int dy = y1 - y0;

    float m = float(dy) / (float)(dx);

    if (m >= 1 || m <= 0)
    {
      cout << "ERROR: Slope must be between 0 and 1." << endl;
      exit(1);
    }

    int d = 2 * dy - dx;
    int del_E = 2 * dy;
    int del_NE = 2 * (dy - dx);

    int x = x0;
    int y = y0;
    putpixel(x, y, val);

    while (x < x1)
    {
      if (d <= 0)
      {
        d += del_E;
        x += 1;
      }
      else
      {
        d += del_NE;
        x += 1;
        y += 1;
      }

      putpixel(x, y, val);
    }
  }

  return;
}

int main(void)
{
  int x0, y0, x1, y1;
  cout << "Enter Left Endpoint (x0 y0): ";
  cin >> x0 >> y0;
  cout << "Enter Right Endpoint (x1 y1): ";
  cin >> x1 >> y1;

  cout << "Drawing Line..." << endl;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  bresenhamLine(x0, y0, x1, y1, WHITE);
  delay(5e3);
  closegraph();

  cout << "Finished..." << endl;

  return 0;
}
