import math

def gcd (a,b):
        if b == 0:
                return a
        c = a
        while c: 
                c = a % b
                a = b
                b = c
                return a

def reduce(self):
    d = gcd(self.num, self.denom)
    return Rational(self.num / d, self.den / d)

class Rational:
        def __init__ (self, n = 0, d = 1):
                self.num = n
                self.den = d
                self.simplify ()

        def simplify (self):
                (n,d) = (self.num, self.den)
                if d < 0:
                        d = -d
                        n = -n
                if n == 0:
                        return (0,1)
                else:
                        g = gcd (n, d)
                        (n,d) =  (n/g, d/g)

                (self.num, self.den) = (n,d)

        def __add__ (a, b):
                (x,y) = (a.num, a.den)
                (p,q) = (b.num, b.den)
                return Rational (x*q + p*y, y*q)

        def __sub__ (a, b):
                return a + (- b)

        def __mul__ (a,b):
                (x,y) = (a.num, a.den)
                (p,q) = (b.num, b.den)
                return Rational (x*p, y*q)

        def __div__ (a,b):
                (x,y) = (a.num, a.den)
                (q,p) = (b.num, b.den)
                return Rational (x*p, y*q)

        def __str__ (a):
                return '%d/%d' % (a.num, a.den)

        def __pos__(a):
                (p,q) = (a.num, a.den)
                return Rational (p,q)

        def __neg__ (a):
                (p,q) = (a.num, a.den)
                return Rational (-p,q)

        def __abs__ (a):
                (p,q) = (a.num, a.den)
                return Rational (-p,q)
