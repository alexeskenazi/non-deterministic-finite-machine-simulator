#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "helper.h"

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

        Automata();
        Automata* build(const string &fileContents);
        string run();

    private:
        int getStartStateId();
        int getMatchingTransitionsCount(int stateId, char c);
};
