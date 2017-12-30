#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, double> atomic_mass{{"H", 1.008},   // Hydrogen
                                            {"C", 12.011}}; // Carbon
  atomic_mass["O"] = 15.999;                                // Oxygen
  atomic_mass["Fe"] = 55.845;                               // Iron
  atomic_mass.insert(make_pair("Al", 26.982));              // Aluminium

  for (unordered_map<string, double>::iterator itr = atomic_mass.begin();
       itr != atomic_mass.end(); itr++)
    cout << itr->first << ":" << itr->second << " ";
  cout << endl;

  for (const std::pair<string, double> &kv : atomic_mass)
    cout << kv.first << ":" << kv.second << " ";
  cout << endl;

  string element = "Fe";
  //   string element = "Ti"; // Titanium
  if (atomic_mass.find(element) == atomic_mass.end())
    cout << "Element " << element << " is not in the map" << endl;
  else
    cout << "Element " << element << " has atomic mass " << atomic_mass[element]
         << "" << endl;
}