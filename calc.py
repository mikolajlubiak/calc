#!/usr/bin/env python3

from sys import argv

def calc(s: tuple):
    so = list(s)
    if "(" in s and ")" in s:
        for i in range(len(s)):
            if s[i] == "(":
                for x in range(len(s)):
                    if s[x] == ")":
                        sb = []
                        for y in range(i, x+1):
                            sb.append(so[i])
                            so.pop(i)
                        sb.pop(0)
                        sb.pop()
                        so.insert(i, calc(sb))
                        return calc(tuple(so))
    elif "*" in s or "/" in s:
        for i in range(len(s)):
            if s[i] == "*":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) * float(s[i+1]))
                return calc(tuple(so))
            elif s[i] == "/":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) / float(s[i+1]))
                return calc(tuple(so))
    elif "+" in s or "-" in s:
        for i in range(len(s)):
            if s[i] == "+":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) + float(s[i+1]))
                return calc(tuple(so))
            elif s[i] == "-":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) - float(s[i+1]))
                return calc(tuple(so))
    else:
        return float(s[0])
try:
    print(calc(argv[1].split(" ")))
except:
    a = input("Give an expression: ")
    print(calc(a.split(" ")))
