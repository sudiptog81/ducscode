#include <conio.h>
#include <graphics.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int outcode;
outcode compOutcode(double x, double y);
enum
{
  TOP = 0x1,
  BOTTOM = 0x2,
  RIGHT = 0x4,
  LEFT = 0x8
};

double xmin, xmax, ymin, ymax;

outcode compOutcode(double x, double y)
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

void clipPolygon(int x0, int y0, int x1, int y1)
{
  int accept = 0, done = 0;
  outcode outcode0, outcode1, outcodeOut;

  outcode0 = compOutcode(x0, y0);
  outcode1 = compOutcode(x1, y1);

  do
  {
    if (!(outcode0 | outcode1))
    {
      accept = 1;
      done = 1;
    }
    else if (outcode0 & outcode1)
      done = 1;
    else
    {
      double x, y;
      outcodeOut = outcode0 ? outcode0 : outcode1;
      if (outcodeOut & TOP)
      {
        x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
        y = ymax;
      }
      else if (outcodeOut & BOTTOM)
      {
        x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
        y = ymin;
      }
      else if (outcodeOut & RIGHT)
      {
        y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
        x = xmax;
      }
      else
      {
        y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
        x = xmin;
      }

      if (outcodeOut == outcode0)
      {
        x0 = x;
        y0 = y;
        outcode0 = compOutcode(x0, y0);
      }
      else
      {
        x1 = x;
        y1 = y;
        outcode1 = compOutcode(x1, y1);
      }
    }
  } while (done == 0);

  if (accept)
    line(x0, y0, x1, y1);
}

void main()
{
  int i, n;
  int gd = DETECT, gm;
  int poly[24];

  initgraph(&gd, &gm, "..\\BGI");

  cout << "Enter Bounds of Clipping Rectangle: ";
  cout << "\n\txmin: ";
  cin >> xmin;
  cout << "\tymin: ";
  cin >> ymin;
  cout << "\txmax: ";
  cin >> xmax;
  cout << "\tymax: ";
  cin >> ymax;

  cout << "Enter Number of Edges in Polygon: ";
  cin >> n;

  cout << "Enter Coordinates of the Polygon: ";
  for (i = 0; i < 2 * n; i++)
    cin >> poly[i];

  poly[2 * n] = poly[0];
  poly[2 * n + 1] = poly[1];

  cleardevice();

  rectangle(xmin, ymin, xmax, ymax);
  drawpoly(n + 1, poly);

  getch();
  cleardevice();

  rectangle(xmin, ymin, xmax, ymax);

  for (i = 0; i < n; i++)
    clipPolygon(poly[2 * i], poly[(2 * i) + 1], poly[(2 * i) + 2], poly[(2 * i) + 3]);

  getch();
  closegraph();
}
