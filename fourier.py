from scipy import fft
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 1, 16)
y = np.sin(x)
fourier = fft.fft(y)

plt.plot(x, y)
plt.show()
plt.plot(np.real(fourier))
plt.show()