# NFA - Non-Deterministic Finite Machine

This project implements a Non-Deterministic Finite Automaton (NFA) simulator. It reads an automaton definition from a file and processes input strings to determine if they are accepted or rejected by the automaton.

## Files

- `eskenazi_p1.cpp`: Main program file.
- `automata.h` and `automata.cpp`: Implementation of the Automata class.
- `automata-tests.h` and `automata-tests.cpp`: Unit tests for the Automata class.
- `helper.h` and `helper.cpp`: Helper functions for file reading and vector operations.
- `sample_1.txt`: Sample automaton definition file.
- `sample_2.txt`: Sample automaton definition file.
- `makefile`: Makefile for building and running the project.

## Usage

### Building the Project

To build the project, run the following command in the project directory:

```sh
make
```

### Running the Program

To run the program, use the following command:

```sh
./eskenazi_p1 <input file> <input string>
```

For example:

```sh
./eskenazi_p1 sample_1.txt 010111
```

### Running Tests

To run the unit tests, use the following command:

```sh
make tests
```

## Automaton Definition File Format

The automaton definition file should contain state and transition definitions. Each state is defined with the `state` keyword followed by the state ID and optional `start` and `accept` keywords. Each transition is defined with the `transition` keyword followed by the source state ID, input character, and target state ID.

Example:

```
state 1 start
state 7 accept
transition 1 0 1
transition 1 1 1
transition 1 0 2
transition 2 0 2
transition 2 0 1
transition 2 1 1
transition 2 0 7
transition 7 0 7
transition 7 1 7
```

## Notes and Limitations

- E-transitions are NOT yet supported.
- Supports up to 1000 states.
- Supports multiple transitions per state.
- Supports multiple accept states.
- Supports a single start state.
- States are identified by an integer ID.
