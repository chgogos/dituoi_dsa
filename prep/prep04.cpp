#include <iostream>
#include <map>

using namespace std;

int main(void) {
  map<string, int> planets = {{"jupiter", 142981},
                              {"mars", 6779},
                              {"earth", 12742},
                              {"neptune", 49500},
                              {"venus", 12100}};
  string key;
  cout << "Enter the name of a planet: ";
  cin >> key;
  if (planets.find(key) == planets.end())
    cout << "Not found" << endl;
  else
    cout << "Diameter difference with earth:"
         << (double)(planets[key] - planets["earth"]) *100 /
                (double)planets["earth"] << "%" << endl;;
}
