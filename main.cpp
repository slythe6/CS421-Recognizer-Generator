#include<iostream>
#include<string>
#include <queue>
using namespace std;
// include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is any combination of 0's and 1's}.
// Your name: Simon Hausmaninger
//----------------------------------------------

//queue<string> combinations;

// Function to generate all possible combinations of characters from the string with the length of the integer n and below using a queue.
vector<string> generateCombinations(string str, int n) {
  vector<string> combinations;
  for (int i = 1; i <= n; i++) {
    queue<string> q;
    q.push("");

    while (!q.empty()) {
      string result = q.front();
      q.pop();
      
      //if the length of the result is equal to the iteration we are on, add it to combinations
      if (result.length() == i) {
        combinations.push_back(result);
        continue;
      }
      //concatenate chars to the end of result
      for (int j = 0; j < str.length(); j++) {
        q.push(result + str[j]);
      }
    }
  }

  return combinations;
}

//recognizer recognizes and returns true for strings comprised of 0's and 1's only
bool recognizer(string s)
{ 
  for(char i : s)
    {
      if(i != '0' && i != '1'){
        //cout << "NO NOT IN L\n";
        return false;
      }
    }
  //cout << "YES IN L\n";
  return true;
}// end of recognizer

// main: It should create each string over E = {0, 1, 2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can 
//   terminate the program with control-C 
//   after about 20 strings have been displayed.
int main()
{ 
  //characters to make combination out of
  string chars = "012";
  //max length of combination
  int len = 10;
  //counter will increment over each pass not depending on if it is printed
  int counter = 0;
  //printed will keep track of how many have been printed to console
  int printed = 1;
  //user input to see how many combinations to print
  int numCombos;
  cout << "Enter number of combinations to output: ";
  cin >> numCombos;
  vector<string> combinations = generateCombinations(chars, len);
  while(printed <= numCombos)
  {
    if(recognizer(combinations[counter]) == true){
    cout << combinations[counter];
   // cout << "\t--\t<";
    //cout << printed;
    cout << "\n";
    printed++;
  }
  counter++;
}

}// end of main

