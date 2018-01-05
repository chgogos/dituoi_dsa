#include <iostream>

using namespace std;

struct record {
  string key;
  string value;
};

class oa_hashtable {
private:
  int capacity;
  int size;
  record **data; // array of pointers to records

  size_t hash(string &key) {
    size_t value = 0;
    for (size_t i = 0; i < key.length(); i++)
      value = 37 * value + key[i];
    return value % capacity;
  }

public:
  oa_hashtable(int capacity) {
    this->capacity = capacity;
    size = 0;
    data = new record *[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = nullptr;
  }

  ~oa_hashtable() {
    for (size_t i = 0; i < capacity; i++)
      if (data[i] != nullptr)
        delete data[i];
    delete[] data;
  }

  record *get(string &key) {
    size_t hash_code = hash(key);
    while (data[hash_code] != nullptr) {
      if (data[hash_code]->key == key)
        return data[hash_code];
      hash_code = (hash_code + 1) % capacity;
    }
    return nullptr;
  }

  void put(record *arecord) {
    if (size == capacity)
      cerr << "The hashtable is full" << endl;
    size_t hash_code = hash(arecord->key);
    while (data[hash_code] != nullptr && data[hash_code]->key != "ERASED") {
      if (data[hash_code]->key == arecord->key) {
        delete data[hash_code];
        data[hash_code] = arecord; // update existing key
        return;
      }
      hash_code = (hash_code + 1) % capacity;
    }
    data[hash_code] = arecord;
    size++;
  }

  void erase(string &key) {
    size_t hash_code = hash(key);
    while (data[hash_code] != nullptr) {
      if (data[hash_code]->key == key) {
        delete data[hash_code];
        data[hash_code] = new record{"ERASED", "ERASED"}; // insert dummy record
        size--;
        return;
      }
      hash_code = (hash_code + 1) % capacity;
    }
  }

  void print_all() {
    for (int i = 0; i < capacity; i++)
      if (data[i] != nullptr && data[i]->key != "ERASED")
        cout << "#(" << i << ") " << data[i]->key << " " << data[i]->value
             << endl;
    cout << "Load factor: " << (double)size / (double)capacity << endl;
  }
};

int main() {
  oa_hashtable hashtable(101); // hashtable with maximum capacity 101 items
  record *precord1 = new record{"John Smith", "+1-555-1234"};
  record *precord2 = new record{"Lisa Smith", "+1-555-8976"};
  record *precord3 = new record{"Sam Doe", "+1-555-5030"};
  hashtable.put(precord1);
  hashtable.put(precord2);
  hashtable.put(precord3);
  hashtable.print_all();
  string key = "Sam Doe";
  record *precord = hashtable.get(key);
  if (precord == nullptr)
    cout << "Key not found" << endl;
  else {
    cout << "Key found: " << precord->key << " " << precord->value << endl;
    hashtable.erase(key);
  }
  hashtable.print_all();
}
