/*
Sam Carter
CPSC 122 spring 2023
Date: 2/21/23
Programming Assignment: PA3
Description: This program does three different tasks. First it answers three 
questions about different numbers from a file. It then allows the user to enter a 
number and play the lottery. Lastly it takes word types from a file a generates sentences from that.
Notes: NA
*/
#ifndef PA3_H
#define PA3_H

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


using namespace std;

// task 1
void answerIntegerQuestions(const int num, bool *, bool *, bool *);
// TODO: add your additional function prototypes for task 1 here
bool questionOne(int);
bool questionTwo(int);
bool questionThree(int);
// task 2
bool findWinningLotteryTicket(int, const int *, const int);
// TODO: add your additional function prototypes for task 2 here
void runTask2();
// task 3
string *createWordsArray(ifstream &, const int);
void generateSentence(string *, const string *, const int, const string *,
                      const int, const string *, const int, const string *,
                      const int);
// TODO: add your additional function prototypes for task 3 here
void sortArray(string *& arr, int size);
void displayArray(string * array, int size, string name);
#endif