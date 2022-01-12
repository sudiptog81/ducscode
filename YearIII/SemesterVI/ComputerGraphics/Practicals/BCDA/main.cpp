/**
 * Write a program to implement mid-point circle drawing algorithm.
 *
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cmath>
#include <cstdlib>
#include <graphics.h>
#include <iostream>

using namespace std;

void drawCirclePoints(int x, int y, int val, int c_x, int c_y)
{
  putpixel(c_x + x, c_y + y, val);
  putpixel(c_x + y, c_y + x, val);
  putpixel(c_x + y, c_y + -x, val);
  putpixel(c_x + x, c_y + -y, val);
  putpixel(c_x + -x, c_y + -y, val);
  putpixel(c_x + -y, c_y + -x, val);
  putpixel(c_x + -y, c_y + x, val);
  putpixel(c_x + -x, c_y + y, val);
  return;
}

void midpointCircle(int r, int val, int c_x = 0, int c_y = 0)
{
  int x = 0;
  int y = r;
  int d = 1 - r;
  drawCirclePoints(x, y, val, c_x, c_y);
  while (y > x)
  {
    if (d < 0)
    {
      d += 2 * x + 3;
      x += 1;
    }
    else
    {
      d += 2 * (x - y) + 5;
      x += 1;
      y -= 1;
    }
    drawCirclePoints(x, y, val, c_x, c_y);
  }
  return;
}

int main(void)
{
  int x, y, r;
  cout << "Enter Centre (x y): ";
  cin >> x >> y;
  cout << "Enter Radius (r): ";
  cin >> r;

  cout << "Drawing Circle..." << endl;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  midpointCircle(r, WHITE, x, y);
  delay(5e3);
  closegraph();

  cout << "Finished..." << endl;

  return 0;
}
