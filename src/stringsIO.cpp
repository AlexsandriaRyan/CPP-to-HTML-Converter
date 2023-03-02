// Alexsandria Ryan
// Assignment #1
// PROG2100 - C++

#include "../inc/stringsIO.h"

using namespace std;

// Custom exception class
// Referred to this source: https://rollbar.com/blog/cpp-custom-exceptions/
class myException : public exception {

private:
    string message;

public:
    myException(string msg) {
        message = std::move(msg);
    }

    myException(const string& msg1, const string& msg2) {
        message = msg1 + "\n" + msg2;
    }

    string what() {
        return "Cannot open the following file(s):\n" + message +
               "\nPlease check your file(s) and try again.";
    }
};

string inputFile(const string& fileType, const string& action) {
    cout << "Please enter the name and location of the ." << fileType << " file.\n"
            "Remember: this file will be used for " << action << ".\n"
            "Example: C:\\Users\\username\\Documents\\School\\FileName."<< fileType <<"\n"
            "Enter file path:";
    string filePath;
    getline (cin, filePath);
    filePath = validatePath(filePath, fileType);

    return filePath;
}

string validatePath(string filePath, const string& fileType) {
    bool valid = false;
    while (!valid) {
        // Got a regex from: https://stackoverflow.com/questions/15709711/c-regex-to-search-file-paths-in-a-string
        // My file path includes "&", which is permitted in Windows filenaming conventions.
        // The regex from the website above did not account for special characters like this.
        // I then looked up what characters were permitted in a Windows filename, and referred
        // to the exception list as provided by Microsoft: https://learn.microsoft.com/en-us/windows/win32/fileio/naming-a-file
        if (regex_match (filePath, regex(".?:(\\\\[^<>:\"\\/\\\\|?*]*)*\." + fileType))) {
            valid = true;

        } else {
            cout << "\nSorry, that path was invalid. Please enter a valid path for the ." << fileType << " file.\n"
            "Example: C:\\Users\\username\\Documents\\School\\FileName."<< fileType <<"\n"
            "Enter file path:";
            getline (cin, filePath);
        }
    }

    cout << "\nThank you!\n\n";
    return filePath;
}

bool checkFail(ifstream& inputFile, ofstream& outputFile, const string& cppFile, const string& htmlFile) {
    cout << "Opening files...\n";

    try {
        inputFile.open(cppFile.c_str());
        outputFile.open(htmlFile.c_str());

        if (inputFile.fail() && outputFile.fail()) {
            throw myException(cppFile, htmlFile);

        } else if (inputFile.fail()) {
            throw myException(cppFile);

        } else if (outputFile.fail()) {
            throw myException(htmlFile);

        } else {
            cout << "Read/Write request complete!\n";
            return false;
        }

    } catch (myException& customEx) {   // custom catch
        cerr << "Caught Custom Exception...\n";
        cerr << customEx.what();

    } catch (...) { // default catch
            cerr << "ERROR...\n";
    }

    return true;
}

void readWriteFile(ifstream& inputFile, ofstream& outputFile) {
    // to preserve whitespace & newlines
    outputFile << "<PRE>\n";

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            // retrieving a line of text from the file
            string line;
            getline(inputFile, line);

            // iterating over each character of the file's line, converting as needed
            for (char& c : line) {
                if (c == '<') {
                    outputFile << "&lt";

                } else if (c == '>') {
                    outputFile << "&gt";

                } else {
                    outputFile << c;
                }
            }
            // end each line with a newline
            outputFile << "\n";
        }
    }

    outputFile << "</PRE>";
}