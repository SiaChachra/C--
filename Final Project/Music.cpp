#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// The Song class holds information about a song, including title, artist, genre, duration, and play count.
class Song
{
private:
    std::string title;  // Title of the song
    std::string artist; // Artist of the song
    std::string genre;  // Genre of the song
    int duration;       // Duration of the song in seconds
    int plays;          // Number of times the song has been played

public:
    // Default constructor
    Song() : title(""), artist(""), genre(""), duration(0), plays(0) {}

    // Parameterized constructor
    Song(std::string t, std::string a, std::string g, int d, int p)
        : title(t), artist(a), genre(g), duration(d), plays(p) {}

    // Getters
    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getGenre() const { return genre; }
    int getDuration() const { return duration; }
    int getPlays() const { return plays; }

    // Setters
    void setTitle(std::string t) { title = t; }
    void setArtist(std::string a) { artist = a; }
    void setGenre(std::string g) { genre = g; }
    void setDuration(int d) { duration = d; }
    void setPlays(int p) { plays = p; }

    // Display the song details
    void display() const
    {
        std::cout << "Title: " << title << ", Artist: " << artist
                  << ", Genre: " << genre << ", Duration: " << duration
                  << " seconds, Plays: " << plays << "\n";
    }
};

// The Playlist class manages a collection of Song objects.
class Playlist
{
private:
    std::vector<Song> songs; // Vector to store the list of songs

public:
    // Adds a new song to the playlist
    void addSong(const Song &song)
    {
        songs.push_back(song);
    }

    // Removes a song from the playlist by its title
    void removeSong(const std::string &title)
    {
        auto it = std::remove_if(songs.begin(), songs.end(), [&title](const Song &song)
                                 { return song.getTitle() == title; });

        if (it != songs.end())
        {
            songs.erase(it, songs.end());
            std::cout << "Song removed.\n";
        }
        else
        {
            std::cout << "Song not found.\n";
        }
    }

    // Displays all songs in the playlist
    void viewPlaylist() const
    {
        if (songs.empty())
        {
            std::cout << "Playlist is empty.\n";
        }
        else
        {
            for (const auto &song : songs)
            {
                song.display();
            }
        }
    }

    // Updates the play count of a song by its title
    void updateSongStatistics(const std::string &title, int newPlays)
    {
        for (auto &song : songs)
        {
            if (song.getTitle() == title)
            {
                song.setPlays(newPlays);
                std::cout << "Updated plays for " << title << " to " << newPlays << ".\n";
                return;
            }
        }
        std::cout << "Song not found.\n";
    }
};

// Displays the menu options to the user
void showMenu()
{
    std::cout << "1. Add Song" << std::endl;
    std::cout << "2. View Songs" << std::endl;
    std::cout << "3. Update Song Statistics" << std::endl;
    std::cout << "4. Delete Song" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{
    Playlist musicCollection; // Create an instance of Playlist
    int choice;               // Variable to store user's menu choice

    while (true)
    {
        showMenu();         // Show the menu options
        std::cin >> choice; // Get the user's choice

        if (choice == 1)
        {
            std::string title, artist, genre;
            int duration, plays;
            // Get the details of the song from the user
            std::cout << "Enter song's title: ";
            std::cin.ignore(); // To handle the newline character from previous input
            std::getline(std::cin, title);
            std::cout << "Enter artist's name: ";
            std::getline(std::cin, artist);
            std::cout << "Enter genre: ";
            std::getline(std::cin, genre);
            std::cout << "Enter duration (in seconds): ";
            std::cin >> duration;
            std::cout << "Enter number of plays: ";
            std::cin >> plays;

            // Add the song to the playlist
            musicCollection.addSong(Song(title, artist, genre, duration, plays));
        }
        else if (choice == 2)
        {
            // View all songs in the playlist
            musicCollection.viewPlaylist();
        }
        else if (choice == 3)
        {
            std::string title;
            int plays;
            // Get the title of the song to update and the new play count
            std::cout << "Enter song's title to update: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter new number of plays: ";
            std::cin >> plays;

            // Update the play count of the specified song
            musicCollection.updateSongStatistics(title, plays);
        }
        else if (choice == 4)
        {
            std::string title;
            // Get the title of the song to delete
            std::cout << "Enter song title to delete: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            // Remove the song from the playlist
            musicCollection.removeSong(title);
        }
        else if (choice == 5)
        {
            // Exit the program
            std::cout << "Exiting program.\n";
            break;
        }
        else
        {
            // Handle invalid menu choices
            std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
