#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

void printVillagers(const map<string, tuple<int, string, string>>& villagers)
void increaseFriendship(map<string, tuple<int, string, string>>& villagers, const string& name)
void decreaseFriendship(map<string, tuple<int, string, string>>& villagers, const string& name)
int main() {
    map<string, tuple<int, string, string>> villagers;
    villagers["Audie"]   = make_tuple(10, string("Wolf"), string("Let's do this!"));
    villagers["Raymond"] = make_tuple(7, string("Cat"),  string("I love coffee."));
    villagers["Marshal"] = make_tuple(9, string("Squirrel"), string("Squeak!"));

    while (true) {
        cout << "Menu:\n"
             << "1. Increase Friendship\n"
             << "2. Decrease Friendship\n"
             << "3. Search for Villager\n"
             << "4. Exit\n"
             << "Enter choice: ";

        int choice;
        
    // access the map using a range-based for loop
    // cout << "Villagers and their data (range-based for loop):" << endl;
    // for (const auto &pair : villagers) {
    //     const auto& [friendshipLevel, species, catchphrase] = pair.second;
    //     const auto& name = pair.first;
    //     const auto& info = pair.second;

    //     cout << name << ": "
    //          << "Friendship Level: " << friendshipLevel << ", "
    //          << "Species: " << species << ", "
    //          << "Catchphrase: " << catchphrase << endl;
    // }

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
