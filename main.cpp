#include "brainfuck.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv)
{
        if(argc < 2){
                std::cerr << "argument needed!" << std::endl;
                std::exit(EXIT_FAILURE);
        }
        if(argc > 2){
                std::cerr << "too many arguments!" << std::endl;
                std::exit(EXIT_FAILURE);
        }

        brainfuck bf(argv[1]);
        bf.evaluate();

        return 0;
}
