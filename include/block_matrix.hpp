#ifndef BLOCK_MATRIX
#define BLOCK_MATRIX

#include <vector>
#include <iostream>

#include "exception_handling.hpp"

/**
* @mainpage Programming homework 1
* @par Block matrix data structure
* 
* @ref bmx::block_matrix a data structure which is store two square matrix in the two corner
* and does not store the null elements.
* 
* @par Implementation
* I am using two std::vector<std::vector<Type> > (where is @ref Type is a template parameter)
* to store the two square matrix. It can be use for store big square matrix's in a block matrix
* where you can not store the null elements.
* 
* @par Running the code
* The source is C++98 compatible. Go to the root of the project and compile the @code with g++
* e.g.: @code g++ main.cpp 
*/

/// @file
/// @brief The main part of the program.

namespace bmx
{
    /// This collections is a block matrix implementation
    template <class Type = int>
    class block_matrix
    {
        private:
            std::vector<std::vector<Type> > _block_one;
            // Store the first block
            std::vector<std::vector<Type> > _block_two;
            // Store the second block
            std::size_t _size_one;
            // Store the size of the first block
            std::size_t _size_two;
            // Store the size of the second block
        public:
            /// Default constructor which is provide to declare a @ref bmx::block_matrix without size
            block_matrix() {}
            
            /// This constructor makes a @ref bmx::block_matrix with size
            /// @throws @ref exception::invalid_size() if @p is not valid
            block_matrix(const std::size_t _size_one, const std::size_t _size_two)
            {
                if(_size_one < 1 || _size_two < 1) throw exception::invalid_size();
                else
                {
                    this->_size_one = _size_one;
                    this->_size_two = _size_two;
                }
            }

            /// Return the size of @ref bmx::block_matrix
            std::size_t size()
            {
                return (_size_one + _size_two) * (_size_one + _size_two); 
            }

            /// Makes the first matrix
            void set_block_one(std::size_t size_one)
            {
                this->_size_one = size_one;
                Type temp;
                this->_block_one.resize(_size_one);

                for(int i = 0; i < _size_one; ++i)
                {
                    this->_block_one.at(i).resize(_size_one);
                    for(int j = 0; j < _size_one; ++j) 
                    {
                        std::cin >> temp;
                        this->_block_one[i][j] = temp;
                    }
                }   
            }

            /// Makes the second matrix
            void set_block_two(std::size_t size_two)
            {
                this->_size_two = size_two;
                Type temp;
                this->_block_two.resize(_size_two);
                for(int i = 0; i < _size_two; ++i)
                {
                    this->_block_two.at(i).resize(_size_two);
                    for(int j = 0; j < _size_two; ++j)
                    {
                        std::cin >> temp;
                        this->_block_two[i][j] = temp;
                    }
                }   
            }

            /// Write out the first matrix
            /// ONLY FOR DEBUG
            void write_out_matrix1()
            {
                for(int i = 0; i < _block_one.size(); ++i) 
                {
                    for(int j = 0; j < _block_one.at(i).size(); ++j)
                        std::cout << _block_one.at(i).at(j) << " ";
                    std::cout << '\n';
                }
            
            }
            
            /// Write out the second matrix
            /// ONLY FOR DEBUG
            void write_out_matrix2()
            {
                for(int i = 0; i < _block_two.size(); ++i)
                {
                    for(int j = 0; j < _block_two.size(); ++j)
                        std::cout << _block_two.at(i).at(j) << " ";
                    std::cout << '\n';
                }
            }
            
            /// Return the first matrix values
            Type get_block_one_values(const int i, const int j)
            {
                if(i > _size_one || j > _size_one) 
                {
                    throw exception::invalid_index();
                    return -1;
                }
                else
                    return this->_block_one.at(i).at(j);
            }
            
            /// Returns the second matrix values
            Type get_block_two_values(const int i, const int j)
            {
                if(i > _size_two || j > _size_two) 
                {
                    throw exception::invalid_index();
                    return -1;
                }
                else
                    return this->_block_two.at(i).at(j);
            }

            /// Sum two block matrix
            void sum(bmx::block_matrix<Type>& b)
            {
                for(int i = 0; i < _size_one; ++i)
                {
                    for(int j = 0; j < _size_one; ++j)
                    {
                        this->_block_one[i][j] += b.get_block_one_values(i, j);
                    }
                }
            
                for(int i = 0; i < _size_two; ++i)
                {
                    for(int j = 0; j < _size_two; ++j)
                    {
                        this->_block_two[i][j] += b.get_block_two_values(i, j);
                    }
                }
            }
            
            /// Multiplie two block_matrix
            void multiplication(bmx::block_matrix<Type>& b)
            {
                for(int i = 0; i < _size_one; ++i)
                {
                    for(int j = 0; j < _size_one; ++j)
                    {
                        this->_block_one[i][j] *= b.get_block_one_values(i, j);
                    }
                }
                
                for(int i = 0; i < _size_two; ++i)
                {
                    for(int j = 0; j < _size_two; ++j)
                    {
                        this->_block_two[i][j] *= b.get_block_two_values(i, j);
                    }
                }
            }
            
            /// Print the block matrix and show where is the 0 elements
            void print() 
            {
                std::string block_one_zeros = "";
                std::string block_two_zeros = "";
                for(int i = 0; i < _size_two; ++i) 
                {
                    block_one_zeros.push_back('0');
                    block_one_zeros.push_back(' ');
                }

                for(int i = 0; i < _size_one; ++i) 
                {
                    block_two_zeros.push_back('0');
                    block_two_zeros.push_back(' ');
                }

                for(int i = 0; i < _size_one; ++i) 
                {
                    for(int j = 0; j < _block_one.at(i).size(); ++j) 
                    {
                        std::cout << _block_one.at(i).at(j) << " ";
                    }
                    
                    std::cout << block_one_zeros << std::endl;
                }

                for(int i = 0; i < _size_two; ++i) 
                {
                    std::cout << block_two_zeros;

                    for(int j = 0; j < _block_two.at(i).size(); ++j) 
                    {
                        std::cout << _block_two.at(i).at(j) << " ";
                    }
                    
                    std::cout << std::endl;
                }
            }
    
            /// Returns the the index value        
            int get(const int x, const int y) const
            {
                if(x > _size_two || y > _size_two) throw exception::invalid_index();
                else {
                    if(x < _size_one && y < _size_one) {
                        return _block_one[x][y];
                    } else if(x > _size_one && y > _size_one) {
                        return _block_two[x - _size_one][y - _size_one];
                    } else {
                        return 0; 
                    }                
                }     
            }
    };        
}
#endif //BLOCK_MATRIX