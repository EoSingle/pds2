CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=main

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/criatura.o ${BUILD_DIR}/peixe.o ${BUILD_DIR}/polvo.o ${BUILD_DIR}/aquario.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${TARGET}

${BUILD_DIR}/criatura.o: ${INCLUDE_DIR}/criatura.hpp ${SRC_DIR}/criatura.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/criatura.cpp -o ${BUILD_DIR}/criatura.o

${BUILD_DIR}/peixe.o: ${INCLUDE_DIR}/peixe.hpp ${SRC_DIR}/peixe.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/peixe.cpp -o ${BUILD_DIR}/peixe.o

${BUILD_DIR}/polvo.o: ${INCLUDE_DIR}/polvo.hpp ${SRC_DIR}/polvo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/polvo.cpp -o ${BUILD_DIR}/polvo.o
	
${BUILD_DIR}/aquario.o: ${INCLUDE_DIR}/aquario.hpp ${SRC_DIR}/aquario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/aquario.cpp -o ${BUILD_DIR}/aquario.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/criatura.hpp ${INCLUDE_DIR}/peixe.hpp ${INCLUDE_DIR}/polvo.hpp ${INCLUDE_DIR}/aquario.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

debug:
	${CC} ${CFLAGS} -g -I ${INCLUDE_DIR} ${SRC_DIR}/*.cpp -o ${TARGET}

clean:
	rm -f ${BUILD_DIR}/*.o ${BUILD_DIR}/${TARGET}
