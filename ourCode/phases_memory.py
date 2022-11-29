from const import *
from general_funcs import *


def memory(cpu):
    cpu.valM = VNONE

    if cpu.icode in [IPOPQ, IRET]:
        mem_addr = cpu.valA
    elif cpu.icode in [IRMMOVQ, IPUSHQ, ICALL, IMRMOVQ]:
        mem_addr = cpu.valE
    else:
        mem_addr = None

    if cpu.icode in [IMRMOVQ, IPOPQ, IRET]:
        read_flag = True
    else:
        read_flag = False
    if cpu.icode in [IRMMOVQ, IPUSHQ, ICALL]:
        write_flag = True
    else:
        write_flag = False

    if read_flag:
        try:
            cpu.valM = cpu.Mem.read(strHex2int(mem_addr), 4)
            cpu.addOperation('Memory reads {}. '.format(swichEndian(cpu.valM)))
        except:
            cpu.STAT = SADR
            cpu.addOperation('Memory error: read from {}. '.format(swichEndian(mem_addr)))

    if write_flag:
        try:
            cpu.Mem.write(strHex2int(mem_addr), cpu.valA)
            cpu.addOperation('Memory writes {}. '.format(swichEndian(cpu.valA)))
        except:
            cpu.STAT = SADR
            cpu.addOperation('Memory error: write to {}. '.format(swichEndian(mem_addr)))