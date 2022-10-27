CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=main

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/veiculo.o ${BUILD_DIR}/caminhao.o ${BUILD_DIR}/caminhao_autonomo.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${TARGET}

${BUILD_DIR}/veiculo.o: ${INCLUDE_DIR}/veiculo.hpp ${SRC_DIR}/veiculo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/veiculo.cpp -o ${BUILD_DIR}/veiculo.o

${BUILD_DIR}/caminhao.o: ${INCLUDE_DIR}/caminhao.hpp ${SRC_DIR}/caminhao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/caminhao.cpp -o ${BUILD_DIR}/caminhao.o

${BUILD_DIR}/caminhao_autonomo.o: ${INCLUDE_DIR}/caminhao_autonomo.hpp ${SRC_DIR}/caminhao_autonomo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/caminhao_autonomo.cpp -o ${BUILD_DIR}/caminhao_autonomo.o
	
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/veiculo.hpp ${INCLUDE_DIR}/caminhao.hpp ${INCLUDE_DIR}/caminhao_autonomo.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

debug:
	${CC} ${CFLAGS} -g -I ${INCLUDE_DIR} ${SRC_DIR}/*.cpp -o ${TARGET}

clean:
	rm -f ${BUILD_DIR}/*.o ${BUILD_DIR}/${TARGET}
