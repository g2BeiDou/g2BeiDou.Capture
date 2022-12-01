//
// Created by GengG on 2022/12/1.
//

#ifndef G2BEIDOU_CAPTURE_GRROR_H
#define G2BEIDOU_CAPTURE_GRROR_H
#include <string>
class grror
{
public:
    grror(int code = 0, std::string message = "", std::string name = "", std::string function ="", int line = 0):code(code), message(message), name(name), function(function), line(line){}
    
    ~grror(){}

public:
    int code;
    std::string message;
    std::string name;
    std::string function;
    int line;
public:
    int operator=(const grror &other) const
    {
        return code == other.code;
    }
    operator bool() const
    {
        return code == 0;
    }
    bool operator!() const
    {
        return code != 0;
    }
    operator int() const
    {
        return code;
    }
    grror& operator=(const std::pair<int,std::string> in)
    {
        code = in.first;
        message = in.second;
        return *this;
    }
    
};

typedef std::pair<int, std::string> error_info;

#endif //G2BEIDOU_CAPTURE_GRROR_H
