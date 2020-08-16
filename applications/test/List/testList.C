/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2020 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    testList

Description
    Simple tests and examples of use of List

Foam::List

\*---------------------------------------------------------------------------*/

//#include "fvCFD.H"


#include "argList.H"
#include "OSspecific.H"
#include "wordReList.H"

#include "scalar.H"
#include "vector.H"
#include "IOstreams.H"
#include "IStringStream.H"
#include  "ListOps.H"

#include <list>

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Main program:

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
//  #include "createTime.H"

    argList::noParallel();
    argList::addOption("reList","reList");
    argList::addOption("wordList","wordList");
    argList::addOption("stringList","stringList");
    argList::addOption("float","xxx");
    argList::addBoolOption("flag");

    List<vector> list1(IStringStream("1 ((0 1 2))")());
    Info << "list1:" << list1 << endl;

    List<vector> list2=
    {
        vector(0,1,2),
        vector(3,4,5),
        vector(6,7,8)
    };
    Info << "list2: " << list2 << endl;

    list1.append(list2);
    Info << "list1.append(list2): " << list1 << endl;

    List<vector> list3(list2.xfer());
    Info << "Transfer via the xfer() method" << endl;
    Info << "list2: " << list2 << nl
         << "list3: " << list3 << endl;

    List<vector> list4 
    {
        vector(0,1,2),
        vector(3,4,5),
        vector(6,7,8)
    };
    Info << "list4: " << list4 << endl;

    List<vector> list5=
    {
        vector{8,1,0},
        vector{5,3,1},
        vector{10,2,2}
    };
    Info << "list5: " << list5 << endl;

    list4.swap(list5);
    Info << "Swapped via the swap() method" << endl;
    Info << "list4: " << list4 << nl 
         << "list5: " << list5 << endl;

    List<vector> list6(list4.begin(),list4.end());
    Info << "list6: " << list6 << endl;

    //Subset
    //labelList: List<label>
    
    const labelList map{0 , 2};
    List<vector> subList3(list3,map);
    Info << "Elements " << map << "out of " << list3
         << " => " << subList3 << endl; 

    wordReList reList;
    wordList wLst;
    stringList sLst;

    scalar xxx(-1);

    if (args.optionFound("flag")) 
    { 
        Info << "-flag:" << args["flag"] << endl;
    }

    if (args.optionReadIfPresent<scalar>("float",xxx))
    {
        Info << "read float" << xxx << endl;
    }

    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //





    Info<< "\nEnd\n" << endl;
    return 0;
} 


// ************************************************************************* //
