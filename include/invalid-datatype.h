#ifndef OOP_INVALID_DATATYPE_H
#define OOP_INVALID_DATATYPE_H

#include "transportation-exception.h"

class InvalidDatatype: public TransportationException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Transportation type not in the preferred list";
    }
};

#endif //OOP_INVALID_DATATYPE_H
