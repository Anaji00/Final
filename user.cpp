//// Alessio Naji-Sepasgozar, Mai Hoang, Yennefer Melendez 11-22-2024 - User Implementation
#include "User.h"
#include "Music.h"
#include "Order.h"
#include <iostream>
using namespace std;

// Constructor
User::User(int id, const string& name, const string& email, const string& password)
    : userId(id), name(name), email(email), password(password) {}

// Getters
int User::getUserId() const {
    return userId;
}

string User::getName() const {
    return name;
}

string User::getEmail() const {
    return email;
}

// Setters
void User::setName(const string& newName) {
    name = newName;
}

void User::setEmail(const string& newEmail) {
    email = newEmail;
}

void User::setPassword(const string& newPass) {
    password = newPass;
}

// Add order to history
void User::addOrder(const Order& order) {
    orderHistory.push_back(order);
}

// View order history
void User::viewOrderHistory() const {
    if (orderHistory.empty()) {
        cout << "No Order History!" << endl;
        return;
    }
    for (const auto& order : orderHistory) {
        order.displayOrderDetails();
        cout << "-----------------" << endl;
    }
}

// Add a song to saved music - Yennefer Melendez - 11/27/24
void User::addToSavedMusic(const Music& song) {
    savedMusic.push_back(song);
    cout << "Added to Saved playlist!" << endl;
    song.getMusicDetails();
    cout << endl;
}

// View saved music - Yennefer Melendez - 11/27/24
void User::viewSavedMusic() const {
    if (savedMusic.empty()) {
        cout << "No music saved!" << endl;
        return;
    }

    cout << "saved music for " << name << endl;
    for (const auto& song : savedMusic) {
        song.getMusicDetails();
        cout << "-------------=-----" << endl;
    }
};
