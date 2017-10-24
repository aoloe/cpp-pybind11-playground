# Modules with classes

The `pet` module provides the `Dog` and `Cat` classes.

Both classes have the `getName()` and `setName()` class functions.

`Dog` is added to the Python module with a getter and a setter.

`Cat` is more _pythonic_ and can access the C++ accessor as a property.

~~~.sh
$ mkdir build
$ cmake -Dpybind11_DIR=~/bin/pybind11/share/cmake/pybind11 ..
$ make
$ python3
>>> import pet
>>> a = pet.Dog('Flip')
>>> print(a)
<pet.Pet object at 0x10cd98060>
>>> a.getName()
'Flip'
>>> a.setName('Flop')
>>> a.getName()
'Flop'
>>> b = pet.Cat('Fox')
>>> b.name
'Fox'
>>> b.name = 'Fix'
>>> b.name
'Fix'
~~~

