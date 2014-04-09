
SETUP = python2 setup.py
SRC = src/pymath.c src/pymath.h src/divides.c
MOD = pymath.so

all: clean ${MOD}

full:
	${SETUP} build

${MOD}: ${SRC}
	${SETUP} build_ext --inplace

install:
	${SETUP} install

clean:
	@echo "cleaning..."
	${SETUP} clean --all
	@rm -f pymath.so

	
