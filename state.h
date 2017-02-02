//Christopher Clarizio CSE20311 10/28/2016
//Interface for the class State

#include <string>
using namespace std;

class State{
	public:
		State();   //defualt constructor
		State( string, string, string, int, int, int );   //constructor that takes arguments for each of the fields
		~State();   //destructor does nothing
		string getAbbreviation();   //getter for the abbreviaiton
		void setAbbreviation( string );   //setter for the abbreviaiton
		string getName();   //getter for the name
		void setName( string );   //setter for the name
		string getCapital();   //getter for the capital
		void setCapital( string );   //setter for the capital
		int getPopulation();   //getter for the population
		void setPopulation( int );   //setter for the population
		int getYearEst();   //getter for the year the state was created
		void setYearEst( int );   //settter for the year the state was created
		int getNumReps();   //getter for the number of representatives from that state
		void setNumReps( int );   //setter for the number of representatives from that state
		void disp();   //displays all the information about the state contained in this class
	private:
		string abr;   //stores the two letter abbreviation for the state
		string name;   //store the name of the state
		string cap;   //store the name of the capital of the sate
		int pop;   //store the population of teh state
		int year;   //stores the year that the state was created
		int reps;   //stores the number of representatives from that state
};
