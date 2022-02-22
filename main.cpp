#include <iostream>
#include <limits>
#include "orders.h"

// Function prototypes
void askCustomerInfo(std::string& name, std::string& num);
void orderOnePizza(Order& userOrder);
void askPizzaType(std::string& pizzaType);
bool isNotValidPizzaType(std::string pizzaType);
void askPizzaSize(std::string& pizzaSize);
bool isNotValidPizzaSize(std::string pizzaSize);
void askNumToppings(int& numToppings);
bool isNotValidToppings(int numToppings);
void askIfOrderAgain(std::string& choice);
void lowerCaseStr(std::string& userStr);

int main()
{
    std::string name, phoneNum;
    std::string orderAgain = "yes";

    std::cout << "Welcome to the Pizza Program!" << std::endl;
    askCustomerInfo(name, phoneNum);

    Order userOrder(name, phoneNum);
    while (orderAgain == "yes")
    {
        orderOnePizza(userOrder);
        askIfOrderAgain(orderAgain);
    }

    std::cout << userOrder.showOrder();

    return 0;
}


void askCustomerInfo(std::string& name, std::string& phoneNum)
{
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Please enter your phone number: ";
    std::getline(std::cin, phoneNum);
}

void orderOnePizza(Order& userOrder)
{
    std::string pizzaType, pizzaSize;
    int numToppinngs;

    // grab the user's choice of pizza type and make sure it is valid
    askPizzaType(pizzaType);
    while (isNotValidPizzaType(pizzaType))
    {
        std::cerr << "Invalid choice for type of pizza, please enter the correct choice" << std::endl;

        askPizzaType(pizzaType);
    }

    // Valid pizza size
    askPizzaSize(pizzaSize);
    while (isNotValidPizzaSize(pizzaSize))
    {
        std::cerr << "Invalid choice for pizza size, please enter the correct choice" << std::endl;

        askPizzaSize(pizzaSize);
    }

    // Valid number of toppings
    askNumToppings(numToppinngs);
    while (isNotValidToppings(numToppinngs))
    {
        std::cerr << "Invalid number of toppings, please make sure your entry is positive" << std::endl;

        askNumToppings(numToppinngs);
    }

    userOrder.addPizza(pizzaType, pizzaSize, numToppinngs);
}

void askPizzaType(std::string& pizzaType)
{
    // Display a menu of pizza types to the user
    std::cout << "What type of pizza would you like:" << std::endl;
    std::cout << "- deep dish" << std::endl;
    std::cout << "- hand tossed" << std::endl;
    std::cout << "- pan" << std::endl;
    std::getline(std::cin, pizzaType);
    lowerCaseStr(pizzaType);
}

bool isNotValidPizzaType(std::string pizzaType)
{
    // Validate the user's type of pizza
    if (pizzaType.compare("deep dish") == 0)
        return false;
    else if (pizzaType.compare("hand tossed") == 0)
        return false;
    else if (pizzaType.compare("pan") == 0)
        return false;

    return true;
}

void askPizzaSize(std::string& pizzaSize)
{
    std::cout << "What size would you like your pizza to be: " << std::endl;
    std::cout << "- small" << std::endl;
    std::cout << "- medium" << std::endl;
    std::cout << "- large" << std::endl;
    std::getline(std::cin, pizzaSize);
    lowerCaseStr(pizzaSize);
}

bool isNotValidPizzaSize(std::string pizzaSize)
{
    // Validate the user's type of pizza
    if (pizzaSize.compare("small") == 0)
        return false;
    else if (pizzaSize.compare("medium") == 0)
        return false;
    else if (pizzaSize.compare("large") == 0)
        return false;

    return true;
}

void askNumToppings(int& numToppings)
{
    std::cout << "How many toppings would you like: " << std::endl;
    std::cin >> numToppings;
}

bool isNotValidToppings(int numToppings)
{
    // Validate the user's type of pizza
    if (numToppings >= 0)
        return false;

    return true;
}

void askIfOrderAgain(std::string& choice)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Would you like to order another pizza? (yes/no): " << std::endl;
    std::getline(std::cin, choice);

    lowerCaseStr(choice);


    while (choice.compare("yes") != 0 && choice.compare("no") != 0)
    {
        std::cerr << "Invalid input, please either enter \"yes\" or \"no\"" << std::endl;

        std::cout << "Would you like to order another pizza? (yes/no): " << std::endl;
        std::getline(std::cin, choice);

        lowerCaseStr(choice);

    }
}

void lowerCaseStr(std::string& userStr)
{
    // Set string to lower case w/ a range based loop
    for (char& userChar : userStr)
    {
        if (userChar >= 65 && userChar <= 90)
            userChar += 32;
    }
}
