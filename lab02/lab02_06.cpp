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
  // 1st way
  bool operator<(const Rectangle &other) { return this->area() < other.area(); }

private:
  double width;
  double height;
};

// 2nd way
// bool operator<(const Rectangle &r1, const Rectangle &r2) {
//   return r1.area() < r2.area();
// }

int main() {
  list<Rectangle> rectangles;
  rectangles.push_back(Rectangle(5, 6));
  rectangles.push_back(Rectangle(3, 3));
  rectangles.push_back(Rectangle(5, 2));
  rectangles.push_back(Rectangle(6, 1));

  //  1st and 2nd way
  rectangles.sort();

  // 3nd way
  //   struct CompareRectangle {
  //     bool operator()(Rectangle lhs, Rectangle rhs) {
  //       return lhs.area() < rhs.area();
  //     }
  //   };
  //   rectangles.sort(CompareRectangle());

  // 4th way
  //   rectangles.sort([](const Rectangle &r1, const Rectangle &r2) { return
  //   r1.area() < r2.area(); });

  for (auto r : rectangles)
    r.print_info();
}