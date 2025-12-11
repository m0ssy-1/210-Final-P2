#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    newNode->drink = drinks[drinkIndex];
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

//Milestone 2: Run the simulation for 10 rounds. 
// Initialize the queue with 3 customers. 
// For any given round, there's a 50% probability that someone will join the queue. 
// The customer at the head of the queue is always served in each round. 
// If the queue is currently empty, no customer is served, but there is still a 50% probability that someone will join the queue.




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

    cout << "Initializing queue with 3 customers...\n";
    for (int i = 0; i < 3; i++) {
        enqueueRandomCustomer(head, tail, NAMES, NAME_COUNT, DRINKS, DRINK_COUNT);
    }

    cout << "Initial queue:\n";
    printQueue(head);

    //10 rounds
    const int ROUNDS = 10;
    for (int round = 1; round <= ROUNDS; ++round) {
        cout << "---------------------\n";
        cout << "Round " << round << ":\n";

        printQueue(head);

        if (!serveCustomer(head, tail)) {
            cout << "No one served this round, queue empty.\n";
        }
        //50% to join q
        int joinChance = rand() % 2;
        if (joinChance == 0) {
            enqueueRandomCustomer(head, tail, NAMES, NAME_COUNT, DRINKS, DRINK_COUNT);
            cout << "Customer joined the queue: " << tail->name << " - " << tail->drink << '\n';
        } else {
            cout << "No new customers this round.\n";
        }

        cout << "Queue at end of round " << round << ":\n";
        printQueue(head);
        cout << "\n";
    }
    
    return 0;
}