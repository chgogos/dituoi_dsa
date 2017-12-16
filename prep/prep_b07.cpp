#include <iostream>
#include <queue>

using namespace std;

struct customer {
  string name;
  int time;
  bool operator>(customer other) const { return time > other.time; }
};

int main() {
  priority_queue<customer, vector<customer>, greater<customer>> customers;
  int choice, c = 0;
  do {
    cout << "1. Available cashier" << endl;
    cout << "2. Customer arrival" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;
    if (choice == 1) {
      if (customers.empty())
        cout << "No customer is waiting." << endl;
      else {
        customer acustomer = customers.top();
        cout << "The customer " << acustomer.name << " is served." << endl;
        customers.pop();
        c++;
      }
    } else if (choice == 2) {
      customer new_customer;
      cout << "Enter customer name: ";
      cin >> new_customer.name;
      cout << "Enter time on receipt (1..100): ";
      cin >> new_customer.time;
      customers.push(new_customer);
    }
  } while (choice != 3);
  cout << "Customers served: " << c << endl;
  cout << "Customers still in queue: " << customers.size() << endl;
}
