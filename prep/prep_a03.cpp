#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Cylinder {
private:
  double radius;
  double height;

public:
  Cylinder(double r, double h) {
    radius = r;
    height = h;
  }
  double get_radius() { return radius; }
  double get_height() { return height; }
  double volume() const { return M_PI * pow(radius, 2) * height; }
  double area() {
    return 2 * M_PI * pow(radius, 2) + height * 2 * M_PI * radius;
  }
  bool operator<(const Cylinder other) const {
    return this->volume() > other.volume();
  }
};

int main(void) {
  Cylinder cyls[5] = {
      {3.1, 2.3}, {5.1, 2.2}, {7.2, 1.1}, {5.1, 2.9}, {3.9, 6.1}};
  cout << "Cylinders: " << endl;

  for (int i = 0; i < 5; i++)
    cout << "Radius: " << cyls[i].get_radius()
         << " height: " << cyls[i].get_height()
         << " volume: " << cyls[i].volume() << " area: " << cyls[i].area()
         << endl;

  sort(cyls, cyls + 5);
  cout << "Sorted by volume: " << endl;
  for (int i = 0; i < 5; i++)
    cout << "Radius: " << cyls[i].get_radius()
         << " height: " << cyls[i].get_height()
         << " volume: " << cyls[i].volume() << " area: " << cyls[i].area()
         << endl;
}