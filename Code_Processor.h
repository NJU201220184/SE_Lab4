#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Code_Processor{
private:
    string file_A_name;
    string file_B_name;

    string file_A_code;
    string file_B_code;

    vector<string> input_list;

    string appendix;
    string judgement;
public:
    Code_Processor(string file_A, string file_B, vector<string> input);
    bool is_same();
    void write_to_file(string str, string file_name);
    void code_process();
    bool execute_code(string code, string pro, string error_log, string output_file_name, string input); 
    void judge(string file_A, string file_B);
    void auto_judge();
};