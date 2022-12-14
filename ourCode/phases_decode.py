from const import *
from general_funcs import *


#################################################################################
# 六大阶段的第二阶段：译码
# 根据 icode 设置srcA srcB dstE dstM
# 根据 srcA 和 srcB 分别读取 valA 和 valB
#################################################################################
def decode(cpu):
    # set srcA
    if cpu.icode in [IRMMOVQ, IRRMOVQ, IOPQ, IPUSHQ]:
        cpu.srcA = cpu.rA
    elif cpu.icode in [IPOPQ, IRET]:
        cpu.srcA = RRSP
    else:
        cpu.srcA = RNONE

    # set srcB
    if cpu.icode in [IOPQ, IRMMOVQ]:
        cpu.srcB = cpu.rB
    elif cpu.icode in [IPUSHQ, IPOPQ, ICALL, IRET]:
        cpu.srcB = RRSP
    else:
        cpu.srcA = RNONE

    # set dstE
    if cpu.icode in [IIRMOVQ, IOPQ]:
        cpu.dstE = cpu.rB
    elif cpu.icode in [IRMMOVQ] and cpu.Cnd:
        cpu.dstE = cpu.rB
    elif cpu.icode in [IPUSHQ, IPOPQ, ICALL, IRET]:
        cpu.dstE = RRSP
    else:
        cpu.dstE = RNONE

    # set dstM
    if cpu.icode in [IMRMOVQ, IPOPQ]:
        cpu.dstM = cpu.rA
    else:
        cpu.dstM = RNONE

    # read valA & valB
    cpu.valA, cpu.valB = cpu.Reg.read(cpu.srcA, cpu.srcB)

    # if cpu.icode in [ICALL, IJXX]:
    #     cpu.valP = cpu.valC
    #     cpu.valid_valA = True
    #     # 对于call和jmp, 不需要从寄存器读, 用valA代替valP ----- ????? why not valC
