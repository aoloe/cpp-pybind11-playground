# Providing an API for manipuling a document

Demoing how to provide an API that let's a Python script manipulate a document strucuture in the c++ application.

- The application is called "Sample".
- Its API for Python is called "ScripterAPI"
- The `Document` data structure (and its "sub" elements) contains the data of the c++ appplication.
- From Python you import a module called "Sample" and access the document as `Sample.document`

~~~.sh
$ mkdir build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11/share/cmake/pybind11 ..
$ make
$ ./scripting
~~~

## notes

thinking loud... since thinking silently did not give me a solution yet...

i'm prototyping an scripter engine for an application wich has documents. i want to be able to pass the current document to the scripting engine, let the script modify the main document and finally let the main c++ code continue its work with the document.

there are cases, where i will start the scripter engine without any current document existing. and in other cases the scripter engine can open new documents by itself and then (probbably) still be able to reference the current open document

i'm now looking for a data structure that would allow me to pass my document. if i use "naked" pointers i can get there:

http://cpp.sh/3pasg

```.cpp
#include <iostream>

class B
{
    public:
        int c{0};
        void print() {std::cout << c << std::endl;}
};

class A
{
    public:
        void setB(B *bb) {b = bb;}
        void changeC() {b->c = 6;}
    private:
        B *b;
};


int main()
{
    B *b = new B();
    A a;
    a.setB(b);
    a.changeC();
    b->print();
}
```

 while thinking about ways to avoid naked pointers, i came to idea of using references, but that fails to compile, since the reference to the document object (the b in the code) is not allowed to be undefined in A (which was very obvious to me, when i saw the error thrown at me)

https://framabin.org/?6c95725601855806#Ys80zuKzx9wllGoYXgTpAXrnl5XH/8y4JfgJY5huanU=

```.cpp
class B
{
    int c{0};
};

class A
{
    public:
        void setB(B &bb) {b = bb;}
    private:
        B &b;
};


int main()
{
    B b;
    A a;
    a.setB(b);
}
```

any idea what would be a good c++11/14 data structure for this type of code?

... i'm trying to do something with unique_ptr ... not sure if this is a good way...

[dbedrenko] a-l-e:  You should pass the document by reference, but you don't need to store it as a member in your Script engine

Just do `Document myDoc; myScriptEngine.processDocument(myDoc);`

The signature looks like this: `ScriptEngine::processDocument(Document& doc)`

[a-l-e] dbedrenko, i have to check that idea...

 mmm... no, i fear that it won't work. i fear that i have to store it in a class if i want to have the whole API included in a python class...

and generally, it would break a bit the design...

[dbedrenko] a-l-e:  With pointers there is no copy. It's one object, with multiple pointers pointing at that object

[a-l-e] ok passing a unique_ptr to pybind11 does not work, at least not without further analysis of the problem... i will re-ask my question later and focus on having something that works, before trying to further improve the design.

[dbedrenko] a-l-e:  you're welcome. Keep in mind you shouldn't pass unique_ptr as a parameter unless you want to pass ownership of that object to that function

You should think about who owns the document, is it one class (unique_ptr), do multiple classes own it (shared_ptr)? Or one class owns it and others will get access to it (unique_ptr, and you pass raw pointers or references to give access)

[a-l-e] the document is owned by the main application... but during the time the script runs, the main app is not allowed to do any change on the document itself.

[a-l-e] i don't have a huge experience with c++ and this is probably the most complex code i have written in c++...

[dbedrenko] Is the main application Python or C++? By "own", in C++ it means a *class* owns it

[a-l-e] the main application is c++

(it's a c++ / qt application that can be scripted through python; the application (scribus) and the scripting already exist and i'm working on a new scripter engine)
