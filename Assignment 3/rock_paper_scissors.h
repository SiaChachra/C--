#ifndef ROCK_PAPER_SCISSORS_H
#define ROCK_PAPER_SCISSORS_H

#include <string> // Include the string header for std::string

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

char getUserChoice();
char getComputerChoice();
void displayChoices(char userChoice, char computerChoice);
std::string determineWinner(char userChoice, char computerChoice);

#endif // ROCK_PAPER_SCISSORS_H
