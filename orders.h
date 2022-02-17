#include "pizza.h"
#include <math.h>
#include <vector>

class Order
{
    private:
        std::vector <Pizza> pizzaOrders;
        std::string name;
        std::string phoneNum;

    public:
        // Default constructor
        Order();

        // Non-default constructor
        Order(std::string name, std::string phoneNum);

        // accessors
        std::string getName();
        std::string getPhoneNum();

        // mutators
        void setName(std::string name);
        void setPhoneNum (std::string phoneNum);

        // add a pizza to the order
        void addPizza(std::string pizzaType, std::string pizzaSize, int numToppings);

        // show the entire order of the pizza with the total price
        std::string showOrder();
};
