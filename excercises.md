# list of excercises on Cpp topics


## Ex: 1: Time calculating function
Write a function called hms_to_secs() that takes three int values—for hours, minutes, and seconds—as arguments, and returns the equivalent time in seconds (type long). Create a program that exercises this function by repeatedly obtaining a time value in hours, minutes, and seconds from the user (format `12:59:59`), calling the function, and displaying the value of seconds it returns.

## EX 2: tollbooth
Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of the total amount of money collected Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of these to 0. A member function called `payingCar()` increments the car total and adds 0.50 to the cash total. Another function,
called `nopayCar()`, increments the car total but adds nothing to the cash total. Finally, a member function called `display()` displays the two totals. Make appropriate member functions const.
Include a program to test this class. This program should allow the user to push one key to count a paying car, and another to count a nonpaying car. Pushing the 'q' key should cause the program to print out the total cars and total cash and then exit

## EX 3: time class
Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor should initialize this data to 0, and another should initialize it to fixed values. Another member function should display it, in 11:59:59 format. The final member function should add two objects of type time passed as arguments.
A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized. Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should display the value of this third variable.
Make appropriate member functions const

### EX 3.1: operator overloading
extend the time class to be able to add two time objects using the + operator.

### EX 3.2: time passing
extend the time class to be able to count time using the ++ and -- operators. it should be able to count time properly starting with seconds and then minutes and then hours.


## EX 4: Counter class
Create a simple counter class that always inits to zero. Implement methods `increment` and `decrement` that should increment or decrement the counter by 1 each time they are called.

### EX 4.1: Operator overloading
replace `increment` and `decrement` methods with overloading operator of ++ and --

### EX 4.2: define a step value
Add an additional variable to account for a step value for the counter so that it's able to count with steps other that one. the step is allowed to be +ve or -ve 

### EX 4.3: inheritance
make the previous `Counter` Class a base class and derive two other classes from it: 
- `SimpleCounter` class which has a default step value of 1 and can only increment

- `ExtendedCounter` class which has a configurable step value and can increment and decrement

NOTES:
- Both should have use operator overloading for either increment of decrement operations
- Both should implement method chaining for the increment and decrement methods


# EX 5: object self counting

Create a class that includes a data member that holds a “serial number” for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on.
To do this, you’ll need another data member that records a count of how many objects have been created so far. (This member should apply to the class as a whole; not to individual objects. What keyword specifies this?) Then, as each object is created, its constructor can examine this count member variable to determine the appropriate serial number for the new object.
Add a member function that permits an object to report its own serial number. Then write a main() program that creates three objects and queries each one about its serial number. They should respond `I am object number 2`, and so on


## EX 6: Money String formating
write a program to convert the input string of numbers entered by the user like this "123465798" to be formated like this
"123,465,798". Then convert the number into an integer.


## EX 7: Simple Tokenizer
Let the user enter a long string using `getline()`. The given line is assumed to contain many words seperated by whitespace and or punctuation marks in this set `".,?!:;"`. Write a program o split these words into a statically allocated array of string objects.
To verify your output, print the array with each word in one line.

## EX 8: [Hacker Rank] simple strings 

please visit Hacker rank on [this link](https://www.hackerrank.com/challenges/c-tutorial-strings/problem)

## EX 9: Polar class
Create a class Polar that represents the points on the plain as polar coordinates (radius and angle). Create an overloaded +operator for addition of two
Polar quantities. “Adding” two points on the plain can be accomplished by adding their
X coordinates and then adding their Y coordinates. This gives the X and Y coordinates of
the “answer.” Thus you’ll need to convert two sets of polar coordinates to rectangular
coordinates, add them, then convert the resulting rectangular representation back to polar
(Hint: you may need to also create another Class for Cartesian representation )

## EX 10: Company Heirarchy
Create a base class `Employee` with a virtual method `printPosition()`
This method should be overriden by classes like `Engineer` and `Manager` and `Salesman`.
The constuctor of the base class should take the name and age of the employee as input.


## EX 11: SafeArray
Create a Class Called `SafeArray` that checks when indexing is out of bounds. Start with an `int` array and a fixed size using a `#define`.
overload the `[]` operator

### EX 11.1: 
Make this class into a template, so the safe array can store any kind of data, with any size. In `main()`, create safe arrays of at least two different types, and store some data in them.

## EX 12: Student Simple Database
Create a class `Student` that can hold data as `name:string` and `class:string` and grades for different subjects `math`, `english`, `science`.
The class should be able to save the student data into a file in csv format and be able to read it again and modify it.
Create an interactive program in the `main.cpp` file to use this class.
You should cover all CRUD operations on the file.


