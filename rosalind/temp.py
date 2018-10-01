

import numpy as np

string = input()
st_len = len(string)
# print(type(m))
m, n = st_len, st_len
ara = []

# for i in range(st_len):
#     ara.string[i]

for i in range(st_len):
    temp = ""
    if i >= 1:
        for j in range(st_len):
            if (j == 0):
                temp = temp + ara[i-1][st_len - 1]
            else:
                temp = temp + ara[i-1][j - 1]
        ara.append(temp)
    else:
        ara.append(string)

# for i in range(st_len):
#     print(ara[i])


print(sorted(ara))
