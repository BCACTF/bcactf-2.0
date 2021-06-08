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

while True:
    print("Would you like to encrypt (E), decrypt (D), or quit (Q)?")
    l = input(">>> ").strip().upper()
    if (len(l) > 1):
        print("You inputted more than one character...")
    elif (l == "Q"):
        print("We hope you enjoyed!")
        exit()
    elif (l == "E"):
        print("What would you like to encrypt?")
        I = input(">>> ").strip()
        if (set(I.lower()) & set("flg!nsm")): # Disallowed characters changed to make the target query more difficult
            print("You're never getting my flag!")
            exit()
        else:
            iv = secrets.token_bytes(16)
            cipher = AES.new(tempkey, AES.MODE_CBC, iv)
            c = str(binascii.hexlify(iv + cipher.encrypt(pad(str.encode(I), 16))))[2:-1]
            print("Here's your message:")
            print(c)
    elif (l == "D"):
        print("What was the message?")
        I = input(">>> ").strip()
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
                print("Here's the decoded message:")
                print(m)
        except ValueError:
            print("I can't read that!")

