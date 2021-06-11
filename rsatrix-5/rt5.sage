import binascii

# future server implementer (todo ed delete this): all of these should be regenerated on every server connection
# also todo, you probably want to put a POW on this problem

print("Starting...")
e = 65537
p = 65538
while (p-1) % e == 0:
	p = random_prime(2^401, false, 2^400)
q = 65538
while (q-1) % e == 0:
	q = random_prime(2^401, false, 2^400)
n =  p * q
d = int(Zmod((p-1)*(q-1))(e)^-1)
N = 64

R = Zmod(n)
MS = MatrixSpace(R, N, N)
S = SymmetricGroup(N)
running = True
while running:
	try:
		s = 0
		while s.order() < 2000:
			s = S.random_element()
		P = MS(s.matrix())
		running = false
	except:
		continue
C = MS([randrange(n) for i in range(N*N)])
print("Calculating G...") 
G = C * P * C^-1

def encrypt(m):
	M = m * G
	return (M^e).list()

with open("flag.txt", "r") as f:
    flag = f.read().strip().encode("ascii")
m = int(binascii.hexlify(flag), 16)

print("Encrypting...")
mats = {"G" : G, "E" : MS(encrypt(m))}
vals = {"e" : e, "d" : d}
done = {"A" : False, "M" : False, "C" : False, "X" : False, "U" : False, "N" : False, "T" : False}


print("""
Our calculator demo has gotten pretty expensive.
Given you're not a paying customer or anything, we decided it was fair to implement a POW 
and only allow one of each type of operation per connection.
Try them all for the full experience!
Also, d is secret now. Oops! We've added integer operations to compensate.
""")
print(f"n = {n}")

while True:
	print("Would you like to print the traces of your stored matrices (P), list your stored integers (L), \nadd two matrices (A), multiply two matrices (M), multiply a matrix by a constant (C), \ntake a matrix power (X), add two integers (D), \nmultiply two integers (U), exponentiate two integers mod n (N), save the trace of a matrix (T), or quit (Q)?")
	try:
		l = input(">>> ").strip().upper()
		if len(l) > 1:
			print("You inputted more than one character...")
		elif l == "Q":
			print("We hope you enjoyed!")
			exit()
		elif l == "P":
			print("Here the traces of your matrices:")
			for k in mats:
				print(k + ": " + str(mats[k].trace()))
		elif l == "L":
			print("Here is your list of integers:")
            print(list(vals.keys()))
		elif l == "A" and not done["A"]:
			done["A"] = True
			print("What is the name of the first matrix you would like to add?")
			A = input(">>> ").strip()
			print("What is the name of the second matrix you would like to add?")
			B = input(">>> ").strip()
			C = mats[A]+mats[B]
			print("The trace of their sum is: " + str(C.trace()))
			print("Would you like to save this matrix? (Y/N)")
			I = input(">>> ").strip().upper()
			if I == "N":
				continue
			print("What would you like the name of the matrix to be?")
			N = input(">>> ").strip()
			mats[N] = C
			print("Matrix saved.")
		elif l == "M" and not done["M"]:
			done["M"] = True
			print("What is the name of the first matrix you would like to multiply?")
			A = input(">>> ").strip()
			print("What is the name of the second matrix you would like to multiply?")
			B = input(">>> ").strip()
			C = mats[A]*mats[B]
			print("The trace of their product is: " + str(C.trace()))
			print("Would you like to save this matrix? (Y/N)")
			I = input(">>> ").strip().upper()
			if I == "N":
				continue
			print("What would you like the name of the matrix to be?")
			N = input(">>> ").strip()
			mats[N] = C
			print("Matrix saved.")
		elif l == "C" and not done["C"]:
			done["C"] = True
			print("What is the name of the matrix you would like to multiply?")
			A = input(">>> ").strip()
			print("What is the value of the constant you would like to multiply it by?")
			B = int(input(">>> ").strip())
			C = B * mats[A]
			print("The trace of the product is: " + str(C.trace()))
			print("Would you like to save this matrix? (Y/N)")
			I = input(">>> ").strip().upper()
			if I == "N":
				continue
			print("What would you like the name of the matrix to be?")
			N = input(">>> ").strip()
			mats[N] = C
			print("Matrix saved.")
		elif l == "X" and not done["X"]:
			done["X"] = True
			print("What is the name of the matrix you would like to exponentiate?")
			A = input(">>> ").strip()
			print("What is the name or value of the exponent you would like to use?")
			B = input(">>> ").strip()
			if B in vals:
				B = vals[B]
			else:
				B = int(B)
			if B <= 0:
				print("Positive powers only.")
				continue
			C = mats[A]^B
			print("The trace of the matrix power is is: " + str(C.trace()))
			print("Would you like to save this matrix? (Y/N)")
			I = input(">>> ").strip().upper()
			if I == "N":
				continue
			print("What would you like the name of the matrix to be?")
			N = input(">>> ").strip()
			mats[N] = C
			print("Matrix saved.")
		elif l == "D" and not done["D"]:
			done["D"] = True
			print("What is the name or value of the first number you would like to add?")
			A = input(">>> ").strip()
			if A in vals:
				A = vals[A]
			else:
				A = int(A)
			print("What is the name or value of the second number you would like to add?")
			B = input(">>> ").strip()
			if B in vals:
				B = vals[B]
			else:
				B = int(B)
			C = A + B
			print("Sum calculated. Do you want to save the result (S), or print and quit (Q)?")
			I = input(">>> ").strip().upper()
			if I == "Q":
				print(C)
				print("We hope you enjoyed!")
				exit()
			print("What would you like the name of the variable to be?")
			N = input(">>> ").strip()
			vals[N] = C
		elif l == "U" and not done["U"]:
			done["U"] = True
			print("What is the name or value of the first number you would like to multiply?")
			A = input(">>> ").strip()
			if A in vals:
				A = vals[A]
			else:
				A = int(A)
			print("What is the name or value of the second number you would like to multiply?")
			B = input(">>> ").strip()
			if B in vals:
				B = vals[B]
			else:
				B = int(B)
			C = A * B
			print("Product calculated. Do you want to save the result (S), or print and quit (Q)?")
			I = input(">>> ").strip().upper()
			if I == "Q":
				print(C)
				print("We hope you enjoyed!")
				exit()
			print("What would you like the name of the variable to be?")
			N = input(">>> ").strip()
			vals[N] = C
		elif l == "N" and not done["N"]:
			done["N"] = True
			print("What is the name or value of the first number you would like to exponentiate?")
			A = input(">>> ").strip()
			if A in vals:
				A = vals[A]
			else:
				A = int(A)
			print("What is the name or value of the second number you would like to exponentiate?")
			B = input(">>> ").strip()
			if B in vals:
				B = vals[B]
			else:
				B = int(B)
			C = int(R(A) ^ B)
			print("Power calculated. Do you want to save the result (S), or print and quit (Q)?")
			I = input(">>> ").strip().upper()
			if I == "Q":
				print(C)
				print("We hope you enjoyed!")
				exit()
			print("What would you like the name of the variable to be?")
			N = input(">>> ").strip()
			vals[N] = C
		elif l == "T" and not done["T"]:
			done["T"] = True
			print("What is the name of the matrix whose trace you would like to save?")
			A = input(">>> ").strip()
			C = mats[A].trace()
			print("Trace calculated. We will make the brash assumption you'd like to save the result.")
			print("What would you like the name of the variable to be?")
			N = input(">>> ").strip()
			vals[N] = C
		
	except:
		print("Your input caused an error.")