#ifndef BRAINFUCK_HPP
#define BRAINFUCK_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>

//#define DEBUG

class brainfuck{
public:
        brainfuck(const char *filename){
                mPtr = mData;

                std::ifstream ifs(filename);
                if(!ifs){
                        std::cerr << "file open error!" << std::endl;
                        std::exit(EXIT_FAILURE);
                }

                char c;
                while(ifs.get(c)){
                        mProgram.push_back(c);
                }
                mItr = mProgram.begin();
        }

        int evaluate(){
                do{
#ifdef DEBUG
                        std::cout << std::endl << *mItr;
                        for(int i = 0; i < mPtr - mData; ++i)
                                std::cout << "    ";
                        std::cout << " ****" << std::endl << "  ";
                        for(int i = 0; i < 10; ++i )
                                std::cout << std::setw(4) << (int)mData[i];
                        std::cout << std::endl;
#endif
                        switch(*mItr){
                        case '>': incPtr(); break;
                        case '<': decPtr(); break;
                        case '+': incVal(); break;
                        case '-': decVal(); break;
                        case '.': outVal(); break;
                        case ',': getVal(); break;
                        case '[': openBR(); break;
                        case ']': closBR(); break;
                        defalut: break;
                        }
                }while(mItr++ != mProgram.end());
        }

        void incPtr(){
                mPtr++;
        }
        void decPtr(){
                mPtr--;
        }
        void incVal(){
                (*mPtr)++;
        }
        void decVal(){
                (*mPtr)--;
        }
        void outVal(){
                std::cout << *mPtr;
        }
        void getVal(){
                std::cin >> *mPtr;
        }
        void openBR(){
                if((*mPtr) == 0){
                        int flag = 0;
                        while(flag >= 0){
                                ++mItr;
                                if(*mItr == '[') flag++;
                                if(*mItr == ']') flag--;
                        }
                }
        }
        void closBR(){
                if(*mPtr){
                        int flag = 0;
                        while(flag >= 0){
                                --mItr;
                                if(*mItr == ']') flag++;
                                if(*mItr == '[') flag--;
                        }
                }
        }
private:
        std::vector<char> mProgram;
        std::vector<char>::iterator mItr;
        char mData[30000];
        char* mPtr;
};

#endif
