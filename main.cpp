//author : STALIN X
//created on : 13/07/2025
//description : number guessing game in c++23
//TLDR : just tried c++23 features. if u encounter any bad practices or bad code snippets, feel free to ignore it! iam still learning.

#include <iostream>  
#include <print>  
#include <random>
#include <chrono>
#include <thread>

int main()
{
    std::println("*****************************************************");
    std::println("WELCOME TO NUMBER GUESSING GAME!");

    std::println("Select difficulty : ");
    std::println("1.Simple : (1 - 100)");
    std::println("2.Medium : (1 - 500)");
    std::println("3.Hard : (1 - 1000)");

    int user_option{};

    while (true)
    {
        std::cin >> user_option;
        std::println("You choose option :  {}", user_option);
        if ((user_option == 1) or (user_option == 2) or (user_option == 3))
        {
            break;
        }
        else {
            std::println("Enter a valid input (1 - 3)");
        }
    }


    //fake spinner
    int seconds{ 3 };
    const char spinner[] = { '|', '/', '-', '\\' };
    std::print("The machine is thinking of a number  ");
    for (int i{}; i < seconds * 4; ++i) {
        std::cout << "\b" << spinner[i % 4] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << "\b" << std::endl;
    //end of fake spinner

    int random_num{};

    //generate random number (1 - 100)
    if (user_option == 1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 100);
        random_num = dist(gen);
    }
    else if (user_option == 2) {
        //generate random number(1 - 500)
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 500);
        random_num = dist(gen);
    }
    else {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution <> dist(1, 1000);
        random_num = dist(gen);
    }

    //checking number against the random number
    int counter{};
    int user_input;
    do {
        //number input from user
        std::println("Enter your guess : ");
        std::cin >> user_input;

        counter ++;

        if (user_input < random_num) {
            std::println("Too low");
        }
        else if (user_input > random_num) {
            std::println("Too High");
        }
        else {
            std::println("You Won in {} attempts!", counter);
        }
    } while (user_input != random_num);

    std::println("Random number : {}", random_num);
    std::println("********** THANK YOU FOR PLAYING **********");  

    return 0;  
}
