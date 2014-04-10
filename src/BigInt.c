
#include "pymath.h"

/* Put this in the header?
extern PyTypeObject BigIntT;
extern PyMethodDef BigIntMethods[];
typedef struct {
	PyObject_HEAD
	
	// add fields here
	
} BigIntObj;
*/

PyTypeObject BigIntT =
{
	PyObject_HEAD_INIT(NULL)
	0,
	"bigint.BigInt",
	sizeof(BigIntObj),
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	Py_TPFLAGS_DEFAULT,
	"Big Integer",
}

PyMethodDef BigIntMethods[] = { {NULL} };

#ifndef PyMODINIT_FUNC
#define PyMODINIT_FUNC void
#endif

PyTypeObject * initBigInt(void)
{
	
	BigIntT.tp_new = PyType_GenericNew;
	if (PyType_READY( &BigIntT ) < 0)
	{
		return NULL; 
	}
	
	
	PyINCREF(&BigIntT);
	
	return &BigIntT;
	
	
}

