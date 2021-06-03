p = 88109622073295520500026063548593441481459793670692032053411931178649897693130103
q = 14878830270854902955513568066940373050935544276293181725780703748393199119251103
n = p * q
e = 3
N = 23

R = Zmod(n)
MS = MatrixSpace(R, N, N)
s = PermutationGroupElement('(1,6,8)(2,3,4,5,7)(9,11,13,15,17,19,21,23)(10,12,14,16,18,20,22)')
P = MS(s.matrix())
with seed(1): C = MS([randrange(100) for i in range(N*N)])
G = C * P * C^-1

def encrypt(m):
	M = m * G
	return (M^e).list()