#include "Serializer.hpp"
#include "stdint.h"
#include <iostream>

/**
 * @brief Private:
 */
Serializer::Serializer()
{
    std::cout << "Serializer class has been created" << std::endl;
}

Serializer::Serializer(Serializer const& src)
{
    (void)src;
    std::cout << "Serializer class has been copied" << std::endl;

}

Serializer& Serializer::operator=(Serializer const& src)
{
    (void)src;
    std::cout << "Serializer class has been assigned" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer class has been destroyed" << std::endl;
}

/**
 * @brief Public:
 */
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
