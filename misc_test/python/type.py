#!/usr/bin/python
#-*- coding=utf-8 -*-

'''
Python有5个标准数据类型：
    Numbers:数字
        int
        long: L表示 (小写l也可以，但不建议，因为容易与数字1混淆)
        float
        complex: a + bj,或者 complex(a, b)表示
    String:字符串
        有两种取值顺序[头下标:尾下标)：
            left -> right: [0:max_length-1]
            right -> left: [-max_length:-1] ==>新技能：注意学习掌握
    List:列表
        用[]标识;
        下标(相对于首地址的偏移)相关操作，参考String的下标操作;
        有序的对象集合;
    Tuple:元组
        用()表示;
        不能再次赋值，相当于"只读列表";
    Dictionary:字典
        用{}表示;
        通过Key来存取;
        元序的对象集合;

数据类型转换：
    int(x [,base])
    将x转换为一个整数

    long(x [,base] )
    将x转换为一个长整数

    float(x)
    将x转换到一个浮点数

    complex(real [,imag])
    创建一个复数

    str(x)
    将对象 x 转换为字符串

    repr(x)
    将对象 x 转换为表达式字符串

    eval(str)
    用来计算在字符串中的有效Python表达式,并返回一个对象

    tuple(s)
    将序列 s 转换为一个元组

    list(s)
    将序列 s 转换为一个列表

    set(s)
    转换为可变集合

    dict(d)
    创建一个字典。d 必须是一个序列 (key,value)元组。

    frozenset(s)
    转换为不可变集合

    chr(x)
    将一个整数转换为一个字符

    unichr(x)
    将一个整数转换为Unicode字符

    ord(x)
    将一个字符转换为它的整数值

    hex(x)
    将一个整数转换为一个十六进制字符串

    oct(x)
    将一个整数转换为一个八进制字符串
'''

# t1. 变量赋值
counter = 100       # 整型变量
miles = 1000.0      # 浮点型
name = "John"       # 字符串
print counter
print miles
print name
print

# t2. 多变量赋值 (变量和值数量必须匹配，这点跟lua的有区别)
a = b = c = 1
print a
print b
print c
print

a, b, c = 2, 3, "John"
print a
print b
print c
print

#a, b, c = 4, 5         # error
#a, b, c = 4, 5, 6, 7   # error
#a, b, c = 4, 5, 6      # right

# t3. 字符串
test_str = "abcdefg"

# 输出完整字符串
print test_str
print test_str[0:] #参考其它语言(如C#中的string.substring方法)
print test_str[:]
# l2r的结束，r2l的开头索引，如果"不小于最大长度"，就会输出全部内容
print test_str[0:8]
print test_str[-8:]
print

# 取子串
# l2r
print test_str[0] #a
print test_str[-1] #g
print test_str[0:3] #abc，注意：不包括尾下标所指的元素哦！！！
#r2l
print test_str[-3:-1] #ef，注意：不包括尾下标所指的元素哦！！！
print test_str[-3:] #efg
print

# 重复输出 (*)
print test_str * 3 #abcdefgabcdefgabcdefg
print

# 字符串连接 (+)
print test_str + "_test"
print


# t4. 列表 & 元组
list_a = ['stra_1', 'stra_2', 3.4, 5]
list_b = ['strb_1', 6L, 'strb_2']

print list_a #['stra_1', 'stra_2', 3.4, 5]
print list_a[0] #'stra_1'
print list_a[1:3] #'stra_2', 3.4，注意：不包括尾下标所指的元素哦！！！
print list_a + list_b #['stra_1', 'stra_2', 3.4, 5, 'strb_1', 6L, 'strb_2']

#元组不允许更新，列表是可以的
tuple = ('abc', 123, 4.56, 7L)
#tuple[2] = 8.99 #error
list_a[1] = 'another' #ok
print list_a
print


# t5. 字典
dict = {}
dict['one'] = "this is one"
dict[2] = "this is two"

dict2 = {'name':'john', 'code':1234, 'dept':'deve'}

print dict['one']
print dict[2]
print dict.keys()
print dict.values()
print dict2.keys()
print dict2.values()
print dict
