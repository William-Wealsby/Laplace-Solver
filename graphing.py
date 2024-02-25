import matplotlib.pyplot as plt
import seaborn
from json import loads 
filename = input()
with open(filename) as file:
    jsondata=loads(file.read())
seaborn.heatmap(jsondata)
plt.show()

