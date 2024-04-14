
"""
make a recursive function in python which accepts path name as argument give input from user for it.
if it is a file print name of file followed by its content
if it is directory ,print name and recursively read its file
"""
import os
from pathlib import Path


def fun(pathi):
    if os.path.isfile(pathi):
        # print(os.path.basename)
        print(Path(pathi).name)
        f = open(pathi, "r")
        for i in f:
            print(i, end="")
        print("\n")
    else:
        doc = os.listdir(pathi)
        for i in doc:
            new = pathi+'/'+i
            fun(new)


ts = "C:\Users\saksh\AssignMent\Afold\Arecu.py"
# file
# fun(ts)
ts = "C:\Users\saksh\AssignMent\Afold\Arecu.py"  # directory

fun(ts)
