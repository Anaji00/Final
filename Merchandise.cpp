// Alessio Naji-Sepasgozar, Yennifer Melendez, Mai Hoang 11-22-2024 - Merchandise Implementation
#include "Merchandise.h"
#include <iostream>

using namespace std;

// Constructor
Merchandise::Merchandise(int merchid, const string& prodName, const string& artist, double cost, const string& cat, int inv)
    : merchandiseId(merchid), productName(prodName), artistMerch(artist), cost(cost), category(cat), inventory(inv) {}

// Display merchandise details
void Merchandise::display() const {
    cout << "Merchandise ID: " << merchandiseId << endl;
    cout << "Product: " << productName << endl;
    cout << "Artist: " << artistMerch << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Category: " << category << endl;
    cout << "Inventory: " << inventory << endl;
}

// Getters
int Merchandise::getMerchandiseId() const {
    return merchandiseId;
}

string Merchandise::getProductName() const {
    return productName;
}

string Merchandise::getArtistMerch() const {
    return artistMerch;
}

double Merchandise::getCost() const {
    return cost;
}

string Merchandise::getCategory() const {
    return category;
}

int Merchandise::getInventory() const {
    return inventory;
}

// Setters
void Merchandise::setProductName(const string& name) {
    productName = name;
}

void Merchandise::setArtist(const string& art) {
    artistMerch = art;
}

void Merchandise::setCost(double price) {
    cost = price;
}

void Merchandise::setCategory(const string& cat) {
    category = cat;
}

void Merchandise::setInventory(int inv) {
    inventory = inv;
}

// Check availability
bool Merchandise::checkAvailability() const {
    return inventory > 0;
}

// Update inventory
void Merchandise::incrementInventory(int amount) {
    inventory += amount;
}
// Decrement Inventory After order
bool Merchandise::decrementInventory(int amount) {
    if (inventory >= amount) {
        inventory -= amount;
        return true;
    }
    return false;
}
