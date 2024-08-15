#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rock_paper_scissors.h"

char getUserMove()
{
    char move;
    std::cout << "Enter r for Rock, p for Paper, s for Scissors: ";
    std::cin >> move;
    return move;
}

char getComputerMove()
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
        return ROCK;
    if (randomNum == 1)
        return PAPER;
    return SCISSORS;
}

void showChoices(char userMove, char computerMove)
{
    std::cout << "You chose: " << userMove << std::endl;
    std::cout << "Computer chose: " << computerMove << std::endl;
}

std::string decideWinner(char userMove, char computerMove)
{
    if (userMove == computerMove)
        return "It's a tie!";

    if ((userMove == ROCK && computerMove == SCISSORS) ||
        (userMove == PAPER && computerMove == ROCK) ||
        (userMove == SCISSORS && computerMove == PAPER))
    {
        return "You win!";
    }
    else
    {
        return "Computer wins!";
    }
}

int main()
{
    srand(time(0));
    int userScore = 0;
    int computerScore = 0;

    while (userScore < 3 && computerScore < 3)
    {
        char userMove = getUserMove();
        char computerMove = getComputerMove();

        showChoices(userMove, computerMove);

        std::string outcome = decideWinner(userMove, computerMove);
        std::cout << outcome << std::endl;

        if (outcome == "You win!")
            userScore++;
        if (outcome == "Computer wins!")
            computerScore++;

        std::cout << "Score: You - " << userScore << ", Computer - " << computerScore << std::endl;
    }

    if (userScore == 3)
    {
        std::cout << "Congratulations! You won the game!" << std::endl;
    }
    else
    {
        std::cout << "Sorry, the computer won the game." << std::endl;
    }

    return 0;
}
