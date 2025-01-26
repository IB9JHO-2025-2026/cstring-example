#pragma once

class Cstring
{
    char *m_string;
    unsigned int m_string_length;

public:
    
    const char * get() const
    {
        return m_string;
    }

    // CONSTRUCTOR
    Cstring(const char *const str);

    // DESTRUCTOR
    ~Cstring();

    // COPY CONSTRUCTOR
    Cstring(const Cstring &str_obj);

    // + OPERATOR OVERLOAD
    Cstring operator+(const Cstring &str);

    // COPY ASSIGNMENT OPERATOR OVERLOAD
    Cstring &operator=(const Cstring &str);
};