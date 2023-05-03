#include <iostream>
#include <vector>
#include <stdlib.h>
#include "hangman_functions.hpp"
using namespace std;

int main()
{
  string arrWords[20] {"house", "world", "sentence", "mountain", "horse", "animal", "mother", "number", "country", "language", "phenomenon", "statistics", "pumpkin", "hospital", "travelling", "holiday", "surname", "eyebrow", "mechanic", "seventeen"};
  string answer = "";
  string codeword = "";
  int players = 0;
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;
  char letter;

  greet();
  cout<<"Enter the number of players (1 or 2):";
  cin>>players;
    
  if (players == 2) {
    cout<<"Guess a word:";
    cin >>codeword;
  } else {
    srand(time_t(NULL));
    codeword = arrWords[rand()%20];
  }
    
  for (auto index : codeword){
    answer += "_";
  }
    
  while(answer!=codeword && misses < 7)
  {
      display_misses(misses);
      display_status(incorrect, answer);
      
      cout<<"\n\nPlease enter your guess: ";
      cin>>letter;
      
      letter = tolower(letter);
      
      if (letter >= 'a' && letter <= 'z' ) {
          
          for(int i = 0; i<codeword.length(); i++)
          {
              if(letter==codeword[i])
              {
                answer[i] = letter;
                guess = true;
              }
          }
          
          if(guess)
          {
              cout<<"\nCorrect!\n";
          }
          else
          {
              if(!count(incorrect.begin(), incorrect.end(), letter)){
                  cout<<"\nIncorrect! Another portion of the person has been drawn.\n";
                  incorrect.push_back(letter);
                  misses++;
              } else {
                  cout<<"Do not repeat letters.\n";
              }
          }
          guess = false;
      } else {
          cout<<"Enter a letter from a to z.\n";
      }
  }

  end_game(answer, codeword);
  return 0;
}
