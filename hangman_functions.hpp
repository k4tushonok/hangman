#ifndef hangman_functions_hpp
#define hangman_functions_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//функция приветсвия
void greet();
//функция отрисовки виселицы
void display_misses(int misses);
//функция проверки буквы
void display_status(std::vector<char> incorrect, string answer);
//функция окончания игры
void end_game(string answer, string codeword);
#endif




