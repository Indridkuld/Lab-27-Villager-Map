#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {10, "Wolf", "Let's do this!"};
    villagers["Raymond"] = {7, "Cat", "I love coffee."};
    villagers.insert({"Marshal", make_tuple(9, string("Squirrel"), string("Squeak!"))});

    // access the map using a range-based for loop
    cout << "Villagers and their data (range-based for loop):" << endl;
    for (const auto &pair : villagers) {
        const auto& [friendshipLevel, species, catchphrase] = pair.second;
        const auto& name = pair.first;
        const auto& info = pair.second;

        cout << name << ": "
             << "Friendship Level: " << friendshipLevel << ", "
             << "Species: " << species << ", "
             << "Catchphrase: " << catchphrase << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their data (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin(); 
                                               it != villagers.end(); ++it) {
        const string &name = it->first;
        const auto& info = it->second;
        cout << name << ": "
             << "Friendship Level: " << get<0>(info) << ", "
             << "Species: " << get<1>(info) << ", "
             << "Catchphrase: " << get<2>(info) << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
        cout << "\nFound " << searchKey << "'s info: ";
        cout << "Friendship Level: " << get<0>(it->second) << ", "
             << "Species: " << get<1>(it->second) << ", "
             << "Catchphrase: " << get<2>(it->second);
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
