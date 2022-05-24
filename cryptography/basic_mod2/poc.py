#!/bin/env/python3

set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"

with open("message.txt", "rb") as filp:
    line = filp.readline()
    flag = ""
    for c in line.split():
        c = int(c.decode("utf-8"))
        y = pow(c, -1, 41)
        print(f"{y=}")
        flag += set[y-1]
    flag = "picoCTF{" + flag + "}"
    print(flag)
                

