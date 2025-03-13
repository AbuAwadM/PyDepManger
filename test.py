from PyDepManger import PyDepManger
import numpy as np

PyDepManger.one()
# Generate two random arrays with the same length
print(PyDepManger.two(np.random.rand(10),np.random.rand(10)))
