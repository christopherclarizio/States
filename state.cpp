//Christopher Clarizio
//Implementation for the class State

#include <iostream>
#include "state.h"
using namespace std;

//defualt constructor sets the fields of the state to that of our 51st and northernmost state
State::State()
{ abr = "CA"; name = "Canada"; cap = "Ottowa"; pop = 35160000; year = 1867; reps = 0; }

//constructur takes arguments for all the field that and sets each field accordingly
State::State( string a, string n, string c, int p, int y, int r )
{ abr = a; name = n; cap = c; pop = p; year = y; reps = r; }

//destructor does nothing
State::~State(){ }

string State::getAbbreviation(){ return abr; }   //returns the abbreviation of the state
void State::setAbbreviation( string a ){ abr = a; }   //sets the abbreviation to the argument sent

string State::getName(){ return name; }   //returns the name of the state
void State::setName( string n ){ name = n; }   //sets the name to the argument sent

string State::getCapital(){ return cap; }   //returns the capital of the state
void State::setCapital( string c ){ cap = c; }   //sets the cpaital to the argument sent

int State::getPopulation(){ return pop; }   //returns the population of the state
void State::setPopulation( int p ){ pop = p; }   //sets the population to the argument sent

int State::getYearEst(){ return year; }   //returns the year the state was established
void State::setYearEst( int y ){ year = y; }   //sets the year the state was established ot the argument sent

int State::getNumReps(){ return reps; }   //returns the number of representatives for that state
void State::setNumReps( int r ){ reps = r; }   //sets the numbe of representataives for that state to the argument sent

void State::disp(){   //displays information aobut the state including its name, abbreviaiton, year it was established, population, cpaital and nnumber of reps
	cout << getName() << " abbreviated " << getAbbreviation();
	cout << " was established in " << getYearEst();
	cout << " has a capital in " << getCapital();
	cout << " a population of " << getPopulation() << " people and ";
	cout << getNumReps() << " representatives.\n";
}
