# Modules with classes

The `pet` module provides the `Dog` and `Cat` classes.

Both C++ classes have a `getName()` and a `setName()` class functions.

The `Dog` and `Cat` classes are exposed in a different way to the Python code:

- `Dog` is added to the Python module with a getter and a setter.
- `Cat` is more _pythonic_ and provides access to the C++ accessors as a property.

In C++, both classes are defined in the exact same way, but:

- the `get` and `set` function of the `Dog` class are bound to functions of the same name in Python
- for the `Cat` the `name` class property on the Python side is _using_ the C++ getter and setter to read and write the `name` value.

```py
py::class_<Dog>(m, "Dog")
.def(py::init<const std::string &>())
.def("setName", &Dog::setName, "Setting the dog's name")
.def("getName", &Dog::getName), "Getting the dog's name";

py::class_<Cat>(m, "Cat")
.def(py::init<const std::string &>())
.def_property("name", &Cat::getName, &Cat::setName, "The cat name");
```

You can compile and import the `pet` module, containing a `Dog` and a `Cat` classes:

```.sh
$ mkdir build
$ cmake ..
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
```
