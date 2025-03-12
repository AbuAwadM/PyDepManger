from setuptools import setup, Extension
import numpy

mod1 = Extension(
    'PyDepManger.cpylibs.helloworld',  
    sources=['PyDepManger/cpylibs/helloworld.c'],  
)

setup(
    name='PyDepManger',
    ext_modules=[mod1],
    include_dirs=[numpy.get_include()]

)

'''
python setup.py build_ext --inplace
'''
