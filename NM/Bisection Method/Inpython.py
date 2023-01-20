print('')
print('************************')
print('Code in Bisection Method')
print('************************')
print('')

e=float(2.718)

def func(x):
    funct = e**x-3*x
    return funct

def bisection(f1,x1,x2,sc):
    if(f1<0):
        a=x1
        b=x2
    else:
        a=x2
        b=x1
    i=1
    condition =True
    while condition:
        x0=(a+b)/2
        f0=func(x0)
        print('Iteration: ',i,'\tIterval: [{},{}]'.format(round(a,5),round(b,5)),'\tMid-term: ',round(x0,5),'\tValue in Function: ',round(f0,5))
        if(f0<0):
            a=x0
        else:
            b=x0
        if(abs(float((b-a)/b))<sc):
            root = (a+b)/2
            condition = False
        else:
            i=i+1
            condition = True
    print('The Solution is: ',root)


x1,x2= input('Enter Two Guesses: ').split()
sc= input('Enter Stopping Criteria: ')
x1=int(x1)
x2=int(x2)
sc=float(sc)
f1=func(x1)
f2=func(x2)
if (f1*f2>0):
    print('No Solution')
    exit()
else:
    bisection(f1,x1,x2,sc)