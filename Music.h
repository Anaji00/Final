// Alessio Naji-Sepasgozar, Mai Hoang, Yennifer Melendez 11-18-2024 Music Header File

#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Music {
private:
    int musicId;         // Unique music identifier
    string title;        // Song title
    string artist;       // Artist name
    string album;        // Album name
    string genre;        // Genre of the song
    string releaseDate;  // Release date
    double price;        // Price of the track
    double duration;     // Duration of the track in minutes

public:
    // Constructor
    Music(int id, const string& title, const string& artist, const string& album, const string& genre,
          const string& releaseDate, double price, double duration);

    // Display music details
    void getMusicDetails() const;

    // Getters
    int getMusicId() const;
    string getTitle() const;
    string getArtist() const;
    string getGenre() const;

    // Static methods for filtering and top charts
    static vector<Music> filterByGenre(const vector<Music>& songs, const string& genre);
    static vector<Music> getTopCharts(const vector<Music>& songs, const string& genre);
};

#endif // MUSIC_H
