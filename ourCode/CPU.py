from CC import *
import Memory
import Register
from const import *
from general_funcs import *
from Memory import *
from Register import *
from CC import *
import json

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
        self.valP = 0           # next pc
        self.valA = ZERO
        self.valB = ZERO
        self.valE = ZERO
        self.valM = ZERO
        self.valC = ZERO
        self.Cnd = False        # whether to jump   判断是否要跳转
        self.rA = RNONE
        self.rB = RNONE
        self.srcA = RNONE
        self.srcB = RNONE
        self.dstE = RNONE
        self.dstM = RNONE
        self.operation = []

    def init(self, instr_code):
        self.Mem = Memory()
        self.Mem.getInstr(instr_code)
        self.Reg = Register()

    def addOperation(self, op):
        self.operation.append(op)

    def changeSTAT(self, status):
        self.STAT = status

    def getSTAT(self):
        if self.STAT == SAOK:
            return 'SAOK'
        elif self.STAT == SADR:
            return 'SADR'
        elif self.STAT == SINS:
            return 'SINS'
        else:
            return 'SHLT'

    def getCPUlog(self):
        CPU_log = {
            'PC': self.PC,
            'Register': self.Reg.return_info(),
            'Memory': self.Mem.getMemory(),
            'CC': self.CC.getCC(),
            'STAT': self.getSTAT()
            # 'Operation': self.operation
        }
        return CPU_log

    def getAllOperation(self):
        return self.operation

if __name__ == "__main__":
    myCPU = CPU()
    instr1 = '0x000: 30f2090000000000'      # 0
    instr2 = '0x008: 30f3150000000000'      # 0+8 = 8
    instr3 = '0x010: 6123'                  # 0+8+8 = 16
    instr4 = '0x012: 30f4800000000000'      # 0+8+8+2 = 18
    instr5 = '0x01a: 4043640000000000'      # 0+8+8+2+8 = 26
    instr6 = '0x022: a02f'                  # 0+8+8+2+8+8 = 34
    instr7 = '0x024: b00f'                  # 0+8+8+2+8+8+2 = 36
    instr8 = '0x026: 7340000000000000'      # 0+8+8+2+8+8+2+2 = 38
    instr9 = '0x02e: 8041000000000000'      # 0+8+8+2+8+8+2+2+8 = 46
    instr10 = '0x036: 00'                   # 0+8+8+2+8+8+2+2+8+8 = 54
    instr11 = '0x037: 90'                   # 0+8+8+2+8+8+2+2+8+8+1 = 55
    instr = [instr1, instr2, instr3, instr4, instr5, instr6, instr7, instr8, instr9, instr10, instr11]
    for i in range(0, 10):
        # print("Test of instruction %d" % i)
        myCPU.Mem.get_instr_test(instr[i])
    cpu_log = myCPU.getCPUlog()
    cpu_log1 = json.dumps(cpu_log, sort_keys=True, indent=4, separators=(',', ': '))
    print(cpu_log1)
