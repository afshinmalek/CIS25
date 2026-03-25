#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

struct Question {
  int id;
  string topic;
  string prompt;
  string answer;
  int streak;
};

#endif