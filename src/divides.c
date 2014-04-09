#include "pymath.h"

static PyObject * pymath_divides(PyObject *self, PyObject *args)
{
	long long numerator, denominator;
	
	if (!PyParseTuple(args, "L", &numerator, &denominator))
	{
		return NULL;
	}
	
	if (numerator % denominator)
	{
		return Py_BuildValue("i", 0);
	}
	
	else
	{
		return Py_BuildValue("i", 1);
	}
}
