


#include <iostream>
#include <fstream>
#include "UserInput.h"
#include "FileInput.h"
#include "FileAnalysis.h"
#include "DoubleLinkedList.h"


/*
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DGB_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__ , __LINE__ )

#define new DBG_NEW
#endif
#endif
*/



using namespace std;
int main()
{
    
    bool runProgram = true;
    while (runProgram)
    {



        FileAnalysis file(getFileName("Enter File Name To Analyze: "));








        runProgram = getUserBool("Continue? [y/n]","y","n");

    }

    return EXIT_SUCCESS;
}