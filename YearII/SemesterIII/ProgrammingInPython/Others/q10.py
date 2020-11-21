import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('iris.csv')

for label in data['Species'].unique():
    plt.hist(data[data['Species'] == label]
             ['PetalLengthCm'], bins=10)
plt.xlabel('Petal Length (cm)')
plt.ylabel('Frequency')
plt.title('Petal Length Distribution')
plt.show()

for label in data['Species'].unique():
    plt.scatter(data[data['Species'] == label]['PetalLengthCm'],
                data[data['Species'] == label]['PetalWidthCm'])
plt.xlabel('Petal Length (cm)')
plt.ylabel('Petal Width (cm)')
plt.title('Petal Dimension Correlation')
plt.show()
