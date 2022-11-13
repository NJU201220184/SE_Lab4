#include "File_generator.h"
#include "Input_generator.h"
#include "Code_Processor.h"

void judge(string path)
{
    struct dirent *ptr;
    DIR *dir;
    dir = opendir(path.c_str());

    vector<string> folder_list;
    
    while((ptr = readdir(dir)) != NULL){
        //跳过'.'和'..'两个目录
        if(ptr->d_name[0] == '.')  continue;
        else{
            folder_list.push_back(path + '/' + ptr->d_name);
        }
    }

    ofstream f_1("output/abnormal.csv", ios::out);
    f_1<<"file_1"<<','<<"file_2"<<endl;
    f_1.close();

    ofstream f_2("output/inequal.csv", ios::out);
    f_2<<"file_1"<<','<<"file_2"<<endl;
    f_2.close();

    ofstream f_3("output/equal.csv", ios::out);
    f_3<<"file_1"<<','<<"file_2"<<endl;
    f_3.close();

    for(auto iter = folder_list.begin(); iter != folder_list.end(); ++iter)
    {
        //Generate files
        File_List fl(*iter);
        vector<string> file_list = fl.get_file_list();
        string input_format = fl.get_input_format();

        //Generate input
        Input_generator ig(input_format);
        ig.generate_input();
        string input = ig.get_input();

        //Code Process
        auto iter_1 = file_list.begin();
        for(iter_1; iter_1 + 1 != file_list.end(); iter_1++)
        {
            for(auto iter_2 = iter_1 + 1; iter_2 != file_list.end(); iter_2++)
            {
                Code_Processor cp(*(iter_1), *(iter_2), input);
                cp.auto_judge();
            }
        }
    }
}