#include <iostream>
#include <memory>

class Example
{
    public:
    Example() 
    {
        std::cout << "Example has been created!" << std::endl;
    }
    ~Example()
    {
        std::cout << "Example has been destroyed!" << std::endl;
    }
};

int main()
{
    std::shared_ptr<Example> sharedPtr1 = std::make_shared<Example>();
    std::weak_ptr<Example> weakPtr1 = sharedPtr1;

    //Output: Example has been created!
    std::cout << "SharedPtr reference count before scope: " << sharedPtr1.use_count() << std::endl; //Output: 1
    std::cout << "WeakPtr reference count before scope: " << weakPtr1.use_count() << std::endl; //Output: 1

    {
        std::shared_ptr<Example> sharedPtr2 = weakPtr1.lock();

        std::cout << "SharedPtr reference count inside scope: " << sharedPtr2.use_count() << std::endl; //Output: 2
        std::cout << "WeakPtr reference count inside scope: " << weakPtr1.use_count() << std::endl; //Output: 2
    }

    std::cout << "SharedPtr reference count after scope: " << sharedPtr1.use_count() << std::endl; //Output: 1
    std::cout << "WeakPtr reference count after scope: " << weakPtr1.use_count() << std::endl; //Output: 1

    sharedPtr1.reset(); //sharedPtr1 destroys the object it points to.
    
    //Output: Example has been destroyed!

    std::shared_ptr<Example> sharedPtr3 = weakPtr1.lock();

    std::cout << "SharedPtr reference count after reset: " << sharedPtr1.use_count() << std::endl; //Output: 1
    std::cout << "WeakPtr reference count after reset: " << weakPtr1.use_count() << std::endl; //Output: 1
    std::cout << "SharedPtr reference count after reset: " << sharedPtr3.use_count() << std::endl; //Output: 1

    if(sharedPtr3)
    {
        std::cout << "Reference is expected 0, so this should not be printed." << std::endl;
    }
    else
    {
        std::cout << "The object has been destroyed." << std::endl;
    }

    //Output: The object has been destroyed.

    return 0;
}