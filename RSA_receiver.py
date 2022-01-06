import RSA_lib
import RSA_sender

def receiving(package):
    pk, ciphertext = package # this should be publickey, encrypted_msg
    plaintext = RSA_lib.decrypt(pk, ciphertext)
    return plaintext

decrypted = receiving(RSA_sender.package)

print(decrypted)