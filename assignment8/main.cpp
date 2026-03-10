#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Step 1: Define the Patient struct
struct Patient {
  int id;
  string name;
  int age;
  string gender;
  string diagnosis;
};

// Step 6: Binary Search Function
int binarySearch(Patient patients[], int size, int searchID) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (patients[mid].id == searchID)
      return mid;

    if (patients[mid].id < searchID)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

int main() {
  // Step 2: Dynamic Array Requirement
  int capacity = 100;
  Patient *patients = new Patient[capacity];
  int count = 0;
  int choice;

  do {
    // Step 3: Create Menu
    cout << "\nHospital Patient System\n";
    cout << "1. Add Patient\n";
    cout << "2. Display Patients\n";
    cout << "3. Search Patient\n";
    cout << "4. Update Patient\n";
    cout << "5. Save Patients\n";
    cout << "6. Exit\n";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
      // Step 4: Add Patient
      if (count < capacity) {
        cout << "Enter Patient ID: ";
        cin >> patients[count].id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, patients[count].name);
        cout << "Enter Age: ";
        cin >> patients[count].age;
        cout << "Enter Gender: ";
        cin >> patients[count].gender;
        cout << "Enter Diagnosis: ";
        cin.ignore();
        getline(cin, patients[count].diagnosis);
        count++;
      } else {
        cout << "System at capacity.\n";
      }
    } else if (choice == 2) {
      // Step 5: Display Patients
      cout << "\nPatient Records\n";
      for (int i = 0; i < count; i++) {
        cout << "--------------------\n";
        cout << "ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
      }
    } else if (choice == 3) {
      // Step 6: Search Patient
      int searchID;
      cout << "Enter patient ID to search: ";
      cin >> searchID;

      int result = binarySearch(patients, count, searchID);
      if (result != -1) {
        cout << "\nPatient Found\n";
        cout << "Name: " << patients[result].name << endl;
        cout << "Age: " << patients[result].age << endl;
        cout << "Diagnosis: " << patients[result].diagnosis << endl;
      } else {
        cout << "\nPatient not found.\n";
      }
    } else if (choice == 4) {
      // Step 7: Update Patient
      int updateID;
      cout << "Enter patient ID to update: ";
      cin >> updateID;

      int index = binarySearch(patients, count, updateID);
      if (index != -1) {
        cout << "Enter new diagnosis: ";
        cin.ignore();
        getline(cin, patients[index].diagnosis);
        cout << "Record updated successfully.\n";
      } else {
        cout << "Patient ID not found.\n";
      }
    } else if (choice == 5) {
      // Step 8: Store patient data
      ofstream outFile("patients.txt");
      if (outFile.is_open()) {
        for (int i = 0; i < count; i++) {
          outFile << patients[i].id << " " << patients[i].name << " "
                  << patients[i].age << " " << patients[i].gender << " "
                  << patients[i].diagnosis << endl;
        }
        outFile.close();
        cout << "Data saved to patients.txt\n";
      } else {
        cout << "Error opening file.\n";
      }
    } else if (choice == 6) {
      // Step 8 (Final): Exit Program
      cout << "Good Bye!\n";
    }

  } while (choice != 6);

  // Clean up dynamic memory
  delete[] patients;

  return 0;
}