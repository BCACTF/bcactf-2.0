import random
import math
import time
import binascii
from Crypto.Cipher import AES 
from Crypto.Hash import SHA
from Crypto.Util.Padding import pad, unpad


p = 2**255 - 19
a = 34534324
b = 267562990728472881298781656145103402487842088313918623955114524186280435434


def negp(P):
    x,y,z = P
    return (-x,y,z)

def dubp(P):
    x,y,z = P
    if z:
        return P
    if y == 0:
        return (0, 0, True)
    L = (3 * x * x + a) * pow(2 * y, -1, p)
    xr = L * L - 2 * x
    yr = y + L * (xr - x)
    return (xr % p, -yr % p, False)

def addp(P, Q):
    xp,yp,zp = P
    xq,yq,zq = Q
    if zp:
        return Q
    if zq:
        return P
    if P == negp(Q):
        return (0, 0, True)
    if P == Q:
        return dubp(P)
    L = (yq - yp) * pow(xq - xp, -1, p)
    xr = L*L - xp - xq
    yr = yp + L * (xr - xp)
    return (xr % p, -yr % p, False)

def mulp(P, n):
    s = bin(n)[3:]
    r = P
    for c in s:
        r = dubp(r)
        if c == '1':
            r = addp(r, P)
    return r


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

g = (6338567613751034815419808245388791220143818116529749309763011972528582947444, 6338567613751034815419808245388791220143818116529749309763011972528582947444, False)
print(g)
print(mulp(g, 10000))


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
        I = str.encode(input(">>> ").strip())
        if (not set(I.lower()) & set("flgnq")): # Disallowed characters changed to make the key query more difficult
            print("You're never getting my flag!")
            exit()
        else:
            print("Here's your message:")
            c = str(binascii.hexlify(cipher.encrypt(pad(I, 16))))[2:-1]
            print(c)
    elif (l == "D"):
        print("What was the message?")
        I = input(">>> ").strip()
        try:
            m = str(unpad(cipher.decrypt(binascii.unhexlify(I)), 16))[2:-1]
            if (m[0:len(passphrase)] == passphrase and key_query in m):
                print("Passphrase accepted. Here's your flag:")
                print(str(flag)[2:-1])
                exit()
            else:
                print("Here's the decoded message:")
                print(m)
        except ValueError:
            print("I can't read that!")

