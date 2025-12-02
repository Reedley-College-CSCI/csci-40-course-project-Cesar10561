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

void addCard(PokemonCard cards[], int& count)
{
    if (count >= MAX_SIZE) {
        cout << "Collection is too full!!!";
        return;
    }
    cout << "Enter Pokemon Name: ";
    getline(cin, cards[count].name);
    cout << "Enter Type of Pokemon: ";
    getline(cin, cards[count].type);
    cout << "Enter Cost of Card: ";
    cin >> cards[count].cost;
    cin.ignore();
    cout << "Enter HP of Card: ";
    cin >> cards[count].hp;
    count++;
    cout << "Card Successfully Added!";
}

void displayCards(const PokemonCard cards[], int count)
{
    if (!count) { cout << "No cards to display.\n"; return; }
    for (int i = 0; i < count; i++)
        cout << i + 1 << ". " << cards[i].name << " | "
        << cards[i].type << " | $" << cards[i].cost
        << " | " << cards[i].hp << endl;
}

int linearSearch(const PokemonCard cards[], int count, string name)
{
    for (int i = 0; i < count; i++)
        if (cards[i].name == name) return i;
    return -1;
}

void bubbleSort(const PokemonCard cards[], int count)
{
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (cards[j].cost > cards[j + 1].cost)
                swap(cards[j], cards[j + 1]);
}

void removeCard(const PokemonCard cards[], int& count)
{
    string name;
    cout << "Enter name to remove: ";
    getline(cin, name);

    int index = linearSearch(cards, count, name);

    if (index == -1) {
        cout << "Card not found.\n";
        return;
    }
}

    void displayMenu()
{
    cout << endl << "---- Welcome to the Pokemon Cards Inventory ----" << endl;
    cout << "1. Add Cards\n2. Display Cards\n3. Search Card\n4. Sort by Value\n";
    cout << "5. Remove Card\n6. Exit\nChoice: ";
}
