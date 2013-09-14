#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1288313479/OssRootNode.o \
	${OBJECTDIR}/_ext/1288313479/OssSpecialFunctions.o \
	${OBJECTDIR}/_ext/1288313479/OssTree.o \
	${OBJECTDIR}/_ext/1303538962/I2cHost.o \
	${OBJECTDIR}/_ext/1303538962/I2cSlave.o \
	${OBJECTDIR}/_ext/1303538962/I2cSmbSlave.o \
	${OBJECTDIR}/src/OssGroups.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOpenSensorSystem.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOpenSensorSystem.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOpenSensorSystem.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/_ext/1288313479/OssRootNode.o: /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/OssRootNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1288313479
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1288313479/OssRootNode.o /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/OssRootNode.cpp

${OBJECTDIR}/_ext/1288313479/OssSpecialFunctions.o: /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/OssSpecialFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1288313479
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1288313479/OssSpecialFunctions.o /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/OssSpecialFunctions.cpp

${OBJECTDIR}/_ext/1288313479/OssTree.o: /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/OssTree.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1288313479
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1288313479/OssTree.o /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/OssTree.cpp

${OBJECTDIR}/_ext/1303538962/I2cHost.o: /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/i2c/I2cHost.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1303538962
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1303538962/I2cHost.o /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/i2c/I2cHost.cpp

${OBJECTDIR}/_ext/1303538962/I2cSlave.o: /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/i2c/I2cSlave.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1303538962
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1303538962/I2cSlave.o /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/i2c/I2cSlave.cpp

${OBJECTDIR}/_ext/1303538962/I2cSmbSlave.o: /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/i2c/I2cSmbSlave.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1303538962
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1303538962/I2cSmbSlave.o /home/thomas/Dokumente/Projekte/robotic/OpenSensorSystem/src/i2c/I2cSmbSlave.cpp

${OBJECTDIR}/src/OssGroups.o: src/OssGroups.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/OssGroups.o src/OssGroups.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOpenSensorSystem.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
