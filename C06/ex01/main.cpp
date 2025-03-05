#include "Serializer.hpp"
#include <iostream>
#include "stdint.h"

int main(void)
{
    Data originalData;
    originalData.name = "Test Data";
    originalData.value = 42;

    uintptr_t raw = Serializer::serialize(&originalData);

    std::cout << "Serialized Data: " << raw << std::endl;
    std::cout << "Serialized Data (hex): 0x" << std::hex << raw << std::dec << std::endl;
    std::cout << "Serialized Data (address without conversion): " << &raw << std::endl;


    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data name: " << deserializedData->name << std::endl;
    std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;

    std::cout << "Original Address: " << &originalData << std::endl;
    std::cout << "Deserialized Address: " << deserializedData << std::endl;

}