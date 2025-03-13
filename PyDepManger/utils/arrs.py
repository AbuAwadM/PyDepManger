from numpy import ndarray , full , int32

from ..cpylibs import _add_arr

def add_arr(arr1 : ndarray, arr2 : ndarray):
    narr1 = len(arr1.flatten())
    narr2 = len(arr2.flatten())
    if narr1 == narr2:
        return _add_arr(arr1,arr2,narr1,full(narr1,0,int32))
    