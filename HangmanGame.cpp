/*
 Week 2 Game Project
 Tyson_Week2_gp.cpp
 Tyson, Eric
 
 Hangman
 
 Psuedocode (I wanted to leave this to demonstrate my thought process from when I started to when I finished)
 1. Create the vocabulary list that the game will choose from
 2. Create an empty vector for good guesses
 3. Create an empty vector for bad guesses
 4. Have the system choose a random word from the vocabularly list
 5. Write the main loop
    a. Output the number of letters in the word, like: _ _ _ _ _ _
    b. Ask the user to guess a letter
    c. Let the user know if their guess was correct or not; append the appropriate list with that letter
    d. Display to the user the updated word, with their letter if they guessed it correctly
    e. Ask the user for another guess, repeat steps b - e until the word is formed, or the user runs out of guesses
    f. Exit the program when the user either:
        i. guesses the word correctly
        ii. runs out of letter guesses
        iii. fills the word in correctly
 
 Tasks accomplished:
 1. Display the word as a series of blank lines
 2. Ask the user to guess the letter
 3. Correctly identify if the letter is or is not in the word
 4. Indicate that the game has ended; both if the user wins or loses
 5. Display how many incorrect guesses
 6. Diplay a used letter board
 
 
 Where I had trouble:
 I struggled to allow the user to guess the full word. I managed to get the general concept working (I have coded out the lines that pertain to this task because I want to revisit this later) but I ran into some serious bugs. I believe it has to do with the stream not properly flushed, but I ran out of time searching for where I have to properly clear it.
 */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//steps 1, 2, 3: create the arrays needed for the game as well as the variables
vector <string> vocabularyList = {"apple", "orange", "pear", "banana", "watermelon","peach", "grape", "blueberry", "strawberry", "melon"};
vector <char> guesses;
string word;
char guess;
string guessWord;
int remainingGuesses = 10;
string newWord;
int i;
int incorrectGuesses = 0;

//function prototypes for my word displays
void wordDisplay();
void newWordDisplay();

int main()
{
    
    //step 4: choose a random word from the vocabularyList
    int elapsedSeconds = time(nullptr);
    srand(elapsedSeconds);
    word = vocabularyList[rand() % 10];
    
    //display the game board
    cout << "Welcome to the Hangman Game!" << endl << endl;
    wordDisplay();
    cout << endl << endl;
    
    //ask the user to guess a letter
    cout << "You have " << remainingGuesses << " guesses left." << endl;
    //cout << "Would you like to solve the word? Pres \'y\' or \'n\' ";
    //cin >> guess;
    /* allow the user to guess the full word
    if (guess == 'y')
    {
        cout << "Great! What do you think the word is? " << endl;
        cin >> guessWord;
    } */
    cout << "Please guess a letter: " << endl;
    cin >> guess;
    cout << endl;
    
    //step 5
    while (remainingGuesses > 0)
    {
        if (guessWord == word)
        {
            cout << "Great job! " << word << " is the word! Game Over." << endl << endl;
            exit(0);
        }
        //the main loop for if the guess is not in the word
        //display if the user losses the game (out of guesses) and display if they just guessed incorrectly
        if (word.find(guess) == -1)
        {
            guesses.push_back(guess);
            incorrectGuesses += 1;
            remainingGuesses -= 1;
            //output if they are out of guesses
            if (remainingGuesses == 0)
            {
                cout << "Sorry, you are out of guesses. Better luck next time." << endl << endl;
                exit(0);
            }
            //if the user guessed incorrectly
            else
            {
                cout << "Sorry, that letter is not in the word." << endl << endl;
                cout << "You have guessed incorrectly " << incorrectGuesses << " times." << endl << endl;
                newWordDisplay();
                cout << "You have " << remainingGuesses << " guesses left." << endl << endl;
                cout << "Your guesses so far: " << endl;
                for (i = 0; i <= guesses.size(); i++)
                    cout << guesses[i] << " ";
                //cout << endl << endl << "Would you like to solve for the word? \'y\' or \'n\' ";
                //cin >> guess;
                /*
                if (guess == 'y')
                {
                    cout << "What do you think the word is? ";
                    cin >> guessWord;
                }
                else
                { */
                cout << endl << endl << "Please guess another letter: ";
                cin >> guess;
                cout << endl;
            }
        }
        //main loop for if the user guesses a correct letter
        //
        else
        {
            guesses.push_back(guess);
            remainingGuesses -= 1;
            //display if they are out of guesses
            if (remainingGuesses == 0)
            {
                cout << "Sorry, you are out of guesses. Better luck next time." << endl << endl;
                exit(0);
            }
            else
            {
                cout << "Good job! " << guess << " is in the word!" << endl << endl;
                newWordDisplay();
                //victory
                if (newWord == word)
                {
                    cout << "Good job! " << word << " is the word!" << endl
                        << "You win!" << endl << endl;
                    exit(0);
                }
                //game continues and the user guesses again
                else
                {
                    cout << "You have " << remainingGuesses << " guesses left." << endl << endl;
                    cout << "Your guesses so far: " << endl;
                    for (i = 0; i <= guesses.size(); i++)
                        cout << guesses[i] << " ";
                    //cout << endl << endl << "Would you like to solve for the word? \'y\' or \'n\' ";
                    //cin >> guess;
                    /*
                    if (guess == 'y')
                    {
                        cout << "What do you think the word is? ";
                        cin >> guessWord;
                    }
                    else
                    { */
                    cout << endl << endl << "Please guess another letter: ";
                    cin >> guess;
                    cout << endl;
                }
            }
        }
        /*
        if (!guessWord.empty() || guessWord != word)
        {
            guessWord.clear();
            cout << "Sorry, " << guessWord << " is not the word." << endl;
            incorrectGuesses += 1;
            cout << "You've guessed incorrectly " << incorrectGuesses << " times." << endl;
            cout << "Please try another letter. ";
            cin >> guess;
        } */
    }
}


//display the word as "_ "
void wordDisplay()
{
    for (int i = 1; i <= word.size(); ++i)
    {
        newWord += "_";
    }
    cout << newWord << endl;
}

//this displays the newWord with letters filled in
void newWordDisplay()
{
    cout << "Word: " << endl << endl;
    for (int i = 0; i <= word.size(); ++i)
    {
        if (word[i] == guess)
        {
            newWord[i] = guess;
        }
    }
    cout << newWord << endl << endl;
}


