#include "pymath.h"

PyObject * pymath_divides(PyObject *self, PyObject *args)
{
	long long n, d;
	
	if (!PyArg_ParseTuple(args, "LL", &d, &n))
	{
		return NULL;
	}
	
	if (n % d)
	{
		return Py_BuildValue("i", 0);
	}
	
	else
	{
		return Py_BuildValue("i", 1);
	}
}
