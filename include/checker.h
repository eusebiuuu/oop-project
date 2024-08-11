#include "stdexcept"
#include "algorithm"

template<class T>
class Checker {
public:
    Checker() = default;
    virtual ~Checker() = default;

    static void throwIfNotInList(T value, const std::vector<T> &arr, const std::string &err) {
        if (arr.empty() or std::count(arr.begin(), arr.end(), value) == 0) {
            throw std::runtime_error(err);
        }
    }
};