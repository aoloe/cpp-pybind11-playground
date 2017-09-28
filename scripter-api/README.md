# Providing an API for manipuling a document

A Scripter engine that provides Python scripting to a C++ Sample application. The main use of the scripting is for modifying the current document in the C++ application.

This sample application shows a sane data structure for a sample document and how to provide an API to it through pybind11

- The `Sample` application has a `Document` data structure that contains margins and pages:  

  ```
  sample
    .document
      .margin
        .top
        .right
        .bottom
        .left
      .page[]
        .margin
          ...
   ```

- The `ScripterAPI` API has a `Document` structure that provides acces to the current C++ `Document` through a Python module called `scripterapi`.
- When the scripter is called, there could be no current document (no document open).
- The scripter should be able to modify the current document (and open / create documents).
- From the scripter it must be possible to modify the document in the Sample application.
- While the scripter is running, the Sample application cannot modifiy the document.

~~~.sh
$ mkdir build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11/share/cmake/pybind11 ..
$ make
$ ./scripting
~~~

## notes

- if we ever want to check how it works with `unique_ptr`s, this is a good article on how to add a `unique_ptr` as a private member in a class: <https://katyscode.wordpress.com/2012/10/04/c11-using-stdunique_ptr-as-a-class-member-initialization-move-semantics-and-custom-deleters/>


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
