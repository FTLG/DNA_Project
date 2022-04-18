/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: main.cpp
 * Date Created: 4/18/2022
 * File Contents: This file contains the main program for the Final Project
 **********************************/

#include "../include/DNA.h"

int main( const int argc, const char* argv [] )
{

    if (argc > 1) {
        IFSTREAM DNA_infile ( argv[argc-1] );

        read_from_file(DNA_infile);

    }


}