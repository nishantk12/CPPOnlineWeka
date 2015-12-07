#include <GenericClassifierWeka.h>
using namespace std;	

int main(int n, char *argv[]) {
	
	GenericClassifierWeka classifier;
	
	char modelFilePath[] = "M5P-magic04.model";
	char propertiesFilePath[] = "magic04.properties";
	int indexOfClass = 11;


	try{
		classifier.loadClassifier(modelFilePath,propertiesFilePath,indexOfClass);
		
		double p1[] = {12.9712,11.1602,2.0952,0.747,0.4297,-14.5735,6.7776,10.4579,71.9552,194.357};
		int sizeOfVector = sizeof(p1)/sizeof(*p1);
		double classOfInstance = classifier.classify(p1,sizeOfVector);
		cout << "Class of instance 1: " << classOfInstance << endl;

		
		double p2[] = {155.856,95.4667,3.7478,0.1004,0.0535,-211.837,100.209,-85.8418,50.3906,254.759};
		sizeOfVector = sizeof(p2)/sizeof(*p2);
		vector<double> a2(p2, p2+sizeOfVector);
		classifier.classify(a2);
		classOfInstance = classifier.classify(a2);
		cout << "Class of instance 2: " << classOfInstance << endl;
		
		return -1;
	}catch(const char* ErrorMsg){
		cerr << ErrorMsg << endl;
	}
}


