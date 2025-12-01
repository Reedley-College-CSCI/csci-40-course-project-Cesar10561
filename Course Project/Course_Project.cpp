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
    int cardNumber;
    int hp;
    float cost;
};

// Function Prototypes
void addCard(PokemonCard cards[], int &count);
void displayCards(const PokemonCard cards[], int count);
int linearSearch(const PokemonCard cards[], int count, string name);
void bubbleSort(const PokemonCard cards[], int count);
void removeCard(const PokemonCard cards[], int& count);
void displayMenu();



int main() {
    PokemonCard cards[MAX_SIZE];
    int count = 0;
    int choice = 1;


    return 0;
}