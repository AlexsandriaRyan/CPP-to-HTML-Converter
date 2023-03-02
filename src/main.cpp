// Alexsandria Ryan
// Assignment #1
// PROG2100 - C++

#include "../inc/stringsIO.h"

using namespace std;

int main() {

    cout << "STRING TEST\n";

    // declaring and initializing cpp / html files
    const string cppFile = inputFile("cpp", "reading");
    const string htmlFile = inputFile("html", "writing");

    // declare stream objects
    ifstream inputFile;
    ofstream outputFile;

    // ensuring cpp / html files can be read
    bool isFailed = checkFail(inputFile, outputFile, cppFile, htmlFile);

    if (isFailed) {
        inputFile.close();
        outputFile.close();
        cout << "Could not complete request. Exiting program...\n";
        return 1;
    }

    // try / catch block for reading / writing
    try {
        readWriteFile(inputFile, outputFile);
        cout << "Closing files...";

    } catch (bad_exception &badEx) { // library catch
        cerr << "Caught exception " << badEx.what() << "\nEnsuring files are closed...";

    } catch (...) { // default catch
        cerr << "Could not complete request.\nEnsuring files are closed...";
    }

    // closing resources
    inputFile.close();
    outputFile.close();

    return 0;
}