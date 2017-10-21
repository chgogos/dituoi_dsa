#include <iostream>
#include <list>

using namespace std;

struct Rectangle {
  double width;
  double height;
  bool operator<(Rectangle other) {
    return width * height < other.width * other.height;
  }
};

int main() {
  list<Rectangle> rectangles = {{5, 6}, {3, 3}, {5, 2}, {6, 1}};

  rectangles.sort();
  for (auto r : rectangles)
    cout << "Width:" << r.width << " Height:" << r.height
         << " Area: " << r.width * r.height << endl;
}