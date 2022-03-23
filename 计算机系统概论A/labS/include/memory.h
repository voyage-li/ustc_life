#include "common.h"

namespace virtual_machine_nsp
{
    const int kInstructionLength = 16;

    inline int16_t TranslateInstruction(std::string &line)
    {
        // TODO: translate hex mode
        //把字符串转化为 int16_t
        int16_t result = 0;
        if (line.size() == kInstructionLength)
        {
            for (int index = 0; index < kInstructionLength; ++index)
            {
                result = (result << 1) | (line[index] & 1);
            }
        }
        return result;
    }

    const int kVirtualMachineMemorySize = 0xFFFF;

    class memory_tp
    {
    private:
        int16_t memory[kVirtualMachineMemorySize];
        //定义内存数组

    public:
        memory_tp()
        {
            memset(memory, 0, sizeof(int16_t) * kVirtualMachineMemorySize);
            //全部置0
        }
        // Managements
        void ReadMemoryFromFile(std::string filename, int beginning_address = 0x3000);
        int16_t GetContent(int address) const;
        int16_t &operator[](int address);
    };

}; // virtual machine nsp