#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "automata.h"
#include "automata-tests.h"

using namespace std;

bool debug = false;


int main(int argc, char* argv[]) {

    if(argc == 2 && (string(argv[1]) == "test" || string(argv[1]) == "tests")) {
        cout << "Running tests" << endl;
        runTests();
        return 0;
    }
    
    if (argc != 3) {
        cout << "******************************************************" << endl;
        cout << "* Runs an NFA (Non Deterministic Finite Automata)" << endl;
        cout << "******************************************************" << endl;
        cout << "* Notes and Limitations:" << endl;
        cout << "*  E-transitions are NOT yet supported." << endl;
        cout << "*  Supports up to 1000 States." << endl;
        cout << "*  Supports multiple transitions per state." << endl;
        cout << "*  Supports multiple accept states." << endl;
        cout << "*  Supports a single start state." << endl;
        cout << "*  States are identified by an integer id." << endl;
        cout << "* Usage 1: " << argv[0] << " <input file> <input string>" << endl;
        cout << "* Usage 2: " << argv[0] << " test" << endl;
        cout << "* Examples:" << endl;
        cout << "*    " << argv[0] << " data/sample_2.txt 010111" << endl;
        cout << "*    " << argv[0] << " test" << endl;
        cout << "******************************************************" << endl;
        return 0;
    }

    // Get the input and output file names from command-line arguments
    string input_file = argv[1];
    string input = argc>2 ? argv[2] : "";

    string fileContents = readFile(input_file);

    Automata automata;
    automata.debug = debug;
    automata.build(fileContents);
    automata.input = input;
    string output = automata.run();
    cout << output << endl;
    return 0;
}



