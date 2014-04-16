
SETUP = python2 setup.py
SRC = src/pymath.c src/pymath.h src/divides.c
MOD = pymath.so
TDIR = build/test
TEXE = ${TDIR}/tBI.x
TOBJ = ${TDIR}/testBigInt.o

all: clean ${MOD}

full:
	${SETUP} build

${MOD}: ${SRC}
	${SETUP} build_ext --inplace

install:
	${SETUP} install

test: ${TEXE}
	@echo
	@echo "running Big Int tests:"
	@echo
	@./${TDIR}/tBI.x
	@echo

${TDIR}/tBI.x: ${TDIR}/testBigInt.o ${TDIR}/BigInt.o
	gcc -o $@ $^

${TDIR}/testBigInt.o: test/testBigInt.c src/BigInt.h
	mkdir -p build/test
	gcc -c -o $@ $<

${TDIR}/BigInt.o: src/BigInt.c src/BigInt.h
	mkdir -p build/test
	gcc -c -o $@ $<

clean:
	@echo "cleaning module..."
	${SETUP} clean --all
	rm -f pymath.so
	@echo
	@echo "cleaning build directory"
	rm -rf build
	@echo
	@echo "All Done!"
	@echo

	
