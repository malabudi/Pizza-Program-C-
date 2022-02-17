#include "pizza.h"


// Non-default constructor
Pizza::Pizza(std::string pizzaType, std::string pizzaSize, int numToppings)
{
    this->pizzaType = pizzaType;
    this->pizzaSize = pizzaSize;
    this->numToppings = numToppings;
}

// Accessors
std::string Pizza::getPizzaType()   { return this->pizzaType; }
std::string Pizza::getPizzaSize()   { return this->pizzaSize; }
int Pizza::getNumToppings()         { return this->numToppings; }

// Mutators
void Pizza::setPizzaType(std::string pizzaType)     { this->pizzaType = pizzaType; }
void Pizza::setPizzaSize(std::string pizzaSize)     { this->pizzaSize = pizzaSize; }
void Pizza::setNumToppings(int numToppings)         { this->numToppings = numToppings; }

// show description of the pizza
std::string Pizza::showPizzaDesc()
{
    return "Pizza Type: " + getPizzaType() + ", Pizza Size: " + getPizzaSize() + ", Number of Toppings: " + std::to_string(getNumToppings());
}

double Pizza::calcPrice()
{
    double price = 0.0d;

    // Calculate initial cost based on size
    if (getPizzaSize().compare("small") == 0)
        price += 10.00;
    else if (getPizzaSize().compare("medium") == 0)
        price += 14.00;
    else if (getPizzaSize().compare("large") == 0)
        price += 17.00;

    // Each topping is 2 bucks, return final total
    return price + (getNumToppings() * 2.00);
}
