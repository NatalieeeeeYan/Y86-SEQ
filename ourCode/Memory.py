from general_funcs import *
from const import *
import re

#################################################################################
# 内存模拟
# 使用字符串模拟内存，考虑到指令形式，以两个bits为一个单位进行初始化
# 共有四个接口: 读、写、读取指令、按要求返回内存所有非零信息
# 读: 两个参数（读取位置、要读取的内存长度）
#     先判断读取位置是否合法（为负或超出memory最长空间），非法则抛出异常
#     将读到的字段连成字符串，输出
# 写: 两个参数同上
#     先判断读取位置是否合法（为负或超出memory最长空间），非法则抛出异常
#     将待写入的字段按2bits为单位分开，写入memory中
# 读取指令: 根据指令字段中的':'和'｜'两个符号分割指令的每一部分
#          ':'左侧为内存地址，右侧为指令; '|'左侧为指令，右侧为对指令的解释，不需要存储
# 返回内存信息: 按要求以8bits为单位、小端、十进制输出
#################################################################################
class Memory:
    def __init__(self):
        self.memory = ["00"] * MEMSIZE

    def read(self, position, length):
        if position < 0 or position >= MEMSIZE:
            raise Exception(("Invalid memory access: Trying to read data from %d to %d" % (position, position + length)))

        return "".join(self.memory[position: position + length])
        # res = self.memory[position: position + length]
        # swichEndian(res)
        # print(res)
        # return res

    def write(self, position, data):
        if position < 0 or position >= MEMSIZE:
            raise Exception(("Invalid memory access: Trying to write from %d to %d" % (position, position + len(data))))
        self.memory[position: position + len(data) // 2] = split(data, 2)

    def getInstr(self, instr_file):
        for line in instr_file:
            if line.find('|') != -1:
                line = line[:line.find('|')]
            if len(line) == 0 or line.isspace():
                continue
            position = None
            instruction = None
            try:
                position_str = re.search('0x[0-9a-fA-F]+', line).group()
                # print(position_str)
                instruction_pos = line.find(':')
                instruction_str = line[line.find(':')+1:]
                # print(instruction_str)
                instruction = instruction_str.strip(' ')
                # print(instruction)
                if len(position_str) != 0:
                    position = int(position_str, 16)
                    if len(instruction) != 0:
                        self.write(position, instruction)
            except Exception as expt:
                raise Exception("Get instruction to memory error in %s" % line) from expt

    def getMemory(self):
        memInfo = {}
        for i in range(0, MEMSIZE, 8):
            val = ''.join(self.memory[i: i+8])
            if val != '00' * 8:
                data1 = swichEndian(val)
                # print(data1)
                data = hex2int(data1)
                # print(data)

                # data1 = hex2int(val)
                # data = Bin2Signed(Unsigned2Binary(strHex2int(val)))
                # print(data)
                memInfo[i] = data
        return memInfo


if __name__ == "__main__":
    myMemory = Memory()
    print(myMemory.read(0, 8))
    myMemory.write(0, "aaaaaaaa")
    print(myMemory.read(0, 8))
    instr1 = '0x000: 30f20900000000000000'
    instr2 = '0x00a: 30f31500000000000000'
    instr3 = '0x014: 6123'
    instr4 = '0x016: 30f48000000000000000'
    instr5 = '0x020: 40436400000000000000'
    instr6 = '0x02a: a02f'
    instr7 = '0x02c: b00f'
    instr8 = '0x02e: 734000000000000000'
    instr9 = '0x037: 804100000000000000'
    instr10 = '0x040: 00'
    instr11 = '0x041: 90'
    instr = [instr1, instr2, instr3, instr4, instr5, instr6, instr7, instr8, instr9, instr10, instr11]
    for i in range(0, 10):
        print("Test of instruction %d" % i)
        myMemory.get_instr_test(instr[i])
    print(myMemory.read(0, MEMSIZE))
