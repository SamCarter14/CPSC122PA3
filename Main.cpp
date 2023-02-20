
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

int main() {
  srand(time(0)); // this should be the ONLY call to srand() in PA3
  //create variables
bool isMultiple, isSumEven, isPrime = false;
int num, totalStatements, nounsSize, articlesSize, prepsSize, verbsSize;
  int i = 0;
ifstream inFile;
string wordType = "";
string sentence;
string * articlesArr = NULL;
string * nounsArr = NULL;
string * verbsArr = NULL;
string * prepsArr = NULL;
  
  // TODO: your task 1 code here
  cout << "*****************" << endl;
  cout << "*Starting task 1*" << endl;
  cout << "*****************" << endl;
  cout << endl;
  inFile.open("/home/runner/CarterPA3/pa3-SamCarter14/numbers.txt");
  //answer questions about every number while not end of file
  while(!inFile.eof()){
    if(i == 0){
      inFile >> num;
    }
  answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);
     inFile >> num;
    i++;
  }
  inFile.close();
 

  // TODO: your task 2 code here
  cout << "*****************" << endl;
  cout << "*Starting task 2" << endl;
  cout << "*****************" << endl;
  cout << endl;
  runTask2();

  
  // TODO: your task 3 code here
  cout << "*****************" << endl;
  cout << "*Starting task 3*" << endl;
  cout << "*****************" << endl;
  cout << endl;
  inFile.open("/home/runner/CarterPA3/pa3-SamCarter14/input_words.txt");
  //gather total sentence count
  inFile >> totalStatements;
  //only four wordtypes
  for (i = 0; i < 4; i++){
  inFile >> wordType;
  
//fill arrays based off of word type
  if(wordType == "Articles"){
    inFile >> articlesSize;
  articlesArr = createWordsArray(inFile, articlesSize);
    displayArray(articlesArr, articlesSize, "Articles");
    }

  if(wordType == "Nouns"){
    inFile >> nounsSize;
  nounsArr = createWordsArray(inFile,nounsSize);
   displayArray(nounsArr, nounsSize, "Nouns");
    }

  if(wordType == "Verbs"){
    inFile >> verbsSize;
  verbsArr = createWordsArray(inFile,verbsSize);
    displayArray(verbsArr, verbsSize, "Verbs");
    }

  if(wordType == "Prepositions"){
  inFile >> prepsSize;
   prepsArr = createWordsArray(inFile, prepsSize);
   displayArray(prepsArr, prepsSize, "Prepositions");
}
}

  //number off 1 through totalStatements count
  for(i = 0; i < totalStatements; i++){
    cout << i + 1 << ". ";
  generateSentence(&sentence, articlesArr, articlesSize, nounsArr, nounsSize, verbsArr, verbsSize, prepsArr, prepsSize);}

  //delete memory allocation
  delete [] articlesArr;
  articlesArr = NULL;
  delete [] nounsArr;
  nounsArr = NULL;
  delete [] verbsArr;
  verbsArr = NULL;
  delete [] prepsArr;
  prepsArr = NULL;
  //close file
  inFile.close();
  return 0;
}
