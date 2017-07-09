#include "dfa.h"

int main( void )
{
		DFA * dfa = createDFA( 10 );
		int currStates = 0;

		int choice = -1;
		while( choice )
		{
				printf( "\n" );
				printf( "DFA Menu\n" );
				printf( "0 - Exit\n" );
				printf( "1 - Create State\n" );
				printf( "2 - Create Transistion\n" );
				printf( "3 - View States\n" );
				printf( "4 - Print Transitions\n" );
				scanf( "%d", &choice );
				switch( choice )
				{
						case 1:
								if (currStates < dfa->numberOfStates)
								{
										char value = 0;
										printf( "Value?\n" );
										scanf( "%c", &value );
										dfa->states[currStates] = *createState( value );
										++currStates;
								}
								break;
						case 2:
								int fromState = 0;
								printf( "From State?\n" );
								scanf( "%d", &fromState );
								int toState = 0;
								printf( "To State?\n" );
								scanf( "%d", &toState );
								char value = 0;
								printf( "Value?\n" );
								scanf( "%c", &value );
								createTransition( dfa->states[fromState], 
																		dfa->states[toState], 
																		value);
								break;
						case 3:
								printStates( dfa, currStates );
								break;
						case 4:
								int state = 0;
								printf( "Which State?\n" );
								scanf( "%d", &state );
								printTransistion( dfa->statest[state], state )
								break;
				}
		}
}

DFA * createDFA( int states )
{
		DFA * dfa = calloc( 1, sizeof( DFA ) );
		dfa->states = calloc( states, sizeof( State * ) );
		dfa-> numberOfStates = states;
		return dfa; 
}

State * createState( char value )
{
		State * state = calloc( 1, sizeof( State ) );
		state->value = value;
		state->numberOfTransitions = 0;
		state->transistions = calloc( MAX_TRANSITIONS, sizeof(Transistion *) );
		return state;
}

void createTransition( State * to, State * from, char value )
{
		Transistion transistion = calloc( 1, sizeof( Transistion ) );
		transistion->value = value;
		transistion->stateTo = to;
		from->transistions[from->numberOfTransitions] = transistion;
}

void printStates( DFA * dfa, int states )
{
		int i;
		for( i = 0; i < states; ++i )
		{
				printf( "State - %d  Value = %c\n", i, dfa->states[i].value );
		}
}

void printTransistion( State state, int stateNum )
{
		int i;
		printf( "State - %d", stateNum );
		for( i = 0; i < state.numberOfTransitions; ++i )
		{
				printf( "Transition %d - value %c", i, state->transitions[i].value );
		}
}
