
SRC = src/*
MOD = pymath.so

all: ${MOD}

full:
	@python2 setup.py build

${MOD}: ${SRC}
	@python2 setup.py build_ext --inplace

install:
	@python2 setup.py install	

clean:
	@echo "cleaning..."
	@python2 setup.py clean --all
	@rm pymath.so

	
