# CPPOnlineWeka
Contibutors:
------------
    Arunukumar Subramanian (arunsubmn@gmail.com)
    Milind Jindal (milindjindal@gmail.com)
    Nishant Kumar (nishantk12@gmail.com
 
ONLINE WEKA:
version 1.0
 
 
FILES:
1. GenericClassifierWeka.h
    This is the header file, containing a CPP class, which offers a method for loading of a WEKA Model file and 2 methods to classify instances.
    The containing class creates a JVM environment and executes the GenericClassifierWeka.java class
2. GenericClassifierWeka.java
    This is a Java class that is loaded into the JVM and provides the a static method to load the model file from the CPP environment and another static method to classify the CPP Vector instance.
3. run.sh
	This shell script sets up all the environment variables needed for the GenericClassifierWeka module to work. User should make sure that they edit
	this file according to their development environment.	
4. SampleDriver.cpp
	This is a sample Driver Program that demonstrates the usage of the header file "GenericClassifierWeka.h"
	
REQUIREMENTS:
1. A c++ compiler should be installed. (Eg g++)
2. Assumes that that system has proper Java Development Environment Set up (Eg JVM an all).
3. RAM 2 GB
4. JDK Version 1.6 and higher
5. The system has Weka installed and the module has developed has been pre-trained.

LIMITATIONS:
	Works only on Linux Systems
	
HOW TO INSTALL:
	Download the entire git folder, and change the run.sh file as per your system configurations.
	Care must be taken to provide the correct Java ClassPath, working directory etc. This could be easily 
	figured out if you go through the run.sh file. 
	Once the run.sh file executes without throwing up any errors, you are all set to use the header file 
	GenericClassifierWeka.h into your C++ code and use the interfaces that that the library provides.
	
INTERFACES:
	loadClassifier :  The method loadClassifier provides an interface to load the classifier
                      in your driver program. The class takes 3 inputs namely:
		              inputModelFilePath : the path of your Weka model 
                      inputPropertyFilePath : The path of your propertyFile, weka needs the propertyFile 
                      to match your attributes to its Classification model
                      indexOfClass : This indicates the index of the class in the feature vector, weka module uses 
                      this class index to generate predicted output.
	
	classify : The method classify is overloaded to accept 
		 vector and array inputs. The method takes
		a double array ( along with it's size) or a
	        vector and returns the class corresponding 
                to the feature vector ( or array).
                The method throws 3 exceptions namely,
                No data in the vector, JavaDouble Array Creation Failed,
                class of the vector could not be found.
                Example of method call - classify(inputVector);
------------------------------------------------------------------------------------------------------------
Please refer to the sample driver program and the Examples folder to gain an insight
of how to use this library.
	
This is just a beta version of the Read-me file. Shall come up with a one
with a better insight shortly.
