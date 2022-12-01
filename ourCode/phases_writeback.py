from const import *
from general_funcs import *



#################################################################################
# 六大阶段第五阶段: 写回
# 根据 dstE 和 dstM 写回寄存器
#################################################################################
def writeback(cpu):
    if cpu.dstE != RNONE:
        cpu.Reg.write(cpu.dstE, cpu.valE)
        cpu.addOperation('Writeback: Write {0} back to {1}'.format(swichEndian(cpu.valE), regName[cpu.dstE]))
    if cpu.dstM != RNONE:
        cpu.Reg.write(cpu.dstM, cpu.valM)
        cpu.addOperation('Writeback: Write {0} back to {1}'.format(swichEndian(cpu.valM), regName[cpu.dstM]))
