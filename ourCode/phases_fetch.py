from const import *
from general_funcs import *

def fetch(cpu):
    cpu.operation = []
    imem_error = False
    try:    # 取icode和ifun
        icf = split(cpu.Mem.read(cpu.PC, 1), 1)
        cpu.icode = hex2int(icf[0])
        cpu.ifun = hex2int(icf[1])
        # cpu.icode = hex2int(cpu.icode)
        # cpu.ifun = hex2int(cpu.ifun)
    except:
        cpu.imem_error = True
        cpu.icode = INOP
        cpu.ifun = FNONE

    instr_valid = cpu.icode not in [INOP, IHALT, IRRMOVQ, IIRMOVQ, IRMMOVQ, IMRMOVQ, IOPQ, IJXX, ICALL, IRET, IPOPQ, IPUSHQ]
    cpu.need_regids = cpu.icode in [IRMMOVQ, IOPQ, IPUSHQ, IPOPQ, IRMMOVQ, IIRMOVQ, IMRMOVQ]
    cpu.need_valC = cpu.icode in [IRMMOVQ, IIRMOVQ, IMRMOVQ, IJXX, ICALL]
    # cpu.valP = hex2int(cpu.PC) + 1 + int(cpu.need_regids) + 8 * int(cpu.need_valC)
    valp = cpu.PC + 1 + int(cpu.need_regids) + 8 * int(cpu.need_valC)
    # print(valp)
    # valp = str(valp)
    cpu.valP = valp
    # print(cpu.valP)

    cpu.valC = ZERO
    if cpu.need_valC:
        try:
            cpu.valC = cpu.Mem.read(cpu.PC + 1 + int(cpu.need_regids), 8)
            # print(cpu.valC)
        except:
            cpu.addOperation("Fetch: read valC fail")
            print("Fetch: read valC fail")
            cpu.imem_error = True

    if cpu.need_regids:
        try:
            cpu.rA, cpu.rB = split(cpu.Mem.read(cpu.PC + 1, 1), 1)
            cpu.rA = hex2int(cpu.rA)
            cpu.rB = hex2int(cpu.rB)
        except:
            cpu.addOperation("Fetch: read rA, rB fail")
            print("Fetch: read rA, rB fail")
            cpu.imem_error = True

    if cpu.imem_error:
        cpu.changeSTAT(SADR)
        cpu.addOperation('Fetch: Error: memory address invalid')
    elif instr_valid:
        cpu.changeSTAT(SINS)
        cpu.addOperation('Fetch: Error: instruction invalid')
    elif cpu.icode == IHALT:
        cpu.changeSTAT(SHLT)
        cpu.addOperation('Halt')
    else:
        cpu.changeSTAT(SAOK)

    ins = VNONE
    if cpu.STAT in [SAOK, SHLT]:
        ins = "Fetch: " + str(cpu.PC) + ': ' + show_step(cpu.icode, cpu.ifun, cpu.rA, cpu.rB, cpu.valC)
        cpu.addOperation(ins)