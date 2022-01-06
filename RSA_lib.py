import random

# function for making a large list of primes
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

# finding gcd using euclid's algorithm
def euclid1(a, b):
    x, y, u, v = 0, 1, 1, 0
    while a != 0:
        q, r = b//a, b%a
        m, n = x - u * q, y - v * q
        b, a, x, y, u, v = a, r, u, v, m, n
    gcd = b
    return gcd, x, y

# euclid's modulo inverse function of two numbers
def euclid2(a, m):
    gcd, x, y = euclid1(a, m)
    if gcd != 1:
        return None
    else: return x % m

# key pair generator
def keygen(p, q):
    n = p * q

    phi = (p - 1) * (q - 1)

    e = random.randrange(1, phi)

    g, _, _ = euclid1(e, phi)
    while g != 1:
        e = random.randrange(1, phi)
        g, _, _ = euclid1(e, phi)

    d = euclid2(e, phi)

    return ((e, n), (d, n))

# encrypting with the public key
def encrypt(pk, plaintext):
    key, n = pk
    cipher = [(ord(char) ** key) % n for char in plaintext]
    return cipher 

# decrypting with the private key
def decrypt(pk, ciphertext):
    key, n = pk
    plain = [chr((char ** key) % n) for char in ciphertext]
    return ''.join(plain)


### functions to be called from inside a program


# key generation fuction to be called in programs
# receiver side
def receiver_key_generation():
    primelist = primesInRange(1500, 2500) # make a list of primes in range
    p = random.choice(primelist) # choose a prime from the list
    q = random.choice(primelist) # choose a second one
    while p == q:
        q = random.choice(primelist)
    publickey, privatekey = keygen(p, q)
    return publickey, privatekey

# decrypting using privatekey
# receiver side
def receiver_decryption(encrypted_msg, privatekey):
    plaintext = decrypt(privatekey, encrypted_msg)
    return plaintext

# encryption using publickey
# sender side
def sender_encryption(publickey, plaintext):
    encrypted_msg = encrypt(publickey, plaintext)
    return encrypted_msg

### for later reference

# example how to implement into an app


# step one - key generation on receivers side
publickey, privatekey = receiver_key_generation()
# only the public key gets sent to the sender
# private key is stored for later decryption

# step two
# sender inputs any message
message = input("Input a message you want to send to receiver: ")
# obtaining the public key
key_to_encrypt = publickey
# encrypting the message using the public key
encrypted_msg = sender_encryption(key_to_encrypt, message)

# step three
# receiver decrypts the encrypted message
decrypted_msg = receiver_decryption(encrypted_msg, privatekey)
# print out the decrypted message
print(decrypted_msg)