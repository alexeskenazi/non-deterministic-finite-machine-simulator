#pragma once
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

    Automata() {
        
        states.resize(1001);
    }



};