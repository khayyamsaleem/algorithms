'''
cs.py
Provides range, map, filter, reduce in Python 2.7 style,
for use with Python 3.

USAGE: first line of your programs should be:
from cs import *

@author Zachary Caldarola
@date Aug 31, 2015
'''
import functools

def __helprange(start, end, step=1):
    lst = []
    if step<0:
        while start>end:
            lst += [start]
            start += step
    elif step>0:
        while start<end:
            lst += [start]
            start += step
    else:
        raise Exception('step cannot equal zero')
    return lst

def range(*args):
    """range(stop) -> list of integers
       range(start,stop[,step]) -> list of integers
       Like list(range(...)) in Python 3."""
    if len(args) == 1: return __helprange(0, args[0])
    elif len(args) == 2: return __helprange(args[0], args[1])
    else: return __helprange(args[0],args[1],args[2])
    
def map(function, sequence):
    """map(function, sequence) -> list
       Like list(map(...)) in Python 3."""
    return ([function(x) for x in sequence]
              if function != None
              else [item for item in sequence if item]
            )

def filter(function, iterable):
    """map(function, iterable) -> list
       Like list(filter(...)) in Python 3."""
    return ([item for item in iterable if function(item)]
              if function != None
              else [item for item in iterable if item]
            )

def reduce(function, iterable, initializer=None):
    return ( functools.reduce(function,iterable,initializer)
             if initializer != None
             else functools.reduce(function,iterable)
            )
      
    
