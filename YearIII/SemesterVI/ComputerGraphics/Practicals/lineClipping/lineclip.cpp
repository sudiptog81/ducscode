#include <conio.h>
#include <graphics.h>
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int outcode;
enum
{
  TOP = 0x1,
  BOTTOM = 0x2,
  RIGHT = 0x4,
  LEFT = 0x8
};

outcode computeOutcode(double x, double y, double xmin, double xmax, double ymin, double ymax)
{
  outcode code = 0;

  if (y > ymax)
    code |= TOP;

  else if (y < ymin)
    code |= BOTTOM;

  if (x > xmax)
    code |= RIGHT;

  else if (x < xmin)
    code |= LEFT;

  return code;
}

void clipLine(double x0, double yo, double x1, double y1, double xmin, double xmax, double ymin, double ymax)
{
  int accept = 0, done = 0;
  outcode outcode0, outcode1, outcodeout;

  outcode0 = computeOutcode(x0, yo, xmin, xmax, ymin, ymax);
  outcode1 = computeOutcode(x1, y1, xmin, xmax, ymin, ymax);

  do
  {
    if (!(outcode0 | outcode1))
    {
      accept = 1;
      done = 1;
    }

    else if (outcode0 & outcode1)
    {
      done = 1;
    }

    else
    {
      double x, y;
      outcodeout = outcode0 ? outcode0 : outcode1;

      if (outcodeout & TOP)
      {
        x = x0 + (ymax - yo) * (x1 - x0) / (y1 - yo);
        y = ymax;
      }
      else if (outcodeout & BOTTOM)
      {
        x = x0 + (ymin - yo) * (x1 - x0) / (y1 - yo);
        y = ymin;
      }
      else if (outcodeout & LEFT)
      {
        y = yo + (xmin - x0) * (y1 - yo) / (x1 - x0);
        x = xmin;
      }
      else
      {
        y = yo + (xmax - x0) * (y1 - yo) / (x1 - x0);
        x = xmax;
      }

      if (outcodeout == outcode0)
      {
        x0 = x;
        yo = y;
        outcode0 = computeOutcode(x0, yo, xmin, xmax, ymin, ymax);
      }
      else
      {
        x1 = x;
        y1 = y;
        outcode1 = computeOutcode(x1, y1, xmin, xmax, ymin, ymax);
      }
    }
  } while (done == 0);

  if (accept)
    line(x0, yo, x1, y1);
}

int main(void)
{
  int gd = DETECT, gm;
  double x0, x1, y0, y1;
  double xmin, ymin, xmax, ymax;

  initgraph(&gd, &gm, "..\\BGI");

  cout << "Enter Point A (x0, y0): ";
  cin >> x0 >> y0;

  cout << "Enter Point B (x1, y1): ";
  cin >> x1 >> y1;

  cout << "Enter Bounds of Clipping Rectangle : ";
  cout << "\n\txmin: ";
  cin >> xmin;
  cout << "\tymin: ";
  cin >> ymin;
  cout << "\txmax: ";
  cin >> xmax;
  cout << "\tymax: ";
  cin >> ymax;

  cleardevice();

  line(xmin, ymin, xmax, ymin);
  line(xmin, ymin, xmin, ymax);
  line(xmin, ymax, xmax, ymax);
  line(xmax, ymin, xmax, ymax);
  line(x0, y0, x1, y1);

  getch();
  cleardevice();

  line(xmin, ymin, xmax, ymin);
  line(xmin, ymin, xmin, ymax);
  line(xmin, ymax, xmax, ymax);
  line(xmax, ymin, xmax, ymax);
  clipLine(x0, y0, x1, y1, xmin, xmax, ymin, ymax);

  getch();
  closegraph();
  return 0;
}
