#include "StudyModule.h"
#include <iostream>
#include <string>

using namespace std;

void showMenu() {
  cout << "\n=======================================" << endl;
  cout << "   CS & AI SPACED REPETITION ENGINE    " << endl;
  cout << "=======================================" << endl;
  cout << "1. Start Algorithm Quiz" << endl;
  cout << "2. Start Machine Learning Quiz" << endl;
  cout << "3. Search for Question by ID" << endl;
  cout << "4. Save Progress & Exit" << endl;
  cout << "Choose an option: ";
}

int main() {
  AlgorithmQuiz algoModule(100);
  MachineLearningQuiz mlModule(100);

  // Store the filenames in variables so we can reuse them for saving
  string algoFile = "algorithms_questions.csv";
  string mlFile = "ml_systems_questions.csv";

  cout << "Initializing system and loading datasets..." << endl;
  algoModule.loadDataset(algoFile);
  mlModule.loadDataset(mlFile);
  cout << "System ready.\n" << endl;

  int choice;

  do {
    showMenu();
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
      algoModule.studySession();
    } else if (choice == 2) {
      mlModule.studySession();
    } else if (choice == 3) {
      int searchID;
      cout << "\nEnter Question ID to search: ";
      cin >> searchID;
      cin.ignore();

      cout << "\nSearching Algorithm Database...";
      algoModule.searchByID(searchID);

      cout << "\nSearching ML Database...";
      mlModule.searchByID(searchID);
    } else if (choice == 4) {
      // Save directly back into the CSV files so progress persists!
      cout << "\nSaving progress to databases..." << endl;
      algoModule.saveToFile(algoFile);
      mlModule.saveToFile(mlFile);
      cout << "Exiting program. Goodbye!\n";
    } else {
      cout << "\nInvalid choice. Please enter a number between 1 and 4.\n";
    }
  } while (choice != 4);

  return 0;
}