/*
 * ============================================================================
 * PROJECT #10: WORD FREQUENCY COUNTER & ANALYZER
 * ============================================================================
 * Data Structure: Hash Map (unordered_map) + Min Heap (Priority Queue)
 * Features: Count word frequency, find top K words, search, analyze text
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

struct WordFreq {
    string word;
    int count;

    WordFreq(string w = "", int c = 0) : word(w), count(c) {}

    // Max heap (for top K frequent words)
    bool operator<(const WordFreq& other) const {
        return count < other.count;
    }
};

class WordAnalyzer {
private:
    unordered_map<string, int> wordMap;
    int totalWords;

    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    string cleanWord(string word) {
        string cleaned = "";
        for (char c : word) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        return cleaned;
    }

public:
    WordAnalyzer() : totalWords(0) {}

    void addText(const string& text) {
        stringstream ss(text);
        string word;

        while (ss >> word) {
            word = cleanWord(word);
            if (!word.empty()) {
                wordMap[word]++;
                totalWords++;
            }
        }

        cout << "✅ Text processed! Total words: " << totalWords << endl;
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "❌ Could not open file!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            addText(line);
        }

        file.close();
        cout << "✅ File loaded successfully!" << endl;
    }

    void displayAllWords() {
        if (wordMap.empty()) {
            cout << "\n⚠️  No words to display!" << endl;
            return;
        }

        cout << "\n📚 Word Frequency List:" << endl;
        for (const auto& pair : wordMap) {
            cout << "  " << pair.first << ": " << pair.second << endl;
        }
        cout << "\n  Total Unique Words: " << wordMap.size() << endl;
        cout << "  Total Words: " << totalWords << endl;
    }

    void searchWord(const string& word) {
        string cleaned = cleanWord(word);
        if (wordMap.find(cleaned) != wordMap.end()) {
            cout << "\n✅ Word \"" << cleaned << "\" found!" << endl;
            cout << "   Frequency: " << wordMap[cleaned] << " times" << endl;
            cout << "   Percentage: " << (wordMap[cleaned] * 100.0 / totalWords) << "%" << endl;
        } else {
            cout << "\n❌ Word \"" << cleaned << "\" not found!" << endl;
        }
    }

    void topKFrequent(int k) {
        if (wordMap.empty()) {
            cout << "\n⚠️  No words to analyze!" << endl;
            return;
        }

        priority_queue<WordFreq> maxHeap;

        for (const auto& pair : wordMap) {
            maxHeap.push(WordFreq(pair.first, pair.second));
        }

        cout << "\n🏆 Top " << k << " Most Frequent Words:" << endl;
        int count = 0;
        while (!maxHeap.empty() && count < k) {
            WordFreq wf = maxHeap.top();
            maxHeap.pop();
            cout << "  " << (count + 1) << ". " << wf.word 
                 << " - " << wf.count << " times ("
                 << (wf.count * 100.0 / totalWords) << "%)" << endl;
            count++;
        }
    }

    void findLeastFrequent(int k) {
        if (wordMap.empty()) {
            cout << "\n⚠️  No words to analyze!" << endl;
            return;
        }

        // Min heap
        priority_queue<WordFreq, vector<WordFreq>, greater<WordFreq>> minHeap;

        for (const auto& pair : wordMap) {
            minHeap.push(WordFreq(pair.first, pair.second));
        }

        cout << "\n📉 Top " << k << " Least Frequent Words:" << endl;
        int count = 0;
        while (!minHeap.empty() && count < k) {
            WordFreq wf = minHeap.top();
            minHeap.pop();
            cout << "  " << (count + 1) << ". " << wf.word 
                 << " - " << wf.count << " times" << endl;
            count++;
        }
    }

    void getStatistics() {
        if (wordMap.empty()) {
            cout << "\n⚠️  No data to analyze!" << endl;
            return;
        }

        int maxFreq = 0, minFreq = totalWords;
        string mostFrequent, leastFrequent;

        for (const auto& pair : wordMap) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
                mostFrequent = pair.first;
            }
            if (pair.second < minFreq) {
                minFreq = pair.second;
                leastFrequent = pair.first;
            }
        }

        cout << "\n📊 Text Statistics:" << endl;
        cout << "  Total Words: " << totalWords << endl;
        cout << "  Unique Words: " << wordMap.size() << endl;
        cout << "  Most Frequent: \"" << mostFrequent << "\" (" << maxFreq << " times)" << endl;
        cout << "  Least Frequent: \"" << leastFrequent << "\" (" << minFreq << " times)" << endl;
        cout << "  Average Frequency: " << (totalWords * 1.0 / wordMap.size()) << endl;
    }

    void clear() {
        wordMap.clear();
        totalWords = 0;
        cout << "✅ All data cleared!" << endl;
    }
};

int main() {
    WordAnalyzer analyzer;

    cout << "\n========================================================\n";
    cout << "       WORD FREQUENCY COUNTER & ANALYZER                \n";
    cout << "========================================================\n";

    // Sample text
    string sample = "The quick brown fox jumps over the lazy dog. "
                   "The dog was really lazy and the fox was very quick. "
                   "Quick movements and lazy afternoons.";
    
    cout << "\n  Sample text loaded for demonstration.\n";
    analyzer.addText(sample);

    int choice;
    while (true) {
        cout << "\n  1. Add Text\n";
        cout << "  2. Load from File\n";
        cout << "  3. Display All Words\n";
        cout << "  4. Search Word\n";
        cout << "  5. Top K Frequent Words\n";
        cout << "  6. Least K Frequent Words\n";
        cout << "  7. Show Statistics\n";
        cout << "  8. Clear All Data\n";
        cout << "  9. Exit\n";
        cout << "  Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string text;
            cout << "  Enter text (press Enter twice to finish):\n  ";
            string line;
            while (getline(cin, line) && !line.empty()) {
                text += line + " ";
            }
            analyzer.addText(text);
        }
        else if (choice == 2) {
            string filename;
            cout << "  Enter filename: ";
            getline(cin, filename);
            analyzer.loadFromFile(filename);
        }
        else if (choice == 3) analyzer.displayAllWords();
        else if (choice == 4) {
            string word;
            cout << "  Enter word to search: ";
            getline(cin, word);
            analyzer.searchWord(word);
        }
        else if (choice == 5) {
            int k;
            cout << "  Enter K: ";
            cin >> k;
            analyzer.topKFrequent(k);
        }
        else if (choice == 6) {
            int k;
            cout << "  Enter K: ";
            cin >> k;
            analyzer.findLeastFrequent(k);
        }
        else if (choice == 7) analyzer.getStatistics();
        else if (choice == 8) analyzer.clear();
        else if (choice == 9) {
            cout << "\n  📖 Thanks for using Word Analyzer!\n";
            break;
        }
    }

    return 0;
}
