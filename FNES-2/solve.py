import random
import math
import time
import binascii
import secrets
from Crypto.Cipher import AES 
from Crypto.Hash import SHA
from Crypto.Util.Padding import pad, unpad


with open("flag.txt", "r") as f:
    flag = f.read().strip().encode("ascii")

with open("key.txt", "r") as f:
    key = int(f.read().strip())

target_query = "Open sesame... Flag please!"

print("""
Welcome to your new and improved FNES... FNES 2!
As before, if you and a friend both run this service at the same time,
you should be able to send messages to each other!
Here are the steps:
1. Friends A and B connect to the server at the same time (you have about a five second margin)
2. Friend A encodes a message and sends it to Friend B
3. Friend B decodes the message, encodes their reply, and sends it to Friend A
4. Friend A decodes the reply, rinse and repeat
PS: For security reasons, there are still some characters you aren't allowed to encrypt. Sorry!
""")

tempkey = SHA.new(int(key + int(time.time() / 10)).to_bytes(64, 'big')).digest()[0:16]


def decrypt(I):
    iv = I[:32]
    I = I[32:]
    try:
        cipher = AES.new(tempkey, AES.MODE_CBC, binascii.unhexlify(iv))
        m = str(unpad(cipher.decrypt(binascii.unhexlify(I)), 16))[2:-1]
        if (m == target_query):
            print("\nPassphrase accepted. Here's your flag:\n")
            print(str(flag)[2:-1])
            try:
                with open("advertisement.txt", "r") as ff:
                    print(ff.read())
            except:
                pass
            exit()
        else:
            return m
    except ValueError:
        return -1

def TD(I):
    iv = I[:32]
    I = I[32:]
    try:
        cipher = AES.new(tempkey, AES.MODE_CBC, binascii.unhexlify(iv))
        m = cipher.decrypt(binascii.unhexlify(I))
        return m
    except ValueError:
        return -1

def brk():
    c = b'1'*64 + b'0'
    for i in range(16):
        ret = -1
        i = i + 16
        while ret == -1:
            print(c)
            print(TD(c[:-1]))
            ret = decrypt(c[:-1])
            if ret == -1:
                t = c[-3 + -2*i:-2 + -2*i] + c[-2 + -2*i:-1 + -2*i]
                t = (hex(int(str(t)[2:-1],16)+1)[2:]).encode('ascii')
                if len(t) == 1:
                    t = b'0' + t
                if len(t) == 3:
                    print("oh no")
                    return -1
                c = c[:-3+-2*i] + t + c[-1+-2*i:] 
            else:
                print(c)
                for j in range(i-15):
                    j += 16
                    t = c[-3 + -2*i:-2 + -2*i] + c[-2 + -2*i:-1 + -2*i]
                    t = (hex(int(str(t)[2:-1],16)+1)[2:]).encode('ascii')
                    if len(t) == 1:
                        t = b'0' + t
                    if len(t) == 3:
                        t = t[1:]
                    c = c[:-3+-2*i] + t + c[-1+-2*i:] 
                    print("AAA")
                    print(c)
                break
    return c, decrypt(c)



