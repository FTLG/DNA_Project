/**********************************
 * Name: Felixander Kery, George Perry, Max Mullen, Duncan Park
 * Email: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
 * File Name: DNA.h
 * Date Created: 4/18/2022
 * File Contents: This file contains the function declarations for the Final Project
 **********************************/

#ifndef __DNA_H__
#define __DNA_H__

#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <fstream>
#include <cstring> 
#include <stdexcept>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define VECTOR std::vector
#define CIN std::cin
#define COUT std::cout
#define ENDL std::endl
#define IFSTREAM std::ifstream
#define STRING std::string
#define BITSET std::bitset
#define MEMSET std::memset

#define BASE_MASK 0x3 /* binary: 11 */
# define NO_OF_CHARS 256

enum
{
    BASE_A = 0x0, /* binary: 00 */
    BASE_C = 0x1, /* binary: 01 */
    BASE_G = 0x2, /* binary: 10 */
    BASE_T = 0x3, /* binary: 11 */
};


STRING read_from_file(IFSTREAM& DNA_infile);
char get_choice();
int max(int a, int b);
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]);
int search(char *txt, char *pat);
void huntingtonSearch(char *txt);

class DNA_BS
{
public:

    // Default Constructor
    DNA_BS(): m_data(), m_len() {}

    /**
     * @brief Constructs a compressed representation of a DNA sequence.
     * @param dna_str A string holding a DNA sequence (e.g. "ATGCACG").
     * @param dna_len The length of the DNA sequence.
     */
    DNA_BS(STRING dna_str, const size_t dna_len)
    {
        m_len = dna_len;
 
        /* number of bytes necessary to store dna_str as a bitset */
        size_t dna_bytes = (dna_len / 4) + (dna_len % 4 != 0);
 
        m_data = new uint8_t[dna_bytes];
 
        MEMSET(m_data, 0, dna_bytes);
 
        /* for each base of the DNA sequence */
        for (size_t i = 0; i < dna_len; ++i)
        {
            uint8_t shift = (uint8_t) (6 - 2 * (i % 4));
 
            switch (toupper(dna_str[i]))
            {
                case 'A':
                    m_data[i / 4] |= (uint8_t) (BASE_A << shift);
                    break;
                case 'C':
                    m_data[i / 4] |= (uint8_t) (BASE_C << shift);
                    break;
                case 'G':
                    m_data[i / 4] |= (uint8_t) (BASE_G << shift);
                    break;
                case 'T':
                    m_data[i / 4] |= (uint8_t) (BASE_T << shift);
                    break;
                case '\0':
                    break;
                case '\n':
                    break;
                default:
                    COUT << dna_str[i] << ENDL;
                    throw std::invalid_argument("Invalid DNA base");
            }
 
            shift = (shift == 0) ? 6 : (uint8_t) (shift - 2);
        }
    }
 
    /**
     * @brief Destructor.
     */
    ~DNA_BS()
    {
        delete[] m_data;
        
    }
 
    /**
     * @brief Returns the stored DNA sequence as an ASCII string.
     */
    char* to_string() const
    {
        char* dna_str = new char[m_len + 1];

        /* for each base of the DNA sequence */
        for (size_t i = 0; i < m_len; ++i)
        {
            uint8_t shift = (uint8_t) (6 - 2 * (i % 4));
            uint8_t mask = (uint8_t) (BASE_MASK << shift);
 
            /* get the i-th DNA base */
            uint8_t base = (uint8_t) ((m_data[i / 4] & mask) >> shift);
 
            switch (base)
            {
                case BASE_A:
                    dna_str[i] = 'A';
                    break;
                case BASE_C:
                    dna_str[i] = 'C';
                    break;
                case BASE_G:
                    dna_str[i] = 'G';
                    break;
                case BASE_T:
                    dna_str[i] = 'T';
                    break;
                default:
                    throw std::runtime_error("Invalid DNA base");
            }
        }
 
        dna_str[m_len] = '\0';
        return dna_str;
    }
 
private:
    uint8_t* m_data;
    size_t m_len;
};

#endif
