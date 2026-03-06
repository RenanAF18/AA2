while True:
    n = int(input())
    if n == 0: break
    a = [int(x) for x in input().split()]
    aux = []
    printou = False
    min = 1
    
    for i in range(n):
        if(a[i] != min):
            if aux:
                while aux and min >= aux[-1]:
                    aux.pop()
                if aux and aux[-1] < a[i]:
                    print("no")
                    printou = True
                    break
                else:
                    aux.append(a[i])
            elif not aux:
                aux.append(a[i])
        elif a[i] == min:
            min+=1
    
    if not printou:
        print("yes")