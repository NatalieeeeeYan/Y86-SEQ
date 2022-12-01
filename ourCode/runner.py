import io
import os
import yaml
import json
import pprint
from CPU import *
from phases_fetch import *
from phases_decode import *
from phases_memory import *
from phases_execute import *
from phases_writeback import *
from phases_updatePC import *

def run(cpu, i):
    log_list = []
    first_open = True
    while cpu.getSTAT() not in ['SHLT', 'SINS', 'SADR']:
        fetch(cpu)
        decode(cpu)
        memory(cpu)
        execute(cpu)
        writeback(cpu)
        updatePC(cpu)
        log = cpu.getCPUlog()
        # print(log)
        log_list.append(log)
    res = json.dumps(log_list, sort_keys=False, indent=4, separators=(',', ': '))       # 改为json格式
    generate_answer(log_list, i, first_open)        # 输出到文件
    # print(log_list)
    # return res


# 生成答案输出文件
def generate_answer(res, i, flag):
    current_path = os.path.abspath(".")     # 获取当前绝对路径
    # yaml_path = os.path.join(current_path, "test" + str(i) + "_ans.yaml")
    # print(current_path)
    father_file_loc = current_path.rfind('/')       # 答案文件夹在当前路径的的父文件夹下，是一个新的文件夹，故需要找到父文件夹字串
    # print(father_file_loc)
    path1 = current_path[0: father_file_loc]
    father_file_loc = path1.rfind('/')
    # print(father_file_loc)
    path2 = current_path[0:father_file_loc]
    # print(path2)
    # 生成答案文件所在文件名（绝对路径）
    father_file = path2 + "/ourCode/test_ans/test" + str(i) + "_ans.json"       # output .json
    # father_file = path2 + "/ourCode/test_ans/test" + str(i) + "_ans.yaml"     # output .yaml
    # print(father_file)
    # if flag:
    file = open(father_file, 'w')       # 打开只写文件，若无则新建
        # flag = False
    # else:
    #     file = open(father_file, 'a')
    # yaml.dump(res, file)      # output yaml
    file.close()

if __name__ == "__main__":
    current_path = os.path.abspath(".")
    test_path = current_path + "/test"
    os.chdir(test_path)     # 改变当前文件路径
    # 测试文件放在了列表当中，答案文件名与测试文件变量名相同
    test0 = io.StringIO(open("asum.yo", "r").read())
    test1 = io.StringIO(open("prog1.yo", "r").read())
    test2 = io.StringIO(open("prog2.yo", "r").read())
    test3 = io.StringIO(open("prog3.yo", "r").read())
    test4 = io.StringIO(open("prog4.yo", "r").read())
    test5 = io.StringIO(open("prog5.yo", "r").read())
    test6 = io.StringIO(open("prog6.yo", "r").read())
    test7 = io.StringIO(open("prog7.yo", "r").read())
    test8 = io.StringIO(open("prog8.yo", "r").read())
    test9 = io.StringIO(open("prog9.yo", "r").read())
    test10 = io.StringIO(open("prog10.yo", "r").read())
    test11 = io.StringIO(open("pushquestion.yo", "r").read())
    test12 = io.StringIO(open("pushtest.yo", "r").read())
    test13 = io.StringIO(open("ret-hazard.yo", "r").read())
    test14 = io.StringIO(open("cjr.yo", "r").read())
    test15 = io.StringIO(open("poptest.yo", "r").read())
    test16 = io.StringIO(open("asumr.yo", "r").read())
    # instruction = [test0, test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11, test12, test13, test14, test15, test16]
    tests = [test0, test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11, test12, test13, test14, test15, test16]
    # tests = [test13]
    i = 0
    # i = 13
    for test_case in tests:
        print("i:", i)
        myCPU = CPU()
        myCPU.init(test_case)
        run(myCPU, i)
        i += 1
