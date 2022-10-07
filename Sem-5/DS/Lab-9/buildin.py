import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score

class BuildInModels():
	def __init__(self):
		self.data = pd.read_csv("diabetes.csv")

	#Supervised learning [used labels here]
	def minimumDistanceClassifier(self, data: pd.DataFrame, featuresList):
		#choosing glucose content as a feature
		features = data[featuresList].to_numpy()
		#outcomes as the labels
		labels = data["Outcome"].to_numpy()
		#splitting the features and labels into training and testing set 80, 20% respectively
		features_train, features_test, labels_train, labels_test = train_test_split(features, labels, test_size=0.2)
		#initializing the minimum distance classifier also known as nearest centroid classifier
		clf = KNeighborsClassifier(n_neighbors=1, weights="distance")
		#fitting with training data
		clf.fit(features_train, labels_train)
		#predicting with the test data
		labels_pred = clf.predict(features_test)
		print("\n##### Minimum Distance Classifier Predictions[KNearestNeighbor=1 Model] #####\n")
		print(labels_pred)
		accuracy = accuracy_score(labels_pred, labels_test)
		print(f"Accuracy Score of Minimum distance classifier Model[supervised]: {accuracy}")

	#Unsupervised learning [no labels are used here]
	def kMeansClustering(self, data: pd.DataFrame, featuresList):
		#choosing glucose content as a feature
		features = data[featuresList].to_numpy()
		#just for accuracy prediction
		labels = data["Outcome"].to_numpy()
		#splitting features into train and test data 80 and 20 % respectively
		features_train, features_test, _ , labels_test = train_test_split(features,labels, test_size=0.2)
		#initializing KMeans cluster with 2 clusters and fitting it with features_train
		kmeans = KMeans(n_clusters=2, random_state=0).fit(features_train)
		#predicting the results
		labels_pred = kmeans.predict(features_test)
		print("\n##### KMeans Cluster Predictions #####\n")
		print(labels_pred)
		accuracy = accuracy_score(labels_pred, labels_test)
		print(f"Accuracy Score of KMeans clustering Model[unsupervised]: {accuracy}")

models = BuildInModels()
models.minimumDistanceClassifier(models.data, featuresList=["Glucose", "Insulin", "Age"])
models.kMeansClustering(models.data, featuresList=["BloodPressure", "BMI", "Glucose"])