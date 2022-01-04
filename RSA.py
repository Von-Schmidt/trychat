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

# old gcd funct
#def euclid3(a, b):
#    while b != 0:
#        a, b = b, a % b
#    return a

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


    # this used the old gcd func. 
    #g = euclid3(e, phi)
    #while g != 1:
    #    e = random.randrange(1, phi) 
    #    g = euclid3(e, phi)

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

if __name__ == '__main__':
    primelist = primesInRange(1000, 1500)
    p = random.choice(primelist)
    q = random.choice(primelist)
    #p = int(input("Enter a prime number (17, 19, 23, etc): "))             ------ for input
    #q = int(input("Enter another prime number (Not one you entered above): "))
    print("Generating keypairs...")
    public, private = keygen(p, q)
    print("Public key: ", public, "Private key: ", private)
    message = input("Enter a message to encrypt using the private key: ")
    encrypted_msg = encrypt(private, message)
    print("Encrypted message:", ''.join(map(lambda x: str(x), encrypted_msg)))
    print("Decrypting with public key: ", public, " ...")
    print("Decrypted message: ", decrypt(public, encrypted_msg))

