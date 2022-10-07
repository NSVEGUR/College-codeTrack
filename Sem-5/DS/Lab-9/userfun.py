import pandas as pd
import numpy as np
import random as rd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

class UserFunModels():
	def __init__(self):
		self.data = pd.read_csv("diabetes.csv")

	#Supervised learning
	def minimumDistanceClassifier(self, data: pd.DataFrame, featuresList):
		features = data[featuresList].to_numpy()
		labels = data["Outcome"].to_numpy()
		features_train, features_test, labels_train, labels_test = train_test_split(features, labels, test_size=0.2)
		#Separating the features based on their output
		mean0, mean1 = [], []
		for index, value in enumerate(features_train):
			if(labels_train[index] == 0):
				mean0.append(value)
			else:
				mean1.append(value)
		#Calculating the mean of those features
		mean0, mean1 = np.array(mean0).reshape(len(featuresList), len(mean0)), np.array(mean1).reshape(len(featuresList), len(mean1))
		mean_features_0, mean_features_1 = [], []
		for feature in mean0:
			mean_features_0.append(np.array(feature).mean())
		for feature in mean1:
			mean_features_1.append(np.array(feature).mean())
		mean_features_0, mean_features_1 = np.array(mean_features_0), np.array(mean_features_1)
		labels_pred = []
		for feature in features_test:
			dist0 = np.linalg.norm(mean_features_0 - feature)
			dist1 = np.linalg.norm(mean_features_1 - feature)
			if dist0 < dist1:
				labels_pred.append(0)
			else:
				labels_pred.append(1)
		labels_pred = np.array(labels_pred)
		print("\n##### Minimum Distance Classifier Predictions[HandWritten] #####\n")
		print(labels_pred)
		accuracy = accuracy_score(labels_pred, labels_test)
		print(f"Accuracy Score of Minimum distance classifier Model[supervised]: {accuracy}")

	#Unsupervised learning [no labels are used here]
	def kMeansClustering(self, data: pd.DataFrame, featuresList, n_iterations=300):
		features = data[featuresList].to_numpy()
		labels = data["Outcome"].to_numpy()
		features_train, features_test, _ , labels_test = train_test_split(features, labels, test_size=0.2)
		#Assigning initial random values between maxima and minima of training data
		maxima = np.max(features_train)
		minima = np.min(features_train)
		mean0 = rd.randrange(minima, maxima)
		mean1 = rd.randrange(minima,maxima)
		#for each iteration calculating mean of features and updating old mean till convergence
		while(n_iterations):
			features_0, features_1 = [], []
			for feature in features_train:
				m = np.array(feature).mean()
				dist0 = abs(m-mean0)
				dist1 = abs(m-mean1)
				if dist0 < dist1:
					features_0.append(m)
				else:
					features_1.append(m)
			new_mean0 = np.array(features_0).mean()
			new_mean1 = np.array(features_1).mean()
			if(abs(new_mean0-mean0)<1 and abs(new_mean1-mean1)<1):
				break
			else:
				mean0, mean1 = new_mean0, new_mean1
			n_iterations-=1
		labels_pred = []
		for feature in features_test:
			m = np.array(feature).mean()
			dist0 = abs(mean0-m)
			dist1 = abs(mean1-m)
			if dist0 < dist1:
				labels_pred.append(0)
			else:
				labels_pred.append(1)
		labels_pred = np.array(labels_pred)
		print("\n##### KMeans Cluster Predictions[HandWritten] #####\n")
		print(labels_pred)
		accuracy = accuracy_score(labels_pred, labels_test)
		print(f"Accuracy Score of KMeans clustering Model[unsupervised]: {accuracy}")
models = UserFunModels()
models.minimumDistanceClassifier(models.data, featuresList=["Glucose", "Insulin"])
models.kMeansClustering(models.data, featuresList=["Glucose"])