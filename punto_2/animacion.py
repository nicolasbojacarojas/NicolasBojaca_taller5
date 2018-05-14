import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
data = np.loadtxt('data.txt')
fig = plt.figure()
ax = plt.axes(xlim=(0, 100), ylim=(-1, 1))
line, = ax.plot([], [], lw=2)

def init():
    line.set_data([],[]) 
    return line,
    
def animate(i):
    x = np.linspace(0, 100, len(data[0]))
    line.set_data(x, data[i])
    return line,

plt.ylim(-1,1)
ani = animation.FuncAnimation(fig, animate, init_func=init, interval=10 ,blit=True)
ani.save('cuerda.gif', writer='imagemagick', fps=60)
