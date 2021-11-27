#include "codelift.h"

char encryptfunc_docs[] = "RSA decrypt/encrypt with private key";
char decryptfunc_docs[] = "RSA-OEAP decrypt with private key";


PyMethodDef cdmapi_funcs[] = {
	{
		"decrypt",
		(PyCFunction)_decrypt,
		METH_VARARGS,
		decryptfunc_docs
	},{
		"encrypt",
		(PyCFunction)_encrypt,
		METH_VARARGS,
		decryptfunc_docs},
	{	NULL}
};

char cdmapimod_docs[] = "CMD API module for chrome 2209.";
char cdmapimod_name[] = "cdmapi";

#if PY_MAJOR_VERSION >= 3

PyModuleDef cdmapi_mod = {
	PyModuleDef_HEAD_INIT,
	cdmapimod_name,
	cdmapimod_docs,
	-1,
	cdmapi_funcs,
	NULL,
	NULL,
	NULL,
	NULL
};

extern "C" {
	PyMODINIT_FUNC PyInit_cdmapi(void)
	{
		return PyModule_Create(&cdmapi_mod);
	}
}
#endif
