#pragma once
#include <vector>
#include <string>
#include <iostream>

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

};