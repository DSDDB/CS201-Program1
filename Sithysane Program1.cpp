#include <iostream>
using namespace std;
// The following code is the function to roll the dice to output a random number from set of 1-6
int RollDice(){
    int Roll = rand() % 6 + 1;
    return Roll;
}
// The following code is the function that reads the dice output and orders the pair together from largest to smallest to make a larger number
int Round(){
    int Dice1 = RollDice();
    int Dice2 = RollDice();
    int Total = 0;

    if (Dice1 > Dice2){
        Total = (Dice1 * 10) + Dice2;
    }
    else {
        Total = (Dice2 * 10) + Dice1;
    }
    cout << "Rolled " << Dice1 << " and " << Dice2 << ", making " << Total << endl;
    cout << endl;
    return Total;
}

// The following code is the main function that switches between Human and Computer players and tallies up the scores to see how many rounds each player has won
int main()
{
    int HumanScore = 0;
    int ComputerScore = 0;
    int BeatScore = 0;
    int NewScore = 0;
    string player = "Human";
    srand(time(NULL));

    while(true){
        cout << "Rolling 2 dice for " << player << endl;
        NewScore = Round();

        if(NewScore < BeatScore){

            if(player == "Human")
                player = "Computer";
            else
                player = "Human";


            if(player == "Computer"){
                HumanScore = HumanScore + 1;
            }
            else
                ComputerScore = ComputerScore + 1;
            cout << "Too bad! Unlucky roll for the " << player << " player" << endl;
            cout << "The current score is - Human: " << HumanScore << ", Computer: " << ComputerScore << endl;
            cout << endl;

            cout << "Would you like to go again[Y/N]? " << endl;
            char userInput;
            cin >> userInput;
            userInput = toupper(userInput);

            if(userInput == 'Y'){
                player = "Human";
                BeatScore = 0;
                NewScore = 0;
                continue;
            }

            else
                break;
        }
        BeatScore = NewScore;
        cout << BeatScore << " is the number to beat" << endl;


    }
}