// Alessio Naji-Sepasgozar, Harmony Edgley, Yennefer Melendez, Minh Anh Thai, Mai Hoang 11-24-2024, Order Implementation

#include "Order.h"
#include <iostream>

using namespace std;

// paymentData Constructor
Order::paymentData::paymentData(const string& cardnum, const string& cvv, const string& exdate)
    : cardNumber(cardnum), cvv(cvv), expDate(exdate) {}

// Order Constructor
Order::Order(int id, int userID, const vector<Merchandise>& itemList, const string& date, double cost, const string& status)
    : order_ID(id), user_ID(userID), items(itemList), total_amount(cost), orderDate(date), orderStatus(status) {}

// Static method to create an order
Order Order::createOrder(int userId, const vector<Merchandise>& cartItems) {
    double totalCost = 0.0;
    for (const auto& item : cartItems) {
        totalCost += item.getCost();
    }
    return Order(0, userId, cartItems, "12/1/2024", totalCost, "Pending");
}

// Mai Hoang 11/28 - Add an item to the cart
void Order::addToCart(const Merchandise& item) {
    items.push_back(item);
    total_amount += item.getCost();
}

// Mai Hoang - Remove an item from the cart
void Order::removeFromCart(int merchandiseId) {
    for (auto it = items.begin(); it != items.end(); ) {
        if (it->getMerchandiseId() == merchandiseId) {
            total_amount -= it->getCost();
            it = items.erase(it);
        } else {
            ++it;
        }
    }
}

// Recalculate the total cost
void Order::updateTotalCost() {
    total_amount = 0.0;
    for (const auto& item : items) {
        total_amount += item.getCost();
    }
}

// Process payment
bool Order::processPayment(const paymentData& paymentDetails) {
    if (paymentDetails.getCardNumber().empty() || paymentDetails.getCardNumber().length() != 16) {
        cout << "Payment Failed: Invalid Card Number (16 digits required)\n";
        return false;
    }
    if (paymentDetails.getCVV().empty() || paymentDetails.getCVV().length() != 3) {
        cout << "Payment Failed: Invalid CVV (3 digits required)\n";
        return false;
    }
    if (paymentDetails.getExpDate().empty()) {
        cout << "Payment Failed: Expiration date is missing.\n";
        return false;
    }
    cout << "Payment Successful!\n";
    return true;
}

// Display order details
void Order::displayOrderDetails() const {
    cout << "Order ID: " << order_ID << "\n"
         << "User ID: " << user_ID << "\n"
         << "Total Amount: $" << total_amount << "\n"
         << "Order Date: " << orderDate << "\n"
         << "Order Status: " << orderStatus << "\n"
         << "Items in the order:\n";

    for (const auto& item : items) {
        item.display(); // Calls display function of Merchandise
    }
}
