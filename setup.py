from setuptools import setup, Extension
import numpy

mod1 = Extension(
    'PyDepManger.cpylibs.helloworld',  
    sources=['PyDepManger/cpylibs/helloworld.c'],  
)
mod2 = Extension(
    'PyDepManger.cpylibs.AddArr',  
    sources=['PyDepManger/cpylibs/AddArr.c'],  
)

setup(
    name='PyDepManger',
    ext_modules=[mod1,mod2],
    include_dirs=[numpy.get_include()]

)

'''
python setup.py build_ext --inplace
'''
