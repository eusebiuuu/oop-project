#ifndef OOP_TRANSPORTATION_EXCEPTION_H
#define OOP_TRANSPORTATION_EXCEPTION_H

#include "string"
#include "exception"

class TransportationException: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override = 0;
};

#endif //OOP_TRANSPORTATION_EXCEPTION_H
