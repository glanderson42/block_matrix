#include "include/block_matrix.hpp"
#include "include/exception_handling.hpp"
#include "include/menu.hpp"

int main()
{
    try
    { 
        progress(menu());
    }
    catch(const std::exception& exception)
    {
        if(exception.what() == "choice") menu();
    } 
}
