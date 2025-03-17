#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Face Database (Simulated)
vector<string> knownFaces = {"Alice", "Bob"};
vector<string> facePatterns = {
    "101010010101",  // Sample binary pattern for Alice
    "110011001100"   // Sample binary pattern for Bob
};

// Function to add a new face to the system
void addNewFace() {
    string name, pattern;
    cout << "Enter name for the new face: ";
    cin >> name;

    cout << "Enter binary pattern for the new face (e.g., 1010011101): ";
    cin >> pattern;

    knownFaces.push_back(name);
    facePatterns.push_back(pattern);

    cout << "New face added: " << name << endl;
}

// Function to remove a face from the system
void removeFace() {
    string name;
    cout << "Enter the name of the face to remove: ";
    cin >> name;

    for (size_t i = 0; i < knownFaces.size(); i++) {
        if (knownFaces[i] == name) {
            knownFaces.erase(knownFaces.begin() + i);
            facePatterns.erase(facePatterns.begin() + i);
            cout << "Face removed: " << name << endl;
            return;
        }
    }
    cout << "Face not found!" << endl;
}

// Function to display all known faces
void displayKnownFaces() {
    cout << "\nRegistered Faces in the System:\n";
    for (size_t i = 0; i < knownFaces.size(); i++) {
        cout << "- " << knownFaces[i] << " (" << facePatterns[i] << ")" << endl;
    }
}

// Function to search for a face by name
void searchFace() {
    string name;
    cout << "Enter the name to search: ";
    cin >> name;

    for (size_t i = 0; i < knownFaces.size(); i++) {
        if (knownFaces[i] == name) {
            cout << "Face found: " << knownFaces[i] << " (Pattern: " << facePatterns[i] << ")" << endl;
            return;
        }
    }
    cout << "Face not found!" << endl;
}

// Function to update the binary pattern of a face
void updateFacePattern() {
    string name, newPattern;
    cout << "Enter the name of the face to update: ";
    cin >> name;

    for (size_t i = 0; i < knownFaces.size(); i++) {
        if (knownFaces[i] == name) {
            cout << "Enter the new binary pattern: ";
            cin >> newPattern;
            facePatterns[i] = newPattern;
            cout << "Face pattern updated successfully!" << endl;
            return;
        }
    }
    cout << "Face not found!" << endl;
}

// Main function
int main() {
    cout << "Real-Time Face Management System (Simulation)" << endl;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add New Face\n";
        cout << "2. Remove Face\n";
        cout << "3. Display Known Faces\n";
        cout << "4. Search Face by Name\n";
        cout << "5. Update Face Pattern\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
            case 1: addNewFace(); break;
            case 2: removeFace(); break;
            case 3: displayKnownFaces(); break;
            case 4: searchFace(); break;
            case 5: updateFacePattern(); break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    }

    cout << "Exiting program..." << endl;
    return 0;
}