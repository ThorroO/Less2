#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compareFiles(const string& file1, const string& file2) {
    ifstream inFile1(file1);
    ifstream inFile2(file2);

    if (!inFile1.is_open() || !inFile2.is_open()) {
        cerr << "Couldn't open a file, hello, how are you using me?!" << endl;
        return;
    }

    string line1, line2;
    int lineNumber = 1;
    bool filesMatch = true;

    while (getline(inFile1, line1) && getline(inFile2, line2)) {
        if (line1 != line2) {
            cout << "String number " << lineNumber << " do not match:" << endl;
            cout << "File 1: " << line1 << endl;
            cout << "File 2: " << line2 << endl;
            filesMatch = false;
        }
        lineNumber++;
    }

    while (getline(inFile1, line1)) {
        cout << "String number " << lineNumber << " do not match:" << endl;
        cout << "File 1: " << line1 << endl;
        cout << "File 2: (empty)" << endl;
        lineNumber++;
        filesMatch = false;
    }

    while (getline(inFile2, line2)) {
        cout << "String number " << lineNumber << " do not match:" << endl;
        cout << "File 1: (empty)" << endl;
        cout << "File 2: " << line2 << endl;
        lineNumber++;
        filesMatch = false;
    }

    if (filesMatch) {
        cout << "The files match completely" << endl;
    }

    inFile1.close();
    inFile2.close();
}

bool isVowel(char ch) {
    ch = (ch >= 'A' && ch <= 'Z') ? ch + ('a' - 'A') : ch;
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

void analyzeFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Couldn't open a file, hello, how are you using me?!" << endl;
        return;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    string line;
    while (getline(inFile, line)) {
        lineCount++;
        for (char ch : line) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                charCount++;
                if (isVowel(ch)) {
                    vowelCount++;
                }
                else {
                    consonantCount++;
                }
            }
            else if (ch >= '0' && ch <= '9') {
                digitCount++;
                charCount++;
            }
            else if (ch != ' ' && ch != '\t') {
                charCount++;
            }
        }
    }

    outFile << "Number of characters: " << charCount << endl;
    outFile << "Number of lines: " << lineCount << endl;
    outFile << "Number of vowel letters: " << vowelCount << endl;
    outFile << "Number of consonant letters: " << consonantCount << endl;
    outFile << "Number of digits: " << digitCount << endl;

    inFile.close();
    outFile.close();
}

int main() {
    string file1 = "file1.txt";
    string file2 = "file2.txt";
    compareFiles(file1, file2);
    string inputFile = "file1.txt";
    string outputFile = "output.txt";
    analyzeFile(inputFile, outputFile);
    return 0;
}