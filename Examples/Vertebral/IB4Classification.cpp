#include <GenericClassifierWeka.h>
using namespace std;	

int main(int n, char *argv[]) {
	
	GenericClassifierWeka classifier;
	
	char modelFilePath[] = "IB4-Vertebral.model";
	char propertiesFilePath[] = "Vertebral.properties";
	int indexOfClass = 7;


	try{
		classifier.loadClassifier(modelFilePath,propertiesFilePath,indexOfClass);
		
		double p1[] = {39.05695098,10.06099147,25.01537822,28.99595951,114.4054254,4.564258645};
		int sizeOfVector = sizeof(p1)/sizeof(*p1);
		double classOfInstance = classifier.classify(p1,sizeOfVector);
		cout << "Class of instance 1: " << classOfInstance << endl;

		
		double p2[] = {56.53505139,14.37718927,44.99154663,42.15786212,101.7233343,25.77317356};
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


