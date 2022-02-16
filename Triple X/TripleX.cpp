#include <iostream>
#include<windows.h>
#include <ctime>

void PrintIntroduction(int Difficulty){

    std::cout << "*===========================================================================\n";
    std::cout << "                              .,,uod8B8bou,,.\n";
    std::cout << "                  ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.\n";
    std::cout << "              ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||\n";
    std::cout << "              !...:!TVBBBRPFT||||||||||!!^^\"\"\'   ||||\n";
    std::cout << "              !.......:!?|||||!!^^\"\"\'            ||||\n";
    std::cout << "              !.........||||                     ||||\n";
    std::cout << "              !.........||||  ##                 ||||\n";
    std::cout << "              !.........||||                     ||||\n";
    std::cout << "              !.........||||                     ||||\n";
    std::cout << "              !.........||||                     ||||\n";
    std::cout << "              !.........||||                     ||||\n";
    std::cout << "              `.........||||                    ,||||\n";
    std::cout << "               .;.......||||               _.-!!|||||\n";
    std::cout << "        .,uodWBBBBb.....||||       _.-!!|||||||||!:'\n";
    std::cout << "     !YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....\n";
    std::cout << "     !..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.\n";
    std::cout << "     !....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.\n";
    std::cout << "     !......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"`;:::       `.\n";
    std::cout << "     !........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.\n";
    std::cout << "     `..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.\n";
    std::cout << "       `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'\n";
    std::cout << "         `........::::::::::::::::;iof688888888888888888888b.     `\n";
    std::cout << "           `......:::::::::;iof688888888888888888888888888888b.\n";
    std::cout << "             `....:::;iof688888888888888888888888888888888899fT!\n";
    std::cout << "               `..::!8888888888888888888888888888888899fT|!^\"\'\n";
    std::cout << "                  `' !!988888888888888888888888899fT|!^\"\'\n";
    std::cout << "                      `!!8888888888888888899fT|!^\"'\n";
    std::cout << "                        `!988888888899fT|!^\"'\n";
    std::cout << "                          `!9899fT|!^\"'\n";
    std::cout << "                            `!^\"\'\n";

    // Printing on the prompt the game's introduction
    std::cout << std::endl;
    std::cout << "*===========================================================================\n";
    std::cout << "* Hello, would you kindly defusing the bombs that I spread across the city?\n";
    std::cout << "* I was really bored ;c\n";
    std::cout << "* Please, kill someone :)\n";
    std::cout << "* As my guest, I made a point of separating " << Difficulty << " bombs for you S2!\n";
    std::cout << "*===========================================================================\n";
}

bool PlayGame (int Difficulty)
{
    srand(time(NULL)); // Create new random sequence based on time of day

    // Delcare 3 number code
    const int FirstDigit  = rand() % Difficulty + Difficulty;
    const int SecondDigit = rand() % Difficulty + Difficulty;
    const int ThirdDigit  = rand() % Difficulty + Difficulty;

    const int   SumDigits   = FirstDigit + SecondDigit + ThirdDigit;
    const int ProductDigits = FirstDigit * SecondDigit * ThirdDigit;

    // Printing sumDigits and product to the terminal
    std::cout << "*=========================== Current difficulty: "<< Difficulty << " =========================\n";
    std::cout << "* My rules are simply, there are 3 numbers in the code." << std::endl;
    std::cout << "* The code add-up to: " << SumDigits << std::endl;
    std::cout << "* And the codes multiply to give: " << ProductDigits << std::endl;
    std::cout << "*===========================================================================\n";

    // Store player guess
    int FirstGuess, SecondGuess, ThirdGuess;

    std::cin >> FirstGuess >> SecondGuess >> ThirdGuess;
    std::cout << "* You entered: " << FirstGuess <<" "<< SecondGuess <<" "<< ThirdGuess << ".\n";

    int   SumGuess   = FirstGuess + SecondGuess + ThirdGuess;
    int ProductGuess = FirstGuess * SecondGuess * ThirdGuess;

    // Check if the player guess is correct
    if (SumDigits == SumGuess && ProductDigits == ProductGuess)
    {
        std::cout << "* You got it :/\n";
        std::cout << "*===========================================================================\n";
        return true;
    }
    else
    {
        std::cout << "* BOOOOM !!!\n";
        std::cout << "* I'm really happy for the fun that you gave me :)\n";
        std::cout << "* Just listen these screams <3\n";
        std::cout << "*===========================================================================\n";
        Sleep(10^9);
        return false;
    }
}



int main ()
{
    int const MaxDifficulty = 5;
    int DifficulytLevel = 1;
    bool bLevelComplete;

    PrintIntroduction(MaxDifficulty);

    while (DifficulytLevel <= MaxDifficulty) // Loop game until all levels aompleted
    {
        bLevelComplete = PlayGame(DifficulytLevel);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            // increase the level difficulty
            DifficulytLevel++;
        }
        else
        {
            // Lose
            return 0;
        }
    }

    // Win
    std::cout << "* YOU CAN DEFUSE ALL THE BOMBS! >:|";
    std::cout << "*=====================================END===================================\n";
    return 0;
}