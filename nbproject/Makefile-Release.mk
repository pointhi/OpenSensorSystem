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
	${OBJECTDIR}/src/OssGroups.o \
	${OBJECTDIR}/src/OssNodeType.o \
	${OBJECTDIR}/src/OssRootNode.o \
	${OBJECTDIR}/src/OssSpecialFunctions.o \
	${OBJECTDIR}/src/OssTree.o \
	${OBJECTDIR}/src/i2c/I2cHost.o \
	${OBJECTDIR}/src/i2c/I2cSlave.o \
	${OBJECTDIR}/src/i2c/I2cSmbSlave.o \
	${OBJECTDIR}/src/lua/LuaSensorScript.o \
	${OBJECTDIR}/src/sensor/OssSensor.o


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
LDLIBSOPTIONS=-ltinyxml2 -llua5.2 -lluabind

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOpenSensorSystem.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOpenSensorSystem.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOpenSensorSystem.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/OssGroups.o: src/OssGroups.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/OssGroups.o src/OssGroups.cpp

${OBJECTDIR}/src/OssNodeType.o: src/OssNodeType.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/OssNodeType.o src/OssNodeType.cpp

${OBJECTDIR}/src/OssRootNode.o: src/OssRootNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/OssRootNode.o src/OssRootNode.cpp

${OBJECTDIR}/src/OssSpecialFunctions.o: src/OssSpecialFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/OssSpecialFunctions.o src/OssSpecialFunctions.cpp

${OBJECTDIR}/src/OssTree.o: src/OssTree.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/OssTree.o src/OssTree.cpp

${OBJECTDIR}/src/i2c/I2cHost.o: src/i2c/I2cHost.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/i2c
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/i2c/I2cHost.o src/i2c/I2cHost.cpp

${OBJECTDIR}/src/i2c/I2cSlave.o: src/i2c/I2cSlave.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/i2c
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/i2c/I2cSlave.o src/i2c/I2cSlave.cpp

${OBJECTDIR}/src/i2c/I2cSmbSlave.o: src/i2c/I2cSmbSlave.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/i2c
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/i2c/I2cSmbSlave.o src/i2c/I2cSmbSlave.cpp

${OBJECTDIR}/src/lua/LuaSensorScript.o: src/lua/LuaSensorScript.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/lua
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/lua/LuaSensorScript.o src/lua/LuaSensorScript.cpp

${OBJECTDIR}/src/sensor/OssSensor.o: src/sensor/OssSensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/sensor
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/usr/include/lua5.2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/sensor/OssSensor.o src/sensor/OssSensor.cpp

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
