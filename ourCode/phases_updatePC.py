from const import *
from general_funcs import *


#################################################################################
# 六大阶段第六阶段: 更新PC
# 根据 icode 用不同的值更新 PC
#################################################################################
def updatePC(cpu):
    if cpu.icode in [ICALL]:
        cpu.PC = swichEndian(cpu.valC)
        cpu.addOperation("Update PC: Update PC with valC " + str(cpu.PC))
    elif cpu.icode in [IJXX] and cpu.Cnd:
        cpu.PC = cpu.valC
        cpu.addOperation("Update PC: Update PC with valC " + str(cpu.PC))
    elif cpu.icode in [IRET]:
        cpu.PC = hex2int(swichEndian(cpu.valM))
        cpu.addOperation("Update PC: Update PC with valM " + str(cpu.PC))
    elif cpu.STAT in [SHLT]:
        cpu.PC = cpu.PC
        cpu.addOperation("Update PC: HALT, no need to update PC. ")
    else:
        cpu.PC = cpu.valP
        cpu.addOperation("Update PC: Update PC with valP " + str(cpu.PC))
