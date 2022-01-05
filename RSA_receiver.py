import RSA_lib
import RSA_sender

def receiving():
    pk, ciphertext = RSA_sender.package # this should be publickey, encrypted_msg
    plaintext = RSA_lib.decrypt(pk, ciphertext)
    return plaintext

decrypted = receiving()

print(decrypted)