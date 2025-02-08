#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MAX_STATES 1500


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

        ~Transition() {
            // cout << "Transition destroyed" << endl;
        }
};

class State {
    public:
        int id;
        bool start;
        bool accept;
        vector<Transition> transitions;
    
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

   ~State() {
        // cout << "State destroyed" << endl;
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
        states.resize(MAX_STATES+1);
    }

    string run(){
        string output;

        // Find the start state and set currState to it.
        int startStateId = getStartStateId();

        // Set initial state
        currStateIds.push_back(startStateId);

        if(debug) cout << "Input string '" << input << "'" << endl;

        // Loop through the chars in the input
        for(size_t i = 0; i < input.size(); ++i){

            // Get the input character
             char c = input[i];

            if(debug) cout << "Input States " << intVectorToString(currStateIds) << endl;

            // Loop throgh all the current states to find the applicable transitions
            // and get the new set of states.
            newStateIds.clear();
            for(size_t k = 0; k < currStateIds.size(); ++k){
                int stateId = currStateIds[k];
                State currState = states[stateId];


                // If the current state has no transitions for the current input then
                // keep the state in the vector (add it again)
                if(getMatchingTransitionsCount(stateId, c)==0) {
                    if(debug) cout << "   on char: " << c << " " << stateId << " has no transitions. Adding " << stateId << endl;
                    newStateIds.push_back(stateId);
                }

                // Loop through the transitions avaiable for the current state and
                // find the new state for those that match the input character.
                for(size_t j = 0; j < currState.transitions.size(); ++j){

                    // if the transition matches the input character then add
                    // the resulting state to our vector of new states ids
                    if(currState.transitions[j].x == c){
                        // find the next state for the transition
                        int newStateId  = currState.transitions[j].q;

                        newStateIds.push_back(newStateId);

                        if(debug) cout << "   on char: " << c << "(" << currState.transitions[j].x << ")" << " " << stateId << " . " << newStateId << endl;
                    }
                }
            }

            currStateIds = newStateIds;
            currStateIds = removeDuplicates(currStateIds);
            if(debug) cout << "Output States " << intVectorToString(currStateIds) << endl;
        }

        // Separate the last set of states into accepted and rejected in order
        // to later create the output string.
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


        // If there is a least one accepted state then the input was accepted,
        // else the input was rejected.
        if(acceptedList.size()>0) {
            string output = "accept";
            for(size_t i = 0; i<acceptedList.size(); ++i) {
                output += " " + to_string(acceptedList[i]);
            }
            return output;
        } else {
            string output = "reject";
            for(size_t i = 0; i<rejectedList.size(); ++i) {
                output += " " + to_string(rejectedList[i]);
            }
            return output;
        }
    }

    int getStartStateId() {
        int startStateId = -1;
        for (size_t i = 0; i < states.size(); ++i)
        {
            if (states[i].start)
            {
                startStateId = i;
                break;
            }
        }
        if(debug) cout << "Start state: " << startStateId << endl;
        return startStateId;
    }

    Automata* buildAutomataFromFile(string &input_file) {
        // Open file for reading
        ifstream infile(input_file);
        if (!infile) {
            cerr << "Error: Could not open input file " << input_file << endl;
            return this;
        }

        // Read the entire file into a string
        stringstream buffer;
        buffer << infile.rdbuf();
        string fileContents = buffer.str();
        infile.close();

        // Call the new method to process the file contents
        return buildAutomataFromString(fileContents);
    }

    Automata* buildAutomataFromString(const string &fileContents) {
        // Process the file contents line by line
        istringstream iss(fileContents);
        string line;
        while (getline(iss, line)) {
            istringstream lineStream(line);
            string command;
            lineStream >> command;
            if (command == "state") {
                int id = 0;
                string temp;
                lineStream >> id;

                if(id < 0 || id > MAX_STATES) {
                    // Ignore states that are out of range
                    continue;
                }

                states[id].id = id;
                while (lineStream >> temp) {
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
                lineStream >> p >> x >> q;
                if (p < 0 || p > MAX_STATES || q < 0 || q > MAX_STATES) {
                    // Ignore transitions that are out of range
                    continue;
                }
                states[p].transitions.push_back(Transition(p, x, q));

                // Mark the target state as a valid state
                states[q].id = q;
            }
        }

        return this;
    }

    vector<int> removeDuplicates( vector<int> v ) {
        vector<int> unique;
        for(size_t i = 0; i < v.size(); ++i) {
            bool found = false;
            for(size_t j = 0; j < unique.size(); ++j) {
                if(v[i] == unique[j]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                unique.push_back(v[i]);
            }
        }
        return unique;
    }


    int getMatchingTransitionsCount(int stateId, char c) {
        int count = 0;
        State currState = states[stateId];
        for(size_t j = 0; j < currState.transitions.size(); ++j){
            if(currState.transitions[j].x == c){
                count++;
            }
        }
        return count;

    }

    string intVectorToString(const vector<int> &vec) {
        string output;
        for(size_t i = 0; i<vec.size(); ++i) {
            output += " " + to_string(vec[i]);
        }
        return output;
    }


};