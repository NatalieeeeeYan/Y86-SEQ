from names import *
from func import *


def writeback(cur, reg, status_code):
    if cur.W.stat in [BUBBLE]:      # what is bubble??
        status_code = AOK       # 状态码为AOK才进行写回
    else:
        status_code = cur.W.stat
    reg.write(cur.W.dstE, cur.W.valE, cur.W.dstM, cur.W.valM)
    operation = []
    if cur.W.dstE != RNONE:
        operation.append('Writeback: Write {0} back to {1}'.format(
            swichEndian(cur.W.valE), regName[cur.W.dstE]))
    if cur.W.dstM != RNONE:
        operation.append('Writeback: Write {0} back to {1}'.format(
            swichEndian(cur.W.valM), regName[cur.W.dstM]))
    cur.W.__dict__.update(**{'operation': operation})
