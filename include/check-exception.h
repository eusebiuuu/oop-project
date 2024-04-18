#ifndef OOP_CHECK_EXCEPTION_H
#define OOP_CHECK_EXCEPTION_H

#include "transportation-exception.h"

class CheckException: public TransportationException {
    const char* message;
public:
    explicit CheckException(const char* mess) {
        this->message = mess;
    }

    [[nodiscard]] const char* what() const noexcept override {
        return this->message;
    }
};

#endif //OOP_CHECK_EXCEPTION_H
