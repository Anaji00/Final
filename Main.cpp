// Alessio Naji-Sepasgozar, Harmony Edgley, Yennefer Melendez, Minh Anh Thai, Mai Hoang/ Main File Implementation
#include "User.h"
#include "Music.h"
#include "Merchandise.h"
#include "Order.h"
#include <iostream>
#include <algorithm> 
#include <vector>
#include <limits>

using namespace std;

// Clears input buffer to handle incorrect or extra input values
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Yennifer Melendez - Display navigation pane 11/27/24
void showMainMenu() {
    cout << "\n--- Main Menu ---\n";
    cout << "1. View Merchandise\n";
    cout << "2. View Saved Music\n";
    cout << "3. Place an Order\n";
    cout << "4. View Order History\n";
    cout << "5. Manage User Details\n";
    cout << "6. Add Song to Playlist and Get Recommendations\n"; 
     cout << "7. View Music Library\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}
// Harmony Edgley - 11-27-2024 - View Music Details
void viewMusicLibrary(const vector<Music>& musicLibrary) {
    if (musicLibrary.empty()) {
        cout << "No music available.\n";
        return;
    }

    cout << "\n--- Music Library ---\n";
    for (const auto& song : musicLibrary) {
        song.getMusicDetails(); // Displays Song Details
        cout << "---------------------\n";
    }
}

// View Merchandise if not empty - Minh Anh Thai
void viewMerchandise(const vector<Merchandise>& merchandiseList) {
    if (merchandiseList.empty()) {
        cout << "No merchandise available.\n";
        return;
    }
    for (const auto& item : merchandiseList) {
        item.display();    
        cout << "---------------------\n";
    }
}

// View saved music by user
void viewSavedMusic(const User& user) {
    user.viewSavedMusic();
}

// Create order from cart - Minh Anh Thai - 11-27-2024
void placeOrder(User& user, vector<Merchandise>& merchandiseList) {
    vector<Merchandise> cart;
    int merchId;
    char addMore = 'y';

    while (addMore == 'y' || addMore == 'Y') {
        cout << "Enter Merchandise ID to add to cart: ";
        cin >> merchId; // add more to order

        auto it = find_if(merchandiseList.begin(), merchandiseList.end(), [merchId](const Merchandise& m) {
            return m.getMerchandiseId() == merchId;    // Search Merchandise Vector for Merch ID
        });

        if (it != merchandiseList.end()) {    // If merch found, add to cart
            cart.push_back(*it);
            cout << "Item added to cart.\n";
        } else {
            cout << "Merchandise not found.\n";
        }

        cout << "Add more items? (y/n): ";
        cin >> addMore;
    }

    Order order = Order::createOrder(user.getUserId(), cart); // Creates the order
    user.addOrder(order);
    cout << "Order placed successfully!\n";
}
// Upderate user details - Mai Hoang
void manageUserDetails(User& user) {                          // Allows user to manage details
    cout << "\n--- Manage User Details ---\n";
    cout << "Current Name: " << user.getName() << "\n";
    cout << "1. Update Name\n";
    cout << "2. Update Email\n";
    cout << "3. Update Password\n";
    cout << "0. Return to Main Menu\n";

// Clears input
    int choice;
    cin >> choice;
    clearInputBuffer();

    string newValue;
    switch (choice) {                  // Harmony Edgley - Switch statement for User Details shell menu
        case 1:
            cout << "Enter new name: "; // Updates Name
            getline(cin, newValue);
            user.setName(newValue);
            cout << "Name updated successfully.\n";
            break;
        case 2:
            cout << "Enter new email: ";
            getline(cin, newValue);
            user.setEmail(newValue);
            cout << "Email updated successfully.\n";
            break;
        case 3:
            cout << "Enter new password: ";
            getline(cin, newValue);
            user.setPassword(newValue);
            cout << "Password updated successfully.\n";
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice.\n";
    }
}

// Function to add a song and recommend a similar one based on music Genre
void addSongToPlaylist(User& user, const vector<Music>& musicLibrary) {
    int songId;
    cout << "Enter the Song ID to add to your playlist (101, 102...): ";
    cin >> songId;                                                          // Registers user input as songID
    clearInputBuffer();
    // Searches Music Library Vector for song id - Mai Hoang
    auto it = find_if(musicLibrary.begin(), musicLibrary.end(), [songId](const Music& m) { 
        return m.getMusicId() == songId;
    });

    if (it != musicLibrary.end()) {
        user.addToSavedMusic(*it);
        cout << "Song added to your playlist: " << it->getTitle() << " by " << it->getArtist() << "\n";

        // Recommending a similar song based on genre
        vector<Music> similarSongs = Music::filterByGenre(musicLibrary, it->getGenre());
        if (!similarSongs.empty()) {
            cout << "You might also like:\n";
            similarSongs[0].getMusicDetails(); // Displaying the first recommended song
        } else {
            cout << "No similar songs found.\n";
        }
    } else {
        cout << "Song not found.\n";
    }
}

int main() {
    // Merch Test case - Mai Hoang
    vector<Merchandise> merchandiseList = {
        Merchandise(1, "T-Shirt", "Band A", 19.99, "Clothing", 50),
        Merchandise(2, "Vinyl Record", "Artist B", 29.99, "Vinyl", 30)
    };
    // Music Test Case - Yennifer Melendez
    vector<Music> musicLibrary = {
        Music(101, "Song A", "Artist A", "Album A", "Rock", "2023-01-01", 1.29, 3.5),
        Music(102, "Song B", "Artist B", "Album B", "Rock", "2023-02-01", 1.29, 4.0),
        Music(103, "Song C", "Artist C", "Album C", "Pop", "2023-03-01", 1.29, 3.2)
    };

    User user(1001, "Alessio", "alessio@example.com", "password123");

    int choice;
    do {
        showMainMenu();
        cin >> choice;
        clearInputBuffer();
        // Main Menu Switch - Minh Anh Thai
        switch (choice) {
    case 1:
        viewMerchandise(merchandiseList);
        break;
    case 2:
        viewSavedMusic(user);
        break;
    case 3:
        placeOrder(user, merchandiseList);
        break;
    case 4:
        user.viewOrderHistory();
        break;
    case 5:
        manageUserDetails(user);
        break;
    case 6:
        addSongToPlaylist(user, musicLibrary);
        break;
    case 7:
        viewMusicLibrary(musicLibrary); 
        break;
    case 0:
        cout << "Exiting the program. Goodbye!\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
}

    } while (choice != 0);

    return 0;
}
