import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB

from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix

import seaborn as sns 

dataframe=pd.read_csv('PimaIndiansDiabetes.csv')

dataframe.info()

dataframe.sample(5)

dataframe.describe().to_string()

plt.figure(figsize=(15,9))
dataframe.boxplot()
plt.show()


x=dataframe[['TimesPregnant','GlucoseConcentration','BloodPrs','SkinThickness','Serum','BMI','DiabetesFunct','Age']]
y=dataframe['Class']

y.value_counts().plot(kind='pie',autopct='%0.2f')

X_train,X_test,Y_train,Y_test=train_test_split(x,y,test_size=0.2,random_state=42)

model=GaussianNB()
model.fit(X_train,Y_train)
Y_pred=model.predict(X_test)

accuracy=accuracy_score(Y_test,Y_pred)
print(accuracy)

cm=confusion_matrix(Y_test,Y_pred)
print(cm)

sns.heatmap(cm,cmap='Blues')

dataframe['Serum']=dataframe['Serum'].replace(0,dataframe['Serum'].mean())
x=dataframe[['TimesPregnant','GlucoseConcentration','SkinThickness','Serum','BMI','DiabetesFunct','Age']]
y=dataframe['Class']

X_train,X_test,Y_train,Y_test=train_test_split(x,y,test_size=0.2,random_state=42)

model=GaussianNB()
model.fit(X_train,Y_train)
Y_pred=model.predict(X_test)

accuracy=accuracy_score(Y_test,Y_pred)
print(accuracy)