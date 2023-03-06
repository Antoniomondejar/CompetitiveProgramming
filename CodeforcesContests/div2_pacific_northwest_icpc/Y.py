import math

K = str(input())
K, P, X = K.split(" ")
K = float(K)
P = float(P)
X = float(X)
# P = float(input())
# X = float(input())

number_of_painters = round(math.sqrt(K*P/X))
cost = K*P/number_of_painters + X * number_of_painters
print(f"{cost:.3f}")