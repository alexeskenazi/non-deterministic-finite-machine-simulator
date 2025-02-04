#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


class Transition {
    public:
        int p;
        char x;
        int q;

        Transition() {
            p = -1;
            q = -1;
            x = -1;
        }

        Transition(int _p, char _x, int _q) {
            p = _p;
            q = _q;
            x = _x;
        }
};

class State {
    public:
        int id;
        bool start;
        bool accept;
        vector<Transition*> transitions;
    
    State() {
        id = -1;
        start = false;
        accept = false;
    }

    State(int _id, bool _start, bool _accept) {
        id = _id;
        start = _start;
        accept = _accept;
    }

} ;


class Automata {
    public:
    vector<State> states;
    vector<int> currStateIds;
    vector<int> newStateIds;
    string input;
    bool debug;

    Automata() {
        debug = false;
        states.resize(1001);
    }

    string run(){
        string output;

        // Find the start state and set currState to it.
        int startStateId = -1;
        for(size_t i = 0; i < states.size(); ++i){
            if(states[i].start){
                startStateId = i;
                break;
            }
        }

        if(debug) cout << "Start state: " << startStateId << endl;

        // Set initial state
        currStateIds.push_back(startStateId);

        // Loop through the chars in the input
        for(size_t i = 0; i < input.size(); ++i){
            char c = input[i];

            for(size_t k = 0; k < currStateIds.size(); ++k){
                int stateId = currStateIds[k];
                State currState = states[stateId];

                // Loop through the transitions avaiable for the current state
                for(size_t j = 0; j < currState.transitions.size(); ++j){

                    // if the transition matches the input char
                    if(currState.transitions[j]->x == c){
                        // find the next state for the transition
                        int newStateId  = currState.transitions[j]->q;

                        newStateIds.push_back(newStateId);

                        if(debug) cout << "on char: " << c << "(" << currState.transitions[j]->x << ")" << " " << stateId << " -> " << newStateId << endl;
                    
                    }
                }
            }
            currStateIds = newStateIds;
        }

        vector<int> acceptedList;
        vector<int> rejectedList;
        for(size_t i = 0; i < currStateIds.size(); ++i){
            int stateId = currStateIds[i];
            State currState = states[stateId];
            if(currState.accept){  
                acceptedList.push_back(stateId);
            } else {  
                rejectedList.push_back(stateId);
            }
        }

        if(acceptedList.size()>0) {
            string output = "accepted";
            for(size_t i = 0; i<acceptedList.size(); ++i) {
                output += " " + to_string(acceptedList[i]);
            }
            return output;
        } else {
            string output = "rejected";
            for(size_t i = 0; i<rejectedList.size(); ++i) {
                output += " " + to_string(rejectedList[i]);
            }
            return output;
        }

    }


    Automata* buildAutomata(string &input_file) {
        // Open file for reading
        ifstream infile(input_file);
        if (!infile) {
            cerr << "Error: Could not open input file " << input_file << endl;
            return this;
        }

        string line;
        // Read file line by line
        while (getline(infile, line)) {
            istringstream iss(line);
            string command;
            iss >> command;
            if (command == "state") {
                int id = 0;
                string temp;
                iss >> id;
                states[id].id = id;
                while (iss >> temp) {
                    if ((temp.find("accept") != string::npos)) {
                        states[id].accept = true;
                    }
                    if ((temp.find("start") != string::npos)) {
                        states[id].start = true;
                    }
                }
            } else if (command == "transition") {
                int p = 0;
                char x = 0;
                int q = 0;
                iss >> p >> x >> q;
                Transition* trans = new Transition(p, x, q);
                states[p].transitions.push_back(trans);
            }
        }
    
        // Close the input and output files
        infile.close();


        return this;
    }

};