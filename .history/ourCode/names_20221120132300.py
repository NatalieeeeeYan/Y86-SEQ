regName = {
    0: 'RAX',
    1: 'RCX',
    2: 'RDX',
    3: 'RBX',
    4: 'RSP',
    5: 'RBP',
    6: 'RSI',
    7: 'RDI',
    8: 'R8',
    9: 'R9',
    0xa: 'R10',
    0xb: 'R11',
    0xc: 'R12',
    0xd: 'R13',
    0xe: 'R14',
    0xf: 'null',
    '0': 'RAX',
    '1': 'RCX',
    '2': 'RDX',
    '3': 'RBX',
    '4': 'RSP',
    '5': 'RBP',
    '6': 'RSI',
    '7': 'RDI',
    '8': 'R8',
    '9': 'R9',
    'a': 'R10',
    'A': 'R10',
    'b': 'R11',
    'B': 'R11',
    'c': 'R12',
    'C': 'R12',
    'd': 'R13',
    'D': 'R13',
    'e': 'R14',
    'E': 'R14',
    'f': 'null',
    'F': 'null'
}

instrName = {
    "00": "halt",
    "10": "nop",
    "20": "rrmovl",
    "21": "cmovle",
    "22": "cmovl",
    "23": "cmove",
    "24": "cmovne",
    "25": "cmovge",
    "26": "cmovg",
    "30": "irmovl",
    "40": "rmmovl",
    "50": "mrmovl",
    "60": "addl",
    "61": "subl",
    "62": "andl",
    "63": "xorl",
    "70": "jmp",
    "71": "jle",
    "72": "jl",
    "73": "je",
    "74": "jne",
    "75": "jge",
    "76": "jg",
    "80": "call",
    "90": "ret",
    "a0": "pushl",
    "b0": "popl"
}

# Register ID
RAX = 0x0
RCX = 0x1
RDX = 0x2
RBX = 0x3
RSP = 0x4
RBP = 0x5
RSI = 0x6
RDI = 0x7
R8 = 0x8
R9 = 0x9
R10 = 0xA
R11 = 0xB
R12 = 0xC
R13 = 0xD
R14 = 0xE
RNONE = 0xF

# Instruction ID
HALT = 0x0
NOP = 0x1
RRMOVL = 0x2
IRMOVL = 0x3
RMMOVL = 0x4
MRMOVL = 0x5
OPR = 0x6
JXX = 0x7
CALL = 0x8
RET = 0x9
PUSHL = 0xA
POPL = 0xB
NONE = 0x0

# Status
# ALUADD = 0x0  # Function for addition operation

# 以下四个书上有
AOK = 0x1  # Status code for normal operation
HLT = 0x2  # Status code for halt
ADR = 0x3  # Status code for address exception
INS = 0x4  # Status code for illegal instruction exception

BUBBLE = 0x5  # Status for bubble   # ?
STALL = 0x6  # Signal for stall

# Jump
JMP = 0x0
JLE = 0x1
JL = 0x2
JE = 0x3
JNE = 0x4
JGE = 0x5
JG = 0x6

# ALU
ALUADD = 0x0
ALUSUB = 0x1
ALUAND = 0x2
ALUXOR = 0x4

# Special Num
ZERO = "00000000"
FOUR = "04000000"
NEGFOUR = "fcffffff"
VNONE = '--------'

# Size
MAXCLOCK = 1000
MEMSIZE = 1 << 12
