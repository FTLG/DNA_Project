/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: DNA.h
 * Date Created: 4/18/2022
 * File Contents: This file contains the function declarations for the Final Project
 **********************************/

#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <fstream>

#define VECTOR std::vector
#define CIN std::cin
#define COUT std::cout
#define ENDL std::endl
#define IFSTREAM std::ifstream

enum
{
    BASE_A = 0x0, /* binary: 00 */
    BASE_C = 0x1, /* binary: 01 */
    BASE_G = 0x2, /* binary: 10 */
    BASE_T = 0x3, /* binary: 11 */
};


void read_from_file(IFSTREAM& DNA_infile);
