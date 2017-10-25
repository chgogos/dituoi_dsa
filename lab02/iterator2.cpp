#include <iostream>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
  map<string, int> cities_population_2011 = {{"arta", 21895},
                                             {"ioannina", 65574},
                                             {"preveza", 19042},
                                             {"igoumenitsa", 9145}};

  cout << "Cities of Epirus using range for:" << endl;
  for (auto kv : cities_population_2011)
    cout << kv.first << " " << kv.second << endl;

  cout << "Cities of Epirus using iterator:" << endl;
  for (map<string, int>::iterator iter = cities_population_2011.begin();
       iter != cities_population_2011.end(); iter++)
    cout << iter->first << " " << iter->second << endl;

  cout << "Cities of Epirus using reverse iterator:" << endl;
  for (map<string, int>::reverse_iterator iter = cities_population_2011.rbegin();
       iter != cities_population_2011.rend(); iter++)
    cout << iter->first << " " << iter->second << endl;
}
