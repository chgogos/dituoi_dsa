#include <iostream>
#include <list>

using namespace std;

struct record {
  string key;
  string value;
};

class sc_hashtable {
private:
  int size;
  list<record *> *buckets;

  size_t hash(string &key) {
    size_t value = 0;
    for (size_t i = 0; i < key.length(); i++)
      value = 37 * value + key[i];
    return value % size;
  }

public:
  sc_hashtable(int size) {
    this->size = size;
    buckets = new list<record *>[size];
  }

  ~sc_hashtable() {
    for (size_t i = 0; i < size; i++)
      for (record *rec : buckets[i])
        delete rec;
    delete[] buckets;
  }

  record *get(string &key) {
    size_t hash_code = hash(key);
    if (buckets[hash_code].empty())
      return nullptr;
    else
      for (record *rec : buckets[hash_code])
        if (rec->key == key)
          return rec;
    return nullptr;
  }

  void put(record *arecord) {
    size_t hash_code = hash(arecord->key);
    buckets[hash_code].push_back(arecord);
  }

  void erase(string &key) {
    size_t hash_code = hash(key);
    list<record *>::iterator itr = buckets[hash_code].begin();
    while (itr != buckets[hash_code].end())
      if ((*itr)->key == key)
        itr = buckets[hash_code].erase(itr);
      else
        ++itr;
  }

  void print_all() {
    int m = 0;
    for (size_t i = 0; i < size; i++)
      if (!buckets[i].empty())
        for (record *rec : buckets[i]) {
          cout << "#(" << i << ") " << rec->key << " " << rec->value << endl;
          m++;
        }
    cout << "Load factor: " << (double)m / (double)size << endl;
  }
};

int main() {
  sc_hashtable hashtable(101);
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
