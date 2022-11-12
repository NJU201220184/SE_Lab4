#include "Code_Processor.h"

Code_Processor::Code_Processor(string file_A, string file_B, string input)
{
    file_A_name = file_A;
    file_B_name = file_B;

    ifstream if_A(file_A);
    ifstream if_B(file_B);

    ostringstream buf_A, buf_B;
    char ch_A, ch_B;

    while(buf_A && if_A.get(ch_A)) buf_A.put(ch_A);
    while(buf_B && if_B.get(ch_B)) buf_B.put(ch_B);

    if_A.close();
    if_B.close();

    string A = buf_A.str();
    string B = buf_B.str();

    file_A_code = A;
    file_B_code = B;

    //输入文件
    ofstream of_input;
    of_input.open("input.txt", ios::trunc);
    of_input<<input;
    of_input.close();

    //添加部分
    ifstream tmp("appendix.txt");
    char ch; ostringstream buf_tmp;
    while(buf_tmp && tmp.get(ch)) buf_tmp.put(ch);

    appendix = buf_tmp.str();
}

bool Code_Processor::is_same()
{
    return file_A_code == file_B_code;
}

void Code_Processor::code_process()
{
    //重定向输入输出
    int pos_A = file_A_code.find("{");
    int pos_B = file_B_code.find("{");
    file_A_code.insert(pos_A + 1, appendix);
    file_B_code.insert(pos_B + 1, appendix);
}

bool Code_Processor::execute_code(string code, string pro, string error_log, string output_file_name)
{
    ofstream of;
    of.open("temp.cpp", ios::trunc);
    of<<code;
    of.close();

    string command = "g++ temp.cpp -o ";
    command += pro;
    command += " 2> ";
    command += error_log;
    system(command.c_str());

    ifstream error; error.open(error_log, ios::in);
    char ch; error>>ch;

    if(!error.eof())
    {
        return false;
    }

    string new_command = "";
    new_command += "./";
    new_command += pro;
    new_command += ">";
    new_command += output_file_name;
    system(new_command.c_str());
    return true;
    
}

void Code_Processor::judge(string file_A, string file_B)
{
    

    ifstream if_A(file_A);
    ifstream if_B(file_B);

    ostringstream buf_A, buf_B;
    char ch_A, ch_B;

    while(buf_A && if_A.get(ch_A)) buf_A.put(ch_A);
    while(buf_B && if_B.get(ch_B)) buf_B.put(ch_B);

    if_A.close();
    if_B.close();

    string A_output = buf_A.str();
    string B_output = buf_B.str();

    judgement = A_output == B_output ? "equivalent" : "nonequivalent";
    return;
}

void Code_Processor::auto_judge()
{
    if(is_same()){
        return;
    }

    code_process();
    bool is_A = execute_code(file_A_code, "A.out", "A_error.log", "A_out.txt");
    bool is_B = execute_code(file_B_code, "B.out", "B_error.log", "B_out.txt");

    if(!is_A || !is_B)
    {
        ofstream f("output/abnormal.csv", ios::out|ios::app);
        f<<file_A_name<<','<<file_B_name<<endl;
        return;
    }

    else judge("A_out.txt", "B_out.txt");

    if(judgement == "nonequivalent")
    {
        ofstream f("output/inequal.csv", ios::out|ios::app);
        f<<file_A_name<<','<<file_B_name<<endl;
    }

    else if(judgement == "equivalent")
    {
        ofstream f("output/equal.csv", ios::out|ios::app);
        f<<file_A_name<<','<<file_B_name<<endl;
    }
}
