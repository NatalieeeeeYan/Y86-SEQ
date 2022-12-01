from const import *
from general_funcs import *


#################################################################################
# 寄存器模拟: 采用列表形式存储, 存储顺序在const.py中
# 三个接口: 读、写、返回所有寄存器信息
# 读: 两个参数 srcA、srcB 表示要读的寄存器的地址（编号）
# 写: 两个参数 dstW、valW 分别表示要写的寄存器地址（编号）和要写入的内容
# 返回所有寄存器信息: 按要求用小端、十进制进行输出，输出形式为列表
#################################################################################
class Register:
    def __init__(self):
        self.register = ["00" * 4] * 15

    def read(self, srcA, srcB):
        srcA = int(srcA)
        srcB = int(srcB)
        valA = VNONE
        valB = VNONE
        if srcA != 0xf:
            valA = self.register[srcA]
        if srcB != 0xf:
            valB = self.register[srcB]
        return valA, valB

    def write(self, dstW, valW):
        dstW = int(dstW)
        if dstW != 0xf:
            self.register[dstW] = valW

    def return_info(self):
        info = {}
        for i in range(0, 15):
            info[regName[i]] = hex2int(swichEndian(self.register[i]))
            # print(regName[i], ":", info[regName[i]])
        return info

if __name__ == "__main__":
    myRegister = Register()
    myRegister.write(0x0, "11111111")
    myRegister.write(0x1, "128")
    myRegister.write(0xf, "ffffffff")
    myRegister.write(0xa, '123123123')
    a, b = myRegister.read(0x0, 0x1)
    c, d = myRegister.read(0xa, 0xf)
    myRegister.return_info()
    e, f = myRegister.read(RRSP, RNONE)
    print(a)
    print(b)
    print(c)
    print(d)
    print(e)
    print(f)
    print(myRegister.return_info())
