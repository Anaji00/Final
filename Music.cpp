// Alessio Naji-Sepasgozar, Harmony Edgley, Minh Anh Thai 11-22-2024 - Music Implementation

#include "Music.h"
#include <iostream>
using namespace std;

// C0nstructor
Music::Music(int id, const string& title, const string& artist, const string& album, const string& genre,
          const string& releaseDate, double price, double duration)
    : musicId(id), title(title), artist(artist), album(album), genre(genre), releaseDate(releaseDate), price(price), duration(duration) {}

// Mai Hoang 11-23-24 - Display Music Details
    void Music::getMusicDetails() const {
        cout << "Song ID: " << musicId << endl;
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Album: " << album << endl;
        cout << "Genre: " << genre << endl;
        cout << "Released: " << releaseDate << endl;
        cout << "Price: $" << price << endl;
        cout << "Song Length: " << duration << endl;
    }

    int Music::getMusicId() const {
        return musicId;
    }
    string Music::getTitle() const {
        return title;
    }
    string Music::getArtist() const {
        return artist;
    }
    string Music::getGenre() const {
        return genre;
    }
    vector<Music> Music::filterByGenre(const vector<Music>& songs, const string& genre){
        vector<Music> filtered;
        for (const auto& song : songs) {
            if (song.genre == genre) {
                filtered.push_back(song);
            }
        }
        return filtered;
    }

