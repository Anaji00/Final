// Alessio Naji-Sepasgozar, Harmony Edgley, Yennefer Melendez, Minh Anh Thai, Mai Hoang 11-18-2024 Order Header File

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include <string>
#include "Merchandise.h"

using namespace std;

class Order {
public:
    // Nested PaymentData class
    class paymentData {
    private:
        string cardNumber;
        string cvv;
        string expDate;

    public:
        // Constructor
        paymentData(const string& cardnum = "", const string& cvv = "", const string& exdate = "");

        // Getters
        string getCardNumber() const { 
            return cardNumber; 
            }
        string getCVV() const { 
            return cvv; 
            }
        string getExpDate() const { 
            return expDate; 
            }
    };

private:
    // Order Attributes
    int order_ID;               // Order Identifier
    int user_ID;                // User Identifier
    vector<Merchandise> items;  // Vector of Merchandise objects
    double total_amount; // 
    string orderDate;
    string orderStatus;

public:
    // Constructor with default status
    Order(int id, int userID, const vector<Merchandise>& itemList, const string& date,
          double cost = 0.0, const string& status = "Pending");

    // Static method to create an order
    static Order createOrder(int userId, const vector<Merchandise>& cartItems);

    // Method to add merchandise to the Cart 
    void addToCart(const Merchandise& item);

    // Method to remove an item from the cart
    void removeFromCart(int merchandiseId);

    // Method to calculate the total cost
    void updateTotalCost();

    // Method to process payment
    bool processPayment(const paymentData& paymentDetails);

    // Method to display order details
    void displayOrderDetails() const;

    // Getters 
    int getOrderID() const { 
        return order_ID; 
        }
    int getUserID() const { 
        return user_ID;
        }
    double getTotalAmount() const { 
        return total_amount; 
        }
    string getOrderDate() const { 
        return orderDate; 
        }
    string getOrderStatus() const { 
        return orderStatus; 
        }
};

#endif // ORDER_H