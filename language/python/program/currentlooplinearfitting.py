#!/usr/bin/python
# -*- coding: UTF-8 -*-


import numpy as np
import matplotlib.pyplot as plt

# 在直线 y = 3 + 5x 附近生成随机点 
#X = np.arange(0, 5, 0.1)
#Z = [3 + 5 * x for x in X]
#Y = [np.random.normal(z, 0.5) for z in Z]

# X = np.array([0, 256, 512, 768, 1024, 1280, 1536, 1792, \
# 	2048, 2304, 2560, 2816, 3072, 3328, 3584, 3840, \
# 	3840, 3584, 3328, 3072, 2816, 2560, 2304, 2048, \
# 	1792, 1536, 1280, 1024, 768, 512, 256, 0])
# Y = np.array([0.0653, 1.5476, 3.0381, 4.5286, 6.0185, 7.5086, 8.9981, 10.4879, \
# 	11.9768, 13.4659, 14.9564, 16.4428, 17.9308, 19.4186, 20.9061, 22.3933, \
# 	22.3927, 20.9038, 19.4151, 17.9259, 16.4366, 14.9478, 13.4581, 11.9685, \
# 	10.4789, 8.9893, 7.4991, 6.0096, 4.5202, 3.0311, 1.5433, 0.0633])

X = np.array([768, 1024, 1280, 1536, 1792, \
	2048, 2304, 2560, 2816, 3072, 3328, 3584, \
	3584, 3328, 3072, 2816, 2560, 2304, 2048, \
	1792, 1536, 1280, 1024, 768])
Y = np.array([4.5286, 6.0185, 7.5086, 8.9981, 10.4879, \
	11.9768, 13.4659, 14.9564, 16.4428, 17.9308, 19.4186, 20.9061, \
	20.9038, 19.4151, 17.9259, 16.4366, 14.9478, 13.4581, 11.9685, \
	10.4789, 8.9893, 7.4991, 6.0096, 4.5202])

Y /= 0.005859375;

#print("Y is ", Y)

plt.plot(X, Y, 'ro')
plt.show()



def linear_regression(x, y):
	N = len(x)
	sumx = sum(x)
	sumy = sum(y)
	sumx2 = sum(x**2)
	sumxy = sum(x*y)

	A = np.mat([[N, sumx], [sumx, sumx2]])
	b = np.array([sumy, sumxy])

	return np.linalg.solve(A, b)

a0, a1 = linear_regression(X, Y)
print("a0 a1 is ", a0, a1)

XX = np.arange(0, 4095, 1)
YY = a1*XX + a0

print(YY[1024])
print(YY[1080])

