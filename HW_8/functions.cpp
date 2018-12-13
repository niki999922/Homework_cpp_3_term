namespace functions {
    typedef int* (*resultFunction)(char const *);
    typedef int (*parameterFunction)(double);
    typedef resultFunction (*complexFunction)(int, parameterFunction);

    template <typename T, typename R>
    bool compare(const T& leftObject, T& rightObject, R (T::*comparator)() const) {
        return (leftObject.*comparator)() < (rightObject.*comparator)();
    }

    template <typename T>
    bool isSameObject(T const * leftObject, T const * rightObject) {
        return (dynamic_cast<const void*>(leftObject) == dynamic_cast<const void*>(rightObject));
    }
}   