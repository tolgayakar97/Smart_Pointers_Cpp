#include<iostream>
#include<memory> //in order to use smart pointers like unique_ptr, memory is included.

class Example
{
    public:
    Example()
    {
        std::cout << "Example has been created." << std::endl;
    }
    ~Example()
    {
        std::cout << "Example has been destroyed." << std::endl;
    }

    int value = 10;
};

int main()
{
    //unique_ptr<int> ptr1(new int(10))
    std::unique_ptr<Example> ptr1 = std::make_unique<Example>();

    //Output: Example has been created.

    std::cout << ptr1->value << std::endl; //Output: 10

    std::unique_ptr<Example> ptr2;

    //ptr2 = ptr1; will throw an error because, unique pointers cannot be shared or copied.

    ptr2 = move(ptr1);

    std::cout << ptr1 << std::endl; //Output: 0x0
    std::cout << ptr2->value << std::endl; //Output: 10

    if(ptr1 == nullptr)
    {
        std::cout << "NULLPTR" << std::endl;
    }

    if(ptr1)
    {
        std::cout << "ptr1 is the owner" << std::endl;
    }
    else
    {
        std::cout << "ptr2 is the owner" << std::endl;
    }

    //Output: ptr2 is the owner

    return 0;
}