#include "pymath.h"

//returns (b^e mod m)
//int pow(int base, int exponent, int modulus);
PyObject * pymath_pow(PyObject *self, PyObject *args)
{
	
	long long b, e, m;
	
	if (!PyArg_ParseTuple(args, "LLL", &b, &e, &m))
	{
		return NULL;
	}
	
	long long a = 1;
	
	while (e > 0)
	{
		if (e % 2)
		{
			a = (a * b) % m;
		}
		
		b = (b * b) % m;
		e = e / 2;
	}
	
	return Py_BuildValue("L", a);
	
}
