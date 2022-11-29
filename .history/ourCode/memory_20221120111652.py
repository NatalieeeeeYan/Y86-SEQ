from names import *
from func import *
import re


class Memory:
    def __init__(self):
        self.memory = ["00"] * MEMSIZE

    def read(self, position, l):
        if position < 0 or position + l >= MEMSIZE:
            raise Exception(
                ("Trying to read memory from %d to %d" % (position, position + l)))
        return "".join(self.memory[position: position + l])

    def write(self, position, value):
        if position < 0 or (position + len(value)) >= MEMSIZE:
            raise Exception(
                ("Trying to write memory from %d to %d" % (position, position+len(value))))
        self.memory[position: position + len(value) // 2] = split(value, 2)

    def get_info(self, instruction):
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
            value = "".join(self.memory[i: i + 4])
            if value != "00" * 4:
                ret_val[i] = value
        return ret_val
