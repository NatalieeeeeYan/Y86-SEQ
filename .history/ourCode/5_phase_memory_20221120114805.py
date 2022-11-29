from names import *
from func import *


def memory(cur, memory):
    operation = []

    if cur.M.icode in [RMMOVL, PUSHL, CALL, MRMOVL]:    # 这些指令
        memory_address = cur.M.valE
    elif cur.M.icode in [POPL, RET]:    # 这些指令
        memory_address = cur.M.valA
    else:
        memory_address = None

    if cur.M.icode in [MRMOVL, POPL, RET]:  # 这些指令需要读取内存
        read_flag = True
    if cur.M.icode in [RMMOVL, PUSHL, CALL]:    # 这些指令需要写入内存
        write_flag = True
    error_flag = False
    if read_flag:
        try:
            valM = memory.read(strHex2int(memory_address), 4)
            operation.append('Read memory {0}'.format(swichEndian(valM)))
        except:
            error_flag = True
            operation.append('Error: read memory from {0}'.format(
                swichEndian(memory_address)))
    if write_flag:
        try:
            memory.write(strHex2int(memory_address), cur.M.valA)
            operation.append('Write memory {0}'.format(
                swichEndian(cur.M.valA)))
        except:
            error_flag = True
            operation.append('Error: write to memory {0}'.format(
                strHex2int(memory_address)))

    cur.M.__dict__.update(**{'operation': operation})
