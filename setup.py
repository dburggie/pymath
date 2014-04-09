from distutils.core import setup, Extension

pymathmodule = Extension('pymath',
		sources = [
			'src/pymath.c',
			'src/divides.c'
		])

setup (name = 'pymathmodule',
       version = '1.00',
       description = 'Provides fast math functions.',
       ext_modules = [pymathmodule])
