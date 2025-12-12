#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    string name;
    string drink;
    Node* next;
};

void enqueueRandomCoffeeCustomer(Node*& head, Node*& tail, const string names[], int nameCount, const string drinks[], int drinkCount) {
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

void printCoffeeQueue(Node* head){
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

bool serveCoffeeCustomer(Node*& head, Node*& tail) {
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

struct MuffinCustomer {
    string name;
    string muffin;
};

void enqueueRandomMuffinCustomer(deque<MuffinCustomer>& q, const string names[], int nameCount, const string muffins[], int muffinCount) {
    int nameIndex = rand() % nameCount;
    int muffinIndex = rand() % muffinCount;

    MuffinCustomer c;
    c.name = names[nameIndex];
    c.muffin = muffins[muffinIndex];

    q.push_back(c);
}

void printMuffinQueue(const deque<MuffinCustomer>& q) {
    cout << "Muffin booth Queue:\n";
    if (q.empty()) {
        cout << "QUEUE IS EMPTY\n";
        return;
    }

    for (size_t i = 0; i < q.size(); ++i) {
        cout << (i + 1) << " " << q[i].name << " " << q[i].muffin << '\n';
    }
}

bool serveMuffinCustomer(deque<MuffinCustomer>& q) {
    if (q.empty()) {
        return false;
    }

    MuffinCustomer front = q.front();
    cout << "Serving muffin customer: " << front.name << " " << front.muffin << '\n';
    q.pop_front();
    return true;
}

struct BraceletCustomer {
    string name;
    string bracelet;
};

void enqueueRandombraceletCustomer(vector<BraceletCustomer>& v, const string names[], int nameCount, const string bracelets[], int braceletCount) {
    int nameIndex = rand() % nameCount;
    int braceletIndex = rand() % braceletCount;

    BraceletCustomer c;
    c.name = names[nameIndex];
    c.bracelet = bracelets[braceletIndex];

    v.push_back(c);
}

void printBraceletQueue(const vector<BraceletCustomer>& v) {
    cout << "Bracelet booth queue:\n";
    if (v.empty()) {
        cout << "QUEUE IS EMPTY\n";
        return;
    }
    for (size_t i = 0; i < v.size(); ++i) {
        cout << (i + 1) << " " << v[i].name << " " << v[i].bracelet << '\n';
    }
}

bool serveBraceletCustomer(vector<BraceletCustomer>& v) {
    if (v.empty()) {
        return false;
    }

    BraceletCustomer front = v.front();
    cout << "Serving bracelet customer: " << front.name << front.bracelet << '\n';

    v.erase(v.begin());
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

    const string MUFFINS[] = {
        //muffins from LLM
        "Blueberry Muffin",
        "Chocolate Chip Muffin",
        "Banana Nut Muffin",
        "Lemon Poppy Seed Muffin",
        "Cranberry Orange Muffin"
    };
    const int MUFFIN_COUNT = sizeof(MUFFINS) / sizeof(MUFFINS[0]);

    const string BRACELETS[] = {
        //from llm
        "Beaded Friendship Bracelet", "Charm Bracelet",
        "Braided String Bracelet", "Leather Wrap Bracelet",
        "Heart Charm Bracelet"
    };

    const int BRACELET_COUNT = sizeof(BRACELETS) / sizeof(BRACELETS[0]);

    const string COOKIES[] = {
        //from llm
    "Chocolate Chip Cookie", "Oatmeal Raisin Cookie", "Snickerdoodle",
    "Peanut Butter Cookie", "Sugar Cookie", "Double Chocolate Cookie",
    "White Chocolate Macadamia Cookie", "Ginger Molasses Cookie"
};
const int COOKIE_COUNT = sizeof(COOKIES) / sizeof(COOKIES[0]);

    Node* coffeeHead = nullptr;
    Node* coffeeTail = nullptr;

    deque<MuffinCustomer> muffinQueue;

    vector<BraceletCustomer> BraceletQueue;

    std::queue<std::pair<std::string, std::string>> cookieQueue;

    cout << "Initializing coffee queue with 3 customers...\n";
    for (int i = 0; i < 3; i++) {
        enqueueRandomCoffeeCustomer(coffeeHead, coffeeTail, NAMES, NAME_COUNT, DRINKS, DRINK_COUNT);
    }

    cout << "Initializing muffin queue with 3 customers...\n";
    for (int i = 0; i < 3; i++) {
        enqueueRandomMuffinCustomer(muffinQueue, NAMES, NAME_COUNT, MUFFINS, MUFFIN_COUNT);
    }

    cout << "Initializing bracelet queue with 3 customers...\n";
    for (int i = 0; i < 3; ++i) {
        enqueueRandombraceletCustomer(BraceletQueue, NAMES, NAME_COUNT, BRACELETS, BRACELET_COUNT);
    }

    cout << "Initializing cookie queue with 3 customers...\n";
    for (int i = 0; i < 3; ++i) {
        string nm = NAMES[rand() % NAME_COUNT];
        string ck = COOKIES[rand() % COOKIE_COUNT];
        cookieQueue.push({nm, ck});
    }


    cout << "\nInitial queues:\n";
    cout << "----------------------\n";
    printCoffeeQueue(coffeeHead);
    cout << "----------------------\n";
    printMuffinQueue(muffinQueue);
    cout << "=====================\n";
    printBraceletQueue(BraceletQueue);
    cout << "=====================\n\n";



    //10 rounds
    const int ROUNDS = 10;
    for (int round = 1; round <= 10; ++round) {
        cout << "\n======== Round " << round << "========\n";

    cout << "\n[Coffee Booth]\n";
    printCoffeeQueue(coffeeHead);

        if (!serveCoffeeCustomer(coffeeHead, coffeeTail)) {
            cout << "No coffee customer served this round, queue empty.\n";
        }
        //50% to join q
        if (rand() % 2 == 0) {
            enqueueRandomCoffeeCustomer(coffeeHead, coffeeTail, NAMES, NAME_COUNT, DRINKS, DRINK_COUNT);
            cout << "New coffee customer joined.\n";
        } else {
            cout << "No new coffe customer this roun.\n";
        }

        cout << "Coffee queue at end of round " << round << ":\n";
        printCoffeeQueue(coffeeHead);

        cout << "\n[Muffin Booth]\n";
        printMuffinQueue(muffinQueue);

        if (!serveMuffinCustomer(muffinQueue)) {
            cout << "No muffin customer served this round, queue empty.\n";
        }

        if (rand() % 2 == 0) {
            enqueueRandomMuffinCustomer(muffinQueue, NAMES, NAME_COUNT, MUFFINS, MUFFIN_COUNT);
            cout << "New muffin customer joined the queue.\n";
        } else {
            cout << "No new muffin customer this round.\n";
        }
        cout << "Muffin queue at end of round " << round << ":\n";
        printMuffinQueue(muffinQueue);

        cout << "[Bracelet Booth]\n";
        printBraceletQueue(BraceletQueue);
        if (!BraceletQueue.empty()) {
            serveBraceletCustomer(BraceletQueue);
        } else {
            cout << "No bracelet customer served this round, queue empty.\n";
        }
        if (rand() % 2 == 0) {
           enqueueRandombraceletCustomer(BraceletQueue, NAMES, NAME_COUNT, BRACELETS, BRACELET_COUNT);
           cout << "New bracelet customer joined the queue.\n";
        } else {
            cout << "No new bracelet customer this round.\n";
        }

        cout << "Bracelet queue at end of round " << round << ":\n";
        printBraceletQueue(BraceletQueue);
        cout << "\n";


        cout << "[Cookie Booth]\n";
        cout << "cookie booth queue:\n";
        if (cookieQueue.empty()) {
            cout << "QUEUE IS EMPTY\n";
        } else {
            std::queue<std::pair<std::string, std::string>> temp = cookieQueue;
            int pos = 1;
            while (!temp.empty()) {
                cout << pos << " " << temp.front().first << " " << temp.front().second << "\n";
                temp.pop();
                pos++;
            }
        }

        if (rand() % 2 == 0) {
            string nm = NAMES[rand() % NAME_COUNT];
            string ck = COOKIES[rand() % COOKIE_COUNT];
            cookieQueue.push({nm, ck});
            cout << "NEw cookie customer joined queue\n";
        } else {
            cout << "No new cookie customer this round.\n";
        }

        cout << "Cookie queue at end of round "<< round << ":\n";
        cout << "Cookie booth queue:\n";
        if (cookieQueue.empty()) {
            cout << " QUEUE IS EMPTY\n";
        } else {
            std::queue<std::pair<std::string, std::string>> temp = cookieQueue;
            int pos2 = 1;

        }
    
    return 0;
}