import random
import math
import time
import binascii
import secrets
from Crypto.Cipher import AES 
from Crypto.Hash import SHA
from Crypto.Util.Padding import pad, unpad

"""
with open("flag.txt", "r") as f:
    flag = f.read().strip().encode("ascii")

with open("key.txt", "r") as f:
    key = int(f.read().strip())
"""
target_query = "Open sesame... Flag please!"
key = 1234
flag = b"test flag"

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



tempkey = SHA.new(int(key).to_bytes(64, 'big')).digest()[0:16]


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



""" # modified not actually true anymore
>>> nn = int(binascii.hexlify(pad(b'Open sesame... Flag please!',16)[:16]),16)
144062367998332532977264151438989526277
>>> oo = int('10'*16,16)
>>> mm = int('1331358226112515603a80f4b23f38ee',16)
24578579110157967680423669472281668203
>>> nn
144062367998332532977264151438989526277
>>> oo
21351050473470648687898014583954083856
>>> mm ^ nn ^ oo
146281903957790059843686435045030215550
>>> hex(_)
'0x6e0cdeb2c70bf1f17468069bbf93bf7e'
>>> TD(b'0'*32+b'6e0cdeb2c70bf1f17468069bbf93bf7e'+b'0'*32)
b'\xf1"\xa3\xec\xf1b^\x06[\x86\xa0j\xcde\xc2:lag please!\x05\x05\x05\x05\x05'
"""

'dee784a384e65433932fd3b6b88af257'
'4c5140fc167250761147f5ca8c0108b8' #goes before
#final string:
b'4c5140fc167250761147f5ca8c0108b8dee784a384e65433932fd3b6b88af257' + b'0'*32



def brk():
    c = b'0'*32 + b'dee784a384e65433932fd3b6b88af257' + b'0'#*32 + b'0'
    for i in range(16):
        ret = -1
        i = i + 16
        for k in range(256):
            print((c[-65:-33],binascii.hexlify(TD(c[:-1]))))
            ret = decrypt(c[:-1])
            if ret == -1:
                t = c[-3 + -2*i:-2 + -2*i] + c[-2 + -2*i:-1 + -2*i]
                t = (hex(int(str(t)[2:-1],16)^(k+1)^k)[2:]).encode('ascii')
                if len(t) == 1:
                    t = b'0' + t
                if len(t) == 3:
                    t = t[1:]
                c = c[:-3+-2*i] + t + c[-1+-2*i:] 
            elif i < 15+16:
                print(c)
                for j in range(i-15):
                    j = j + 16
                    t = c[-3 + -2*j:-2 + -2*j] + c[-2 + -2*j:-1 + -2*j]
                    t = (hex(int(str(t)[2:-1],16)^(i-14)^(i-15))[2:]).encode('ascii')
                    if len(t) == 1:
                        t = b'0' + t
                    if len(t) == 3:
                        return -1
                    c = c[:-3+-2*j] + t + c[-1+-2*j:]
                print(c)
                break
            else:
                break
    return c, decrypt(c[:-1])
