from names import *


# 把names中0-f的数值转为十六进制字符，注意是字符，因为instrName中采用字典来储存操作指令
def id2strHex(d):
    return "0123456789abcdef"[int(d)]


# 把字符串s按l位分割，返回值是分割后的数组块
def split(s, l):
    return [s[i: i + l] for i in range(0, len(s), l)]


# X86（Y86）结构是小端模式，所以需要转换储存模式
def swichEndian(s):
    if s.startswith("0x") or s.startswith("0X"):
        s = s[2:]  # 去掉开头的符号
    if len(s) > 8:
        s = s[-8:]  # 取后八位
    s = "0" * (8 - len(s)) + s  # 不足八位则补全开头的0
    return ''.join(reversed(split(s, 2)))  # s分割成两位两位，并且倒序


# 十六进制（可能是整数或者字符）换成十进制整数
def hex2int(i):
    return int(i, 16)


# 十六进制小端存储字符串形式转为十进制整数
def strHex2int(i):
    return int(swichEndian(i), 16)


# 十进制整数转化为十六进制形式的字符串
def int2strHex(i):
    if i >= 0:
        s = hex(i)
        s = s[2:]
        if len(s) > 8:
            s = s[-8:]
        s = "0" * (8 - len(s)) + s
    else:
        i = ~i + 1
        s = hex(i)
    return s


# 返回该操作执行的内容，返回值为字符串，便于图形化显示每一步的操作
def show_step(code, func, rA, rB, valC):
    i = id2strHex(code) + id2strHex(func)
    try:
        step = instrName[i]
        if code in [RRMOVL, OPR]:
            step += ' ' + regName[rA] + ',' + regName[rB]
        elif code == IRMOVL:
            step += ' ' + swichEndian(valC) + ',' + regName[rB]
        elif code == RMMOVL:
            step += ' %s, %s(%s)' % (regName[rA],
                                     str(strHex2int(valC)), regName[rB])
        elif code == MRMOVL:
            step += ' %s(%s), %s' % (str(strHex2int(valC)),
                                     regName[rB], regName[rA])
        elif code in [JXX, CALL]:
            step += ' ' + swichEndian(valC)
        elif code in [POPL, PUSHL]:
            step += ' ' + regName[rA]
    except:
        step = 'Wrong instruction!'
    return step


if __name__ == "__main__":
    print(show_step(RMMOVL, 0, RCX, RDX, '0x7812345678'))

# int2Hex
# digits = []
# tmp = val
# while tmp != 0:
#     digits.append(tmp % 2)
#     tmp = tmp/2
# if len(digits) < 32:
#     digits = digits + [0] * (32 - len(digits))            #digit为value的逆序二进制，好像在这里没什么用

# def aluAdd(a, b, c, cc):
#     pass
#
#
# def aluSub(a, b, c, cc):
#     pass
#
#
# def aluAnd(a, b, c, cc):
#     pass
#
#
# def aluXor(a, b, c, cc):
#     pass
