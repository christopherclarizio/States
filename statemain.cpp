//Christopher Clarizio
//Driver for testing the functionality of the class State

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include "state.h"
using namespace std;

void dispStates( vector<State> &states );
void dispMenu();
void abrAlphaSort( vector<State> &states );
void nameAlphaSort( vector<State> &states );
void yearSort( vector<State> &states );
void popSort( vector<State> &states );
void repsSort( vector<State> &states );
void stateInfo( vector<State> &states );
void statesYear( vector<State> &states );
void repPopRatio( vector<State> &states );

int main(){

	ifstream ifs;   //create a filestream
	string filename;   //will store the name of the file that the user inputs

	vector<State> states;   //vector of the states
	State state;   //declare a state that will be used to add states to the vector
	string abr, name, cap, pop_s, year_s, reps_s;   //declare strings to store the values read in for eacf piece of info from the states
	int year, pop, reps;   //declare ints to store the integer version of the year the state was created the population and the numbe rof representatives from that state

	cout << "Please enter the name of the input file: ";   //prompts the user to enter the name of the file to read from
	cin >> filename;   //reads in the user's input and stores it into filename

	ifs.open( filename );   //opens the file the user input

	if( !ifs ){   //if the filestream has not be opened then it tells the user that they entered an invlaid filename and exits the program
		cout << "invalid file: " << filename << endl;
		return 1;
	}

	char c = ifs.peek();   //stores the next character in the filestrem into char c
	while( c != EOF ){   //while the next character is not the end of file character
		getline( ifs, abr, ',' );   //reads in the abbreviation of the state and stores it in abr
		getline( ifs, name, ',' );   //reads in the name of the state and stores it in name
		getline( ifs, cap, ',' );   //reads in the capital of the state and stores it in capital
		getline( ifs, pop_s, ',' );   //reads in the population of the state as a string and stores it in pop_s
		pop = stoi( pop_s );   //converts pop_s to an integer and stores that in pop
		getline( ifs, year_s, ',' );   //reads in the year the state was created as a string and stores it in year_s
		year = stoi( year_s );   //converts year_s to an integer and stores that in year
		getline( ifs, reps_s, '\n' );   //reads in the number of representatives from a state and stores it in  reps_s
		reps = stoi( reps_s );   //convers reps_s to an integer and stores it in reps
		state = State( abr, name, cap, pop, year, reps );   //creates a state using the information read in
		states.push_back(state);   //adds the new state to th eend of the vector
		c = ifs.peek();   //looks at the next character in the filestream
	}


	int choice = 1;   //variable to store the user's menu choice

	do{

		dispMenu();   //displays the menu
		cin >> choice;   //reads in and stores the user's input

		//switch sturucture tha calls the appropriate function corresponding to the menu option
		switch( choice ){
			case 1:
				nameAlphaSort( states );
				break;
			case 2:
				abrAlphaSort( states );
				break;
			case 3:
				yearSort( states );
				break;
			case 4:
				popSort( states );
				break;
			case 5:
				repsSort( states );
				break;
			case 6:
				stateInfo( states );
				break;
			case 7:
				statesYear( states );
				break;
			case 8:
				repPopRatio( states );
				break;
			case 9:
				choice = -1;
				break;
		}

	}while( choice != -1 );   //continues looping while the user has not chosen to quit

	return 0;

}
void dispStates( vector<State> &states ){   //iterates through the vector of states and prints them out in a numbered list

	for( int i = 1; i <= states.size(); i++ ){
		cout << setw(2) << i << ". ";
		states[i-1].disp();
	}

}
void dispMenu(){   //displays the menu that the user is prompted with

	cout << "------------------------------------------------------------------------\n";
	cout << "| 1. Sort states alphabetically by name and display                    |\n";
	cout << "| 2. Sort states alphabetically by abbreviation and display            |\n";
	cout << "| 3. Sort states by date established and display                       |\n";
	cout << "| 4. Sort states by poopulation and display                            |\n";
	cout << "| 5. Sort states by representatives and display                        |\n";
	cout << "| 6. Display the information of a given state                          |\n";
	cout << "| 7. Display all states established in a given year                    |\n";
	cout << "| 8. Display the ratio of representatives to population for all states |\n";
	cout << "| 9. Quit                                                              |\n";
	cout << "------------------------------------------------------------------------\n";

}

void abrAlphaSort( vector<State> &states ){   //sorts the vector alphabetically using the abbreviation

	for( int i = 0; i < states.size(); i++ ){
		for( int j = 0; j < states.size() - 1 - i; j++ ){
			if( states[j].getAbbreviation() > states[j+1].getAbbreviation() ){
				State temp = states[j+1];
				states[j+1] = states[j];
				states[j] = temp;
			}
		}
	}

	dispStates( states );

}
void nameAlphaSort( vector<State> &states ){   //sorts the vector alphabetically using the state name

	for( int i = 0; i < states.size(); i++ ){
		for( int j = 0; j < states.size() - 1 - i; j++ ){
			if( states[j].getName() > states[j+1].getName() ){
				State temp = states[j+1];
				states[j+1] = states[j];
				states[j] = temp;
			}
		}
	}

	dispStates( states );

}

void yearSort( vector<State> &states ){   //sorts the vector from oldest state to youngest

	for( int i = 0; i < states.size(); i++ ){
		for( int j = 0; j <states.size() - 1 - i; j++ ){
			if( states[j].getYearEst() > states[j+1].getYearEst() ){
				State temp = states[j+1];
				states[j+1] = states[j];
				states[j] = temp;
			}
		}
	}

	dispStates( states );

}

void popSort( vector<State> &states ){   //sorts the vector from most populous state to least

	for( int i = 0; i < states.size(); i++ ){
		for( int j = 0; j <states.size() - 1 - i; j++ ){
			if( states[j].getPopulation() < states[j+1].getPopulation() ){
				State temp = states[j+1];
				states[j+1] = states[j];
				states[j] = temp;
			}
		}
	}

	dispStates( states );

}

void repsSort( vector<State> &states ){   //sorst the vector from states with the most representatives to those with the least

	for( int i = 0; i < states.size(); i++ ){
		for( int j = 0; j <states.size() - 1 - i; j++ ){
			if( states[j].getNumReps() < states[j+1].getNumReps() ){
				State temp = states[j+1];
				states[j+1] = states[j];
				states[j] = temp;
			}
		}
	}

	dispStates( states );

}

void stateInfo( vector<State> &states ){   //prints out the information of a specific state that the user specifies

	string name;
	cout << "Please enter the name of the state whose information you would like: ";
	cin >> name;
	cout << "\n";

	int isFound = 0;
	string stateName;
	for( auto it = states.begin(); it != states.end(); it++ ){
		stateName = it->getName();
		if( stateName.compare( name ) == 0 ){
			isFound = 1;
			it->disp();
		}
	}

	if( isFound == 0 ){
		cout << "that state was not found\n";
	}

}

void statesYear( vector<State> &states ){   //displays the information of all the states that were created in the year that the user input

	int year;
	cout << "Please enter the year in which the states were established whose information you would like: ";
	cin >> year;
	cout << "\n";

	int isFound = 0;
	for( auto it = states.begin(); it != states.end(); it++ ){
		if( year == it->getYearEst() ){
			isFound = 1;
			it->disp();
		}
	}

	if( isFound == 0 ){
		cout << "no states were established in that year\n";
	}

}

void repPopRatio( vector<State> &states ){   //calculates and displays the number of representatives per person for each state

	nameAlphaSort( states );

	for( auto it = states.begin(); it != states.end(); it++ ){
		float pop = it->getPopulation();
		float rep = it->getNumReps();
		float ratio = rep/pop;
		cout << it->getName() << ": " << ratio  << " representatives per person \n";
	}

}
