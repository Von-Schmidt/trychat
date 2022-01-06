import RSA_lib
import random

def sending(plaintext):
    primelist = RSA_lib.primesInRange(1000, 2000) # make a list of primes in range
    p = random.choice(primelist) # choose a prime from the list
    q = random.choice(primelist) # choose a second one
    while p == q: # in case the same prime gets chosen for both variables
        q = random.choice(primelist)
    publickey, privatekey = RSA_lib.keygen(p, q) # generate the public and private keys
    message = plaintext
    encrypted_msg = RSA_lib.encrypt(privatekey, message) # encrypt the message with private key
    return publickey, encrypted_msg

# replace this with a text input
package = sending("zdeněk")

print(package) # output is in format publickey, encrypted_msg