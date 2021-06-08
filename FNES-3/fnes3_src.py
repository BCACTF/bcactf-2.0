import random
import math
import time
import binascii
from Crypto.Cipher import AES 
from Crypto.Hash import SHA
from Crypto.Util.Padding import pad, unpad


p = 2**135 + 2**75 + 1
a = 313370
b = 12409401451673702436179381616844751057480 # discriminant is zero
g = (313379, 9762458732130899649993884045943131856797, False) 
a = 31337331337331337331337331337
A = (43021995276387189451103561967322585445191, 42451503815183868352427904453717783149363, False)
b = 161415308048655355242463438365887719201 # ascii
B = (11416432354540007307664772848104585637276, 5360283428650501698333324098613510186588, False)
S = (10206173483832403717938242612204319869105, 31545760726761743171436338910767873058077, False)

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

print(mulp(mulp(g,a),161415308048655355242463438365887719201))
B = mulp(g,161415308048655355242463438365887719201)
print(B)
print(mulp(B,a))

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

