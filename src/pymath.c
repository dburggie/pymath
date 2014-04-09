#include "pymath.h"


static PyMethodDef pymathMethods[] = 
{
	{ "divides", pymath_divides, METH_VARARGS, 
			"Returns true if first arg divides second arg." },
	
	//...
	
	{ NULL, NULL, 0, NULL }
	
};

PyMODINIT_FUNC
initpymath(void)
{
	(void) Py_InitModule("pymath", pymathMethods);
}

