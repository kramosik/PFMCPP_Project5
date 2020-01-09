/*
 Chapter 3 Part 1 - Continuation of previous Task
 The 'this' keyword.  
 The purpose of this task is to demonstrate the difference between using member variables in member functions, vs. using member variables in free functions.
 
1) write 5 UDTs.
	a) declare and implement: 
		default constructors, 
		destructors, 
		2+ member functions with an arbitrary number of parameters, and 
		3+ member variables, initialized in-class
	b) the previous tasks required you to write std::cout statements in main() that accessed the member variables, or printed out the results from calling member functions. 
		write 2 std::cout statements in main() that do this for each UDT.  
	
 2) For any std::cout statements you had in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
		c) call those member functions after your std::cout statements in main().  see the example below as to what I'm expecting you to write.
 
 3) if you didn't have any std::cout statements in main() that accessed member variables:
         write some.
         then do 2a) 2b) 2c)
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace example
{
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        void memberFunc() { std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; }  //2a)
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    int main()
    {
        MyFoo mf;
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;  //1b)
        mf.memberFunc(); //2c)
        return 0;
    }
}

/*
 UDT 1:
 */

/*
 UDT 2:
 */

/*
 UDT 3:
 */

/*
 UDT 4:
 */

/*
 UDT 5:
 */

#include <iostream>
int main()
{
    example::main();

	//add your main() work starting here

	//
    std::cout << "good to go!" << std::endl;
}
