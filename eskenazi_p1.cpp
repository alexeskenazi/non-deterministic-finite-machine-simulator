#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "automata.h"
#include <cassert>

bool g_debug = true;

void testBasicStateParsing();
void test(string input_file, string input_string, string expected_output);
void runTests() ;

string runAutomata(string &input_file, string &input_string, bool debug){
    Automata automata;
    automata.debug = debug;
    automata.buildAutomata(input_file);
    automata.input = input_string;
    string output = automata.run();
    return output;
}

int main(int argc, char* argv[]) {

    if(argc == 1) {
        runTests();
    }

    // Check if the correct number of arguments are provided
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input file> <input string>" << endl;
        cerr << "if there are no command line arguments the program will run its tests." << endl;
        return 1;
    }

    // Get the input and output file names from command-line arguments
    string input_file = argv[1];
    string input = argv[2];


    string output = runAutomata(input_file, input, false);
    cout << output << endl;
    return 0;
}



void testBasicStateParsing() {
    Automata a;
    string filename = "data/basic.txt";
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
        cout << "Test passed: " << input_file << " " << input_string << " output: " << output << endl;
    }
    else
    {
        cout << "Test FAILED: " << input_file << " " << input_string << " expected: " << expected_output << " but got: " << output << endl;
    }
}


void runTests() {
    testBasicStateParsing();


    // set the last argument to true to debug the specif test
    test("data/test1.txt", "0", "reject 1", false); 
    
    test("data/sample_1.txt", "0", "reject 1 2", false);
    test("data/sample_1.txt", "000", "accept 7", false);
    test("data/sample_1.txt", "10", "reject 1 2", false);

    test("data/sample_2.txt", "0", "reject 1", false);
    test("data/sample_2.txt", "0101", "reject 3", false);
    test("data/sample_2.txt", "010111", "accept 4 5", false);
    test("data/sample_2.txt", "0101110000", "accept 4 5 6", false);

    // test("data/sample_1.txt", "101010101010101010101010101010101010", "accept 4 5 6", false);
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
    test("data/homework3-a.txt", "10100", "reject 1", false);
    test("data/homework3-a.txt", "111010", "reject 5", false);  
}




