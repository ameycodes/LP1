import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression

from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix

import seaborn as sns 

df=pd.read_csv('iris.csv')

df.info()

df.sample(5)

df.describe()

df.hist()

df.boxplot()

x=df['sepal_length']

plt.figure(figsize=(10,6))
plt.hist(x,bins=15,color='red',edgecolor='black')
plt.title("Sepal Length Histogram")
plt.xlabel("Sepal Length")
plt.ylabel("Frequency")
plt.show()

df['species'].value_counts().plot(kind='pie',autopct='%.2f')
plt.axis('equal')

x=df[['sepal_length','sepal_width','petal_length','petal_width']]
y=df['species']

x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.3,random_state=42)
model=LogisticRegression()
model.fit(x_train,y_train)
y_pred=model.predict(x_test)

accuracy=accuracy_score(y_test,y_pred)
print(accuracy)

cm=confusion_matrix(y_test,y_pred)
print(cm)

sns.heatmap(cm,cmap='Reds')
