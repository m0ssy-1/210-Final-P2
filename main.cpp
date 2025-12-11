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
    const int NAME
}