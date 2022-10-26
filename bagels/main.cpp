#include <iostream>
#include<cstdlib>
#include <string>
using namespace std;

int getSecretNumber();
void getClues(int n, int m);
bool gameLoop{true};
int secretNum {getSecretNumber()};

int main()
{
    while (gameLoop == true)
    {
        int guessesCount {1};
        
        std::cout << "\nI am thinking of a 3-digit number. Try to guess what it is." << std::endl;
        std::cout <<"Here are some clues:\n" << std::endl;
        std::cout << "When I say: Pico" << std::endl;
        std::cout <<"That means: One digit is correct but in the wrong position. \n" << std::endl;
        std::cout << "When I say: Fermi" << std::endl;
        std::cout <<"That means: One digit is correct and in the right position. \n" << std::endl;
        std::cout << "When I say: Bagels" << std::endl;
        std::cout <<"That means: No digit is correct. \n" << std::endl;
        std::cout << "I have thought up a number.\nYou have 10 guesses to get it."<< std::endl;

        for (guessesCount; guessesCount < 11; guessesCount++)
        {
            int guess {};
            std::cout << "\nGuess #" << guessesCount << std::endl;
            std::cin >> guess;

            while (guess >1000 || guess <99)
            {
                std::cout << "Please enter a 3-digit number: ";
                std::cin >> guess;
            }

            if (guess == secretNum)
            {
                    std::cout << "You got it!\n" << std::endl;
                    break;
                    
            }else
            {
                getClues(guess, secretNum);
            }

            if(guessesCount == 10){
                std::cout << "\nOut of guess!!\nThe secret number is \n" << secretNum << std::endl;    
            }

        }
        std::cout<<"Do you want to play again? (yes or no): ";
        string playing;
        std::cin >>  playing;

        while(playing != "yes" || playing != "no"){
            std::cout << "Invalid command" << std :: endl;
            std::cout<<"Do you want to play again? (yes or no): ";
            std::cin >> playing;

            if (playing == "no")
            {
                std::cout << "Thanks for playing!"<< std::endl; 
                gameLoop = false;
                break;
            }else if (playing == "yes")
            {
                main();
            }
            
        }
    }
}

int getSecretNumber(){
    srand((unsigned) time(NULL));

    int result = 100 + (rand()%208);
    return result;
}


void getClues(int n, int m)
{
    int n1,n2,n3, m1, m2, m3;

    n1 = n/100;
    n2 = n%100/10;
    n3 = n%10;
    int guessArray[3]{n1,n2,n3};

    m1 = m/100;
    m2 = m%100/10;
    m3 = m%10;
    int secretNumArray[3]{m1,m2,m3};

    for(int i = 0; i < 3; i++)
    {
        if (guessArray[i] == secretNumArray[i])
        {
            std::cout << "fermi ";
        }else if(guessArray[i] == secretNumArray[0] || guessArray[i] == secretNumArray[1] || guessArray[i] == secretNumArray[2]){
            // idk how to find if contain in the array...
            std::cout << "pico ";
        }else{
            std::cout << "bagels ";
        }
        
    }
}