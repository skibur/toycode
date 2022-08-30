#!/usr/bin/python

from math import sqrt
from math import pi
    
#def height_of_trapezoid(a, b, n):
#    return (b - a) / float(n)

#def area_of_trapezoid(b1, b2, height_of_trapezoid, lambda x: sqrt(25.0 - x * x)):
#    return (b1 + b2) * height_of_trapezoid / 2

#print 'Welcome to the Trapazoid Calculator'

#hp = height_of_trapezoid(-5, 5, 1)

#print hp

#mana = area_of_trapezoid(5, 8, hp)

#print mana

def defint(a,b,n,f):
    return (b - a) / float(n)

def area_of_trapezoid(b1, b2, height): 
    return (b1 + b2) * height / 2.0

interval = 256

while interval > 1:

    height = defint(-5.0, 5.0, interval, lambda x: sqrt(25.0 - x * x))
    #print height
    answer = area_of_trapezoid(5, 8, height)
    print answer

    interval = interval - 1

print 25 * pi / 2
