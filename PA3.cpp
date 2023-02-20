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
#include "PA3.h"

///////////////////////////////////
////////////////////////////////////
// TODO: finish the function and define/call three additional functions
//Function: answerIntegerQuestions
//Date Created: 2/17/23
//Date last modified: 2/17/23
//Description:Outputs to console answers about the numbers, on whether or not
//they are a multiple of 7, 11 or 13, prime and if the digits add up to be even 
//or odd. Calls three other functions to do so
//Input parameters:int num, bool *isMultiple, bool *isSumEven, bool *isPrime
//Returns: Answers to questions through cout
//Pre: Must have opened a file with nums
//Post: Returns answers to console
void answerIntegerQuestions(int num, bool *isMultiple, bool *isSumEven,
                            bool *isPrime) {

  
  *isMultiple = questionOne(num);
  if (*isMultiple == false) {
    cout << num << " is not a multiple of either 7, 11 or 13." << endl;
  } else {
    cout << num << " is a multiple of either 7, 11 or 13." << endl;
  }


  *isSumEven = questionTwo(num);
  if (*isSumEven == false) {
    cout << "The digits of " << num << " add up to be odd." << endl;
  } else {
    cout << "The digits of " << num << " add up to be even." << endl;
  }


  *isPrime = questionThree(num);
  if (*isPrime == false) {
    cout << num << " is not a prime number." << endl;
  } else {
 cout << num << " is a prime number." << endl;
    }
  cout << endl;
}

//Function: bool questionOne
//Date Created: 2/17/23
//Date last modified: 2/17/23
//Description: returns a bool if the number is divisible by 7, 11 or 13
//Input parameters: int num
//Returns: true/false bool
//Pre: Must have number
//Post: Returns whether or not number is divisible by 11, 7 or 13
bool questionOne(int num) {
  if (num % 7 == 0) {
    return true;
  } else if (num % 11 == 0) {
    return true;
  } else if (num % 13 == 0) {
    return true;
  } else {
    return false;
  }
}

//Function: bool questionTwo
//Date Created: 2/17/23
//Date last modified: 2/17/23
//Description: returns a bool if the numbers added up are odd or even
//Input parameters: int num
//Returns: true/false bool
//Pre: Must have number
//Post: Returns whether or not nums added up from num is odd or even
  bool questionTwo(int num) {
  int total = 0;
  while (num >= 10) {
    total += num % 10;
    num /= 10;
  }
  total += num;
  if (total % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

//Function: bool questionThree
//Date Created: 2/17/23
//Date last modified: 2/17/23
//Description: returns a bool if the number is prime
//Input parameters: int num
//Returns: true/false bool
//Pre: Must have number
//Post: Returns whether or not num is prime
bool questionThree(int num){
  int i = 0;
  for(i = 2; i < num; i++){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}
////////////////////////////////////
// TASK 2

////////////////////////////////////
// TODO: finish the function

//Function: bool findWinningLotteryTicket
//Date Created: 2/14/23
//Date last modified: 2/14/23
//Description: Is a bool that checks if user has winning lottery ticket
//Input parameters:const int winningTicketNum, const int *playerNumbers,
//const int numPlayerNumbers
//Returns: True or false, depending on if user guessed correctly
//Pre: Needs lottery numbers and runTask2 must run
//Post: Determines if user wins lottery
bool findWinningLotteryTicket(const int winningTicketNum,
                              const int *playerNumbers,
                              const int numPlayerNumbers) {
  int i;
  for (i = 0; i < numPlayerNumbers; i++) {
    if (*(playerNumbers + i) == winningTicketNum) {
      return true;
    }
  }

  return false;
}


//Function:runTask2
//Date Created: 2/14/23
//Date last modified: 2/14/23
//Description: Runs task two, has player enter lottery number to see if they win
//Input parameters:NA
//Returns: Outputs to console if user wins or loses
//Pre: NA
//Post: Let's user play lottery and see if they win
void runTask2() {
  int playerNums[] = {13579, 26791, 26792, 33445, 55555,
                      62483, 77777, 79422, 85647, 93121};
  int playersNumsSize = 10;
  int winningNum = 0;
  bool winner = false;

  cout << "Enter this week's winning number: ";
  cin >> winningNum;

  winner = findWinningLotteryTicket(winningNum, playerNums, playersNumsSize);
  if (winner) {
    cout << "You Won!!!" << endl;
  } else {
    cout << "You lost." << endl;
  }
}
////////////////////////////////////
// TASK 3
////////////////////////////////////
// TODO: finish the functions and define additional functions

//Function:createWordsArray
//Date Created: 2/19/23
//Date last modified: 2/19/23
//Description: Fills an array with words from in file
//Input parameters: ifstream &inFile, const int size
//Returns: A filled array
//Pre: Must have a file to read from and size of array
//Post: Creates a dyncamically allocated filled array
string *createWordsArray(ifstream &inFile, const int size) { 
  string * arr = new string[size];
  string word;
  for (int i = 0; i < size; i++){
    inFile >> word;
    *(arr + i) = word;
    }
  sortArray(arr, size);
  return arr; }

//Function: generateSentence
//Date Created: 2/19/23
//Date last modified: 2/19/23
//Description: Creates a sentence using words from wordlists
//Input parameters: wordlist array, wordlist sizes, string sentence
//Returns: outputs sentences to the console
//Pre: Must have filled array lists and a valid number for sizes
//Post: Creates a sentence to read.
void generateSentence(string *sentence, const string *articlesArr,
                      const int articlesSize, const string *nounsArr,
                      const int nounsSize, const string *verbsArr,
                      const int verbsSize, const string *prepsArr,
                      const int prepsSize) {
string sentencePlaceholder = "";
int num = 0;
string firstWord = "";
num = rand() % articlesSize;
firstWord = *(articlesArr + num);
firstWord[0] = toupper(firstWord[0]);
sentencePlaceholder.append(firstWord);
sentencePlaceholder.append(" ");
num = rand() % nounsSize;
sentencePlaceholder.append(*(nounsArr + num));
sentencePlaceholder.append(" ");
num = rand() % verbsSize;
sentencePlaceholder.append(*(verbsArr + num));
sentencePlaceholder.append(" ");
num = rand() % prepsSize;
sentencePlaceholder.append(*(prepsArr + num));
sentencePlaceholder.append(" ");
num = rand() % articlesSize;
sentencePlaceholder.append(*(articlesArr + num));
sentencePlaceholder.append(" ");
num = rand() % nounsSize;
sentencePlaceholder.append(*(nounsArr + num));
sentencePlaceholder.append("!");

  *sentence = sentencePlaceholder;
  cout << *sentence << endl;
}

//Function:sortArray
//Date Created: 2/19/23
//Date last modified: 2/19/23
//Description: This sorts an array alphabetically
//Input parameters: size of array and string *& arr
//Returns: The array sorted alphabetically
//Pre: Must give an array(sorted or not) and the size
//Post:Returns array sorted
void sortArray(string *& arr, int size){
  string minWord, compareWord, placeholder = "";
  for(int j = size - 1; j > 0; j--){
for(int i = 0; i < size - 1; i++){
    minWord = *(arr + i);
  compareWord = *(arr + i + 1);
  if(minWord.compare(compareWord) > 0){
    *(arr + i) = compareWord;
    *(arr + i + 1) = minWord;
  }
  }
    }
  }

//Function:displayArray
//Date Created: 2/20/23
//Date last modified:2/20/23
//Description: Displays array out to the console
//Input parameters: string * array, int size, string name
//Returns: Returns a list of a word type to the console.
//Pre: Must give it an array, size and name to display.
//Post: Will cout the array
void displayArray(string * array, int size, string name){
    cout << name << ":" << endl;
  for(int j = 0; j < size; j++){
    cout << *(array + j) << endl;
}
  cout << endl;
  }
