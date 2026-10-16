// example ofstream

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Open a file named "output.txt" for writing
    ofstream outputFile("output.txt");

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Write some data to the file
    outputFile << "Hello, world!" << endl;
    outputFile << 42 << endl;
    outputFile << 3.14 << endl;

    // Close the file when done
    outputFile.close();

    return 0;
}
