/*This is the standard Input/output library for C++ just like stdio.h in C*/
#include <iostream>

/*syntax of Declaring  a template to use any type as long as the user provide type in place of T
it needs to be written before declaring a class / method / function that is gonna be used in*/
template <typename T>

/*syntax to declare a class its good practice to put c before your class name,
since its going to be generic so people can copy syntax for everything explained in the lectures from it
I am gonna call it cClass XD not to confuse people at all :D
its the same as struct in c but u can add functions in it now its called methods and a lot of other things
gonna come one by one later also struct here is the same as a class just that everything in struct is public
by default while everything in class is private by default.
also i got no idea what public and private do in actual work setting and practice but the academic explanation is:
if it got public: before it anyone can modify it from outside the class,
if it got private: before it you can't modify it from outside the class but u can modify it with methods from inside
the class until you use friend before method now u can modify private data from outside the class xD
there is only one edge case for the use of friend keyword which if u want to have some other type on the lhs
of ur overloaded operator since in normal overloading always the obj is on lhs so to have something like int or float
on lhs u have to use friend method i think not sure or maybe declare global function*/
class cClass
{
private:      /*private: everything that comes after it is private no one can access it outside class kinda*/
    T m_data; /*generic type data we used template above with the T for type*/
    static int m_count;
    /*Static data member for self-counting the objects created from class and if object get destroyed it will decrement
    so it only counts the live count of objects in my program.*/

public: /*public: everything that comes after it is public it can be used anywhere*/
    /*generic constructor with no parameters that takes nothing so it can be created like this it will initialize the data to 0

    cClass<some variable type> obj;

    and when i do that it will initialize my data with the type the user provided and put 0 in my m_data as initial value
    i know templates complicates things normally this would look like:

    cClass obj;

    much cleaner :D

    now back to constructors simply its the method that get called when you create a new object from class
    if u didn't make one the compiler will call default one that does nothing and u get garbage in your members

    syntax of constructors have no return type ever and they must have the same name as class.
    */
    cClass() : m_data(0)
    {
        m_count++; /*since this gonna be called when i create an object i need to increase my object count*/
    }

    /*constructor with parameters like if u give it data when making the object since its generic u gotta
    give it data type templates complicates stuff
    if its called like this : cClass<int> obj(5);
    this will be called and initialize the data to int and put 5 in m_data
    if its called like this : cClass<char> obj;
    my other constructor will be called the one with no parameters that data will be char and m_data will be 0

    without templates creating object syntax
    cClass obj;
    or
    cClass obj(5);
    simple and clean
    */
    cClass(T m_data) : m_data(m_data)
    {
        m_count++; /*only one of them is gonna be called when i create an object i need to increase my object count
                     this will happen automatically based on how the object is created*/
    }

    /*Copy constructor it does as it called
    when creating an obj if u give it another object it will copy it
    since we are using generic class u gotta make sure ur types match*/
    /*so whats with the const keyword here its good practice to put it to signify that object that iam
    gonna copy its contents in this case its called "other" that is a promise that iam not gonna modify it
    just copy its contents and thats it.
    also passing the object by reference is good in this case i don't need to create a copy to create a copy to create a copy
    to create a copy to create a copy u get the idea right ? :D*/
    cClass(const cClass &other) : m_data(other.m_data)
    {
        m_count++; /*also when creating a copy u gotta increase the count of objects*/
    }

    /*Getter (const because it doesn't modify the object)
    sorry for the T its because its generic templates no go xD*/
    T getData() const
    {
        return m_data;
    }

    /*Setter it sets data T is not cool xD
    u don't need to use this u can just type m_data=data_;*/
    void setData(T data_)
    {
        this->m_data = data_;
    }

    /* = operator overload (const because 'other the passed object to me' should not be modified)*/
    cClass &operator=(const cClass &rhs)
    {
        if (this != &rhs) /*i got no idea why this here but just if the two objects are the same don't assign them to each other*/
        {
            m_data = rhs.m_data; /*take the data from the passed class and assign it to me*/
        }
        return *this; /*Return a reference to 'this' object just for chaining remember .increment.increment.increment*/
    }

    /*so a lot of operators coming same idea the "*this" for method chaining*/

    cClass &operator+=(const cClass &rhs)
    {
        m_data += rhs.m_data;
        return *this;
    }

    cClass &operator-=(const cClass &rhs)
    {
        m_data -= rhs.m_data;
        return *this;
    }

    cClass &operator*=(const cClass &rhs)
    {
        m_data *= rhs.m_data;
        return *this;
    }

    cClass &operator/=(const cClass &rhs)
    {
        if (rhs.m_data == 0)    /*can't divide by zero*/
        {
            std::cout << "can't divide by zero.\n";
            return *this;
        }
        m_data /= rhs.m_data;
        return *this;
    }

    /*prefix ++obj so the intended behaviour is to increase the m_data always
    so if j=0; and i=0; and i do something like j=++i; now j and i are equal to 1*/
    cClass &operator++()    
    {
        ++m_data;       
        return *this;
    }
    
    /*now for post fix the intended behaviour is to assign first then increase m_data either way the m_data is getting increased
    so in order to do that we play a little trick by just making temp and take copy of the data in my class before incrementing
    then incrementing the data and returning the old state of my data which i saved in the temp object its just a trick
    so if j=0; and i=0; and i something like j=i++; now j=0 same as before and i = 1 */
    const cClass operator++(int)    /*the int here is just a dummy defined by the c++ standards to signify the use of obj++; that is postfix syntax*/
    {
        cClass temp = *this;
        ++m_data;
        return temp;
    }

    cClass &operator--()
    {
        --m_data;
        return *this;
    }

    const cClass operator--(int)
    {
        cClass temp = *this;
        --m_data;
        return temp;
    }
    /*+ operator overload its simple takes class on rhs and add the data together the two objects must use the same datatype
    generic meh! templates ...*/
    const cClass operator+(const cClass &rhs) const
    {
        return cClass(m_data + rhs.m_data);
    }

    const cClass operator-(const cClass &rhs) const
    {
        return cClass(m_data - rhs.m_data);
    }

    const cClass operator*(const cClass &rhs) const
    {
        return cClass(m_data * rhs.m_data);
    }

    const cClass operator/(const cClass &rhs) const
    {
        if (rhs.m_data == 0)
        {
            std::cout << "can't divide by zero.\n";
            return *this;
        }
        return cClass(m_data / rhs.m_data);
    }

    /*Overload for the '+' operator with an integer on the right hand side instead of other object
    you gotta make sure your created object is of a type int since templates u get the idea.*/
    const cClass operator+(int rhs) const
    {
        return cClass(m_data + rhs);
    }

    const cClass operator-(int rhs) const
    {
        return cClass(m_data - rhs);
    }

    /*same as the overload of the + operators with int 
    but now its more generic its generic on both sides
    the object side the lhs and the rhs remember to match types
    i just don't wanna use templates also u gotta before each method using generic type
    on rhs to do the whole template syntax thing
    and don't overload this many "+" no idea how the compiler differentiate between them*/
    template <typename different_type>
    const cClass<T> operator+(different_type rhs) const
    {
        return cClass<T>(m_data + rhs);
    }

    template <typename different_type>
    const cClass<T> operator-(different_type rhs) const
    {
        return cClass<T>(m_data - rhs);
    }

    /*so the friend syntax is just defined by the c++ standards to allow the use of
    of lhs operator overload i think the << and >> u must declare the friend function 
    inside the class however its good practice to define it outside the class
    which i didn't do here tired now so much syntax and can't remember most of it*/
    template <typename different_type>
    friend const cClass operator+(different_type lhs, const cClass &rhs)
    {
        return cClass<T>(lhs + rhs.m_data);
    }

    template <typename different_type>
    friend const cClass operator-(different_type lhs, const cClass &rhs)
    {
        return cClass<T>(lhs - rhs.m_data);
    }

    /*Static function to get count of objects u created gotta use static with static
     note here since we are dealing with template class that means every instance of the class
     that uses a different type is treated separately like its own class 
     u gotta imagine that if i did this cClass<int> obj; that i created class of kinda type int
     and if i did cClass<double> obj2; that is a different class so in summary 
     the .getcount here counts separately for each class since its generic templates :(
        or i just call magic!
        if i created 3 generic objects with the <int> thing if i did .getcount 
        on one of them it will return back 3
        if i created another 2 generic objects with <double> thing ifi did .getcount
        on one of them it will return back 2 
        even though i created in total 5 i just call magic*/ 
    static int getCount() 
    { 
        return m_count; 
    }

    /*Destructor is fun and easy one it always gets called right before } ending the scope the object was created in.
    so just right before the object get deleted from the memory the destructor gets called and its cleaning time :D*/
    ~cClass()
    {
        m_count--; /*Decrease the count when an object is destroyed no longer living object its dead :(*/
    }
};

/*Initialize the static member 'count'
sorry it looks like that if i wasn't using generic class that can accept any data type
it would look much cleaner like this

int cClass::m_count=0;
static members in class must be Initialized outside the class.

this is to count how many objects been created from class and when they go out of scope
they get destroyed and the count decreases by destructor method remember magic*/
template <typename T>
int cClass<T>::m_count = 0;

/**************************************************************************************************************************/
/*start of explaining overriding always use virtual for correctness of calling the method from the correct object
if you know you are going to over ride it Please use the virtual keyword.
also use override its good practice to let others and your team know that this method gonna override a parent method*/
class Parent
{
public:
    virtual void print() const
    {
        std::cout << "hello from parent" << std::endl;
    }
    /*Virtual destructor ensures that the correct destructor is called for base-class pointers/references to derived-class objects.
    we need this so the correct one get called*/
    virtual ~Parent() {}
};

class Child : public Parent
{
public:
    /*use of override is cool it lets your team and everyone knows that this method gonna override
    a parent method when called*/
    void print() const override
    {
        std::cout << "hello from child" << std::endl;
    }

    ~Child() {}
};
/*end of override */
/**************************************************************************************************************************/

/*inheritance kinda explained scroll to الخلاصه  if this too long "TLDR" */
/*child class that gonna inherit from parent
so lets explain the inheritance keywords
like public,private,protected
so as explained to us private is the strongest it can pretty much overwrite the other two
so if inherit with the keyword private all the methods and members i inherited from parent class
become private in my child class.
--so in simple terms if i write private i get everything except private from parent but it all becomes private in child class
--lets call them variables for now instead of members for ease of explanation since we all come from c background
if my parent class got private variable and protected variable and public variable
writing private when inheriting the private variable gonna stay private in parent class i can't access it in
child class at all but the protected variable gonna convert to private in child class so i can access it only
from inside the child class and the public from parent gonna convert to private also in child class
that is why private is the strongest word then comes protected then comes public*/

/*long explanation above
 هنا الخلاصه

private is the strongest can modify everything
inheriting with "private" keyword   >>parent "private"   stays     "private"    can't access it in child class.
                                    >>parent "protected" becomes   "private"    in child class.
                                    >>parent "public"    becomes   "private"    in child class.

protected is strong kinda can only modify public
inheriting with "protected" keyword >>parent "private"    stays    "private"     can't access it in child class.
                                    >>parent "protected"  stays    "protected"   in child class.
                                    >>parent "public"     becomes  "protected"   in child class.

public is weak does nothing can't modify anything best one just inherit it as is
inheriting with "public" keyword    >>parent "private"    stays    "private"     can't access it in child class.
                                    >>parent "protected"  stays    "protected"   in child class.
                                    >>parent "public"     stays    "public"      in child class.

best one is inheriting public just everything stays the same :D


btw protected can't be accessed outside its class unless i inherit it then i can use it in the child class
private on the other hand can't be accessed outside its class at all like ever unless that "friend" thing comes along and ruins everything.
*/

int main()
{
    /*template class with parameter given*/
    const cClass<int> obj1(5);
    std::cout << "data in obj1: " << obj1.getData() << std::endl;

    /*using copy constructor remember gotta be same type*/
    const cClass<int> obj2(obj1);
    std::cout << "data in obj2: " << obj2.getData() << std::endl;

    /*equal operator or any operator in that matter*/
    cClass<int> obj3 = obj1;
    std::cout << "data in obj3: " << obj3.getData() << std::endl;

    /*postfix demonstration*/
    obj3=0;
    cClass<int> obj4;
    obj4=obj3++;
    std::cout << "postfix: " << obj4.getData() << std::endl;

    /*postfix demonstration*/
    obj3=0;
    obj4=0;
    obj4=++obj3;
    std::cout << "prefix: " << obj4.getData() << std::endl;

    /*Use the setter to set data u can't use const object here to set data so obj3 it is*/
    obj3.setData(30);

    /*use getter to get data from object remember same types*/
    int data = obj3.getData();
    /*print*/
    std::cout << "After setting obj3 it equals " << data << std::endl;
    
    /*int object count*/
    std::cout<<"int object count: "<<obj1.getCount()<<std::endl;
    
    /*rhs*/
    cClass<double> double_object;
    double_object=double_object+20.5;
    double double_data = double_object.getData();
    std::cout << "After adding rhs double to my object " << double_data<<std::endl;
    /*lhs and friend... */
    cClass<double> double_object_2;
    double_object_2=50.75+double_object_2;
    float double_data_2 = double_object_2.getData();
    std::cout << "After adding lhs double to my object " << double_data_2<<std::endl;
   
    /*double object count*/
    std::cout<<"double object count: "<<double_object.getCount()<<std::endl;

    /*Using the Parent and Child classes*/
    Parent parentObj;
    Child childObj;

    /*overriding*/
    parentObj.print();
    childObj.print();

    return 0;
}