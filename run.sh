#!/bin/bash
clear
# This is a file to do the initial setup of the code. Before running this 
# file, the user needs to set the following two variables in the system.
# With the variables of LIBPATH and CLASSPATH. LIBPATH and CLASSPATH
# variables are needed for any further use of the code, as an include. The
# execution of this file results in creation of sym-links in the directory:
# /usr/include/ which means that whenever this code is compiled the JNI lib
# files are not needed to be included in the G++ command.
#
# Wheras if the code is to be used then the compilation should be supplied 
# with two library parameters : -ljvm and -L{$JAVA_HOME/jre/lib/amd64/server/}
#
##########################################################################
# VARIABLES TO BE SET BY THE USER
export JAVA_HOME=/usr/lib/jvm/java-8-oracle
export WEKA_HOME=/opt/weka-3-6-13
##########################################################################

# EXTENDED VARIABLES
export WORK_DIRECTORY=${PWD}
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
		ln -s ${PWD}/GenericClassifierWeka.h /usr/include/GenericClassifierWeka.h
fi

g++ SampleDriver.cpp -o executable -L${LIBPATH} -ljvm

./executable
