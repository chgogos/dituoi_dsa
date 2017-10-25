#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  map<string, string> phone_book;
  phone_book.insert(make_pair("nikos", "1234567890"));
  phone_book.insert(make_pair("maria", "2345678901"));
  phone_book.insert(make_pair("petros", "3456789012"));
  phone_book.insert(make_pair("kostas", "4567890123"));

  string name;
  cout << "Enter name: ";
  cin >> name;
  if (phone_book.find(name) == phone_book.end())
    cout << "No such name found ";
  else
    cout << "The phone is " << phone_book[name] << endl;
}
