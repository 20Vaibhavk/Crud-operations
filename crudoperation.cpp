#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
};

vector<Contact> contacts;

void createContact() {
    string name, phone;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phone;
    contacts.push_back({ name, phone });
}

void readContact() {
    string phone;
    cout << "Enter phone number: ";
    cin >> phone;
    for (const auto& contact : contacts) {
        if (contact.phone == phone) {
            cout << "Name: " << contact.name << endl;
            return;
        }
    }
    cout << "Contact not found" << endl;
}

void updateContact() {
    string phone, name;
    cout << "Enter phone number: ";
    cin >> phone;
    for (auto& contact : contacts) {
        if (contact.phone == phone) {
            cout << "Enter new name: ";
            cin >> name;
            contact.name = name;
            cout << "Contact updated" << endl;
            return;
        }
    }
    cout << "Contact not found" << endl;
}

void deleteContact() {
    string phone;
    cout << "Enter phone number: ";
    cin >> phone;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->phone == phone) {
            contacts.erase(it);
            cout << "Contact deleted" << endl;
            return;
        }
    }
    cout << "Contact not found" << endl;
}

int main() {
    while (true) {
        char operation;
        cout << "Enter C to create, R to read, U to update, or D to delete: ";
        cin >> operation;
        switch (operation) {
            case 'C':
                createContact();
                break;
            case 'R':
                readContact();
                break;
            case 'U':
                updateContact();
                break;
            case 'D':
                deleteContact();
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }
    }
    return 0;
}