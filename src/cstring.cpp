#include "cstring.h"

// CONSTRUCTOR
Cstring::Cstring(const char *const str)
{
    // incremement string_length until '\0' character is reached
    for (m_string_length = 0; str[m_string_length] != '\0'; ++m_string_length)
        ;
    // allocate the memory for the string, leaving an extra space for '\0'
    m_string = new char[m_string_length + 1];
    // copy the string into the object
    for (unsigned int i = 0; i < m_string_length; ++i)
        m_string[i] = str[i];
    m_string[m_string_length] = '\0';
}

// DESTRUCTOR
Cstring::~Cstring()
{
    delete[] m_string;
}

// COPY CONSTRUCTOR
Cstring::Cstring(const Cstring &str_obj)
{
    // set the correct string length
    m_string_length = str_obj.m_string_length;
    // allocate the memory for the string copy, leaving an extra space for '\0'
    m_string = new char[m_string_length + 1];
    // copy the existing string into this object
    for (unsigned int i = 0; i < m_string_length; ++i)
        m_string[i] = str_obj.m_string[i];
    m_string[m_string_length] = '\0';
}

// + OPERATOR OVERLOAD
Cstring Cstring::operator+(const Cstring &str)
{
    // copy the existing object (copy constructor)
    Cstring new_string("");
    // set the correct length
    new_string.m_string_length = this->m_string_length + str.m_string_length;
    // allocate enough memory to fit both strings
    new_string.m_string = new char[new_string.m_string_length + 1];
    unsigned int i = 0;
    // copy in the lhs string
    for (; i < this->m_string_length; ++i)
        new_string.m_string[i] = this->m_string[i];
    // copy in the rhs string
    for (; i < new_string.m_string_length; ++i)
        new_string.m_string[i] = str.m_string[i - this->m_string_length];
    new_string.m_string[new_string.m_string_length] = '\0';
    return new_string;
}

// COPY ASSIGNMENT OPERATOR OVERLOAD
Cstring &Cstring::operator=(const Cstring &str)
{
    // Guard self assignment
    if (this == &str)
        return *this;
    // if the strings are already the same length we don't need to tamper with memory
    if (this->m_string_length != str.m_string_length)
    {
        // clean up the existing object
        delete[] m_string;
        m_string = nullptr; // just in case memory allocation on next line fails
        m_string_length = 0;
        m_string = new char[str.m_string_length + 1]; // allocate the new resources
        m_string_length = str.m_string_length;
    }
    // now we have checked memory is correctly allocated/cleaned up, copy the string
    for (unsigned int i = 0; i < m_string_length; ++i)
        m_string[i] = str.m_string[i];
    m_string[m_string_length] = '\0';
    return *this; // by convention return the new object
}