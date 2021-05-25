// SPDX-License-Identifier: Apache-2.0

/**
 * @file nametomotif.cc
 * @author Joshua Gawley
 * @brief A program for converting names/strings into musical motifs, based on Durufle's method used for his Prelude et Fugue sur le nom d'Alain
 * @version 0.1.0
 * @date 2021-05-25
 *
 * @copyright Copyright 2021 Joshua Gawley
 *
 */

// Note: I have made a slight simplification to Durufle's initial system
// In this program: B is B natural and H maps to A rather than B natural

#include <ctype.h>
#include <sysexits.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

/**
 * @brief Gets the position of a letter in the (zero-indexed, English) alphabet
 * 
 * @param c the character we want to convert
 * @return The position of the letter in the (zero-indexed, English) alphabet
 */
constexpr int get_alphabet_position(char c)
{
    return (int(c) -  65);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: nametomotif [name]\n";
        return EX_USAGE;
    }

    std::cout << "Name: " << argv[1] << '\n';

    auto name = std::string(argv[1]);

    // change string to uppercase
    std::transform(std::begin(name), std::end(name), std::begin(name), toupper);

    for (auto iter = name.begin(); iter != name.end(); ++iter)
    {
        // Get the alphabet position and map it to note letters by reducing modulo 7.
        auto remainder = get_alphabet_position(*iter) % 7;
        switch (remainder) {
            case 0:
                *iter = 'A';
                break;
            case 1:
                *iter = 'B';
                break;
            case 2:
                *iter = 'C';
                break;
            case 3:
                *iter = 'D';
                break;
            case 4:
                *iter = 'E';
                break;
            case 5:
                *iter = 'F';
                break;
            case 6:
                *iter = 'G';
                break;
        }
    }

    std::cout << "Motif: " << name << '\n';

    return EX_OK;

}