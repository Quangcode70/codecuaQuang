#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayCurrentState(const string& word, const string& guessed) {
    for (char c : word) {
        if (guessed.find(c) != string::npos) {
            cout << c << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const string& word, const string& guessed) {
    for (char c : word) {
        if (guessed.find(c) == string::npos) {
            return false;
        }
    }
    return true;
}

void displayHangman(int attempts) {
    static const vector<string> hangmanStages = {
        "  +---+\n      |\n      |\n      |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n      |\n      |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n  |   |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n /|   |\n      |\n========= \n",
        "  +---+\n  O   |\n /|\\  |\n      |\n========= \n",
        "  +---+\n  O   |\n /|\\  |\n /    |\n========= \n",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n========= \n"
    };

    cout << hangmanStages[6 - attempts] << endl;
}

string getRandomWord(const vector<string>& words) {
    srand(time(0));
    int index = rand() % words.size();
    return words[index];
}

void startGame() {
    vector<string> words = {
        "angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame",
        "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house",
        "island", "jewel",
        "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun",
        "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth",
        "town", "train", "tray", "tree", "trousers",
        "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"
    };
    string word = getRandomWord(words); 
    string guessed;
    int attempts = 6;

    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0) {
        displayHangman(attempts);
        displayCurrentState(word, guessed);
        cout << "You have " << attempts << " incorrect guesses left. Enter a letter: ";
        
        char guess;
        cin >> guess;

        if (guessed.find(guess) != string::npos) {
            cout << "You have already guessed this letter!" << endl;
            continue;
        }

        guessed += guess;

        if (word.find(guess) == string::npos) {
            attempts--;
            cout << "Wrong!" << endl;
        } else {
            cout << "Correct!" << endl;
        }

        if (isWordGuessed(word, guessed)) {
            cout << "Congratulations! You guessed the word " << word << "!" << endl;
            break;
        }
    }

    if (attempts == 0) {
        displayHangman(attempts);
        cout << "You lost! The correct word was " << word << "." << endl;
    }
}

void showInstructions() {
    cout << "Hangman Instructions:" << endl;
    cout << "1. You will be given a random word to guess." << endl;
    cout << "2. You have a limited number of incorrect guesses before you lose." << endl;
    cout << "3. For each incorrect guess, a part of the hangman is drawn." << endl;
    cout << "4. Try to guess the word by inputting letters." << endl;
    cout << "5. If you guess all letters correctly before running out of attempts, you win!" << endl;
}

void showMenu() {
    int choice;
    do {
        cout << "\nHangman Game Menu:" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showInstructions();
                break;
            case 3:
                cout << "Thank you for playing! Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    } while (choice != 3);
}

int main() {
    showMenu();
    return 0;
}
