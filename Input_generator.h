#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>     //freopen
using namespace std;

class Input_generator{
private:
    string input_format;
    string input;
public:
    Input_generator(string filename);
    void generate_input();
    string get_input(){return input;};
};




