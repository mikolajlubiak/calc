#!/usr/bin/env python3.10

from sys import argv
from math import sqrt

def parens(s: tuple, i: int):
    openers = {"(": ")"}
    closers = {v: k for k, v in openers.items()}
    stack = []
    result = []
    for ii in range(i, len(s)):
        c = s[ii]
        if c in openers:
            stack.append([c, ii])
        elif c in closers:
            if not stack:
                raise ValueError(f"Tried to close brace without an open at position {i}.")
            pair, idx = stack.pop()
            if pair != closers[c]:
                raise ValueError(f"Mismatche brace at position {i}.")
            if idx == i:
                return ii
    if stack:
        raise ValueError(f"No closing brace at position {i}.")
    return result

def calc(s: tuple):
    so = list(s)
    for i in range(len(s)):
        match s[i]:
            case "(":
                d = parens(s, i)
                sb = []
                for x in range(i, d+1):
                    sb.append(so[i])
                    so.pop(i)
                sb.pop(0)
                sb.pop()
                so.insert(i, calc(sb))
                return calc(tuple(so))
    for i in range(len(s)-1):
        match s[i]:
            case "**":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) ** float(s[i+1]))
                return calc(tuple(so))
            case "//":
                so.pop(i)
                so.pop(i)
                so.insert(i, sqrt(float(s[i+1])))
                return calc(tuple(so))
    for i in range(1, len(s)-1):
        match s[i]:
            case "*":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) * float(s[i+1]))
                return calc(tuple(so))
            case "/":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) / float(s[i+1]))
                return calc(tuple(so))
    for i in range(1, len(s)-1):
        match s[i]:
            case "+":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) + float(s[i+1]))
                return calc(tuple(so))
            case "-":
                so.pop(i-1)
                so.pop(i-1)
                so.pop(i-1)
                so.insert(i-1, float(s[i-1]) - float(s[i+1]))
                return calc(tuple(so))
    return s[0]
if __name__ == "__main__":
    try:
        print(calc(argv[1].split(" ")))
    except IndexError:
        a = input("Give an expression: ")
        print(calc(a.split(" ")))
