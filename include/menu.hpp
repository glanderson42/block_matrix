#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include "exception_handling.hpp"
#include "block_matrix.hpp"

bmx::block_matrix<int> bm_one;
bmx::block_matrix<int> bm_two;
bool is_exist = false;

void make_new_bm()
{
    std::size_t size_one;
    std::cin >> size_one;
    std::size_t size_two;
    std::cin >> size_two;
    bm_one.set_block_one(size_one);
    bm_one.set_block_two(size_two);
    is_exist = true;
}

void sum_two_bm()
{
    if(is_exist)
    {
        std::size_t size_one;
        std::cin >> size_one;
        std::size_t size_two;
        std::cin >> size_two;
        bm_two.set_block_one(size_one);
        bm_two.set_block_two(size_two);
        bm_one.sum(bm_two);
    } else {
        make_new_bm();
        sum_two_bm();
    }   
}

void multi_two_bm() { 
    if(is_exist) {
       std::size_t size_one;
       std::cin >> size_one;
       std::size_t size_two;
       std::cin >> size_two;
       bm_two.set_block_one(size_one);
       bm_two.set_block_two(size_two);
       bm_one.multiplication(bm_two);
    } else {
        make_new_bm();
        multi_two_bm();
    }   
} 

void print_matrix() { 
    if(is_exist)
        bm_one.print();
    else {
        make_new_bm();
        print_matrix();
    }
}


void get_element()  
{
    if(is_exist) {
        int x, y;
        std::cin >> x;
        std::cin >> y;
        std::cout << bm_one.get(x, y) << std::endl;
    } else {
        make_new_bm();
        get_element();
    }    
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
            std::cout << "The matrix after the sum: \n";
            bm_one.print();
            break;

        case 3:
            std::cout << "Give the size and the elemens the new block matrix\n";
            multi_two_bm();
            break;

        case 4:
            print_matrix();
            break;

        case 5:
            std::cout << "Give the x and y coordinate!\n";
            std::cout << "Index is start from 0!\n";
            get_element();
            break;

        case 6:
            exit(0);

    }   
}

#endif //MENU_HPP
