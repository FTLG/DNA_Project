/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: DNA.cpp
 * Date Created: 4/18/2022
 * File Contents: This file contains the function definitions for the Final Project
 **********************************/

#include "../include/DNA.h"

char get_choice()
{
    COUT << ENDL << "What would you like to search for: " << ENDL 
    << "h: Huntington's Disease Gene" << ENDL
    << "o: Other motif" << ENDL;

    char choice;

    CIN >> choice;

    return choice;
}

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
 
int search(char *txt, char *pat)
{
    int cnt = 0;
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
            cnt++;
            printf("\n pattern occurs at shift = %d", s); // PATTERN? 
 
            s += (s + m < n) ? m - badchar[ (int) txt[s + m]] : 1;
 
        }
 
        else
            s += max(1, j - badchar[ (int) txt[s + j]]);
    }
    return cnt;
}