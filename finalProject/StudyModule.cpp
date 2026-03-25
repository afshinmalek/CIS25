#include "StudyModule.h"
#include <fstream>
#include <iostream>

using namespace std;

// Base Class Constructor: Allocate dynamic array and initialize stats
StudyModule::StudyModule(int cap) {
  capacity = cap;
  count = 0;
  deck = new Question[capacity];
  sessionTotalAnswered = 0;
  sessionCorrect = 0;
  sessionIncorrect = 0;
}

// Base Class Destructor: Free memory
StudyModule::~StudyModule() { delete[] deck; }

// Read CSV and populate dynamic array
// Read CSV and populate dynamic array
void StudyModule::loadDataset(string filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Error: Could not open " << filename << endl;
    return;
  }

  string line, idStr, topic, prompt, answer, streakStr;
  getline(file, line); // Skip header row

  while (getline(file, idStr, ',') && count < capacity) {
    deck[count].id = stoi(idStr);
    getline(file, topic, ',');
    deck[count].topic = topic;
    getline(file, prompt, ',');
    deck[count].prompt = prompt;
    getline(file, answer, ','); // Stop at the comma before the streak
    deck[count].answer = answer;

    // NEW: Read the 5th column to load your saved progress!
    getline(file, streakStr);
    deck[count].streak = stoi(streakStr);

    count++;
  }
  file.close();
  sortDeck(); // Ensure sorted for binary search
}

// Single File Persistence
void StudyModule::saveToFile(string filename) {
  ofstream fileOut(filename);

  if (fileOut.is_open()) {
    fileOut << "ID,Topic,Prompt,Answer,Streak\n";

    for (int i = 0; i < count; i++) {
      string row = to_string(deck[i].id) + "," + deck[i].topic + "," +
                   deck[i].prompt + "," + deck[i].answer + "," +
                   to_string(deck[i].streak) + "\n";
      fileOut << row;
    }
    fileOut.close();
    cout << "Progress successfully saved to " << filename << ".\n";
  } else {
    cout << "Error opening save file.\n";
  }
}

// Spaced Repetition Logic with Quit Option and Stat Tracking
void StudyModule::studySession() {
  cout << "\n--- Starting Study Session ---\n";
  cout << "(Type 'q' to quit early and view your stats)\n";

  // Reset stats for the new session
  sessionTotalAnswered = 0;
  sessionCorrect = 0;
  sessionIncorrect = 0;
  bool studied = false;

  for (int i = 0; i < count; i++) {
    // Only test if streak is low
    if (deck[i].streak < 2) {
      studied = true;
      cout << "\nTopic: " << deck[i].topic << "\nQ: " << deck[i].prompt
           << "\nPress Enter for answer, 'h' for hint, or 'q' to quit: ";
      string input;
      getline(cin, input);

      // Quit check 1
      if (input == "q" || input == "Q")
        break;

      if (input == "h" || input == "H") {
        displayHint(); // Calls the overridden derived class method
        cout << "Press Enter for answer or 'q' to quit: ";
        getline(cin, input);

        // Quit check 2
        if (input == "q" || input == "Q")
          break;
      }

      cout << "A: " << deck[i].answer
           << "\nDid you get it right? (y/n) or 'q' to quit: ";
      getline(cin, input);

      // Quit check 3
      if (input == "q" || input == "Q")
        break;

      // Update Statistics and Streak
      sessionTotalAnswered++;
      if (input == "y" || input == "Y") {
        deck[i].streak++;
        sessionCorrect++;
      } else {
        deck[i].streak = 0; // Reset streak
        sessionIncorrect++;
      }
    }
  }

  if (!studied) {
    cout << "\nAwesome job! You have mastered all questions in this deck.\n";
  } else {
    cout << "\nSession Ended.\n";
  }

  // Call the stats display at the very end
  displaySessionStats();
}

// Display Session Statistics
void StudyModule::displaySessionStats() {
  if (sessionTotalAnswered == 0) {
    cout << "No questions were answered this session.\n";
    return;
  }

  // Calculate accuracy percentage
  double accuracy =
      (static_cast<double>(sessionCorrect) / sessionTotalAnswered) * 100.0;

  cout << "\n==============================\n";
  cout << "      SESSION STATISTICS      \n";
  cout << "==============================\n";
  cout << "Questions Answered: " << sessionTotalAnswered << "\n";
  cout << "Correct:            " << sessionCorrect << "\n";
  cout << "Incorrect:          " << sessionIncorrect << "\n";
  cout << "Accuracy:           " << accuracy << "%\n";
  cout << "==============================\n";
}

// Bubble Sort by ID to prepare for Binary Search
void StudyModule::sortDeck() {
  for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (deck[j].id > deck[j + 1].id) {
        Question temp = deck[j];
        deck[j] = deck[j + 1];
        deck[j + 1] = temp;
      }
    }
  }
}

// Binary Search
void StudyModule::searchByID(int searchID) {
  int left = 0;
  int right = count - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (deck[mid].id == searchID) {
      cout << "\n--- Question Found ---\n";
      cout << "Topic: " << deck[mid].topic << "\n";
      cout << "Prompt: " << deck[mid].prompt << "\n";
      cout << "Answer: " << deck[mid].answer << "\n";
      cout << "Current Streak: " << deck[mid].streak << "\n";
      return;
    }
    if (deck[mid].id < searchID) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << "\nQuestion ID not found.\n";
}

// Derived Class Hint Implementations
void AlgorithmQuiz::displayHint() {
  cout << "[HINT]: Think about Big O Time Complexity and standard data "
          "structures.\n";
}

void MachineLearningQuiz::displayHint() {
  cout << "[HINT]: Consider the difference between labeled and unlabeled "
          "data.\n";
}