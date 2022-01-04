import random
import math

#nemělo by bejt potřeba later, zatim na test
def isprime(n):
    for i in range (2, n//2+1):
        if (not (n%i)):
            return False
    return True

# find common divisor among the two values
# iteration for faster operation
def euclid3(a, b):
     while b != 0:
         a, b = b, a %b
     return a

def euclid1(a, b):
    x, y, u, v = 0, 1, 1, 0
    while a != 0:
        q, r = b//a, b%a
        m, n = x - u * q, y - v * q
        b, a, x, y, u, v = a, r, u, v, m, n
    gcd = b
    return gcd, x, y

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

    g = euclid3(e, phi)
    while g != 1:
        e = random.randrange(1, phi)
        g = euclid3(e, phi)

    d = euclid2(e, phi) # this shit doesnt fucking work

    return ((e, n), (d, n))

def encrypt(pk, plaintext):
    key, n = pk
    cipher = [(ord(char) ** key) % n for char in plaintext] ## this doesn't appareantly work
    return cipher 

def decrypt(pk, ciphertext):
    key, n = pk
    plain = [chr((char ** key) % n) for char in ciphertext] ## this doesn't appareantly work
    return ''.join(plain)

if __name__ == '__main__':
    p = int(input("Enter a prime number (17, 19, 23, etc): "))
    q = int(input("Enter another prime number (Not one you entered above): "))
    print("Generating your public/private keypairs now . . .")
    public, private = keygen(p, q)
    print("Your public key is ", public ," and your private key is ", private)
    message = input("Enter a message to encrypt with your private key: ")
    encrypted_msg = encrypt(private, message)
    print("Your encrypted message is: ")
    print(''.join(map(lambda x: str(x), encrypted_msg)))
    print("Decrypting message with public key ", public ," . . .")
    print("Your message is:")
    print(decrypt(public, encrypted_msg))
