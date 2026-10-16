/*
ofstream

stands for "output file stream".
It is part of <fstream>

ofstream does:
Opening Files
Writing Data
Closing Files

=================

if (!keystrokeFile.is_open())
 checks whether the file `keystrokes.txt` was opened.

Let's break it down:

- `keystrokeFile.is_open()`:
member function of the `ofstream` class,
which returns `true`
if the file associated with the `ofstream` object is currently open,
and `false` otherwise.
It checks whether the file stream has been successfully opened
and is ready for writing.

- `!keystrokeFile.is_open()`:
if the file is not open (`keystrokeFile.is_open()` returns `false`),
this condition evaluates to `true`,
indicating that there was an error opening the file.
*/


#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    // Open a file
    ofstream keystrokeFile("keystrokes.txt");

    // checks whether the file was opened.
    if (!keystrokeFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Continuously monitor keystrokes
    char keystroke;
    while (true) {
        // Read a single character
        // program waits the user to input a single character 
        keystroke = cin.get();
        // Also can be used
        //cin >> keystroke;

        // Write the keystroke to the file
        keystrokeFile << keystroke;

        // Flush the buffer to ensure the keystroke is written immediately
        keystrokeFile.flush();

        // Optional: Print the keystroke to console
        cout << "Keystroke recorded: " << keystroke << endl;

        // delay to reduce CPU usage
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    // Close the file
    keystrokeFile.close();

    return 0;
}




