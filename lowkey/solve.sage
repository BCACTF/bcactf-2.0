import binascii

m1 = b'When sunlight strikes raindrops in the air, they act like a prism and form a rainbow. The rainbow is a division of white light into many beautiful colors. These take the shape of a long round arch, with its path high above, and its two ends apparently beyond the horizon. There is, according to legend, a boiling pot of gold at one end. People look but no one ever finds it. When a man looks for something beyond his reach, his friends say he is looking for the pot of gold at the end of the rainbow.\x0c\x0c\x0c\x0c\x0c\x0c\x0c\x0c\x0c\x0c\x0c\x0c'

e1 = binascii.unhexlify(b'0074252538126d030056257867484f6400070806330a06660078081c5d571a140018081064105e28006d0841101c4c43000e0408364f1122003f04005b48541d00040b4169050e60007c0b5c471a531600647a4e002d7d2600587a5319391b6c001e054f2e5a502d002405445f1f0c47005a594531575d2d006559555e064947001b06116f0305770076060c4c18501a007076444a470217000f761b61633b2d00160d11230a417d007d0d1b07111f12000c004d715a5776002a004a0d121f140047085b25531c77007708150f074f40004900587211403000210041475f181b000b551c7842142d00365558180f4f1a0011095434135e7200740944134b401a00411a562519037800321a564d5649110023606e780d214b0018607065191c75005e17402c101729006f17015b154a5c004a0a5475440661006f0a13570d530f0011100235135d6e003a104c0e590b540073676a235c304a000067675d3c131a004a00517a0f0d2a006000521c415d4d00317d1f6e164f0700447d67574c3217005e554c2d064c340038550249011e480003151a790950630073155950054e1e00091b527953123f00631b150f0e1c48000206036a001f71003906504616564200155954770e1072006e590a474c5c09000f111c2a1c537c002d11454e52424800130b442a43183e00230b12451e1e4a0076540d2e590d580058540d373a2237')

m2 = []
while m1:
	mp = [('0'*8 + bin(t)[2:])[-8:] for t in m1[:16]]
	for i in range(8):
		m2.append(tuple([ord(t[i])-ord('0') for t in mp]))
	m1 = m1[16:]

e2 = []
while e1:
	mp = [('0'*8 + bin(t)[2:])[-8:] for t in e1[:16]]
	for i in range(8):
		e2.append(tuple([ord(t[i])-ord('0') for t in mp]))
	e1 = e1[16:]

F = GF(2)
V = F ** 16
T = []
U = []
for t, u in zip(m2, e2):
	if not V.are_linearly_dependent(T + [t]):
		T += [t]
		U += [u]

VS = V.span_of_basis(T)

# here's getting the first two letters, because I'm too lazy to write general code:

v = V([1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0])
c = VS.coordinates(v) # has '1' at loc 1 and 8
L = list(V(U[1]) + V(U[8]))
s = ''.join([''+str(i) for i in L])
chr(int(s[:8]) # s
chr(int(s[8:]) # y