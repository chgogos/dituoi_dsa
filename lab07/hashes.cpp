#include <string>

using namespace std;

size_t hash0(string &key) {
  size_t h = 0;
  for (char c : key)
    h += c;
  return h;
}

size_t hash1(string &key) {
  size_t h = 0;
  for (char c : key)
    h = 37 * h + c;
  return h;
}

// Jenkins One-at-a-time hash
size_t hash2(string &key) {
  size_t h = 0;
  for (char c : key) {
    h += c;
    h += (h << 10);
    h ^= (h >> 6);
  }
  h += (h << 3);
  h ^= (h >> 11);
  h += (h << 15);
  return h;
}

// FNV (Fowler–Noll–Vo) hash
size_t hash3(string &key) {
  size_t h = 0x811c9dc5;
  for (char c : key)
    h = (h ^ c) * 0x01000193;
  return h;
}
