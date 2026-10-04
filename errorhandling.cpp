#include <iostream>
#include <stdexcept>
using namespace std;

/***
 *
 * @error handling in C++
 *
 *
 */

// custom error class
class CustomError:public exception{
    string message;
    int errorCode;
    public:
    CustomError(string msg , int code){
        this->message=msg;
        this->errorCode=code;
    }
    const string messageContent()const noexcept{
        return message;
    }
    const int errorCodeContent()const noexcept{
        return errorCode;
    }
    // return status code and msg both(as a object) from the error class
    const CustomError getError()const noexcept{
        return *this;
    }


};






void normalError(int a, int b)
{
    try
    {
        /* code */

        if (b == 0)
        {
            throw "Division by zero error";
        }
    }
    catch (const char *e)
    {
        cerr << e << '\n';
    }
}
void runtimeError(int a, int b)
{
    try
    {
        /* code */

        if (b == 0)
        {
            throw  CustomError("Division by zero error", 1001);
        }
    }
    catch (const CustomError& e)
    {
        cerr << e.messageContent() << " (Error Code: " << e.errorCodeContent() << ")" << '\n';
    }
}




int main()
{
    runtimeError(10, 0);
}
