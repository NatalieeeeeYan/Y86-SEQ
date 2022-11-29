IHALT = 0x0   # Code for halt instruction
INOP = 0x1    # Code for nop instruction
IRRMOVQ = 0x2  # Code for rrmovl instruction
IIRMOVQ = 0x3  # Code for irmovl instruction
IRMMOVQ = 0x4  # Code for rmmovl instruction
IMRMOVQ = 0x5  # Code for mrmovl instruction
IOPQ = 0x6    # Code for integer operation instructions
IJXX = 0x7    # Code for jump instructions
ICALL = 0x8   # Code for call instruction
IRET = 0x9    # Code for ret instruction
IPUSHQ = 0xA  # Code for pushl instruction
IPOPQ = 0xB   # Code for popl instruction

CJMP = 0x0
CJLE = 0x1
CJL = 0x2
CJE = 0x3
CJNE = 0x4
CJGE = 0x5
CJG = 0x6

FNONE = 0x0   # Default function code(默认功能码)

# Register IDs:
RRAX = 0x0
RRCX = 0x1
RRDX = 0x2
RRBX = 0x3
RRSP = 0x4
RRBP = 0x5
RRSI = 0x6
RRDI = 0x7
RR8 = 0x8
RR9 = 0x9
RR10 = 0xa
RR11 = 0xb
RR12 = 0xc
RR13 = 0xd
RR14 = 0xe
RNONE = 0xf

ALUADD = 0x0

SAOK = 0x1  # Status Code for normal operation(正常状态操作码)
SADR = 0x2  # Status Code for address exception(地址异常状态码)
SINS = 0x3  # Status Code for illegal instruction exception(非法指令异常状态码)
SHLT = 0x4  # Status Code for halt(halt状态码)

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
    'b': 'R11',
    'c': 'R12',
    'd': 'R13',
    'e': 'R14',
    'f': 'null',
    'F': 'null'
}

instrName = {
    "00": "halt",
    "10": "nop",
    "20": "rrmovq",
    "21": "cmovle",
    "22": "cmovl",
    "23": "cmove",
    "24": "cmovne",
    "25": "cmovge",
    "26": "cmovg",
    "30": "irmovq",
    "40": "rmmovq",
    "50": "mrmovq",
    "60": "addq",
    "61": "subq",
    "62": "andq",
    "63": "xorq",
    "70": "jmp",
    "71": "jle",
    "72": "jl",
    "73": "je",
    "74": "jne",
    "75": "jge",
    "76": "jg",
    "80": "call",
    "90": "ret",
    "a0": "pushq",
    "b0": "popq",
}

ZERO = "0000000000000000"
EIGHT = "0800000000000000"
NEGEIGHT = "F8FFFFFFFFFFFFFF"
AADD = 0x0
ASUB = 0x1
AAND = 0x2
AXOR = 0x4
VNONE = '--------'

MAXCLOCK = 1000
MEMSIZE = 1 << 12