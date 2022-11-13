#include "Input_generator.h"

Input_generator::Input_generator(string filename)
{
    input_format = filename;
}

string random_integer_input(string str)
{
    int pos = str.find("int") + 4;

    //获取上界 & 下界
    string lb = "";
    string hb = "";

    for(pos; str[pos] != ','; ++pos)
    {
        lb += str[pos];
    }

    pos++;

    for(pos; str[pos] != ')'; ++pos)
    {
        hb += str[pos];
    }

    int lower_bound = atoi(lb.c_str());
    int higher_bound = atoi(hb.c_str());

    //cout<<"lower_bound: "<<lower_bound<<endl;
    //cout<<"higher_bound: "<<higher_bound<<endl;

    int random = (rand() % (higher_bound - lower_bound + 1)) + lower_bound;
    string random_input = to_string(random);

    //cout<<"random_input: "<<random_input<<endl;
    return random_input;
}

char random_char_input(int rand)
{
    char random_input;

    int temp = rand % 51;

    if(temp < 26){
        random_input = temp + 'a';
    }

    else{
        random_input = temp - 26 + 'A';
    }

    return random_input;
}

string random_string_input(string str, int rand)
{
    int pos = str.find("string") + 7;

    //获取上界 & 下界
    string lb = "";
    string hb = "";

    for(pos; str[pos] != ','; ++pos)
    {
        lb += str[pos];
    }

    pos++;

    for(pos; str[pos] != ')'; ++pos)
    {
        hb += str[pos];
    }

    int lower_bound = atoi(lb.c_str());
    int higher_bound = atoi(hb.c_str());

    //cout<<"lower_bound: "<<lower_bound<<endl;
    //cout<<"higher_bound: "<<higher_bound<<endl;

    int random = (rand % (higher_bound - lower_bound + 1)) + lower_bound;
    //cout<<"length of string: "<<random<<endl;

    string random_input = "";
    for(int i = 0; i < random; ++i)
    {
        random_input += random_char_input(random);
    }

    return random_input;
}

void Input_generator::generate_input(int random)
{
    ifstream ifs(input_format);
    string str;
    string temp_input;

    while (ifs >> str)
    {
        //cout<<str<<endl;
        if(str.find("int") != -1)
        {
            //cout<<"Find integer!"<<endl;
            temp_input += random_integer_input(str);
            temp_input += ' ';
        }

        else if(str.find("char") != -1)
        {
            //cout<<"Find char!"<<endl;
            temp_input += random_char_input(random);
            temp_input += ' ';
        }

        else if(str.find("string") != -1)
        {
            //cout<<"Find string!"<<endl;
            temp_input += random_string_input(str, random);
            temp_input += ' ';
        }
    }

    input.push_back(temp_input);
    
    ifs.close(); 
}

void Input_generator::multiple_input()
{
    srand((unsigned)time(NULL));
    for(int i = 0; i < 5; ++i)
    {     
        int random = rand(); 
        generate_input(random);
    }
}