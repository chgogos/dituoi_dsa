#include <iostream>
#include <list>

using namespace std;

class Rectangle {
public:
  Rectangle(double w, double h) : width(w), height(h){};
  double area() const { return width * height; }
  void print_info() {
    cout << "Width:" << width << " Height:" << height << " Area "
         << this->area() << endl;
  }

private:
  double width;
  double height;
};

bool operator<(const Rectangle &r1, const Rectangle &r2) {
  return r1.area() < r2.area();
}

int main(int argc, char *argv[]) {
  list<Rectangle> rectangles = {{5,6},{3,3},{5,2},{6,1}};

  rectangles.sort();
  for (auto r : rectangles)
    r.print_info();
}
