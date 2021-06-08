import random

with open("flag.txt", "r") as file:
    flag = file.read()

with open("plaintext.md", "r") as file:
    plaintext = file.read().replace("INSERT FLAG HERE", flag.strip())

alphabet = []
for i in range(26):
    char = None
    while char is None or char in alphabet:
        char = chr(random.randint(0x100000, 0x10FFFD))
    alphabet.append(char)

def encipher(text):
    ciphertext = ""
    for c in text.lower():
        if ord(c) >= ord("a") and ord(c) <= ord("z"):
            ciphertext += alphabet[ord(c) - ord("a")]
        else:
            ciphertext += c
    return ciphertext

with open("ciphertext.md", "w", encoding="utf8") as file:
    file.write(encipher(plaintext))

print(encipher("Runescape"))