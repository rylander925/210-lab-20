/*
COMSC-210 | Lab 20 | Rylan Der
IDE Used: Visual Studio Code
*/

#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        const int MIN_LEGS = 3;
        const int MAX_LEGS = 4;
        const int MIN_PRICE = 100.00 * 100;
        const int MAX_PRICE = 999.99 * 100;

        prices = new double[SIZE];
        legs = MIN_LEGS + (rand() % (MAX_LEGS - MIN_LEGS + 1));                         //random number from MIN_LEGS to MAX_LEGS
        for (int i = 0; i < SIZE; i++)
            prices[i] = (MIN_PRICE + (rand() % (MAX_PRICE - MIN_PRICE + 1))) / 100.0;   //random number from MIN_PRICE to MAX_PRICE / 100
    }
    //Initializes chair object with given number of legs and prices
    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];           //copy values from given array
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair();
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    double prices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE]; //default constructor initializes w/ random values
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}