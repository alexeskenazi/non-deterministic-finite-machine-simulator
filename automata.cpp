#include "automata.h"




string Automata::DumpToJson() {
        // create a json string based on the following example:
//         {
//   "type": "NFA",
//   "nfa": {
//     "transitions": {
//       "start": {
//         "A": [
//           "s0"
//         ]
//       },
//       "s0": {
//         "B": [
//           "s1"
//         ]
//       },
//       "s1": {
//         "": [
//           "start"
//         ]
//       }
//     },
//     "startState": "start",
//     "acceptStates": [
//       "s1"
//     ]
//   },
//   "states": {
//     "start": {},
//     "s0": {
//       "top": 150,
//       "left": 245,
//       "displayId": "s0"
//     },
//     "s1": {
//       "isAccept": true,
//       "top": 327,
//       "left": 224,
//       "displayId": "s1"
//     }
//   },
//   "transitions": [
//     {
//       "stateA": "start",
//       "label": "A",
//       "stateB": "s0"
//     },
//     {
//       "stateA": "s0",
//       "label": "B",
//       "stateB": "s1"
//     },
//     {
//       "stateA": "s1",
//       "label": "ϵ",
//       "stateB": "start"
//     }
//   ],
//   "bulkTests": {
//     "accept": "AB\nABAB\nABABAB",
//     "reject": "\nA\nB\nABA\nBA\nBB\nABABB"
//   }
// }
        // get the count valid states
        int count = 0;
        for(size_t i = 0; i < states.size(); ++i) {
            if(states[i].id != -1) {
                count++;
            }
        }

        // get count of accepted states
        int acceptedCount = 0;
        for(size_t i = 0; i < states.size(); ++i) {
            if(states[i].id != -1 && states[i].accept) {
                acceptedCount++;
            }
        }

        string json = "{\n";
        json += "  \"type\": \"NFA\",\n";
        json += "  \"nfa\": {\n";
        json += "    \"transitions\": {\n";

        // Loop through the states and create the transitions
        int processed = 0;
        for(size_t i = 0; i < states.size(); ++i) {
            State currState = states[i];
            if(currState.id == -1) continue;
            processed++;
            json += "      \"" + to_string(currState.id) + "\": {\n";
            for(size_t j = 0; j < currState.transitions.size(); ++j) {
                json += "        \"" + string(1, currState.transitions[j]->x) + "\": [\n";
                json += "          \"" + to_string(currState.transitions[j]->q) + "\"\n";
                if(j < currState.transitions.size()-1) {
                    json += "        ],\n";
                } else {

                    json += "        ]\n";
                }
            }
            if(processed < count) {
                json += "      },\n";
            } else {
                json += "      }\n";
            }
        }

        json += "    },\n";
        json += "    \"startState\": \"" + to_string(getStartStateId()) + "\",\n";
        json += "    \"acceptStates\": [\n";
        json += "      ";
        processed = 0;
        for(size_t i = 0; i < states.size(); ++i) {
            State currState = states[i];
            if(currState.id == -1) continue;
            if(currState.accept) {
                processed++;
                json += "\"" + to_string(currState.id) + "\""; 
                if(processed < acceptedCount) {
                    json += ", ";
                }
            }
        }
        json += "\n";
        json += "    ]\n";
        json += "  },\n";
        json += "  \"states\": {\n";
        json += "    \"start\": {},\n";
        processed = 0;
        for(size_t i = 0; i < states.size(); ++i) {
            State currState = states[i];
            if(currState.id == -1) continue;
            processed++;
            json += "    \"" + to_string(currState.id) + "\": {\n";
            json += "      \"top\": 150,\n";
            json += "      \"left\": " + to_string(200*processed) + ",\n";
            json += "      \"displayId\": \"" + to_string(currState.id) + "\"\n";
            if(processed < count) {
                json += "    },\n";
            } else {
                json += "    }\n";
            }
        }
        json += "  },\n";
        json += "  \"transitions\": [\n";
        processed = 0;
        for(size_t i = 0; i < states.size(); ++i) {
            State currState = states[i];
            if(currState.id == -1) continue;
            processed++;
            for(size_t j = 0; j < currState.transitions.size(); ++j) {
                json += "    {\n";
                json += "      \"stateA\": \"" + to_string(currState.id) + "\",\n";
                json += "      \"label\": \"" + string(1, currState.transitions[j]->x) + "\",\n";
                json += "      \"stateB\": \"" + to_string(currState.transitions[j]->q) + "\"\n";
                if(processed < count || j < currState.transitions.size()-1) {
                    json += "    },\n";
                } else {
                    json += "    }\n";
                }
            }
        }
        json += "  ],\n";
        json += "  \"bulkTests\": {\n";
        json += "    \"accept\": \"AB\\nABAB\\nABABAB\",\n";
        json += "    \"reject\": \"\\nA\\nB\\nABA\\nBA\\nBB\\nABABB\"\n";
        json += "  }\n";
        json += "}\n";
        

        

        return json;


    }