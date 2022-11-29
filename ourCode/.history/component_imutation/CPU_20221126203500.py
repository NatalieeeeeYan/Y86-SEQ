from CC import *
import Memory
import Register
# import sys
# sys.path.append("ourCode")
# import const
# import general_funcs


class CPU:
    def __init__(self):
        self.Reg = Register()
        self.Mem = Memory()
        self.CC = ConditionCode()
        self.STAT = SAOK
        self.PC = 0
        self.icode = 0
        self.ifun = FNONE
        self.instr_valid = False
        self.need_regids = False
        self.need_valC = False
        self.imem_error = False
        self.valP = VNONE           # next pc
        self.valA = VNONE
        self.valB = VNONE
        self.valE = VNONE
        self.valM = VNONE
        self.Cnd = False        # whether to jump   判断是否要跳转
        self.rA = RNONE
        self.rB = RNONE
        self.srcA = RNONE
        self.srcB = RNONE
        self.dstE = RNONE
        self.dstM = RNONE
        self.operation = []

    def addOperation(self, op):
        self.operation.append(op)

    def changeSTAT(self, status):
        self.STAT = status

    def getCPUlog(self):
        CPU_log = {
            'PC': self.PC,
            'memory': self.Mem,
            'register': self.Reg,
            'STAT': self.STAT,
            'CC': self.CC
        }
        return CPU_log


if __name__ == "__main__":
    myCPU = CPU()
    print(myCPU.getCPUlog())
