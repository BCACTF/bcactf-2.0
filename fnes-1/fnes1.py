#!/usr/bin/env python3
import random
import math
import time
import binascii
from Crypto.Cipher import ARC4
from Crypto.Hash import SHA


with open("flag.txt", "r") as f:
    flag = f.read().strip().encode("ascii")

with open("key.txt", "r") as f:
    key = int(f.read().strip())

target_query = "Open sesame... Flag please!"

print("""
Welcome to your Friendly Neighborhood Encryption Service (FNES)!
If you and a friend both run this service at the same time,
you should be able to send messages to each other!
Here are the steps:
1. Friends A and B connect to the server at the same time (you have about a five second margin)
2. Friend A encodes a message and sends it to Friend B
3. Friend B decodes the message, encodes their reply, and sends it to Friend A
4. Friend A decodes the reply, rinse and repeat
Make sure to not make any mistakes, though, or your keystreams might come out of sync...
PS: For security reasons, there are four characters you aren't allowed to encrypt. Sorry!
""")

tempkey = SHA.new(int(key + int(time.time() / 10)).to_bytes(64, 'big')).digest()[0:16]
cipher = ARC4.new(tempkey)

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
        I = input(">>> ").strip().encode('utf-8')
        if (set(I.lower()) & set("flg!")): # You're not allowed to encrypt any of the characters in "flg!"
            print("You're never getting my flag!")
            exit()
        else:
            print("Here's your message:")
            c = str(binascii.hexlify(cipher.encrypt(I)))[2:-1]
            print(c)
    elif (l == "D"):
        print("What was the message?")
        I = input(">>> ").strip()
        m = str(cipher.decrypt(binascii.unhexlify(I)))[2:-1]
        if (m == target_query):
            print("Passphrase accepted. Here's your flag:")
            print(str(flag)[2:-1])
            exit()
        else:
            print("Here's the decoded message:")
            print(m)
