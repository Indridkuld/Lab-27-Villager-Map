#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

void printVillagers(const map<string, tuple<int, string, string>>& villagers);
void increaseFriendship(map<string, tuple<int, string, string>>& villagers, const string& name);
void decreaseFriendship(map<string, tuple<int, string, string>>& villagers, const string& name);
void searchVillager(const map<string, tuple<int, string, string>>& villagers, const string& name);

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
        if (!(cin >> choice)) {
                cin.clear();
                cin.ignore();
                cout << "Please enter a valid number (1–4).\n";
                continue;
        }
        cin.ignore(); // clear input buffer

        if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }

        string name;
        switch (choice) {
            case 1:
                cout << "Enter villager name to increase friendship: ";
                getline(cin, name);
                increaseFriendship(villagers, name);
                printVillagers(villagers);
                break;

            case 2:
                cout << "Enter villager name to decrease friendship: ";
                getline(cin, name);
                decreaseFriendship(villagers, name);
                printVillagers(villagers);
                break;

            case 3:
                cout << "Enter villager name to search: ";
                getline(cin, name);
                searchVillager(villagers, name);
                printVillagers(villagers);
                break;

            default:
                cout << "Invalid choice. Please enter 1–4.\n";
                break;
        }
    }

    return 0;
}

// function def
// Function to print the villagers map
void printVillagers(const map<string, tuple<int, string, string>>& villagers) {
    cout << "\nVillager details:\n";
    for (const auto& pair : villagers) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]\n";
    }
    cout << endl;
}

// Increase friendship by 1
void increaseFriendship(map<string, tuple<int, string, string>>& villagers, const string& name) {
    auto it = villagers.find(name);
    if (it == villagers.end()) {
        cout << "Villager \"" << name << "\" not found.\n";
        return;
    }

    int& level = get<0>(it->second);
    level++;
    cout << "Increased " << name << "'s friendship to " << level << ".\n";
}
// Decrease friendship by 1, but not below 0
void decreaseFriendship(map<string, tuple<int, string, string>>& villagers, const string& name) {
    auto it = villagers.find(name);
    if (it == villagers.end()) {
        cout << "Villager \"" << name << "\" not found.\n";
        return;
    }

    int& level = get<0>(it->second);
    level = max(0, level - 1);
    cout << "Decreased " << name << "'s friendship to " << level << ".\n";
}
// Search for a specific villager
void searchVillager(const map<string, tuple<int, string, string>>& villagers, const string& name) {
    auto it = villagers.find(name);
    if (it == villagers.end()) {
        cout << "Villager \"" << name << "\" not found.\n";
        return;
    }

    cout << "Found " << name << ": ["
         << get<0>(it->second) << ", "
         << get<1>(it->second) << ", "
         << get<2>(it->second) << "]\n";
}
