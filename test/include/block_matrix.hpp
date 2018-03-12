#ifndef BLOCK_MATRIX
#define BLOCK_MATRIX

#include <vector>
#include <iostream>

#include "exception_handling.hpp"

namespace bmx
{
    template <class Type = int>
    class block_matrix
    {
        private:
            std::vector<std::vector<Type> > _block_one;
            std::vector<std::vector<Type> > _block_two;
            std::size_t _size_one;
            std::size_t _size_two;
            std::size_t _max_size;
        public:
            block_matrix() {}
            
            block_matrix(const std::size_t _size_one, const std::size_t _size_two)
            {
                if(_size_one < 1 || _size_two < 1) throw exception::invalid_size();
                else
                {
                    this->_size_one = _size_one;
                    this->_size_two = _size_two;
                    this->_max_size = _size_one + _size_two;
                }
            }

            void set_size_one(std::size_t size_one)
            {
                this->_size_one = size_one;
            }
            
            void set_size_two(std::size_t size_two)
            {
                this->_size_two = size_two;
            }

            std::size_t size()
            {
                return (_size_one + _size_two) * (_size_one + _size_two); 
            }

            void set_block_one()
            {
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

            void set_block_two()
            {
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

            void write_out_matrix1()
            {
                for(int i = 0; i < _block_one.size(); ++i) 
                {
                    for(int j = 0; j < _block_one.at(i).size(); ++j)
                        std::cout << _block_one.at(i).at(j) << " ";
                    std::cout << '\n';
                }
            
            }
    
            void write_out_matrix2()
            {
                for(int i = 0; i < _block_two.size(); ++i)
                {
                    for(int j = 0; j < _block_two.size(); ++j)
                        std::cout << _block_two.at(i).at(j) << " ";
                    std::cout << '\n';
                }
            }
            
            Type get_block_one_values(const int i, const int j)
            {
                return this->_block_one.at(i).at(j);
            }
            
            Type get_block_two_values(const int i, const int j)
            {
                return this->_block_two.at(i).at(j);
            }

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
    
            void print_this_shit() {
                std::string block_one_zeros = "";
                std::string block_two_zeros = "";
                for(int i = 0; i < (int(_max_size) - int(_size_two)); ++i) {
                    block_one_zeros.push_back('0');
                    block_one_zeros.push_back(' ');
                }

                for(int i = 0; i < (int(_max_size) - int(_size_one)); ++i) {
                    block_two_zeros.push_back('0');
                    block_two_zeros.push_back(' ');
                }

                for(int i = 0; i < _size_one; ++i) {
                    for(int j = 0; j < _block_one.at(i).size(); ++j) {
                        std::cout << _block_one.at(i).at(j) << " ";
                    }
                    
                    std::cout << block_one_zeros << std::endl;
                }

                for(int i = 0; i < _size_two; ++i) {
                    std::cout << block_two_zeros;

                    for(int j = 0; j < _block_two.at(i).size(); ++j) {
                        std::cout << _block_two.at(i).at(j) << " ";
                    }
                    
                    std::cout << std::endl;
                }
            }
    
            
//            struct point { int x, y; };
//
//            point a_bottom_right_corner = _block_one[_size_one - 1][_size_one - 1];
//            point b_top_left_corner = _block_two[_size_two - 1][_max_size - 1];
//
//            int translate_indices(const int x, const int y) const
//            {
//                if(x <= a_bottom_right_corner.x && y <= a_bottom_right_corner.y) {
//                   return x + y;
//                } else if(x >= b_top_left_corner.x && y >= b_top_left_corner.y) {
//                   return x + y/* - num_zeros()*/;
//                } else {
//               // The requested element is 0.
//                   return -1; 
//                }                     
//            }


    };        
}
#endif //BLOCK_MATRIX


/*
*
*
*
*       x x x x 0 0 0 0
*       x x x x 0 0 0 0
*       x x x x 0 0 0 0
*       x x x x 0 0 0 0
*       0 0 0 0 y y y y
*       0 0 0 0 (y) y y y
*       0 0 0 0 y y y y    
*       0 0 0 0 y y y y
*
*       if x = 5 & y = 6 => block_two[1][0]
*       then => x > size_one and x > 
*   
*
*
*
*
*
*
*/