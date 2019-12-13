/*
 Tyson Week 3 Game Project
 Tyson_Week3_GP.cpp
 Tyson, Eric
 */

//Mastermind game

/*
 Features to add (this is for me; as I plan on revisiting all these games and continue to add functionality:
 Clean up the user guess input (let the user guess all on one line).
 Streamline code... I'm sure I can do this in less than 250 lines of code...
 Display the number and color of pegs at the same time as I display the guess (that way the user doesn't have to scroll up and down to see what they guessed/what they got right)
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//variables the game will need
string difficulty;
int remainingTurns = 7;
vector<int> answers {};
string userGuess;
int userGuessNum;
vector<int> totalGuesses = {};
vector<int> turnGuess = {};
int i;
int x = 4;//this variable is used  to ensure only 4 answers are chosen
int y;//this variable ensures the user can only guess 4 numbers a turn.
//I can't use x becuase this one needs to be reset each turn.
int blackPegs = 0;
int whitePegs = 0;
enum colors {blue, red, purple, orange, brown, green} col;
string colorNames[6] = {"blue", "red", "purple", "orange", "brown", "green"};

//functions
void answerKey(string &s);
void guessLoop();
void blackPegsTotal();
void whitePegsTotal();
void displayGuesses();
void userGuesses();

int main()
{
    //seed time for random
    int elapsed_seconds = time(nullptr);
    srand(elapsed_seconds);
    
    cout << "Welcome to Mastermind!" << endl
         << "Please choose your difficulty (easy or hard)" << endl
         << "> ";
    cin >> difficulty;
    //main loop for the game; allow the user 7 guesses and close the program when those guesses are up
    answerKey(difficulty);
    guessLoop();
    return 0;
}

//answerKey function will randomly choose the answer key and store it. It will take a reference parameter for the difficulty setting.
void answerKey(string &s)
{
    i = 1;
    do
    {
        if (difficulty == "easy")
        {
            //for easy mode; ensures there are no duplicates
            do
            {
                col = colors(rand() % 6);
            }while(find(answers.begin(), answers.end(), col) != answers.end());
            //end of easy mode loop
        }
        else if (difficulty == "hard")
        {
            //for hard mode; allows duplicates
            col = colors(rand() % 6);
        }
        answers.push_back(col);
        i++;
    }while (i <= x);
    /*
     ************ DISPLAYS ANSWER KEY *******************
    for (i = 0; i < answers.size(); i++)
        cout << colorNames[answers[i]] << " ";//colorNames[answers[i]]
    */
    
    cout << endl << endl;
}

/*
 The guess loop. Ensures the user can guess four guesses at a time. It ensures the users guess is a valid guess. It also will display what the user has guessed so far as well as the total number of pegs (displayed from other functions).
 */
void guessLoop()
{
    do
    {
        userGuesses();
        blackPegsTotal();
        whitePegsTotal();
        displayGuesses();
        turnGuess = {}; //set turn guess back to empty
        cout << "You have " << remainingTurns << " turns left. Use them wisely." << endl << endl;
        
        //tring to break up the screen a little bit
        for (i = 0; i <= 75; i++)
            cout << "_";
        cout << endl << endl;
        
        //end if the user runs out of turns (lost)
        if (remainingTurns == 0)
        {
            cout << "Sorry you are out of guesses. The correct answers were: " << endl;
            for (i = 0; i < answers.size(); i++)
                cout << colorNames[answers[i]] << " ";
            cout << endl;
            exit(0);
        }
        
    }while (remainingTurns >= 0);
}

/*
 The function that will take the usersguess and compare them to the answer key.
 If both indexes are equal then the system will add a black peg to what it displays to the user.
 */
void blackPegsTotal()
{
    //black peg loop
    for (i = 0; i <= 3; i++)
    {
        if (turnGuess[i] == answers[i])
        {
            blackPegs += 1;
        }
        else
            continue;
    }
    cout << "You have " << blackPegs << " black peg(s) in your guess." << endl << endl;
    
    //if the user has the correct guesses the system will exit (this is a win)
    if (blackPegs == answers.size())
    {
        cout << "Congratulations! You win!" << endl;
        cout << "The answer key was: " << endl;
        for (i = 0; i <answers.size(); i++)
            cout << colorNames[answers[i]] << " ";
        cout << endl;
        exit(0);
    }
    blackPegs = 0; //resets black pegs back to zero for next turn
}

/*
If the user guess is in the answer key, but they don't line up then the system will add a white peg to what it displays to the user.
*/
void whitePegsTotal()
{
    for (i = 0; i <= 3; i++)
    {
        if (turnGuess[i] != answers[i] && find(answers.begin(), answers.end(), turnGuess[i]) != answers.end())
        {
            whitePegs += 1;
        }
        else
            continue;
    }
    cout << "You have " << whitePegs << " white peg(s) in your guess." << endl << endl;
    whitePegs = 0; //resets white pegs back to zero for next turn
}

/*
 Use this function to display all of the users guesses in a vertical list
 */
void displayGuesses()
{
    int z = 1;//needed an int to establish  the turn to display to the user
    cout << "Your guesses so far: " << endl;
    for (int i = 0; i < totalGuesses.size(); i++)
    {
        if (i % 4 == 0)
        {
            cout << endl << "Turn " << (z) << ": " << colorNames[totalGuesses[i]] << " ";
            z += 1;
        }
        else
            cout << colorNames[totalGuesses[i]] << " ";
    }
    cout << endl;
}

void userGuesses()
{
    y = 4;
    cout << "Please choose four colors from the list below: " << endl;
    for (i = 0; i < 6; i++)
    {
        cout << colorNames[i] << endl;
    }
    do
    {
        cout << "> ";
        cin.ignore();
        cin >> userGuess;
        if  (userGuess != "blue" && userGuess != "red" && userGuess != "purple" && userGuess != "orange" && userGuess != "brown" && userGuess != "green")
        {
            do
            {
                cout << "That guess was not on the list. Please guess again." << endl << "> ";
                cin >> userGuess;
            }while (userGuess != "blue" && userGuess != "red" && userGuess != "purple" && userGuess != "orange" && userGuess != "brown" && userGuess != "green");
        }
        if (userGuess == "blue")
        {
            turnGuess.push_back(blue);
            totalGuesses.push_back(blue);
        }
        else if (userGuess == "red")
        {
            turnGuess.push_back(red);
            totalGuesses.push_back(red);
        }
        else if (userGuess == "purple")
        {
            turnGuess.push_back(purple);
            totalGuesses.push_back(purple);
        }
        else if (userGuess == "orange")
        {
            turnGuess.push_back(orange);
            totalGuesses.push_back(orange);
        }
        else if (userGuess == "brown")
        {
            turnGuess.push_back(brown);
            totalGuesses.push_back(brown);
        }
        else if (userGuess == "green")
        {
            turnGuess.push_back(green);
            totalGuesses.push_back(green);
        }
        y -= 1;
        if (y == 0)
        {
            remainingTurns -= 1;
            break;
        }
    }while (y != 0);
}
