#!/usr/bin/env sage
import binascii
import asyncio
import socket

p = 2118785735523620955301512231868734231925640292462405499978976981762557161416662496081983014179663
q = 1243737700428927574598968208586995066861594665591025213691894901887737529628559457923362470874703
n = p * q
e = 3
N = 31

R = Zmod(n)
MS = MatrixSpace(R, N, N)
s = PermutationGroupElement('(1,8,18)(2,24,14,22,25,6,9,13,31,15,21)(3,16,27,26,12,10,7,5,20,23)(4,29,28,11,19,17,30)')
P = MS(s.matrix())
with seed(1): C = MS([randrange(100) for i in range(N*N)])
G = C * P * C^-1

def encrypt(m):
	M = m * G
	return (M^e).list()

with open("flag.txt", "r") as f:
    flag = f.read().strip().encode("ascii")
m = int(binascii.hexlify(flag), 16)

async def handle_conn(reader, writer):
	def print(text):
		writer.write(text.encode() + b"\n")

	async def prompt():
		writer.write(b">>> ")
		await writer.drain()
		return (await reader.readline()).decode().strip()

	mats = {"I": MS.identity_matrix(), "G": G, "E": MS(encrypt(m))}

	print("""
	Welcome to the RSAtrix demo calculator! 
	Here, you can define matrix variables in terms of sums, products, or powers of matrices.
	You can also multiply a matrix by a constant.
	There's only one catch: you can only receive the trace of the resulting matrices!
	""")

	while True:
		print("Would you like to print the traces of your stored matrices (P), add two matrices (A), \nmultiply two matrices (M), multiply a matrix by a constant (C), take a matrix power (X), or quit (Q)?")
		try:
			l = (await prompt()).upper()
			if (len(l) > 1):
				print("You inputted more than one character...")
			elif (l == "Q"):
				print("We hope you enjoyed!")
				await writer.drain()
				writer.close()
				await writer.wait_closed()
				return
			elif (l == "P"):
				print("Here the traces of your matrices:")
				for k in mats:
					print(k + ": " + str(mats[k].trace()))
			elif (l == "A"):
				print("What is the name of the first matrix you would like to add?")
				A = (await prompt())
				print("What is the name of the second matrix you would like to add?")
				B = (await prompt())
				C = mats[A]+mats[B]
				print("The trace of their sum is: " + str(C.trace()))
				print("Would you like to save this matrix? (Y/N)")
				I = (await prompt()).upper()
				if I == "N":
					continue
				print("What would you like the name of the matrix to be?")
				N = (await prompt())
				mats[N] = C
				print("Matrix saved.")
			elif (l == "M"):
				print("What is the name of the first matrix you would like to multiply?")
				A = (await prompt())
				print("What is the name of the second matrix you would like to multiply?")
				B = (await prompt())
				C = mats[A]*mats[B]
				print("The trace of their product is: " + str(C.trace()))
				print("Would you like to save this matrix? (Y/N)")
				I = (await prompt()).upper()
				if I == "N":
					continue
				print("What would you like the name of the matrix to be?")
				N = (await prompt())
				mats[N] = C
				print("Matrix saved.")
			elif (l == "C"):
				print("What is the name of the matrix you would like to multiply?")
				A = (await prompt())
				print("What is the value of the constant you would like to multiply it by?")
				B = int((await prompt()))
				C = B * mats[A]
				print("The trace of the product is: " + str(C.trace()))
				print("Would you like to save this matrix? (Y/N)")
				I = (await prompt()).upper()
				if I == "N":
					continue
				print("What would you like the name of the matrix to be?")
				N = (await prompt())
				mats[N] = C
				print("Matrix saved.")
			elif (l == "X"):
				print("What is the name of the matrix you would like to exponentiate?")
				A = (await prompt())
				print("What is the value of the exponent you would like to use?")
				B = int((await prompt()))
				C = mats[A]^B
				print("The trace of the matrix power is is: " + str(C.trace()))
				print("Would you like to save this matrix? (Y/N)")
				I = (await prompt()).upper()
				if I == "N":
					continue
				print("What would you like the name of the matrix to be?")
				N = (await prompt())
				mats[N] = C
				print("Matrix saved.")
		except socket.error:
			return
		except:
			print("Your input caused an error.")

async def main():
	server = await asyncio.start_server(handle_conn, "0.0.0.0", 9999)

	async with server:
		await server.serve_forever()

asyncio.run(main())
