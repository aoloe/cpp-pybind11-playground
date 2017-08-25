# Using classes

~~~.sh
$ mkdir build
$ cmake -DPYBIND11_DIR=/home/ale/src/pybind11 -DPYTHON_EXECUTABLE:FILEPATH=/usr/bin/python3 ..
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

