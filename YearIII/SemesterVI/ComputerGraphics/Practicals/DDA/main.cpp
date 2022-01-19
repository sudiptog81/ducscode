/**
 * Write a program to implement and draw a line using the Digital
 * Differential Analyzer (DDA) algorithm.
 *
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cmath>
#include <cstdlib>
#include <graphics.h>
#include <iostream>

using namespace std;

void ddaLine(int x0, int y0, int x1, int y1, int val)
{
  if (x0 == x1 && y0 == y1)
  {
    putpixel(x1, y1, val);
  }
  else
  {
    double x, y;
    int dx = x1 - x0;
    int dy = y1 - y0;
    bool isRTL = !(x1 > x0);
    float m = float(dy) / (float)(dx);

    if (abs(m) <= 1)
    {
      if (!isRTL)
      {
        for (x = x0, y = y0; x <= x1; x++)
        {
          putpixel(x, y, val);
          y += m;
        }
      }
      else
      {
        for (x = x1, y = y1; x >= x0; x--)
        {
          putpixel(x, y, val);
          y -= m;
        }
      }
    }
    else if (abs(m) > 1)
    {
      if (!isRTL)
      {
        for (x = x0, y = y0; y <= x1; y++)
        {
          putpixel(x, y, val);
          x += 1 / m;
        }
      }
      else
      {
        for (x = x1, y = y1; y >= x0; y--)
        {
          putpixel(x, y, val);
          x -= 1 / m;
        }
      }
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
  ddaLine(x0, y0, x1, y1, WHITE);
  delay(10e3);
  closegraph();

  cout << "Finished..." << endl;

  return 0;
}
