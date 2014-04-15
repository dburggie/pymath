
SETUP = python2 setup.py
SRC = src/pymath.c src/pymath.h src/divides.c
MOD = pymath.so
TEXC = build/test/tBI.x
TOBJ = build/test/testBigInt.o

all: clean ${MOD}

full:
	${SETUP} build

${MOD}: ${SRC}
	${SETUP} build_ext --inplace

install:
	${SETUP} install

test: ${TEXC}
	./build/test/tBI.x

build/test/tBI.x: build/test/testBigInt.o
	gcc -o $@ $< build/BigInt.o

build/test/testBigInt.o: test/testBigInt.c src/BigInt.c src/BigInt.h
	mkdir -p build/test
	gcc -c -o $@ $<
	gcc -c -o build/BigInt.o src/BigInt.c

clean:
	@echo "cleaning..."
	${SETUP} clean --all
	@rm -f pymath.so

	
