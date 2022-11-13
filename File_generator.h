#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <dirent.h>
#include <cstring>

using namespace std;

class File_List{
private:
    vector<string>file_list;
    string folder_path;
    string input_format;
public:
    File_List(string path);
    vector<string> get_file_list(){return file_list;}
    string get_input_format(){return input_format;}
};



