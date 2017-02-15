#!/usr/bin/python
#-*- coding=utf-8 -*-

'''
运算符：
    1. 算术运算符：+、-、*、/、%、**(幂)、//(取整除)
    2. 关系运算符：==、!=、<>、>、<、>=、<=
    3. 赋值运算符：=、+=、-=、*=、/=、%=、**=、//=
    4. 位运算符：&、|、~、^(异或)、<<、>>
    5. 逻辑运算符：and、or、not
    6. 成员运算符：in、not int ==> 判断是否在指定序列中
    7. 身份运算符：is、is not ==> 判断两个标识符是否引用自一个对象
优先级：
    **	                        指数 (最高优先级)
    ~ + -	                    按位翻转, 一元加号和减号 (最后两个的方法名为 +@ 和 -@)
    * / % //                    乘，除，取模和取整除
    + -	                        加法减法
    >> <<                       右移，左移运算符
    &                           位 'AND'
    ^ |                         位运算符
    <= < > >=                   比较运算符
    <> == !=                    等于运算符
    = %= /= //= -= += *= **=    赋值运算符
    is is not                   身份运算符
    in not in                   成员运算符
    not or and                  逻辑运算符
'''

# t1
# **
print (2 * 3)
print (2 ** 3)
print
# //
print (3.0 / 2)
print (3.0 // 2)
print