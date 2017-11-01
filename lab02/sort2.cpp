#include <iostream>
#include <list>

using namespace std;

class Rectangle {
public:
  Rectangle(double w, double h) : width(w), height(h){};
  double area() const { return width * height; } // must be const
  void print_info() {
    cout << "Width:" << width << " Height:" << height << " Area "
         << this->area() << endl;
  }
  bool operator<(const Rectangle &other) const {
    return this->area() < other.area();
  }

private:
  double width;
  double height;
};

int main(int argc, char *argv[]) {
  list<Rectangle> rectangles;
  rectangles.push_back(Rectangle(5, 6));
  rectangles.push_back(Rectangle(3, 3));
  rectangles.push_back(Rectangle(5, 2));
  rectangles.push_back(Rectangle(6, 1));

  rectangles.sort();
  for (auto r : rectangles)
    r.print_info();
}
