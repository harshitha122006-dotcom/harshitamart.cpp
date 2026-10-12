#include "ProductRepository.h"

std::vector<Product> ProductRepository::getAll() {
    return {
        {1, "Laptop", 57000, 10},
        {2, "Mouse", 800, 25},
        {3, "Keyboard", 1200, 15},
        {4, "Headphones", 1800, 20},
        {5, "Smart Watch", 2500, 12},
        {6, "Backpack", 1500, 18},
        {7, "Shoes", 2200, 14},
        {8, "Kurti", 1500, 15},
        {9, "T-Shirt", 900, 20},
        {10, "Sunglasses", 700, 16}
    };
}