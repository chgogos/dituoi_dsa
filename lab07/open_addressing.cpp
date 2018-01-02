#include <iostream>
#include <random>

using namespace std;

constexpr int SIZE = 101; // HASHTABLE SIZE
struct record {
  string key;
  string value;
};

class oa_hashtable {
private:
  record *data[SIZE];
  int number_of_items;

  size_t hash(string &key) {
    size_t value = 0;
    for (int i = 0; i < key.length(); i++)
      value = 37 * value + key[i];
    return value % SIZE;
  }

public:
  oa_hashtable() {
    for (int i = 0; i < SIZE; i++)
      data[i] = nullptr;
    number_of_items = 0;
  }

  ~oa_hashtable() {
    for (int i = 0; i < SIZE; i++)
      if (data[i] != nullptr)
        delete data[i];
  }

  record *get(string &key) {
    size_t i = hash(key);
    while (data[i] != nullptr) {
      if (data[i]->key == key)
        return data[i];
      i = (i + 1) % SIZE;
    }
    return nullptr;
  }

  void put(record *arecord) {
    if (number_of_items == SIZE)
      cerr << "The hashtable is full" << endl;
    size_t i = hash(arecord->key);
    while (data[i] != nullptr) {
      if (data[i]->key == arecord->key) {
        number_of_items--;
        delete data[i];
        data[i] = arecord;
      }
      i = (i + 1) % SIZE;
    }
    data[i] = arecord;
    number_of_items++;
  }

  void print_all() {
    for (int i = 0; i < SIZE; i++)
      if (data[i] != nullptr)
        cout << "#(" << i << ") " << data[i]->key << data[i]->value << endl;
    cout << "Load factor: " << (double)number_of_items / (double)SIZE << endl;
  }
};

int main() {
  oa_hashtable hashtable;
  record *precord1 = new struct record();
  precord1->key = "John Smith";
  precord1->value = "+1-555-1234";
  record *precord2 = new struct record();
  precord2->key = "Lisa Smith";
  precord2->value = "+1-555-8976";
  record *precord3 = new struct record();
  precord3->key = "Sam Doe";
  precord3->value = "+1-555-5030";
  hashtable.put(precord1);
  hashtable.put(precord2);
  hashtable.put(precord3);

  string key = "Sam Doe";
  record *precord = hashtable.get(key);
  if (precord == nullptr)
    cout << "Key not found" << endl;
  else
    cout << "Key found: " << precord->key << " " << precord->value << endl;

  hashtable.print_all();
}
