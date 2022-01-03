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
def euclid1(a, b):
    while b != 0:
        a, b = b, a %b
    return a

#   this is a pile of garbage
# for some fucking reason it throws none
# find multiplicative inverse of two numbers
#def euclid2(e, phi):
#    d = 0
#    x1 = 0
#    x2 = 1
#   y1 = 1
#    temp_phi = e
#
#    while e > 0:
#        temp1 = temp_phi / e
#        temp2 = temp_phi - temp1 * e
#        temp_phi = e
#        e = temp2
#
#        x = x2 - temp1 * x1
#        y = d - temp1 * y1
#
#        x2 = x1
#        x1 = x
#        d = y1
#        y1 = y1
#
#    if temp_phi == 1:
 #       for i in range(r):
 #           if((e*i)%r == 1):
 #               return i
 #       return d + phi

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

    g = euclid1(e, phi)
    while g != 1:
        e = random.randrange(1, phi)
        g = euclid1(e, phi)

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
