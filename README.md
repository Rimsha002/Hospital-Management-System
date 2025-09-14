# Hospital-Management-System
Object Oriented Programming Assignment <br><br>

## Overview <br>
The Patient Management System is a simple C++ application that allows users to manage patient records efficiently. It supports adding, updating, deleting, searching, displaying, and persisting patient data using file handling. <br>

## Features <br>
1- Add Patient: Register new patients with their details. <br>
2- Update Patient: Modify existing patient records. <br>
3- Delete Patient: Remove patient records from the system.<br>
4- Search Patient: Find and display patient information using their unique ID.<br>
5- Display All Patients: View a list of all registered patients.<br>
6- File Handling: Save and load patient records to/from a binary file.<br>

## Files in the Repository<br>
Patient.h → Header file containing class definition and function declarations.<br>
Patient.cpp → Implementation file with function definitions.<br>
main.cpp → Entry point for the application.<br>
Patient_Record.dat → Binary file for storing patient records.<br>

## Installation & Usage<br>
Prerequisites
  g++ main.cpp Patient.cpp -o PatientManagement  
<br>

### ▶️ Running the Program  <br>
After compilation, run the executable:  <br>
sh  
 ./PatientManagement  
 <br>

## 🔍 How It Works  <br>
1. The system assigns a unique **ID** to each patient.  <br>
2. Patient details are stored in a binary file (`Patient_Record.dat`).  <br>
3. The system provides **menu-driven interaction** to manage patient records.  <br>
4. Operations like *add, delete, search, and update* modify the data both in memory and in the file.  <br>

## Code Structure  <br>
- **Class `Patient` **: Handles individual patient records.  <br>
- **Standalone Functions**:  <br>
  -  `addPatient()` - Adds a new patient.  <br>
  - `updatePatient()` - Updates patient details.  <br>
  -  `deletePatient()` - Deletes a patient record.  <br>
  -  `searchPatient()` - Searches for a patient by ID.  <br>
  -  `displayAllPatients()` - Displays all patient records.  <br>
  -  `loadFromFile()` - Loads patient records from a binary file.  <br>
  -  `saveToFile()` - Saves patient records to a binary file.  <br>

##  Future Enhancements  <br>
-  Implement a **Graphical User Interface (GUI)**.  <br>
-  Add **sorting and filtering** for patient records.  <br>
-  Enhance file security with **encryption**.  <br>

## Contributing  <br>
Feel free to **fork** the repository, submit **pull requests**, or **report issues**. Contributions to improve the system are always welcome!  <br>

