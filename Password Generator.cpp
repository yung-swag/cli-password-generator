#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <fstream>
#include <cctype>

void generatePasswords(int, int, std::string[]);

int main()
{
    std::ofstream passwordOutput;
    passwordOutput.open("passwords.txt");

    int passwordLength;
    int amountOfPasswords;
    char input = 'r';

    std::cout << "How many passwords do you want to generate? : ";
    std::cin >> amountOfPasswords;

    std::cout << "How long do you want them to be? : ";
    std::cin >> passwordLength;

    std::cout << std::endl;

    std::string* passwords = new std::string[amountOfPasswords];

    srand(time(0));

    // While the passwords have not been regenerated
    while (input == 'r') {
        
        generatePasswords(amountOfPasswords, passwordLength, passwords);

        // Prints passwords to terminal
        for (int i = 0; i < amountOfPasswords; i++) {
            std::cout << passwords[i] << std::endl;
        }

        std::cout << std::endl;

        std::cout << "Do you want to save to a file, regenrate, or quit the program? (r/s/any key to quit) : ";
        std::cin >> input;
        input = tolower(input);

        std::cout << std::endl;


        // Menu letting user save to file, regenerate passwords, or quit the program
        switch (input) {
        case 's':
            for (int i = 0; i < amountOfPasswords; i++) {
                passwordOutput << passwords[i] << std::endl;
            }
            break;
        case 'r':
            break;
        }

    } 

    passwordOutput.close();
    delete[] passwords;

}

// Generates an array 'passList' of passwords using the 'passwordAmount' and 'passwordLength' variables
void generatePasswords(int passwordAmount, int passwordLength, std::string passList[]) {
    for (int i = 0; i < passwordAmount; i++) {
        std::string password;

        for (int j = 0; j < passwordLength; j++) {

            char passLetter;

            // Generates a random symbol char from the ASCII table
            passLetter = (rand() % 91) + 34;
            password.push_back(passLetter);
        }
        passList[i] = password;
    }
}