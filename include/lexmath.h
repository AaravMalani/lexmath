#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif
    typedef enum
    {
        LEX_ADD,        // NULL
        LEX_DIV,        // NULL
        LEX_MUL,        // NULL
        LEX_BRAC_START, // NULL
        LEX_BRAC_END,   // NULL
        LEX_EXP,        // NULL
        LEX_SUB,        // NULL
        LEX_NAME,       // char*
        LEX_NUM         // char*
    } LexTypes;

    struct LexToken
    {
        LexTypes type;
        const char *data;
    };

    struct LexList
    {
        void *data;
        size_t length;
        size_t capacity;
        size_t element_size;
    };

    struct LexList *lex(const char *data);
    void free_lex(struct LexList* lexList);
#ifdef __cplusplus
}
#endif