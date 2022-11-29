from names import *
import func
import re


class Memory:
    def __init__(self):
        self.memory = ["00"] * MEMSIZE

    def read(self, pos, len):
        if pos < 0 or pos + len >= MEMSIZE:
