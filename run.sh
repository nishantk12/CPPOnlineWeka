#!/bin/bash
clear

##########################################################################
# VARIABLES TO BE SET BY THE USER
export JAVA_HOME=/usr/lib/jvm/java-8-oracle
export WORK_DIRECTORY=/home/ni/Robotics/CPP/Robotics/
export WEKA_HOME=/opt/weka-3-6-13
##########################################################################

# EXTENDED VARIABLES
export LIBPATH=$JAVA_HOME/jre/lib/amd64/server/
export LD_LIBRARY_PATH=$JAVA_HOME/jre/lib/amd64/:$JAVA_HOME/jre/lib/amd64/server
export CLASSPATH=$CLASSPATH:$WORK_DIRECTORY:$WEKA_HOME/weka.jar
export PATH=$PATH:$WEKA_HOME/weka.jar

if [ -z ${WEKA_HOME} ]; 
	then 
		echo "ERROR: WEKA_HOME is not set"; 
		exit 1;
fi

if [ -z ${JAVA_HOME} ]; 
	then 
		echo "ERROR: JAVA_HOME is not set"; 
		exit 1;
fi

if [ -z ${WORK_DIRECTORY} ]; 
	then 
		echo "ERROR: WORK_DIRECTORY is not set"; 
		exit 1;
fi

if [ -a GenericClassifierWeka.class ]
	then
		rm GenericClassifierWeka.class		
fi
javac GenericClassifierWeka.java

if [ -a executable ]
	then
		rm executable	
fi

if  [ ! -f /usr/include/jni.h ] 
then
	ln -s /usr/lib/jvm/java-8-oracle/include/jni.h /usr/include/jni.h
fi

if  [ ! -f /usr/include/jni_md.h ]	
then
	ln -s /usr/lib/jvm/java-8-oracle/include/linux/jni_md.h /usr/include/jni_md.h
fi

if  [ ! -f /usr/include/GenericClassifierWeka.h ]	
then
	echo "inside if"
	ln -s ${PWD}/GenericClassifierWeka.h /usr/include/GenericClassifierWeka.h
fi

g++ MultiClass.cpp -o executable -L${LIBPATH} -ljvm

./executable
