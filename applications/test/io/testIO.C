/*
 *Application
 *            IO
*/

//Useful combination of include files which defin Sin ,Sout,and Serr and the use of IO streams generally 
#include "IOstreams.H"

//
#include "IOmanip.H"

#include "scalar.H"
//list are sequence containers
#include "List.H"

using namespace Foam;

int main(void)
{
	string st("sfdsf sdfs23df sdf32f . sdfsdff23/2sf32 ");
	
	Info << word(string::validate<word>(st)) << "END" << endl;

	string st1("1234567");


	Info << label(st1.size()) << tab << string(word(st1)) << endl;

    Info << setw(20)  << setprecision(3) << 1.234234 << endl;

	Info << hex << 255 << 





}








