#!/usr/bin/env python3

import string

set_upper = string.ascii_uppercase
set_lower = string.ascii_lowercase
key = "QWITJSYHXCNDFERMUKGOPVALBZ"
lower_key = key.lower()

with open("message.txt") as filp:
    contents = filp.read()


for character in contents:
    if character.isupper():
        position = key.index(character)
        print(set_upper[position], end="")
    elif character.islower():
        position = lower_key.index(character)
        print(set_lower[position], end="")
    else:
        print(character, end="")

        
