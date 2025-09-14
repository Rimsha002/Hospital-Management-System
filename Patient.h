#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Patient
{
public:
    int id;
    string name;
    int CNIC;
    int phone;
    string disease;
    bool isAdmitted;

    Patient();
    Patient(int id, string name, int CNIC, int phone, string disease, bool isAdmitted);

    int getId() const;
    void displayPatient() const;
    void readFromFile(fstream &file);
    void writeToFile(fstream &file) const;
};

void addPatient(vector<Patient> &patients, fstream &file);
void loadFromFile(vector<Patient> &patients, fstream &file);
void saveToFile(const vector<Patient> &patients, fstream &file);
void deletePatient(vector<Patient> &patients, fstream &file, int id);
void updatePatient(vector<Patient> &patients, fstream &file, int id);
void searchPatient(const vector<Patient> &patients, int id);
void displayAllPatients(const vector<Patient> &patients);

#endif
