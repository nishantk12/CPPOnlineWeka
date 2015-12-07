// Sample Driver Program

#include "GenericClassifierWeka.h"
using namespace std;	
// This an example driver program
// demonstrating the usage of the header file
// GenericClassifierWeka.h
// This program assumes that the model, and the property file are
// allready generated and stored at a particular location.
// The Driver program demonstartes the usage of the two methods
// loadClassifier and classify.

int main(int n, char *argv[]) {
	
	// Object creation
	GenericClassifierWeka classifier;
	
	// Example usage of the loadClassifier Method
	classifier.loadClassifier("/<MyDirectory>/<MyModel>",
							 "/<MyDirectory>/<MyPropertyFile>",
							 <classindex>);

    // This is just a sample vector please change the values as per your model
	double firstSampleVector[] = {115.264,14.0075,2.854,0.7544,0.4136,-88.2076,-117.486,8.4777,28.01,336.991};
	int sizeOfVector = sizeof(firstSampleVector)/sizeof(*firstSampleVector);
	// Example usage of the classify method using a double array as input
	double classOfInstance = classifier.classify(firstSampleVector,sizeOfVector);

	cout << "Class of the first instance: " << classOfInstance << endl;

    // You may fill in with values that correspond to your model
	double p2[] = {12.9712,11.1602,2.0952,0.747,0.4297,-14.5735,6.7776,10.4579,71.9552,194.357};

	// A sample vector 
	vector<double> sampleVector(p2, p2+sizeOfVector);

	//// Example usage of the classify method using a double vector as input
	classifier.classify(sampleVector);
	classOfInstance = classifier.classify(sampleVector);


	cout << "Class of the second instance : " << classOfInstance << endl;

	return -1;
}


