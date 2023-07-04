#include<fstream>
#include<unordered_map>
#include<string>

struct StudentAccount
{
    public:
        void readLoaclFile(); //读取本地文件

    private:
        std::unordered_map<std::string, std::string> studentAccount;
};