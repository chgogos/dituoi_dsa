#include <forward_list>
#include <iostream>
#include <random>

using namespace std;

constexpr int SIZE = 101;
struct record {
  string key;
  string value;
};

class sc_hashtable {
private:
  forward_list<record *> data[SIZE];

  size_t hash(string &key) {
    size_t value = 0;
    for (int i = 0; i < key.length(); i++)
      value = 37 * value + key[i];
    return value % SIZE;
  }

public:
  ~sc_hashtable() {
    for (int i = 0; i < SIZE; i++)
      for (record *rec : data[i])
        delete rec;
  }

  record *get(string &key) {
    size_t i = hash(key);
    if (data[i].empty())
      return nullptr;
    else
      for (record *rec : data[i])
        if (rec->key == key)
          return rec;
  }

  void put(record *arecord) {
    size_t i = hash(arecord->key);
    data[i].push_front(arecord);
  }

  void print_all() {
    int m = 0;
    for (int i = 0; i < SIZE; i++)
      if (!data[i].empty())
        for (record *rec : data[i]) {
          cout << "#(" << i << ") " << rec->key << rec->value << endl;
          m++;
        }
    cout << "Load factor: " << (double)m / (double)SIZE << endl;
  }
};

int main() {
  sc_hashtable hashtable;
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
