from const import *
from general_funcs import *


class ConditionCode:
    def __init__(self):
        self.ZF = True
        self.SF = False
        self.OF = False

    def getCC(self):
        cc = {
            'ZF': self.ZF,
            'SF': self.SF,
            'OF': self.OF
        }
        return cc