#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {

  cout << "Example1: call lambda function" << endl;
  cout << "Area = " << [](double x, double y) { return x * y; }(3.0, 4.5)
       << endl;

  cout << "Example2: assign lambda function to variable" << endl;
  auto area = [](double x, double y) { return x * y; };
  cout << "Area = " << area(3.0, 4.5) << endl;
  cout << "Area = " << area(7.0, 5.5) << endl;

  vector<int> v{5, 1, 3, 2, 8, 7, 4, 5};
  // find_if
  cout << "Example3: find the first even number in the vector" << endl;
  vector<int>::iterator iter =
      find_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
  cout << *iter << endl;

  // count_if
  cout << "Example4: count the number of even numbers in the vector" << endl;
  int c = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
  cout << c << endl;

  // sort
  cout << "Example5: sort list of rectangles by area (ascending)" << endl;
  struct Rectangle {
    double width;
    double height;
  };
  list<Rectangle> rectangles_list = {{5, 6}, {3, 3}, {5, 2}, {6, 1}};
  rectangles_list.sort([](Rectangle &r1, Rectangle &r2) {
    return r1.width * r1.height < r2.width * r2.height;
  });
  for (Rectangle r : rectangles_list)
    cout << "Width:" << r.width << " Height:" << r.height
         << " Area: " << r.width * r.height << endl;

  cout << "Example6: sort vector of rectangles by area (descending)" << endl;
  vector<Rectangle> rectangles_vector = {{5, 6}, {3, 3}, {5, 2}, {6, 1}};
  sort(rectangles_vector.begin(), rectangles_vector.end(),
       [](Rectangle &r1, Rectangle &r2) {
         return r1.width * r1.height > r2.width * r2.height;
       });
  for (Rectangle r : rectangles_vector)
    cout << "Width:" << r.width << " Height:" << r.height
         << " Area: " << r.width * r.height << endl;

  // for_each
  cout << "Example7: for_each" << endl;
  for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });
  cout << endl;
  for_each(v.begin(), v.end(), [](int i) { cout << i * i << " "; });
  cout << endl;
}
