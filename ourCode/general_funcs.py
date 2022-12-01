from const import *


# 把const中0-f的数值转为十六进制字符, 返回字符
def id2strHex(d):
    return "0123456789abcdef"[int(d)]


# 把字符串s按l位分割，返回值是分割后的数组块
def split(s, l):
    return [s[i: i + l] for i in range(0, len(s), l)]


# X86（Y86）结构是小端模式，需要转换储存模式
# 转换存储模式
def swichEndian(s):
    if s.startswith("0x") or s.startswith("0X"):
        s = s[2:]  # 去除开头的'0x'字段
    return ''.join(reversed(split(s, 2)))  # s按两位两位分隔, 进行倒序


# 十六进制字符串换成十进制整数
def hex2int(i):
    res = int(i, 16)    # 读取16进制字符串
    max_int_str = "7fffffffffffffff"
    MAXINT = int(max_int_str, 16)   # 计算32可表示的最大正数
    # print("MAXINT:")
    # print(MAXINT)
    if res > MAXINT:        # 针对溢出情况的处理: 用32位二进制数能表示的最大正数减去得出的结果并+1
        j = i[0:1]
        i_firbit = int(j, 16)
        i_firbit -= 8       # 十六进制最高位 -8
        i_f = id2strHex(i_firbit)
        j = i_f + i[1:]
        res = int(j, 16)
        ret_val = '-' + str(MAXINT - res + 1)   # 加上负号
        return int(ret_val)     # 返回int类型
    else:
        return res      # 没有发生溢出, 直接返回


# 十六进制小端存储字符串形式转为十进制整数: 转换存储形式并且按16进制进行读取、计算
def strHex2int(i):
    return int(swichEndian(i), 16)


# 十进制整数转化为十六进制形式的字符串
def int2strHex(i):
    if i >= 0:
        s = hex(i)
        s = s[2:]       # hex() 返回'0xXXXXXXXX'模式串, 将开头的'0x'字段去除
        # if len(s) > 8:
        #     s = s[-8:]
        # s = "0" * (8 - len(s)) + s
    else:
        i = ~i + 1
        s = hex(i)
    return s


# 返回该操作执行的内容，返回值为字符串，便于图形化显示每一步的操作
######################### 其实没用到，如果前段不需要用，提交之前删掉 ###########################
def show_step(code, func, rA, rB, valC):
    i = id2strHex(code) + id2strHex(func)
    try:
        step = instrName[i]
        if code in [IRRMOVQ, IOPQ]:
            step += ' ' + regName[rA] + ',' + regName[rB]
        elif code == IRRMOVQ:
            step += ' ' + swichEndian(valC) + ',' + regName[rB]
        elif code == IRMMOVQ:
            step += ' %s, %s(%s)' % (regName[rA],
                                     str(strHex2int(valC)), regName[rB])
        elif code == IMRMOVQ:
            step += ' %s(%s), %s' % (str(strHex2int(valC)),
                                     regName[rB], regName[rA])
        elif code in [IJXX, ICALL]:
            step += ' ' + swichEndian(valC)
        elif code in [IPOPQ, IPUSHQ]:
            step += ' ' + regName[rA]
    except:
        step = 'Wrong instruction!'
    return step


if __name__ == "__main__":
    print(show_step(IRMMOVQ, 0, RRCX, RRDX, '0x7812345678'))
