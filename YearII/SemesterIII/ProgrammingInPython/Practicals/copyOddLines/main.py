'''
Write a function that reads a file file1 and copies only alternative lines to
another file file2. Alternative lines copied should be the odd numbered lines.
Use Exception.

Written by Sudipto Ghosh for the University of Delhi
'''

import os


def writeDataToFile(ifilename: str):
    string: str = input("Enter Data: ")
    while True:
        temp: str = input()
        if temp:
            string += os.linesep + temp
        else:
            break
    with open(ifilename, 'w') as fout:
        fout.write(string)
    return


def copyOddLines(ifilename: str, ofilename: str):
    i: int = 1
    with open(ifilename, 'r') as fin:
        with open(ofilename, 'w') as fout:
            for line in fin.readlines():
                if i % 2 != 0:
                    fout.write(line)
                i += 1


if __name__ == '__main__':
    exists: bool = input("Does the file exist (y/n)? ") == 'y'
    if exists:
        ifilename: str = input("Enter Input Filename: ")
    else:
        ifilename: str = input("Enter Filename to Write Data: ")
        writeDataToFile(ifilename)
    ofilename: str = input("Enter Output Filename: ")
    copyOddLines(ifilename, ofilename)
