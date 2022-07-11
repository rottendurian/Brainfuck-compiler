#include <iostream>
#include <fstream>
#include <string>
std::string filepath;
void compile();
std::string readbf(std::string filepath);
void writebf(std::string bf);
void writeline(std::ofstream& createC, char c);