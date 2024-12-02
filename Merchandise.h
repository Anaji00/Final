// Alessio Naji-Sepasgozar, Minh Anh Thai, Harmony Edgley 11-18-2024 Merchandise Header File

#ifndef MERCHANDISE_H
#define MERCHANDISE_H

#include <iostream>
#include <string>

using namespace std;

class Merchandise {
private:
    int merchandiseId;
    string productName;
    string artistMerch;
    double cost;
    string category;
    int inventory;

public:
    // Constructor
    Merchandise(int merchid, const string& prodName, const string& artist, double cost, const string& cat, int inv);

    // Display merchandise details
    void display() const;

    // Getters
    int getMerchandiseId() const;
    string getProductName() const;
    string getArtistMerch() const;
    double getCost() const;
    string getCategory() const;
    int getInventory() const;

    // Setters
    void setProductName(const string& name);
    void setArtist(const string& art);
    void setCost(double price);
    void setCategory(const string& cat);
    void setInventory(int inv);

    // Inventory updates and checks
    bool checkAvailability() const;
    void incrementInventory(int amount);
    bool decrementInventory(int amount);
};

#endif // MERCHANDISE_H
