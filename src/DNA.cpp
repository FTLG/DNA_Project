/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: DNA.cpp
 * Date Created: 4/18/2022
 * File Contents: This file contains the function definitions for the Final Project
 **********************************/

#include "../include/DNA.h"
#include "../src/BM_Algo.cpp"


void read_from_file(IFSTREAM& DNA_infile)
{
    STRING in_string;

    while (DNA_infile >> in_string){
        continue;
    }

    const size_t bitsetSize = 2 * in_string.length();
    DNA_BS sequence(in_string, bitsetSize/2);

    char* out_string = sequence.to_string();

    COUT << out_string << ENDL;

    search(out_string, (char *) "TAC"); // TAC = pattern to search for

    COUT << ENDL;

}

