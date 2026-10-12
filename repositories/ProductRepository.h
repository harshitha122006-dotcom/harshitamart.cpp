#pragma once
#include "../models/Product.h"
#include <vector>

class ProductRepository {
public:
    std::vector<Product> getAll();
};