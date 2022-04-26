/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: main.cpp
 * Date Created: 4/18/2022
 * File Contents: This file contains the main program for the Final Project
 **********************************/

#include "../include/DNA.h"

void usage(int status) {
    fprintf(stderr, "Usage: Enter file name as command line argument\n");
    exit(status);
}

int main( const int argc, const char* argv [] )
{
    const char *filename;

	if(argc == 2) {
		filename = argv[1];
	}
	else {
		usage(1);
		return 1;
	}


    IFSTREAM DNA_infile (filename); // save file data

    STRING dna = read_from_file(DNA_infile);
    const size_t size = dna.length();

    DNA_BS strand(dna, size);
    char* DNA_string = strand.to_string();

    char choice = get_choice();

	 //search(DNA_string, (char *) "TAC");

	switch(choice) {
		case 'h':
			huntingtonSearch(DNA_string);
			break;
		case 'o':
			search(DNA_string, (char *) "TAC");
			break;
		default:
			printf("Invalid choice\n");
			break;
	}

}
