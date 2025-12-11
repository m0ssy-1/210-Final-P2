#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Milestone 1: Using a struct, code a coffee booth queue simulation that uses a linked list as its core data structure. 
// The linked list's struct should be a node that contains the customer's name and drink order. 
// Create data arrays with names and drink orders from which to randomly create customer data. 
// You may use an LLM for creating these data sets. 

struct Node {
    string name;
    string drink;
    Node* next;
};

void enqueueRandomCustomer(Node*& head, Node*& tail, const string names[], int nameCount, const string drinks[], int drinkCount) {
    int nameIndex = rand() % nameCount;
    int drinkIndex = rand() % drinkCount;

    Node* newNode = new Node;
    newNode->name = names[nameIndex];
    newNode->drink = drinks[drinksIndex];
    newNode->next = nullptr;

    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void printQueue(Node* head){
    cout << "Coffee booth queue:\n";
    if (head == nullptr) {
        cout << "QUEUE IS EMPTY\n";
        return;
    }

    int position = 1;
    Node* current = head;
    while (current != nullptr) {
        cout << position << " " << current->name << " " << current->drink << '\n';
        current = current->next;
        position++;
    }
}

bool serveCustomer(Node*& head, Node*& tail) {
    if (head == nullptr) {
        return false;
    }

    Node* temp = head;
    cout << "Serving: " << head->name << " " << head->drink << '\n';

    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    return true;
}



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

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Coffee booth queue\n";
    for (int i = 0; i < 5; i++) {
        enqueueRandomCustomer(head, tail, NAMES, NAMES_COUNT, DRINKS, DRINK_COUNT);
    }

    cout << "Initial queue:\n";
    printQueue(head);

    cout << "Serving customers:\n";
    while (serveCustomer(head, tail)) {
        //serves until empty
    }

    cout << "Queue after serving:\n";
    printQueue(head);
    
    return 0;
}