/*
 Week 1 Game Project
 Tyson_week1_gp.cpp
 Tyson, Eric
 */

#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

//function prototype for both games
void fortuneTeller();
void shellGame();

//main function
int main()
{
    fortuneTeller();
    shellGame();
    return 0;
}

//Fortune Teller
void fortuneTeller()
{
    //set the conditions for random
    int elapsedSeconds = time(nullptr);
    srand(elapsedSeconds);
    
    //set the fortune tellers answers
    string answer1 = "Yes!";
    string answer2 = "No!";
    string answer3 = "Not in this lifetime";
    string answer4 = "Maybe next week";
    string answer5 = "It's hard to say";
    string answer6 = "Ask again tomorrow";
    
    //get the users input
    string question;
    cout << "What is your burning question? > ";
    cin >> question;
    
    //set the tellers answer to a random number
    int tellerAnswer = rand() % 6;
    tellerAnswer = tellerAnswer + 1;
    
    //using if statements, output the teller's answer
    if (tellerAnswer == 1)
    {
        cout << endl << "The fortune teller has answered: " << answer1 << endl << endl;
    }
    else if (tellerAnswer == 2)
    {
        cout << endl << "The fortune teller has answered: " << answer2 << endl << endl;
    }
    else if (tellerAnswer == 3)
    {
        cout << endl << "The fortune teller has answered: " << answer3 << endl << endl;
    }
    else if (tellerAnswer == 4)
    {
        cout << endl << "The fortune teller has answered: " << answer4 << endl << endl;
    }
    else if (tellerAnswer == 5)
    {
        cout << endl << "The fortune teller has answered: " << answer5 << endl << endl;
    }
    else if (tellerAnswer == 6)
        cout << endl << "The fortune teller has answered: " << answer6 << endl << endl;
}

//Shell Game
void shellGame()
{
    //set which box contains the shell
    int elapsedSeconds = time(nullptr);
    srand(elapsedSeconds);
    int boxShell = rand() % 5;
    boxShell = boxShell + 1;
    
    //set user input
    int choice;
    
    //ask the question the first time
    cout << "Where is the shell? Choose box 1-5 > ";
    cin >> choice;
    
    //set the if statements to check if the choice is correct or not
    if (choice != boxShell)
    {
        cout << "That is incorrect. Please try again > ";
        cin >> choice;
    }
    if (choice != boxShell)
    {
        cout << "Sorry, but that is again incorrect." << endl << endl;
    }
    else if (choice == boxShell)
    {
        cout << endl << "That is correct!" << endl << endl;
    }
}
