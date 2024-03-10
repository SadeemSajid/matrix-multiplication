import matplotlib.pyplot as plt
import numpy as np

# X-Axis Values

# Python:     1
# Java:       2
# C:          3
# Pthread (P) 4
# Vector (V)  5
# v with P:   6


pythonTimes = np.array([9645, 9653, 9631])
javaTimes = np.array([532, 409, 547])
cTimes = np.array([545, 493, 547])
pthreadTimes = np.array([127, 153, 154])
vectorTimes = np.array([155, 143, 155])
pthreadVectorTimes = np.array([33, 34, 34])

xaxis = np.array([1, 2, 3, 4, 5, 6])
yaxis = np.array([np.mean(pythonTimes), np.mean(javaTimes), np.mean(cTimes), np.mean(pthreadTimes), np.mean(vectorTimes), np.mean(pthreadVectorTimes)])
error = np.array([np.std(pythonTimes), np.std(javaTimes), np.std(cTimes), np.std(pthreadTimes), np.std(vectorTimes), np.std(pthreadVectorTimes)])

plt.errorbar(xaxis, yaxis, error, marker='o')
plt.xlabel("Code")
plt.ylabel("Average Time")
plt.show()