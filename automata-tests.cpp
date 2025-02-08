#include "automata.h"
#include <cassert>
#include "automata-tests.h"
using namespace std;


const string basic = R"(
    state	1	start
    state	2	accept
    state	3	startaccept
    state	4	acceptstart
    state   5   start accept
)";

void testBasicStateParsing() {
    // Test the basic state parsing to make sure the following formats are accepted:

    Automata a;
    a.build(basic);

    // Check the exptect parsed states

    // state 1 start
    assert(a.states[1].accept == false);
    assert(a.states[1].start == true);

    // state 2 accept
    assert(a.states[2].accept == true);
    assert(a.states[2].start == false);

    // state 3 acceptstart
    assert(a.states[3].accept == true);
    assert(a.states[3].start == true);

     // state 4 start accept
    assert(a.states[4].accept == true);
    assert(a.states[4].start == true);

    // state 5 start accept
    assert(a.states[4].accept == true);
    assert(a.states[4].start == true);
}

void test(string test_name, string automata_string, string input_string, string expected_output, bool debug) {
    Automata automata;
    automata.debug = debug;
    automata.build(automata_string);
    automata.input = input_string;
    string output = automata.run();
    
    if (output == expected_output)
    {
        if(input_string.size() > 10) {
            cout << "Test passed: " << test_name << " " << input_string.substr(0,10) << "... output: " << output << endl;
        } else {
            cout << "Test passed: " << test_name << " " << input_string << " output: " << output << endl;
        }
    }
    else
    {
        if(input_string.size() > 10) {
            cout << "Test FAILED: " << test_name << " " << input_string.substr(0,10) << "... expected: " << expected_output << " but got: " << output << endl;
        } else {
            cout << "Test FAILED: " << test_name << " " << input_string << " expected: " << expected_output << " but got: " << output << endl;
        }
    }
}


void runTests() {
    testBasicStateParsing();

    test("test1.txt", test1, "0", "reject 1", false); 
    
    test("data/sample_1.txt", sample1, "0", "reject 1 2", false); 
    test("data/sample_1.txt", sample1, "000", "accept 7", false); 
    test("data/sample_1.txt", sample1, "10", "reject 1 2", false);
    test("data/sample_1.txt", sample1, "101010101010101010101010101010101010", "reject 1 2", false); 
    

    test("data/sample_2.txt", sample2, "0", "reject 1", false); 
    test("data/sample_2.txt", sample2, "0101", "reject 3", false); 
    test("data/sample_2.txt", sample2, "010111", "accept 4 5", false); 
    test("data/sample_2.txt", sample2, "0101110000", "accept 4 5 6", false); 

    test("data/test3.txt", test3, "ab", "accept 3 4", false); 
    test("data/test3.txt", test3, "aba", "accept 3 4", false); 
    test("data/test3.txt", test3, "abb", "accept 3 4", false); // ??
    test("data/trivial.txt", trivial, "", "reject 0", false); 
    test("data/trivial.txt", trivial, "a", "reject 0", false); 

    test("data/homework4.txt", homework4, "011", "reject 9", false); 
    test("data/homework4.txt", homework4, "101", "accept 8", false); 
    test("data/homework4.txt", homework4, "1111011111", "accept 8", false); 

    test("data/homework3-a.txt", homework3a, "10101", "accept 6", false); 
    test("data/homework3-a.txt", homework3a, "1010100", "accept 6", false); 
    test("data/homework3-a.txt", homework3a, "1010110", "accept 6", false); 
    test("data/homework3-a.txt", homework3a, "11010110", "accept 6", false); 
    test("data/homework3-a.txt", homework3a, "01010110", "accept 6", false); 
    test("data/homework3-a.txt", homework3a, "10100", "accept 1", false); 
    test("data/homework3-a.txt", homework3a, "111010", "reject 5", false);  


    // generate a string of 1000 ones 
    string longInput;
    for (int i = 1; i < 1000; ++i){
        longInput += "1";
    }
    test("data/long.txt", superlong, longInput, "accept 1000", false);
    

    // Generata a string of 999 ones
    longInput = "";
    for (int i = 1; i < 999; ++i){
      longInput += "1";
    }
    test("data/long.txt",superlong, longInput, "reject 999", false);
}



