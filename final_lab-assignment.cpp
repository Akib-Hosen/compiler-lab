#include <iostream>
#include <string>
using namespace std;

bool checkDFA(const string& str) {

    int currentState = 0;

    for (int i = 0; i < str.length(); i++) {

        char symbol = str[i];

        if (symbol != 'a' && symbol != 'b') {
            return false;
        }

        if (currentState == 0) {

            if (symbol == 'a')
                currentState = 1;
            else
                currentState = 2;
        }

        else if (currentState == 1) {

            if (symbol == 'a')
                currentState = 3;
            else
                currentState = 4;
        }

        else if (currentState == 2) {

            if (symbol == 'a')
                currentState = 3;
            else
                currentState = 5;
        }

        else if (currentState == 3) {

            if (symbol == 'a')
                currentState = 3;
            else
                currentState = 6;
        }

        else if (currentState == 4) {

            if (symbol == 'a')
                currentState = 3;
            else
                currentState = 7;
        }

        else if (currentState == 5) {

            if (symbol == 'a')
                currentState = 3;
            else
                currentState = 5;
        }

        else if (currentState == 6) {

            if (symbol == 'a')
                currentState = 3;
            else
                currentState = 5;
        }

        else if (currentState == 7) {

            if (symbol == 'a')
                currentState = 3;
            else
                currentState = 7;
        }
    }

    return true;
}

int main() {

    string samples[] = {
        "",
        "a",
        "ab",
        "abb",
        "abc"
    };

    int total = sizeof(samples) / sizeof(samples[0]);

    for (int i = 0; i < total; i++) {

        string word = samples[i];

        cout << "Input: ";

        if (word.empty())
            cout << "epsilon";
        else
            cout << word;

        if (checkDFA(word))
            cout << " --> Accepted";
        else
            cout << " --> Rejected";

        cout << endl;
    }

    return 0;
}
