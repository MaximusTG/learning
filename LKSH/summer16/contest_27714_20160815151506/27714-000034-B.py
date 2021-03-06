import sys


def merge_sort(s, left=0, right=None, result=None):
    if result is None:
        result = [0] * len(s)
    if right is None:
        right = len(s)
    if right - left > 1:
        middle = (right + left) // 2
        merge_sort(s, left, middle, result)
        merge_sort(s, middle, right, result)
        merge(s, left, middle, right, result)


def key(turp):
    return turp[0]


def merge(s, left, middle, right, result):
    i = left
    j = middle
    for k in range(left, right):
        if i < middle and (j == right or s[i] > s[j]):
            result[k] = s[i]
            i += 1
        else:
            result[k] = s[j]
            j += 1
    for k in range(left, right):
        s[k] = result[k]


sys.setrecursionlimit(100000)
file = open("writeabc.in", "r")
out = open("writeabc.out", "w")

num = [i for i in file.readline()]
del num[-1]

merge_sort(num)
print("".join(num), file=out)

file.close()
out.close()
