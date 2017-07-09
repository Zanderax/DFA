#ifndef DFA_H
#define DFA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSITIONS 5

typedef struct State State;
typedef struct Transistion Transistion;
typedef struct DFA DFA;

struct Transistion {
		char value;
		State * stateTo;
};

struct State {
		char value;
		int numberOfTransitions;
		Transistion * transistions;
};

struct DFA{
		int numberOfStates;
		State * states;
};

DFA * createDFA( int states );
State * createState( char value );
void printStates( DFA * dfa, int states );
void createTransition( State * to, State * from, char value );

#endif // DFA_H
