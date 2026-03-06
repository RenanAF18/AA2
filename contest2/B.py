n = int(input())
for _ in range(n):
    s = input()
    
    
    
    resp = 0
    aux = 0
    um = False
    for i in range(len(s)):
        if s[i] != "1":
            aux += 1
            if aux > resp:
                resp = aux
        else: 
            aux = 0
    
    print(resp)
    resp = 0
    aux = 0