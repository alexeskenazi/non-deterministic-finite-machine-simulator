#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "automata.h"
#include <cassert>

using namespace std;

bool debug = true;

void testBasicStateParsing();
void test(string input_file, string input_string, string expected_output);
void runTests() ;

string runAutomata(string &input_file, string &input_string, bool debug){
    Automata automata;
    automata.debug = debug;
    automata.buildAutomata(input_file);
    automata.input = input_string;
    string output = automata.run();
    if(debug) {
        cout << automata.DumpToJson() << endl;
    }
    return output;
}

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


    string output = runAutomata(input_file, input, false);
    cout << output << endl;
    return 0;
}



void testBasicStateParsing() {
    // Test the basic state parsing to make sure the following formats are accepted:
    // state 1 start
    // state 2 accept
    // state 3 acceptstart
    // state 4 start accept
    Automata a;
    string filename = "./data/basic.txt";
    a.buildAutomata(filename);

    // Check the exptect parsed states

    // state 1 start
    assert(a.states[1].accept == false);
    assert(a.states[1].start == true);

    // state 2 accept
    assert(a.states[2].accept == true);
    assert(a.states[2].start == false);

    // state 3 acceptstart
    assert(a.states[3].accept == true);
    assert(a.states[3].start == true);

     // state 4 start accept
    assert(a.states[4].accept == true);
    assert(a.states[4].start == true);
}

void test(string input_file, string input_string, string expected_output, bool debug) {
    string output = runAutomata(input_file, input_string, debug);
    if (output == expected_output)
    {
        if(input_string.size() > 10) {
            cout << "Test passed: " << input_file << " " << input_string.substr(0,10) << "... output: " << output << endl;
        } else {
            cout << "Test passed: " << input_file << " " << input_string << " output: " << output << endl;
        }
    }
    else
    {
        if(input_string.size() > 10) {
            cout << "Test FAILED: " << input_file << " " << input_string.substr(0,10) << "... expected: " << expected_output << " but got: " << output << endl;
        } else {
            cout << "Test FAILED: " << input_file << " " << input_string << " expected: " << expected_output << " but got: " << output << endl;
        }
    }
}


void runTests() {
    testBasicStateParsing();

    test("data/test1.txt", "0", "reject 1", false); 
    
    test("data/sample_1.txt", "0", "reject 1 2", false); 
    test("data/sample_1.txt", "000", "accept 7", false); 
    test("data/sample_1.txt", "10", "reject 1 2", false); 

    test("data/sample_2.txt", "0", "reject 1", false); 
    test("data/sample_2.txt", "0101", "reject 3", false); 
    test("data/sample_2.txt", "010111", "accept 4 5", false); 
    test("data/sample_2.txt", "0101110000", "accept 4 5 6", false); 

    test("data/sample_1.txt", "101010101010101010101010101010101010", "reject 1 2", false); 
    test("data/test3.txt", "ab", "accept 3 4", false); 
    test("data/test3.txt", "aba", "accept 3 4", false); 
    test("data/test3.txt", "abb", "accept 3 4", false); // ??
    test("data/trivial.txt", "", "reject 0", false); 
    test("data/trivial.txt", "a", "reject 0", false); 

    test("data/homework4.txt", "011", "reject 9", false); 
    test("data/homework4.txt", "101", "accept 8", false); 
    test("data/homework4.txt", "1111011111", "accept 8", false); 

    test("data/homework3-a.txt", "10101", "accept 6", false); 
    test("data/homework3-a.txt", "1010100", "accept 6", false); 
    test("data/homework3-a.txt", "1010110", "accept 6", false); 
    test("data/homework3-a.txt", "11010110", "accept 6", false); 
    test("data/homework3-a.txt", "01010110", "accept 6", false); 
    test("data/homework3-a.txt", "10100", "accept 1", false); 
    test("data/homework3-a.txt", "111010", "reject 5", false);  


    // generate a string of 1000 ones 
    string longString;
    for (int i = 1; i < 1000; ++i){
        longString += "1";
    }
    test("data/long.txt", longString, "accept 1000", false);
    

    // Generata a string of 999 ones
    longString = "";
    for (int i = 1; i < 999; ++i){
      longString += "1";
    }
    test("data/long.txt", longString, "reject 999", false);
}




