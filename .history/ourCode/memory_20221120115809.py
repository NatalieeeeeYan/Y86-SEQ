from names import *
from func import *
import re

# 内存中的内容以字符串形式储存
# 最大容量定义在names.py中: MEMSIZE


class Memory:
    def __init__(self):     # 初始化memory中的数据
        self.memory = ["00"] * MEMSIZE

    def read(self, position, l):    # 读取内存
        if position < 0 or (position + l) >= MEMSIZE:   # 非法内存访问
            raise Exception(
                ("Trying to read memory from %d to %d" % (position, position + l)))
        # 将需要读取的内存地址中的内容拼接，返回
        return "".join(self.memory[position: position + l])

    def write(self, position, value):   # 写入内存，value是要写入的内容（字符串形式），position是要写入的位置
        if position < 0 or (position + len(value)) >= MEMSIZE:  # 非法访问/溢出
            raise Exception(
                ("Trying to write memory from %d to %d" % (position, position+len(value))))
        self.memory[position: position + len(value) // 2] = split(value, 2)
        # 由于memory以"00"为一个单位，故要

    def get_instruntion(self, instruction):
        for line in instruction:
            if line.find('|') != -1:
                line = line[:line.find('|')]
            if len(line) == 0 or line.isspace():
                continue
            position = None
            value = None
            try:
                position_ = re.findall('(0x[0-9a-fA-F]+)', line)
                value_ = re.findall('0x[0-9a-fA-F]+:[ ]*([0-9a-fA-F]+)', line)
                if len(position_) != 0:
                    position = int(position_[0], 16)
                    if len(value_) != 0:
                        value = value_[0]
                        self.write(position, value)
            except Exception as expt:
                raise Exception("Instruction error: %s" % line) from expt

    def info(self):
        ret_val = {}
        for i in range(0, MEMSIZE, 4):
            value = ''.join(self.memory[i: i + 4])
            if value != '00' * 4:
                ret_val[i] = value
        return ret_val


if __name__ == "__main__":
    myMemory = Memory()
    print(myMemory.read(0, MEMSIZE - 2))
    myMemory.write(12, "abcdefghijklmnopqrstuvwxyz")
    print(myMemory.read(0, MEMSIZE - 2))
