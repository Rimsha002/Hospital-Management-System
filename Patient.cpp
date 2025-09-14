#include "Patient.h"

int nextId = 1;

Patient::Patient()
{
    id = nextId++;
    name = "";
    CNIC = 0;
    phone = 0;
    disease = "";
    isAdmitted = false;
}

Patient::Patient(int id, string name, int CNIC, int phone, string disease, bool isAdmitted)
{
    this->id = id;
    this->name = name;
    this->CNIC = CNIC;
    this->phone = phone;
    this->disease = disease;
    this->isAdmitted = isAdmitted;
}

int Patient::getId() const
{
    return id;
}

void Patient::displayPatient() const
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "CNIC: " << CNIC << endl;
    cout << "Phone: " << phone << endl;
    cout << "Disease: " << disease << endl;
    cout << "Is Admitted: " << (isAdmitted ? "Yes" : "No") << endl;
    cout << endl;
}

// File Handling
// Read from file
void Patient::readFromFile(fstream &file)
{
    file.read(reinterpret_cast<char *>(&id), sizeof(id));
    size_t nameLength;
    file.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
    name.resize(nameLength);
    file.read(&name[0], nameLength);
    file.read(reinterpret_cast<char *>(&CNIC), sizeof(CNIC));
    file.read(reinterpret_cast<char *>(&phone), sizeof(phone));
    size_t diseaseLength;
    file.read(reinterpret_cast<char *>(&diseaseLength), sizeof(diseaseLength));
    disease.resize(diseaseLength);
    file.read(&disease[0], diseaseLength);
    file.read(reinterpret_cast<char *>(&isAdmitted), sizeof(isAdmitted));
}

// Write to file
void Patient::writeToFile(fstream &file) const
{
    file.write(reinterpret_cast<const char *>(&id), sizeof(id));
    size_t nameLength = name.size();
    file.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength));
    file.write(name.c_str(), nameLength);
    file.write(reinterpret_cast<const char *>(&CNIC), sizeof(CNIC));
    file.write(reinterpret_cast<const char *>(&phone), sizeof(phone));
    size_t diseaseLength = disease.size();
    file.write(reinterpret_cast<const char *>(&diseaseLength), sizeof(diseaseLength));
    file.write(disease.c_str(), diseaseLength);
    file.write(reinterpret_cast<const char *>(&isAdmitted), sizeof(isAdmitted));
}

// Load already saved records from file
void loadFromFile(vector<Patient> &patients, fstream &file)
{
    file.open("Patient_Record.dat", ios::in | ios::binary);
    if (!file.is_open())
    {
        cout << "File not opened for reading\n";
        return;
    }

    patients.clear();
    Patient p;
    while (file.peek() != EOF)
    {
        p.readFromFile(file);
        patients.push_back(p);
    }

    nextId = patients.empty() ? 1 : patients.back().id + 1;

    file.close();
}

// Save records to file
void saveToFile(const vector<Patient> &patients, fstream &file)
{
    file.open("Patient_Record.dat", ios::out | ios::binary);
    if (!file.is_open())
    {
        cout << "File not opened for writing\n";
        return;
    }

    for (const auto &p : patients)
    {
        p.writeToFile(file);
    }

    file.close();
}

//Add Record Function
void addPatient(vector<Patient> &patients, fstream &file)
{
    string name;
    int CNIC;
    int phone;
    string disease;
    bool isAdmitted;

    cout << "Enter the Name of Patient: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the CNIC: ";
    cin >> CNIC;
    cout << "Enter the Phone: ";
    cin >> phone;
    cin.ignore();
    cout << "Enter the Disease: ";
    getline(cin, disease);
    cout << "Is Admitted(Y/N): ";
    char admitChoice;
    cin >> admitChoice;
    isAdmitted = (admitChoice == 'Y' || admitChoice == 'y');

    Patient p(nextId++, name, CNIC, phone, disease, isAdmitted);
    patients.push_back(p);

    file.open("Patient_Record.dat", ios::out | ios::app | ios::binary);
    if (!file.is_open())
    {
        cout << "File not opened for writing\n";
        return;
    }
    p.writeToFile(file);
    file.close();

    cout << "Patient added successfully\n";
};

//Delete Record Function
void deletePatient(vector<Patient> &patients, fstream &file, int id)
{
    bool found = false;
    for (auto it = patients.begin(); it != patients.end(); ++it)
    {
        if (it->getId() == id)
        {
            patients.erase(it);
            cout << "Patient deleted successfully\n";
            saveToFile(patients, file);
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "No record found\n";
    }
};

//Update Record Function
void updatePatient(vector<Patient> &patients, fstream &file, int id)
{
    bool found = false;
    for (auto &patient : patients)
    {
        if (patient.getId() == id)
        {
            cout << "Enter updated Name of Patient: ";
            cin.ignore();
            getline(cin, patient.name);
            cout << "Enter updated CNIC: ";
            cin >> patient.CNIC;
            cout << "Enter updated Phone: ";
            cin >> patient.phone;
            cin.ignore();
            cout << "Enter updated Disease: ";
            getline(cin, patient.disease);
            cout << "Is Admitted(Y/N): ";
            char admitChoice;
            cin >> admitChoice;
            patient.isAdmitted = (admitChoice == 'Y' || admitChoice == 'y');

            cout << "Patient updated successfully\n";
            saveToFile(patients, file);
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "No record found\n";
    }
};

//Search Record Function
void searchPatient(const vector<Patient> &patients, int id) 
{
    bool found = false;
    for (const auto &patient : patients) {
        if (patient.getId() == id) {
            cout << "Patient found:\n";
            patient.displayPatient();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No record found\n";
    }
};

//Display All Records Function
void displayAllPatients(const vector<Patient> &patients)
{
    if (patients.empty())
    {
        cout << "No patients to display\n";
    }
    else
    {
        for (const auto &patient : patients)
        {
            patient.displayPatient();
        }
    }
}
