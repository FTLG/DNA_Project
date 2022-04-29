/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: main.cpp
 * Date Created: 4/18/2022
 * File Contents: This file contains the main program for the Final Project
 **********************************/

#include "../include/DNA.h"

// Function to display correct usage of the program
void usage(int status) {
    fprintf(stderr, "Usage: Enter input and output file names as command line argument\nExample: exe/./main tests/hunt.txt output.txt\n");
    exit(status);
}

int main( const int argc, const char* argv [] )
{
	// verify that the user has entered the correct number of command line arguments

	IFSTREAM DNA_infile; 
	OFSTREAM DNA_outfile;

	FILE* fp = stdout;

	if (argc == 2 || argc == 3) {
		DNA_infile.open(argv[1]);
		if (argc == 3) {
			fp = fopen(argv[2], "w");
		}
	}

	// otherwise display usage and exit
	else {
		usage(1);
		return 1;
	}

    STRING dna = read_from_file(DNA_infile);
    const size_t size = dna.length();

    DNA_BS strand(dna, size);
    char* DNA_string = strand.to_string();

    char choice = get_choice(); // use function to get user's choice of program to run

    STRING pat;
	int thres;

	switch(choice) {
		// search for huntington's
		case 'h':
			huntingtonSearch(DNA_string, fp);
			break;
		// search for max times a sequence is repeated
		case 'r':
		  pat = get_pattern();
			thres = get_rep_thres();
			repeatSearch(DNA_string, (char *) pat.c_str(), thres, fp);
			break;
		// search for total amount of times a sequence is repeated
		case 't':
			pat = get_pattern();
			thres = get_tot_thres();
			totSearch(DNA_string, (char *) pat.c_str(), thres, fp);
			break;
		// verify correct input
		default:
			fprintf(fp, "Invalid choice\n");
			break;
	}

	fclose(fp);
	delete [] DNA_string;

	return 0;

}
