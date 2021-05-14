# usernames generated with https://www.coolgenerator.com/username-generator

import hashlib

hashes = []
with open("./usernames") as i:
    for line in i:
        assert line not in hashes, "There is a collision (somehow)."
        hashes.append(hashlib.md5(line.encode('utf-8')).hexdigest())
print("No collisions, all good.")