#include <iostream>
#include <map>
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

    // helper to print the map contents
    auto printVillagers = [&](const map<string, tuple<int, string, string>> &m) {
        cout << "\nVillager details:" << endl;
        for (const auto &p : m) {
            const string &name = p.first;
            const auto &info = p.second;
            cout << name << " [" << get<0>(info) << ", "
                 << get<1>(info) << ", " << get<2>(info) << "]" << endl;
        }
    };

    // simple menu-driven loop
    while (true) {
        cout << "\nMenu:\n"
             << "1. Increase Friendship\n"
             << "2. Decrease Friendship\n"
             << "3. Search for Villager\n"
             << "4. Exit\n"
             << "Choose an option: ";

        string line;
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        int choice = 0;
        try { choice = stoi(line); } catch (...) { cout << "Invalid choice\n"; continue; }

        if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }

        if (choice == 1 || choice == 2) {
            cout << "Enter villager name: ";
            string name;
            if (!getline(cin, name)) break;
            auto it = villagers.find(name);
            if (it == villagers.end()) {
                cout << name << " not found.\n";
            } else {
                int &level = const_cast<int&>(get<0>(it->second));
                if (choice == 1) {
                    if (level < 10) { level += 1; cout << name << " friendship increased to " << level << "\n"; }
                    else cout << name << " is already at maximum friendship (10).\n";
                } else {
                    if (level > 0) { level -= 1; cout << name << " friendship decreased to " << level << "\n"; }
                    else cout << name << " is already at minimum friendship (0).\n";
                }
            }
        } else if (choice == 3) {
            cout << "Enter villager name to search: ";
            string name;
            if (!getline(cin, name)) break;
            auto it = villagers.find(name);
            if (it != villagers.end()) {
                const auto &info = it->second;
                cout << it->first << " [" << get<0>(info) << ", " << get<1>(info)
                     << ", " << get<2>(info) << "]" << endl;
            } else {
                cout << name << " not found." << endl;
            }
        } else {
            cout << "Invalid choice" << endl;
        }

        // after every operation show the full map contents
        printVillagers(villagers);
    }

    return 0;
}
