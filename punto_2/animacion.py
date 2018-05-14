import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

data = np.loadtxt('data.txt')
fig, ax = plt.subplots()
x = data[:, 1]
y = data[:, 2]

line, = ax.plot(x, y)	
def animate(i):
    line.set_ydata(y) 
    return line,
    
def init():
    line.set_ydata(np.ma.array(x, mask=True))
    return line,

plt.ylim(-1,1)
ani = animation.FuncAnimation(fig, animate, init_func=init, interval=10 ,blit=True)
ani.save('cuerda.gif', writer='imagemagick', fps=60)
