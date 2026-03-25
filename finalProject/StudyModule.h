#ifndef STUDYMODULE_H
#define STUDYMODULE_H

#include "Question.h"
#include <string>

// Base Class
class StudyModule {
protected:
  Question *deck; // Dynamic array pointer
  int count;
  int capacity;

  // Session statistics trackers
  int sessionTotalAnswered;
  int sessionCorrect;
  int sessionIncorrect;

public:
  StudyModule(int cap);
  virtual ~StudyModule(); // Virtual destructor for memory cleanup

  void loadDataset(string filename);
  void saveToFile(string filename); // Single file output
  void studySession();
  void displaySessionStats();    // Display stats method
  void searchByID(int searchID); // Binary Search
  void sortDeck();

  virtual void displayHint() = 0; // Pure virtual function
};

// Derived Class 1
class AlgorithmQuiz : public StudyModule {
public:
  AlgorithmQuiz(int cap) : StudyModule(cap) {}
  void displayHint() override;
};

// Derived Class 2
class MachineLearningQuiz : public StudyModule {
public:
  MachineLearningQuiz(int cap) : StudyModule(cap) {}
  void displayHint() override;
};

#endif