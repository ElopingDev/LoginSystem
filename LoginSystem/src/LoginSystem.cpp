
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
int main()
{
    int input;

    std::fstream logins;
    std::string line;

    std::string registerUser;
    std::string registerPassword;

    std::string loginUser;
    std::string loginPassword;

    bool foundExisting = false;
    bool loginSuccessful = false;


    std::cout << "Welcome!\n";
    std::cout << "1: Register" << std::endl;
    std::cout << "2: Login" << std::endl;
    std::cin >> input;

    if (input == 1)
    {
        std::cout << "Username : ";
        std::cin >> registerUser;

        logins.open("logins.txt");
        std::string line;

        while (std::getline(logins, line))
        {
            if (line.find(registerUser + ":") == 0)
            {
                std::cout << "Username already exists. Please choose a different username." << std::endl;
                logins.close();
                return 0;
            }
        }
        logins.close();

        std::cout << "Password : ";
        std::cin >> registerPassword;
        logins.open("logins.txt", std::ios::out | std::ios::app);
        logins << registerUser << ":" << registerPassword << "\n";
        std::cout << "Registered" << std::endl;
        logins.close();
    }
        
        if (input == 2)
        {
            std::cout << "Username : ";
            std::cin >> loginUser;
            std::cout << "Password : ";
            std::cin >> loginPassword;

            std::string userPass = loginUser + ":" + loginPassword;

            logins.open("logins.txt");

            while (std::getline(logins, line))
            {
                if (userPass == line)
                {
                    loginSuccessful = true;
                    break;
                }
            }

            if (loginSuccessful)
            {
                std::cout << "Logged in" << std::endl;
            }
            else
            {
                std::cout << "Incorrect User/Password" << std::endl;
            }

            logins.close();
        }
    }

