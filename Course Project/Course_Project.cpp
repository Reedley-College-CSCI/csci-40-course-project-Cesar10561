// CSCI - 40 Final Project
// Author: [Cesar Duarte]

/*
 * Description: I will make an inventory sysyem for Pokemon trading cards, or records with name, category, value, 
 and condition.Users can add new items,
 remove sold/lost items, search by name, and sort by value.
 Data should persist between runs.
 *
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 50;

// Holds Pokemon Card information
struct PokemonCard {
    string name;
    string type;
    int hp;
    float cost;
};


// Function Prototypes
void addCard(PokemonCard cards[], int &count); // add cards
void displayCards(const PokemonCard cards[], int count); // displays cards
int linearSearch(const PokemonCard cards[], int count, string name); // searches the cards
void bubbleSort(const PokemonCard cards[], int count); // sorts them from cost
void removeCard(const PokemonCard cards[], int& count); // removes cards
void displayMenu(); // displays the main menu



int main() {
    PokemonCard cards[MAX_SIZE];
    int count = 0;
    int choice = 1;

    if (choice == 1) {
        addCard(cards, count);
    }
    else if (choice == 2) {
        displayCards(cards, count);
    }
    else if (choice == 3) {
        cout << "Enter name to Search: ";
 
    string name;
    getline(cin, name);
    int index = linearSearch(cards, count, name);

    if (choice == -1) 
        cout << "Card not found." << endl;
    
    else 
        cout << "\nFound: " << cards[index].name << " | "
            << cards[index].type << " | $"
            << cards[index].cost << " | "
            << cards[index].hp << endl;
    }
    else if (choice == 4) {
        bubbleSort(cards, count);
        cout << "Cards sorted!";
    }
    else if (choice == 5) {
        removeCard(cards, count);
    }
    else if (choice == 6) {
        cout << "Exiting Program....." << endl;
    }
    else
        cout << "Invalid Option" << endl;



    return 0;
}


