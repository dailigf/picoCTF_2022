#!/bin/env/python3

set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"

with open("message.txt", "rb") as filp:
    line = filp.readline()
    flag = ""
    for c in line.split():
        c = int(c.decode("utf-8")) % 37
        flag += set[c]
    flag = "picoCTF{" + flag + "}"
    print(flag)
                

