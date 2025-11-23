/*
 * ============================================================================
 * PROJECT #6: PLAYLIST MANAGER (MUSIC/VIDEO QUEUE)
 * ============================================================================
 * Data Structure: Circular Queue + Stack for recently played
 * Features: Play queue, shuffle, repeat, recently played history
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Song {
    int id;
    string title;
    string artist;
    int duration; // in seconds

    void display() const {
        cout << "  [" << id << "] " << title << " - " << artist 
             << " (" << duration/60 << ":" << (duration%60 < 10 ? "0" : "") 
             << duration%60 << ")" << endl;
    }
};

class PlaylistManager {
private:
    queue<Song> playQueue;
    stack<Song> recentlyPlayed;
    vector<Song> allSongs;
    int nextId;
    bool repeatMode;
    Song currentSong;
    bool isPlaying;

public:
    PlaylistManager() : nextId(1), repeatMode(false), isPlaying(false) {
        srand(time(0));
    }

    void addSong(const string& title, const string& artist, int duration) {
        Song song = {nextId++, title, artist, duration};
        allSongs.push_back(song);
        cout << "✅ Song added to library!" << endl;
    }

    void addToQueue(int songId) {
        for (const auto& song : allSongs) {
            if (song.id == songId) {
                playQueue.push(song);
                cout << "✅ Added to play queue!" << endl;
                return;
            }
        }
        cout << "❌ Song not found!" << endl;
    }

    void play() {
        if (playQueue.empty()) {
            cout << "❌ Queue is empty! Add songs first." << endl;
            return;
        }

        currentSong = playQueue.front();
        playQueue.pop();
        isPlaying = true;

        cout << "\n🎵 Now Playing:" << endl;
        currentSong.display();

        recentlyPlayed.push(currentSong);

        if (repeatMode) {
            playQueue.push(currentSong);
        }
    }

    void next() {
        if (playQueue.empty()) {
            cout << "❌ No next song in queue!" << endl;
            isPlaying = false;
            return;
        }
        play();
    }

    void previous() {
        if (recentlyPlayed.size() < 2) {
            cout << "❌ No previous song!" << endl;
            return;
        }

        recentlyPlayed.pop(); // Remove current
        Song prev = recentlyPlayed.top();
        recentlyPlayed.pop();

        playQueue.push(currentSong); // Put current back in queue
        
        // Move remaining queue to front
        queue<Song> temp;
        temp.push(prev);
        while (!playQueue.empty()) {
            temp.push(playQueue.front());
            playQueue.pop();
        }
        playQueue = temp;

        play();
    }

    void shuffle() {
        vector<Song> temp;
        while (!playQueue.empty()) {
            temp.push_back(playQueue.front());
            playQueue.pop();
        }

        random_shuffle(temp.begin(), temp.end());

        for (const auto& song : temp) {
            playQueue.push(song);
        }

        cout << "🔀 Queue shuffled!" << endl;
    }

    void toggleRepeat() {
        repeatMode = !repeatMode;
        cout << (repeatMode ? "🔁 Repeat mode ON" : "➡️  Repeat mode OFF") << endl;
    }

    void showQueue() const {
        if (playQueue.empty()) {
            cout << "\n⚠️  Queue is empty!" << endl;
            return;
        }

        cout << "\n📋 Play Queue:" << endl;
        queue<Song> temp = playQueue;
        int pos = 1;
        while (!temp.empty()) {
            cout << "  " << pos++ << ". ";
            temp.front().display();
            temp.pop();
        }
    }

    void showRecentlyPlayed() const {
        if (recentlyPlayed.empty()) {
            cout << "\n⚠️  No recently played songs!" << endl;
            return;
        }

        cout << "\n🕐 Recently Played:" << endl;
        stack<Song> temp = recentlyPlayed;
        int pos = 1;
        while (!temp.empty()) {
            cout << "  " << pos++ << ". ";
            temp.top().display();
            temp.pop();
        }
    }

    void showLibrary() const {
        if (allSongs.empty()) {
            cout << "\n⚠️  No songs in library!" << endl;
            return;
        }

        cout << "\n📚 Song Library:" << endl;
        for (const auto& song : allSongs) {
            song.display();
        }
    }

    void clearQueue() {
        while (!playQueue.empty()) playQueue.pop();
        cout << "🗑️  Queue cleared!" << endl;
    }
};

int main() {
    PlaylistManager player;

    cout << "\n========================================================\n";
    cout << "             PLAYLIST MANAGER                           \n";
    cout << "========================================================\n";

    // Add sample songs
    player.addSong("Shape of You", "Ed Sheeran", 234);
    player.addSong("Blinding Lights", "The Weeknd", 200);
    player.addSong("Bohemian Rhapsody", "Queen", 354);
    player.addSong("Imagine", "John Lennon", 183);
    player.addSong("Hotel California", "Eagles", 391);

    int choice;
    while (true) {
        cout << "\n  1. Add Song to Library\n";
        cout << "  2. View Library\n";
        cout << "  3. Add Song to Queue\n";
        cout << "  4. View Queue\n";
        cout << "  5. Play Next\n";
        cout << "  6. Previous Song\n";
        cout << "  7. Shuffle Queue\n";
        cout << "  8. Toggle Repeat Mode\n";
        cout << "  9. Recently Played\n";
        cout << "  10. Clear Queue\n";
        cout << "  11. Exit\n";
        cout << "  Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title, artist;
            int duration;
            cout << "  Title: ";
            getline(cin, title);
            cout << "  Artist: ";
            getline(cin, artist);
            cout << "  Duration (seconds): ";
            cin >> duration;
            player.addSong(title, artist, duration);
        }
        else if (choice == 2) player.showLibrary();
        else if (choice == 3) {
            int id;
            cout << "  Enter Song ID: ";
            cin >> id;
            player.addToQueue(id);
        }
        else if (choice == 4) player.showQueue();
        else if (choice == 5) player.play();
        else if (choice == 6) player.previous();
        else if (choice == 7) player.shuffle();
        else if (choice == 8) player.toggleRepeat();
        else if (choice == 9) player.showRecentlyPlayed();
        else if (choice == 10) player.clearQueue();
        else if (choice == 11) {
            cout << "\n  🎵 Thanks for using Playlist Manager!\n";
            break;
        }
    }

    return 0;
}
