#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include "exception_handling.hpp"
#include "block_matrix.hpp"

bmx::block_matrix<int> bm_one;
bmx::block_matrix<int> bm_two;

void make_new_bm()
{
    std::size_t size_one;
    std::cin >> size_one;
    bm_one.set_size_one(size_one);
    std::size_t size_two;
    std::cin >> size_two;
    bm_one.set_size_two(size_two);
    bm_one.set_block_one();
    bm_one.set_block_two();
}

void sum_two_bm()
{
    std::size_t size_one;
    std::cin >> size_one;
    std::size_t size_two;
    std::cin >> size_two;
    bm_two.set_size_two(size_one);
    bm_two.set_size_two(size_two);
    bm_two.set_block_one();
    bm_two.set_block_two();
    bm_one.sum(bm_two);
}

void multi_two_bm() { 
    std::size_t size_one;
    std::cin >> size_one;
    std::size_t size_two;
    std::cin >> size_two;
    bm_two.set_size_two(size_one);
    bm_two.set_size_two(size_two);
    bm_two.set_block_one();
    bm_two.set_block_two();
    bm_one.multiplication(bm_two);
}

void print_matrix() { 
    bm_one.print_this_shit();
}


void get_element()  
{
    std::size_t size_one;
    std::cin >> size_one;
    bm_one.set_size_one(size_one);
    std::size_t size_two;
    std::cin >> size_two;
    bm_one.set_size_two(size_two);
    bm_one.set_block_one();
    bm_one.set_block_two();
    int x, y;
    std::cin >> x;
    std::cin >> y;
   // auto c = bm_one.translate_indices(x,y);
   // std::cout << c;
}

int menu()
{
    std::cout << "Chose one operation from the menu\n";
    std::cout << "1. make new block matrix\n";
    std::cout << "2. sum two matrix\n";
    std::cout << "3. multiplie two matrix\n";
    std::cout << "4. print matrix\n";
    std::cout << "5. get matrix element\n";
    std::cout << "6. exit\n";
    
    int choice;
    std::cout << "Give your choice: ";
    std::cin >> choice;
    if(choice < 1 || choice > 6 || std::cin.fail())
    {
        std::cerr << "Invalid argument\n";
        throw exception::invalid_argument();
        return -1;
    }
    else return choice;
}

void progress(int c)
{
    switch(c) {
        case 1:
            std::cout << "Give the size and the elements of the array\n";
            make_new_bm();
            break;
        
        case 2:
            std::cout << "Give the size and the elements of the second matrix\n";
            sum_two_bm();
            std::cout << "The matrix after the sum: ";
            bm_one.print_this_shit();
            break;

        case 3:
            multi_two_bm();
            break;

        case 4:
            print_matrix();
            break;

        case 5:
            get_element();
            break;

        case 6:
            exit(0);

    }   
}

#endif //MENU_HPP
