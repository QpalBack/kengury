#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include <cstdint>
#include <cstring>

#pragma pack(push, 1)
struct TaskParams
{
    int32_t max_number;
    int32_t word_count;
    char language[16];

    TaskParams() : max_number(10000), word_count(2)
    {
        strcpy(language, "ru");
    }
};

struct TaskResult
{
    int32_t tens_digit;
    bool success;
    char error_msg[256];

    TaskResult() : tens_digit(-1), success(false)
    {
        memset(error_msg, 0, sizeof(error_msg));
    }
};
#pragma pack(pop)

#endif
