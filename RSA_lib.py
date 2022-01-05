import random

# required only if user inputs
def isprime(n):
    for i in range (2, n//2+1):
        if (not (n%i)):
            return False
    return True

def primesInRange(x, y):
    prime_list = []
    for n in range(x, y):
        isPrime = True

        for num in range(2, n):
            if n % num == 0:
                isPrime = False

        if isPrime:
            prime_list.append(n)
            
    return prime_list

# finding gcd
def euclid1(a, b):
    x, y, u, v = 0, 1, 1, 0
    while a != 0:
        q, r = b//a, b%a
        m, n = x - u * q, y - v * q
        b, a, x, y, u, v = a, r, u, v, m, n
    gcd = b
    return gcd, x, y

# modulo inverse function
def euclid2(a, m):
    gcd, x, y = euclid1(a, m)
    if gcd != 1:
        return None
    else: return x % m

# key pair generator
def keygen(p, q):
    if not (isprime(p) and isprime(q)):     # probably to automatize assigning primes later
        print("not prime")                  # to not cause errors
        exit()                              # -||-
    elif p == q:                            # -||-
        print("numbers are equal")          # -||-
    
    n = p * q

    phi = (p - 1) * (q - 1)

    e = random.randrange(1, phi)     # random might not be secure enough?

    g, _, _ = euclid1(e, phi)
    while g != 1:
        e = random.randrange(1, phi)
        g, _, _ = euclid1(e, phi)

    d = euclid2(e, phi) # this shit doesnt fucking work

    return ((e, n), (d, n))

def encrypt(pk, plaintext):
    key, n = pk
    cipher = [(ord(char) ** key) % n for char in plaintext]
    return cipher 

def decrypt(pk, ciphertext):
    key, n = pk
    plain = [chr((char ** key) % n) for char in ciphertext]
    return ''.join(plain)

