#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Milestone 1: Using a struct, code a coffee booth queue simulation that uses a linked list as its core data structure. 
// The linked list's struct should be a node that contains the customer's name and drink order. 
// Create data arrays with names and drink orders from which to randomly create customer data. 
// You may use an LLM for creating these data sets. 
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const string NAMES[] = {
        //names from LLM
     "Alex", "Jordan", "Taylor", "Morgan", "Riley",
     "Casey", "Sam", "Jamie", "Drew", "Quinn"  
    };
    const int NAME_COUNT = sizeof(NAMES) / sizeof(NAMES[0]);

    const string DRINKS[] = {
        //drinks from LLM
        "Latte", "Cappuccino", "Cold Brew", "Mocha", "Espresso",
        "Americano", "Chai Latte", "Matcha Latte", "Iced Coffee", "Hot Chocolate"   
    };
    const int DRINK_COUNT = sizeof(DRINKS) / sizeof(DRINKS[0]);

    node* head = nullptr;
    node* tail = nullptr;

    cout << "Coffee booth queue\n";
    for (int i = 0; i < 5; i++) {
        enqueueRandomCustomer(head, tail, NAMES, NAMES_COUNT, DRINKS, DRINK_COUNT);
    }

    cout << "Initial queue:\n";
    printQueue(head);
}