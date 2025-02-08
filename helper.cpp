#include "helper.h"


string readFile(string &input_file) {
    // Open file for reading
    ifstream infile(input_file);
    if (!infile) {
        cerr << "Error: Could not open input file " << input_file << endl;
        return "";
    }

    // Read the entire file into a string
    stringstream buffer;
    buffer << infile.rdbuf();
    string fileContents = buffer.str();
    infile.close();

    return fileContents;
}

vector<int> removeDuplicates(const vector<int>& vec) {
    vector<int> unique;
    for(size_t i = 0; i < vec.size(); ++i) {
        bool found = false;
        for(size_t j = 0; j < unique.size(); ++j) {
            if(vec[i] == unique[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            unique.push_back(vec[i]);
        }
    }
    return unique;
}

string intVectorToString(const vector<int>& vec) {
    string output;
    for(size_t i = 0; i<vec.size(); ++i) {
        output += " " + to_string(vec[i]);
    }
    return output;
}

