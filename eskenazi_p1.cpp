#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "automata.h"






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


int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided
    // if (argc != 3) {
    //     cerr << "Usage: " << argv[0] << " <input file> <input string>" << endl;
    //     return 1;
    // }

    // Get the input and output file names from command-line arguments
    // string input_file = argv[1];
    // string input = argv[2];
    string command;
    string input_file = "data/sample_2.txt";
    string input = "001";

    // Open file for reading
    ifstream infile(input_file);
    if (!infile) {
        cerr << "Error: Could not open input file " << input_file << endl;
        return 1;
    }

    Automata automata;
    // Read addresses and access types
    while (infile >> command) {
        if(command == "state"){
            int id = 0;
            string temp;
            infile >> id;
            infile >> temp;
            automata.states[id].id = id;
            automata.states[id].accept = (temp=="accept");
            automata.states[id].start = (temp=="start");
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
    return 0;
}

