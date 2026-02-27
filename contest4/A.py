s = input()

unicas = set()

for a in s:
    unicas.add(a)

print(len(s) - len(unicas))
