#include "GenericClassifierWeka.h"
using namespace std;	

int main(int n, char *argv[]) {
	
	GenericClassifierWeka classifier;
	
	classifier.loadClassifier("/home/ni/Robotics/final1/Robotics/modelFiles/M5P-magic04.model",
				 "/home/ni/Robotics/final1/Robotics/propertiesFiles/magic04.properties",11);
	//double values[] = {4.8,3.4,1.6,0.2};
	double p1[] = {115.264,14.0075,2.854,0.7544,0.4136,-88.2076,-117.486,8.4777,28.01,336.991};
	int sizeOfVector = sizeof(p1)/sizeof(*p1);
	double classOfInstance = classifier.classify(p1,sizeOfVector);
	cout << "Class of instance 1: " << classOfInstance << endl;

	double p2[] = {12.9712,11.1602,2.0952,0.747,0.4297,-14.5735,6.7776,10.4579,71.9552,194.357};
	vector<double> a2(p2, p2+sizeOfVector);
	classifier.classify(a2);
	classOfInstance = classifier.classify(a2);
	cout << "Class of instance 2: " << classOfInstance << endl;

	return -1;
}


