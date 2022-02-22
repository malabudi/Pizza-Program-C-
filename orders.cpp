#include "orders.h"
#include <iomanip>
#include <sstream>

// Default constructor
Order::Order()
{
    this->name = "";
    this->phoneNum = "";
}

// Non-default constructors
Order::Order(std::string name, std::string phoneNum)
{
    this->name = name;
    this->phoneNum = phoneNum;
}

// Accessors
std::string Order::getName() { return this->name; }
std::string Order::getPhoneNum() { return this->phoneNum; }

// Mutators
void Order::setName(std::string name) { this->name = name; }
void Order::setPhoneNum(std::string phoneNum) { this->phoneNum = phoneNum; }

// Add a pizza to the Order
void Order::addPizza(std::string pizzaType, std::string pizzaSize, int numToppings)
{
    Pizza userPizza(pizzaType, pizzaSize, numToppings);

    this->pizzaOrders.push_back(userPizza);
}

// show the order the user has made
std::string Order::showOrder()
{
    std::string receipt = "";
    std::stringstream priceStream;
    double total = 0.00d;
    double price;

    receipt += "\nYour Order:\n";
    receipt += "----------------------------------------------------------\n";
    receipt += "Name: " + getName() + "\n";
    receipt += "Phone Number: " + getPhoneNum() + "\n";
    receipt += "----------------------------------------------------------\n";

    // Display the pizzas ordered
    for (Pizza onePizza : this->pizzaOrders)
    {
        price = onePizza.calcPrice();
        priceStream << std::fixed << std::setprecision(2) << price;

        receipt += onePizza.showPizzaDesc() + "\nPrice: $" + priceStream.str() + "\n";
        receipt += "----------------------------------------------------------\n";
        total += price;
        priceStream.str("");
    }

    priceStream << std::fixed << std::setprecision(2) << total;
    receipt += "Total: $" + priceStream.str() + "\n";

    return receipt;
}
