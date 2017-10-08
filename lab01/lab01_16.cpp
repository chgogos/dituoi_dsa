#include <climits>
#include <cmath>
#include <cstdio>

struct Point {
  double x;
  double y;
};

int main(int argc, char **argv) {
  struct Point points[5] = {{4, 17}, {10, 21}, {5, 32}, {-1, 16}, {-4, 7}};

  double min = INT_MAX;
  Point a, b;
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++) {
      Point p1 = points[i];
      Point p2 = points[j];
      double distance = sqrt(pow(p2.x - p1.x, 2.0) + pow(p2.y - p1.y, 2.0));
      if (distance < min) {
        min = distance;
        a = p1;
        b = p2;
      }
    }
  printf("Min %.4f\n", min);
  printf("Point A: (%.4f, %.4f)\n", a.x, a.y);
  printf("Point B: (%.4f, %.4f)\n", b.x, b.y);
  return 0;
}
