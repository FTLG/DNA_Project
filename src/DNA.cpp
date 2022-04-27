/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: DNA.cpp
 * Date Created: 4/18/2022
 * File Contents: This file contains the function definitions for the Final Project
 **********************************/

#include "../include/DNA.h"

// A function that obtains an entered DNA sequence from the user
STRING get_pattern()
{
    STRING pat;
   
    COUT << "Enter Pattern: ";
    CIN >> pat;

    return pat;

}

// A function that obtains the threshold of how many times the sequence can repeat
int get_thres()
{
    int thres;
   
    COUT << "Enter maximum amount of times pattern can appear until it produces a disease: ";
    CIN >> thres;

    return thres;
}

// A function that obtains the user's decision about which program to run
char get_choice()
{
    COUT << "What would you like to search for: " << ENDL 
    << "h: Huntington's Disease Gene" << ENDL
    << "o: Other motif" << ENDL
	 << "Choice: ";

    char choice;

    CIN >> choice;

    return choice;
}

// A funcition that reads in from the file and returns the DNA sequence as a string
STRING read_from_file(IFSTREAM& DNA_infile)
{
    STRING in_string;

    while (DNA_infile >> in_string){
        continue;
    }

    return in_string;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;
 
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

// A function that searches for when and where a given pattern repeats
// and displays whether or not that count exceeds a given threshold
void search(char *txt, char *pat, int thres)
{

    int cnt = 0;
	 int maxCnt = 0;
    int m = (int) strlen(pat);
    int n = (int) strlen(txt);
 
    int badchar[NO_OF_CHARS];
 
    badCharHeuristic(pat, m, badchar);
 
    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (n - m))
    {
        int j = m - 1;
 
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
 
        if (j < 0)
        {
            cnt++; // increase count if pattern is found
            //printf("pattern occurs at index = %d\n", s);

				// update maxCnt if needed 
            if(cnt > maxCnt) {
					maxCnt = cnt;
				}
 
            s += (s + m < n) ? m - badchar[ (int) txt[s + m]] : 1;
 
        }
 
        else {
				cnt = 0;	// reset count if sequence is is broken
            s += max(1, j - badchar[ (int) txt[s + j]]);
		  }
    }

	// display amount of times pattern is found
	COUT << "\nThe pattern was found " << maxCnt << " consecutive times." << ENDL;

	// display whether or not a disease is found
	if(maxCnt > thres) {
		printf("This person has the entered disease.\n");
	}
	else {
		printf("This person does not have the entered disease.\n");
	}

}

// A function that searches for when and where the pattern CAG repeats
// and displays whether or not that count repeats enough to cause Huntington's disease
void huntingtonSearch(char *txt)
{
	 char *pat = (char *) "CAG"; // look for CAG pattern
	 int cnt = 0;
	 int maxCnt = 0;
	 int thres = 36;	// set threshold to 36
	 int m = (int) strlen(pat);
	 int n = (int) strlen(txt);
 
	 int badchar[NO_OF_CHARS];
 
	 badCharHeuristic(pat, m, badchar);
 
	 int s = 0; // s is shift of the pattern with respect to text
	 while (s <= (n - m))
	 {
		  int j = m - 1;
 
		  while (j >= 0 && pat[j] == txt[s + j])
				j--;
 
		  if (j < 0)
		  {
				cnt++; // increase count if pattern is found
				//printf("pattern occurs at index = %d\n", s); 
				
				// update maxCnt if needed
				if(cnt > maxCnt) {
					maxCnt = cnt;
				}
 
				s += (s + m < n) ? m - badchar[ (int) txt[s + m]] : 1;
 
		  }
 
		  else {
				cnt = 0;	// reset count if sequence is broken
				s += max(1, j - badchar[ (int) txt[s + j]]);
			}
	 }

	// display amount of times pattern is found
	COUT << "\nThe pattern was found " << maxCnt << " consecutive times." << ENDL;

	// display whether or not a disease is found
	if(maxCnt >= thres) {
		printf("This person has Huntington's disease.\n");
	}
	else {
		printf("This person does not have Huntington's disease.\n");
	}

}
