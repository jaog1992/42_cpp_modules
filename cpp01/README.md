##ex00
The principal concept is that an object made with new is created o execution time on the heap.
It is the programmer responsability to use delete the memory of the object once it is not 
necessary.

In the other hand an object created as an instance of a class without new is created on 
compilation time on the heap. Thus the destructor is called automatically once the function ends.
This can be seen when randomchump dies while the ones called in the main function only die 
after the main ends.

##ex01
Same principal as before, but more complex main function.

##ex02
A reference acts as an alias for the referenced variable, allowing direct access 
to the original variable. It cannot hold a null value or change to refer to another 
variable once initialized. Using references in function arguments is generally 
more efficient for large objects, as it avoids unnecessary copies. C does not 
implement references; instead, pointers are used to achieve similar functionality.

##ex03
Implementation of classes inside other classes.
A getter that ends in const implies that that function is unable to alter any member variable.

If the constructor implies having a weapon it makes sense to use a referenced variable, as it 
will never have a null value.

In the main we use brackets to set differents scopes. That way we are able to use the same variable
names and be more clear as to how we are handling slightly different approaches to the classes implementation.

##ex04
Getting use to std::string methods

##ex05
The goal of this exercise is to use pointers to member functions.