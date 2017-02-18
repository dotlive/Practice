#!/usr/bin/python
#-*- coding=utf-8 -*-

'''
1、语法：
    def functionname(parameters):
        "函数_文档字符串"
        function_suite
        return [expression]

2、参数参数
    2.1 都是按引用传递：在函数体里修改了参数，原始的参考也会受影响
    2.2 参数类型：

'''

# define
def printme(str):
    "打印传入的任意字符串到标准输出设备上"
    print str
    return

# call
printme('abc')
