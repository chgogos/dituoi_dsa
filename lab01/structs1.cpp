#include <iostream>

using namespace std;

typedef struct {
  string title;
  int price;
  bool isHardpack;
} Book;

// struct Book
// {
//     string title;
//     int price;
//     bool isHardpack;
// };

void print_book(Book b) {
  cout << "Title: " << b.title << " Price: " << b.price / 100.0
       << " Hardcover: " << (b.isHardpack ? "YES" : "NO") << endl;
}

int main(int argc, char **argv) {
  Book b1, b2, *pb;
  b1.title = "The SIMPSONS and their mathematical secrets";
  b1.price = 1899;
  b1.isHardpack = false;
  b2 = b1;
  b2.isHardpack = true;
  b2.price = 2199;
  pb = new Book;
  pb->title = "Bad Science";
  pb->price = 999;
  pb->isHardpack = false;
  print_book(b1);
  print_book(b2);
  print_book(*pb);
  delete pb;
  return 0;
}
