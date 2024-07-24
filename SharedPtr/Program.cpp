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
        std::cout << "Example has beed destroyed!" << std::endl;
    }

    int value = 10;
};

int main()
{
    std::shared_ptr<Example> sharedPtr1 = std::make_shared<Example>();

    //Output: Example has been created!

    std::cout << "Reference count before scope: " << sharedPtr1.use_count() << std::endl; //Output: 1
    std::cout << "value before scope: " << sharedPtr1->value << std::endl; //Output: 10
    
    {
        std::shared_ptr<Example> sharedPtr2 = sharedPtr1;

        std::cout << "Reference count inside scope: " << sharedPtr2.use_count() << std::endl; //Output: 2.
        std::cout << "value inside scope: " << sharedPtr2->value << std::endl;//Output: 10
    }

    std::cout << "Reference count after scope: " << sharedPtr1.use_count() << std::endl; //Output: 1
    std::cout << "value after scope: " << sharedPtr1->value << std::endl; //Output: 10

    //Output: Example has been destroyed!

    return 0;
}