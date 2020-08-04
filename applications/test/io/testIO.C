/*
 *Application
 *            IO
*/

//Useful combination of include files which defin Sin ,Sout,and Serr and the use of IO streams generally 
#include "IOstreams.H"

//Istream and Ostream manipulators taking arguments
#include "IOmanip.H"

//Single floating point number identical to float or double depending on 
//whether WM_SP, WM_DP or WM_LP is defined.
#include "scalar.H"
//A 1D array of objects of type <T>, where the size of the vector
//is known and used for subscript bounds checking 
#include "List.H"

using namespace Foam;

int main(void)
{
	string st("sfdsf sdfs23df sdf32f . sdfsdff23/2sf32 ");
	
	//word : A class for handling words
	//string::validate():Return a valid String from the given string.
	Info << word(string::validate<word>(st)) << "END" << endl;

	string st1("1234567");


	Info << label(st1.size()) << tab << string(word(st1)) << endl;

    Info << setw(20)  << setprecision(3) << 1.234234 << endl;

	Info << hex << 255 << endl;

	Info.operator Foam::OSstream&() << "stop" << endl;





}








