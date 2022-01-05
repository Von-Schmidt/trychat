import RSA_lib
import random

def sending():
    primelist = RSA_lib.primesInRange(1000, 2000)
    p = random.choice(primelist)
    q = random.choice(primelist)
    publickey, privatekey = RSA_lib.keygen(p, q)
    message = "zdenda"
    encrypted_msg = RSA_lib.encrypt(privatekey, message)
    package = publickey, encrypted_msg
    return publickey, encrypted_msg

# replace this with a text input
package = sending()

print(package) # output is in format publickey, encrypted_msg