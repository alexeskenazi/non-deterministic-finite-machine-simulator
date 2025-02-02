#pragma once
#include <vector>
#include <string>

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
    int currStateId = -1;
    string input;

    Automata() {
        
        states.resize(1001);
    }

    string run(){
        string output;

        // Find the start state and set currState to it.
        for(int i = 0; i < states.size(); ++i){
            if(states[i].start){
                currStateId = i;
                break;
            }

        }

        State currState = states[currStateId];
        for(int i = 0; i < input.size(); ++i){
            char c = input[i];
            for(int j = 0; j < currState.transitions.size(); ++j){
                if(currState.transitions[j]->x == c){
                    currStateId = currState.transitions[j]->q;
                }
            }
        }

        if(currState.accept){  
            return "accept " + to_string(currStateId);
        } else {  
            return "reject " + to_string(currStateId);
        }
        


        return output;
    }

};