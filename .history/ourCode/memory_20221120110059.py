from names import *
import func
import re


class Memory:
    def __init__(self):
        self.memory = ["00"] * MEMSIZE

    def read(self, pos, len):
        if pos < 0 or pos + len >= MEMSIZE:
            raise Exception(
                ("Trying to read memory from %d to %d" % (pos, pos+len)))
        return "".join(self.memory[pos:pos+len])
