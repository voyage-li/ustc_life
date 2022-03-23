#include "common.h"
#include "memory.h"

namespace virtual_machine_nsp
{
    void memory_tp::ReadMemoryFromFile(std::string filename, int beginning_address)
    {
        //读取文件内容
        // Read from the file
        // TO BE DONE
        std::ifstream infile(filename.c_str(), std::ios::in);
        if (!infile)
        {
            std::cout << "文件打开错误" << std::endl;
        }
        std::string ans;
        int index = 0;
        while (infile >> ans)
        {
            memory[beginning_address + index] = TranslateInstruction(ans);
            index++;
        }
        infile.close();
    }

    int16_t memory_tp::GetContent(int address) const
    {
        //返回 address地址的内容
        // get the content
        // TO BE DONE
        return memory[address];
    }

    int16_t &memory_tp::operator[](int address)
    {
        //重载 感觉和上面的东西一样？？？
        // get the content
        // TO BE DONE
        return memory[address];
    }
}; // virtual machine namespace
