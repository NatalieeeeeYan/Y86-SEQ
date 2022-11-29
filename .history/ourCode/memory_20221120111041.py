from names import *
from func import *
import re


class Memory:
    def __init__(self):
        self.memory = ["00"] * MEMSIZE

    def read(self, pos, len):
        if pos < 0 or pos + len >= MEMSIZE:
            raise Exception(
                ("Trying to read memory from %d to %d" % (pos, pos+len)))
        return "".join(self.memory[pos:pos+len])

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
