#include <iostream>
#include <fstream>
#include <vector>
#include "Patient.h"

using namespace std;

void displayMenu() {
    cout << "\nSelect the option or -1 to exit: \n"
        << "1- Add Patient to file\n"
        << "2- Read Patient Data from file\n"
        << "3- Delete Patient from file\n"
        << "4- Update Patient\n"
        << "5- Search Patient\n"
        << "6- Display All Patient data\n"
        << "7- Exit\n"
        << "Enter option: ";
}

int main() {
    vector<Patient> patients;
    fstream file;

    loadFromFile(patients, file);

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
			cout << "--Adding Patient to file--\n";
            addPatient(patients, file);
            break;
        }
        case 2: 
        {
			cout << "--Reading Patient Data from file--\n";
            loadFromFile(patients, file);
            displayAllPatients(patients);
            break;
        }
        case 3: {
			cout << "--Deleting Patient--\n";
            int id;
            cout << "Enter the ID to delete: ";
            cin >> id;
            deletePatient(patients, file, id);
            break;
        }
        case 4: {
			cout << "--Updating Patient--\n";
            int id;
            cout << "Enter the ID to update: ";
            cin >> id;
            updatePatient(patients, file, id);
            break;
        }
        case 5: 
        {
			cout << "--Searching Patient--\n";
            int id;
            cout << "Enter the ID to search: ";
            cin >> id;
            searchPatient(patients, id);
            break;
        }
        case 6: 
        {
			cout << "--Displaying All Patients--\n";
            displayAllPatients(patients);
            break;
        }
        case 7: 
        {
            cout << "Exiting the program\n";
            cout << "---ByeBye---\n";
            choice = -1;
            break;
        }
        default: {
            cout << "Invalid option\n";
            break;
        }
        }
    } while (choice != -1);

    return 0;
}
