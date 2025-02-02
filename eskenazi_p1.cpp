#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "automata.h"

bool debug = true;

void test(string input_file, string input_string, string expected_output);
void runTests() ;
string runAutomata(string &input_file, string &input_string);


void test(string input_file, string input_string, string expected_output) {
    string output = runAutomata(input_file, input_string);
    if (output == expected_output)
    {
        if (debug) cout << "Test passed: " << input_file << " " << input_string << endl;
    }
    else
    {
        if (debug) cout << "Test failed: " << input_file << " " << input_string << "expected: " << expected_output << " but got: " << output << endl;
    }
}

void runTests() {
    test("data/sample_1.txt", "0", "reject 1 2\n");
    test("data/sample_1.txt", "000", "accept 7\n");
    test("data/sample_1.txt", "10", "reject 1 2\n");
    test("data/sample_2.txt", "0", "reject 1\n");
    test("data/sample_2.txt", "0101", "reject 3\n");
    test("data/sample_2.txt", "010111", "accept 4 5\n");
    test("data/sample_2.txt", "0101110000", "accept 4 5 6\n");
    // // test("data/sample_1.txt", "101010101010101010101010101010101010", "accept 4 5 6\n");
    // test("data/test3.txt", "ab", "accept 3 4\n");
    // test("data/test3.txt", "aba", "accept 3 4\n");
    // test("data/test3.txt", "abb", "accept 3 4\n"); // ??
    // test("data/trivial.txt", "", "reject 0\n");
    // test("data/trivial.txt", "a", "reject 0\n");

    // test("data/homework4.txt", "011", "reject 9\n");
    // test("data/homework4.txt", "101", "accept 8\n");
    // test("data/homework4.txt", "1111011111", "accept 8\n");

    // test("data/homework3-a.txt", "10101", "accept 6\n");
    // test("data/homework3-a.txt", "1010100", "accept 6\n");
    // test("data/homework3-a.txt", "1010110", "accept 6\n");
    // test("data/homework3-a.txt", "11010110", "accept 6\n");
    // test("data/homework3-a.txt", "01010110", "accept 6\n");
    // test("data/homework3-a.txt", "10100", "reject 3\n");
    // test("data/homework3-a.txt", "111010", "reject 5\n");  
}

    // read and check command line arguments

    // Extract the filename and the input string

    // Start reading the file

    // For each line in the file 
    // Parse:
    // If the line starts with "state" 
    //       we read the state number
    //       we read if is a Start state
    //       we read if is an Accept state
    //       we add the new state to the automata state vector.

     // If the line starts with "transition" 
    //       we read the p state
    //       we read the input char
    //       we read the q state
    //       we add the new transition to the transition vector in the corresponding state.

    // Stope reading the file.


    // Run the machine with the string input.

string runAutomata(string &input_file, string &input_string){
    // Open file for reading
    ifstream infile(input_file);
    if (!infile) {
        cerr << "Error: Could not open input file " << input_file << endl;
        return "";
    }

    Automata automata;
    string command;
    // Read addresses and access types
    while (infile >> command) {
        if(command == "state"){
            int id = 0;
            string temp;
            infile >> id;
            infile >> temp;
            automata.states[id].id = id;
            automata.states[id].accept = (temp.find("accept") != string::npos);
            automata.states[id].start = (temp.find("start") != string::npos);
        }

        if(command == "transition"){
            int p = 0;
            char x = 0;
            int q = 0;
            infile >> p;
            infile >> x;
            infile >> q;

            Transition* trans = new Transition(p, x, q);
            automata.states[p].transitions.push_back(trans);
        }
        
    }
   
    // Close the input and output files
    infile.close();
    automata.input = input_string;
    string output = automata.run();
    return output;
}

int main(int argc, char* argv[]) {
    runTests();

    // Check if the correct number of arguments are provided
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input file> <input string>" << endl;
        return 1;
    }

    // Get the input and output file names from command-line arguments
    string input_file = argv[1];
    string input = argv[2];


    string output = runAutomata(input_file, input);
    cout << output << endl;
    return 0;
}



