#ifndef EXCEPTION_HANDLING_HPP
#define EXCEPTION_HANDLING_HPP

#include <stdexcept>
#include "block_matrix.hpp"

namespace exception
{
    class invalid_argument : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "choice";
        }        
    };

    class invalid_index : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "invalid_index";
        }
    };

    class invalid_matrix : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "invalid_matrix";
        }
    };

    class invalid_size : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "invalid size";
        }
    };
}
#endif //EXCEPTION_HANDLING_HPP
