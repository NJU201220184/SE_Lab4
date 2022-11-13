#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <cstdio>     //freopen
using namespace std;

class Input_generator{
private:
    string input_format;
    vector<string> input;
public:
    Input_generator(string filename);
    void generate_input(int random);
    void multiple_input();
    vector<string> get_input(){return input;};
};




