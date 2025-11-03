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
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (const auto &pair : villagers) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagers.begin(); 
                                               it != villagers.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s info: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
