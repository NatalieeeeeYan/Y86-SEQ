from const import *
from general_funcs import *
import sys
sys.path.append("ourCode")


class ConditionCode:
    def __init__(self):
        self.ZF = True
        self.SF = False
        self.OF = False
