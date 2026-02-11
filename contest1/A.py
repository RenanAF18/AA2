str = input()
di = {}

for a in str:
    di[a] = di.setdefault(a,0) + 1
wrongs = 0
printou = False

# if len(di) == 1:
#     for k,v in di.items():
#         print(k * v)
#         printou = True

for v in di.values():
    if v % 2 != 0 and len(str) % 2 == 0:
        print("NO SOLUTION")
        printou = True
        break
    elif len(str) % 2 != 0:
        if v % 2 != 0 and wrongs != 1:
            wrongs+=1
        elif wrongs == 1 and v % 2 !=0:
            print("NO SOLUTION")
            printou = True
            break
            
if(not printou):
    if len(str) % 2 == 0:
        aux1 = ""
        aux2 = ""
        
        for k, v in di.items():
            aux1 = aux1 + k * (v//2)
            aux2 = k * (v//2) + aux2
        
        print(aux1 + aux2)
    else:
        aux1 = ""
        aux2 = ""
        aux3 = ""
        
        for k, v in di.items():
            if v%2 == 0:
                aux1 = aux1 + k * (v//2)
                aux2 = k * (v//2) + aux2
            else:
                aux3 = k * v
        
        print(aux1 + aux3 + aux2)