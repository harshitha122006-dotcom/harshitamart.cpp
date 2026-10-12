#include "../repositories/ProductRepository.h"
#include <string>

std::string getProducts() {
    ProductRepository repo;
    auto products = repo.getAll();

    std::string result = "[";

    for (size_t i = 0; i < products.size(); i++) {
        result += "{\"id\":" + std::to_string(products[i].id);
        result += ",\"name\":\"" + products[i].name + "\"";
        result += ",\"price\":" + std::to_string(products[i].price);
        result += ",\"stock\":" + std::to_string(products[i].stock) + "}";

        if (i + 1 < products.size())
            result += ",";
    }

    result += "]";
    return result;
}