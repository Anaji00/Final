// Alessio Naji-Sepasgozar, Minh Anh Thai, Harmony Edgley 11-18-2024 User Header File

#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include "Order.h" // Include Order for user orders
#include "Music.h" // Include Music for saved songs

using namespace std;

class User {
private:
    int userId;                     // Unique user ID
    string name;                    // User's name
    string email;                   // User's email
    string password;                // Encrypted password (placeholder for simplicity)
    vector<Order> orderHistory;     // List of user's past orders
    vector<Music> savedMusic;       // List of user's saved songs or favorites

public:
    // Constructor
    User(int id, const string& name, const string& email, const string& password);

    // Getters
    int getUserId() const;
    string getName() const;
    string getEmail() const;

    // Setters
    void setName(const string& newName);
    void setEmail(const string& newEmail);
    void setPassword(const string& newPassword);

    // Add order to history
    void addOrder(const Order& order);

    // View order history
    void viewOrderHistory() const;

    // Add a song to saved music
    void addToSavedMusic(const Music& song);

    // View saved music
    void viewSavedMusic() const;
};

#endif // USER_H
