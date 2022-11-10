#include "File_generator.h"

File_List::File_List(string path){
    folder_path = path;
    struct dirent *ptr;
    DIR *dir;
    dir = opendir(path.c_str());
    
    while((ptr = readdir(dir)) != NULL){
        //跳过'.'和'..'两个目录
        if(ptr->d_name[0] == '.')  continue;
        else if (strstr(ptr->d_name, "txt"))
        {
            input_format = path + '/' + ptr->d_name;
        }
        //cout << ptr->d_name << endl;
        else{
            file_list.push_back(path + '/' + ptr->d_name);
        }
    }

    closedir(dir);
}