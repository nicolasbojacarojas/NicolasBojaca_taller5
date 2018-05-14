import numpy as np
import matplotlib.pyplot as plt
data = np.loadtxt("data.txt")
q2 = data[:,0]
p2 = data[:,1]
plt.scatter(p2, q2)
plt.savefig ("caos.pdf")

