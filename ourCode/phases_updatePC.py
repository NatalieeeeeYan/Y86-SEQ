from const import *
from general_funcs import *


def updatePC(cpu):
    if cpu.icode in [ICALL]:
        cpu.PC = cpu.valC
        cpu.addOperation("Update PC: Update PC with valC " + str(cpu.PC))
    elif cpu.icode in [IJXX] and cpu.Cnd:
        cpu.PC = cpu.valC
        cpu.addOperation("Update PC: Update PC with valC " + str(cpu.PC))
    elif cpu.icode in [IRET]:
        cpu.PC = cpu.valM
        cpu.addOperation("Update PC: Update PC with valM " + str(cpu.PC))
    else:
        cpu.PC = cpu.valP
        cpu.addOperation("Update PC: Update PC with valP " + str(cpu.PC))