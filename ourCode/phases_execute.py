from const import *
from general_funcs import *

# valE 保存计算结果
# set CC

# 把无符号数转换成二进制, 为小端序
def Unsigned2Binary(val):
    bin = []
    tmp = val
    while tmp != 0:
        bin.append(tmp % 2)
        tmp //= 2
    if len(bin) < 32:
        bin += [0] * (32 - len(bin))
    return bin[0:32]


# 把二进制转换成带符号数, 为小端序
def Bin2Signed(bin):
    val = 0
    bas = 1
    for i in range(0, len(bin) - 1):
        val = val + bas * int(bin[i])
        bas *= 2
    if bin[-1] == 1:
        val -= bas
    return val

# 按位的二进制加法
def aluAdd(cpu, a, b, c):
    a = Unsigned2Binary(strHex2int(a))
    b = Unsigned2Binary(strHex2int(b))
    cpu.valA = Bin2Signed(a)
    cpu.valB = Bin2Signed(b)
    s = [0] * 33
    for i in range(0, 32):
        s[i] += a[i] + b[i]
        if s[i] > 1:
            s[i + 1] += 1
            s[i] %= 2
    ans = Bin2Signed(s[0:32])
    if c:
        if (s[0:32] == [0] * 32):
            cpu.CC.ZF = True
        else:
            cpu.CC.ZF = False
        if(s[31] == 1):
            cpu.CC.SF = True
        else:
            cpu.CC.SF = False
        if(cpu.valA > 0 and cpu.valB > 0 and ans < 0) or (cpu.valA < 0 and cpu.valB < 0 and ans > 0):
            cpu.CC.OF = True
        else:
            cpu.CC.OF = False

    s = list(reversed(s[0:32]))
    r = []
    for i in range(0, 32, 4):
        t = 0
        for j in range(0, 4):
            t = t * 2 + s[i + j]
        r.append(id2strHex(t))
    val = ''.join(r)
    return swichEndian(val)


# 按位的二进制减法
def aluSub(cpu, a, b, c):
    a = Unsigned2Binary(strHex2int(a))
    b = Unsigned2Binary(strHex2int(b))
    cpu.valA = Bin2Signed(a)
    cpu.valB = Bin2Signed(b)
    b = list(map(lambda x: 0 if x == 1 else 1, b))
    b[0] += 1
    s = [0] * 33
    for i in range(0, 32):
        s[i] += a[i] + b[i]
        if s[i] > 1:
            s[i + 1] = 1
            s[i] %= 2

    ans = Bin2Signed(s[0:32])
    if c:
        if (s[0:32] == [0] * 32):
            cpu.CC.ZF = True
        else:
            cpu.CC.ZF = False
        if(s[31] == 1):
            cpu.CC.SF = True
        else:
            cpu.CC.SF = False
        if(cpu.valA > 0 and cpu.valB > 0 and ans < 0) or (cpu.valA < 0 and cpu.valB < 0 and ans > 0):
            cpu.CC.OF = True
        else:
            cpu.CC.OF = False

    s = list(reversed(s[0:32]))
    r = []
    for i in range(0, 32, 4):
        t = 0
        for j in range(0, 4):
            t = t * 2 + s[i + j]
        r.append(id2strHex(t))
    val = ''.join(r) # 在r的每个字符中间插入空格
    return swichEndian(val)


# 按位的二进制与运算
def aluAnd(cpu, a, b, c):
    a = Unsigned2Binary(strHex2int(a))
    b = Unsigned2Binary(strHex2int(b))
    s = [0] * 32
    for i in range(0, 32):
        s[i] = a[i] & b[i]
    if c:
        if (s[0:32] == [0] * 32):
            cpu.CC.ZF = True
        else:
            cpu.CC.ZF = False
        if(s[31] == 1):
            cpu.CC.SF = True
        else:
            cpu.CC.SF = False
        cpu.CC.OF = False
    s = list(reversed(s[0:32]))
    r = []
    for i in range(0, 32, 4):
        t = 0
        for j in range(0, 4):
            t = t * 2 + s[i + j]
        r.append(id2strHex(t))
    val = ''.join(r)
    return swichEndian(val)


# 按位的二进制异或运算
def aluXor(cpu, a, b, c):
    a = Unsigned2Binary(strHex2int(a))
    b = Unsigned2Binary(strHex2int(b))
    s = [0] * 32
    for i in range(0, 32):
        s[i] = a[i] ^ b[i]
    if c:
        if (s[0:32] == [0] * 32):
            cpu.CC.ZF = True
        else:
            cpu.CC.ZF = False
        if(s[31] == 1):
            cpu.CC.SF = True
        else:
            cpu.CC.SF = False
        cpu.CC.OF = False
    s = list(reversed(s[0:32]))
    r = []
    for i in range(0, 32, 4):
        t = 0
        for j in range(0, 4):
            t = t * 2 + s[i + j]
        r.append(id2strHex(t))
    val = ''.join(r)
    return swichEndian(val)


#################################################################################
# 六大阶段第三阶段: 执行
# 根据 icode 和 ifun 决定ALU执行的操作、设置 Condition Code、STAT等
#################################################################################
def execute(cpu):
    use_calc = cpu.icode in [IOPQ, IPOPQ, IPUSHQ, ICALL, IRMMOVQ, IMRMOVQ]

    aluA = ZERO
    if cpu.icode in [IRRMOVQ, IOPQ]:
        aluA = cpu.valA
    elif cpu.icode in [IIRMOVQ, IRMMOVQ, IMRMOVQ]:
        aluA = cpu.valC
    elif cpu.icode in [ICALL, IPUSHQ]:
        aluA = NEGEIGHT
    elif cpu.icode in [IRET, IPOPQ]:
        aluA = EIGHT
    cpu.addOperation('Execute: Set aluA to {0}. '.format(swichEndian(aluA)))

    if cpu.icode in [IRMMOVQ, IMRMOVQ, IOPQ, ICALL, IPUSHQ, IRET, IPOPQ]:
        aluB = cpu.valB
    else:
        aluB = ZERO
    cpu.addOperation('Execute: Set aluB to {0}. '.format(swichEndian(aluB)))

    # set which operation ALU should do
    if cpu.icode in [IOPQ]:
        aluFun = int(cpu.ifun)
    else:
        aluFun = AADD

    if cpu.icode in [IOPQ] and cpu.STAT not in [SADR, SINS, SHLT]:
        set_cc = True
    else:
        set_cc = False

    if set_cc:
        cpu.addOperation('Execute: Set condition code. ')
        
    if aluFun == AADD:
        cpu.valE = aluAdd(cpu, aluA, aluB, set_cc)
        cpu.addOperation('Execute: ALU computed summation equals to {0}. '.format(swichEndian(cpu.valE)))
    elif aluFun == ASUB:
        cpu.valE = aluSub(cpu, aluB, aluA, set_cc)
        cpu.addOperation('Execute: ALU computed difference equals to {0}. '.format(swichEndian(cpu.valE)))
    elif aluFun == AAND:
        cpu.valE = aluAnd(cpu, aluA, aluB, set_cc)
        cpu.addOperation('Execute: ALU computed bitwise and equals to {0}. '.format(swichEndian(cpu.valE)))
    else:
        cpu.valE = aluXor(cpu, aluA, aluB, set_cc)
        cpu.addOperation('Execute: ALU computed bitwise xor equals to {0}. '.format(swichEndian(cpu.valE)))

    cpu.Cnd = False
    if cpu.icode in [IJXX, IRRMOVQ]:
        if cpu.ifun in [CJMP]:
            cpu.Cnd = True
        elif cpu.ifun in [CJLE] and ((cpu.CC.SF ^ cpu.CC.OF) | cpu.CC.ZF):
            cpu.Cnd = True
        elif cpu.ifun in [CJL] and (cpu.CC.SF ^ cpu.CC.OF):
            cpu.Cnd = True
        elif cpu.ifun in [CJE] and cpu.CC.ZF:
            cpu.Cnd = True
        elif cpu.ifun in [CJNE] and not cpu.CC.ZF:
            cpu.Cnd = True
        elif cpu.ifun in [CJGE] and not (cpu.CC.SF ^ cpu.CC.OF):
            cpu.Cnd = True
        elif cpu.ifun in [CJG] and not ((cpu.CC.SF ^ cpu.CC.OF) | cpu.CC.ZF):
            cpu.Cnd = True
        cpu.addOperation('Exectute: Condition holds. ' if cpu.Cnd else 'Execute: Condition fails...')


# if __name__ == "__main__":
#     class cc:
#         pass
#     a = "ffffffff"
#     b = "ffffffff"
#     print(aluSub(a, b, True, cc))
#     print(cpu.CC.ZF, cpu.CC.SF, cpu.CC.OF)
#     print(a, b)
