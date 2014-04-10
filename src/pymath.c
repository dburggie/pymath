#include "pymath.h"


PyMethodDef pymathMethods[] = 
{
	
	{ "divides", pymath_divides, METH_VARARGS, 
			"Returns true if first arg divides second arg." },
	
	{ "pow", pymath_pow, METH_VARARGS,
			"Returns (a^b) mod c." },
	
	//...
	
	{ NULL, NULL, 0, NULL }
	
};

PyMODINIT_FUNC
initpymath(void)
{
	(void) Py_InitModule("pymath", pymathMethods);
}

