import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
#decision tree root node is decided by information gain whereas we consider all types of decision trees in
#random forest
from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix

import seaborn as sn

dataframe=pd.read_csv('capitalbikeshare.csv')

dataframe.info()

dataframe.head(10)

dataframe.describe()

x=dataframe[['Duration','Start station number','End station number']]
y=dataframe['Member type']

y.value_counts().plot(kind='pie',autopct='%0.2f')

plt.figure(figsize=(8,6))
x.boxplot()
plt.show()

# y.val

X_train,X_test,Y_train,Y_test=train_test_split(x,y,test_size=0.2,random_state=42)
model=DecisionTreeClassifier()
model.fit(X_train,Y_train)
Y_pred= model.predict(X_test)

accuracy=accuracy_score(Y_test,Y_pred)
print(accuracy)

cm=confusion_matrix(Y_test,Y_pred)
print(cm)

sn.heatmap(cm,cmap='Reds')