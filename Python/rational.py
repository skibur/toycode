def __init__ (self, n=0, d =1):
    self num, self den = n,d
    if self.den < 0:
        self.num, self.den = -self.num, -self.den
    if self.den == 0:
return self, reduce ()

def reduce(self):
    d = gcd(self.num, self.denom)
    return Rational(self.num / d, self.den / d)

def gcd(a,b):
    while b > 0:
        a,b = b, a%b
    return a

def __add__(self, rhs):
    return rational (self.num +  rhs.den * rhs.num, self.den * rhs.den)

def __sub__(self, rhs):
    return rational (self.num -  rhs.den * rhs.num, self.den * rhs.den)

def __mul__(self, rhs):
    return rational (self.num *  rhs.den * rhs.num, self.den * rhs.den)

def __div__(self, rhs):
    return rational (self.num /  rhs.den * rhs.num, self.den * rhs.den)

def __str__(self):
    return("%d %d ")

(self.num, self.den)
__str__
