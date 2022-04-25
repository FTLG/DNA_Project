/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: main.cpp
 * Date Created: 4/18/2022
 * File Contents: This file contains the main program for the Final Project
 **********************************/

#include "../include/DNA.h"

void usage(int status) {
    fprintf(stderr, "Usage:\n");
    fprintf(stderr, "    -f File to read bases from\n");
    exit(status);
}

int main( const int argc, const char* argv [] )
{

    // if (argc > 1) {
    //     IFSTREAM DNA_infile ( argv[argc-1] );

    //     read_from_file(DNA_infile);

    // }

    int argind = 1;
    char *filename = (char *) "tests/ex1.txt"; // Set Default File Path

     while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = (char *) argv[argind++];

        switch (arg[1]){ // set flags
            case 'h':
                usage(0);
                break;
            case 'f':
                filename = (char *) (argv[argind]); // save filename
                break;
            default:
                usage(1);
                break;
        }
     }

     IFSTREAM DNA_infile (filename); // save file data

     read_from_file(DNA_infile); 


}