import math

def fn():
    i = 2 
    while 4*i**3 < 64*i*math.log(i, 2):
        i+=1
    print(i)

fn()
