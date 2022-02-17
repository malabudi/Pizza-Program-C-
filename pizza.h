#include <string>

class Pizza
{
    private:
        std::string pizzaType;
        std::string pizzaSize;
        int numToppings;

    public:
        // Non-default constructor
        Pizza(std::string pizzaType, std::string pizzaSize, int numToppings);

        // Accessors
        std::string getPizzaType();
        std::string getPizzaSize();
        int getNumToppings();

        // Mutators
        void setPizzaType(std::string pizzaType);
        void setPizzaSize(std::string pizzaSize);
        void setNumToppings(int numToppings);

        // show description of pizza
        std::string showPizzaDesc();

        // calculate the price of the pizza
        double calcPrice();
};
