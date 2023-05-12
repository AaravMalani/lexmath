#include <../include/lexmath.h>

const char *readName(const char **dataPtr) {
    const char* data = *dataPtr;

    while ('a' <= *data && *data <= 'z'){
        data++;
    }
    

    char *ptr = malloc(data - *dataPtr + 1);
    memcpy(ptr, *dataPtr, data - *dataPtr);
    ptr[data - *dataPtr] = 0;

    *dataPtr = data;
    return ptr;
}
const char *readNumber(const char *data, const char **dataPtr)
{
    const char *dataCopy = data;
    if ('0' > *dataCopy || *dataCopy > '9')
    {
        return (void *)0;
    }
    char inDec = 0;
    while (*dataCopy)
    {
        if (*dataCopy == '.' && !inDec)
        {
            inDec = 1;
        }
        else if ('0' < *dataCopy || *dataCopy > '9')
        {
            dataCopy++;
            break;
        }
        dataCopy++;
    }
    *dataPtr = dataCopy;

    char *ptr = malloc(dataCopy - data + 1);
    memcpy(ptr, data, dataCopy - data);
    ptr[dataCopy - data] = 0;
    return ptr;
}
const char *strip(const char *data)
{
    while (*data == ' ')
    {
        data++;
    }
    return data;
}








struct LexList* lexlist_new(size_t element_size){
    struct LexList* list = malloc(sizeof(struct LexList));
    list->data = malloc(element_size);
    list->capacity = 1;
    list->length = 0;
    list->element_size = element_size;
    return list;
}

void lexlist_add(struct LexList* list, void* data){
    if (list->length+1 > list->capacity){
        list->capacity*=2;
        list->data = realloc(list->data, list->capacity*list->element_size);
    }
    
    memcpy(((char*)list->data)+(list->element_size*list->length), data, list->element_size);
    list->length++;
}

#define lexSwitch(chr, typ) case chr: \
                               token.type = typ; \
                               token.data = NULL; \
                               lexlist_add(lexedTokenList, &token); \
                               break;



struct LexList *lex(const char *data)
{

    struct LexList* lexedTokenList = lexlist_new(sizeof(struct LexToken));

    
    while (*data)
    {
        struct LexToken token;
        data = strip(data);
        const char *value = readNumber(data, &data);
        data = strip(data);
        if (value)
        {
            token.type = LEX_NUM;
            token.data = value;
            lexlist_add(lexedTokenList, &token);
        } else if ('a'<=*data && *data <='z') {
            token.type = LEX_NAME;
            token.data = readName(&data);
            lexlist_add(lexedTokenList, &token);
        } else {
            switch (*data++)
            {
                lexSwitch('+', LEX_ADD)
                lexSwitch('^', LEX_EXP)
                lexSwitch('-', LEX_SUB)
                lexSwitch('*', LEX_MUL)
                lexSwitch('/', LEX_DIV)
                lexSwitch('(', LEX_BRAC_START)
                lexSwitch(')', LEX_BRAC_END)
                
                
                
                
                default:
                    break;
            }
        }

    }
    return lexedTokenList;
}

void free_lex(struct LexList* lexList) {
    for (size_t i = 0; i < lexList->length; i++){
        if(((struct LexToken*)lexList->data)[i].data){
            free((void*)((struct LexToken*)lexList->data)[i].data);
        }
    }
    free(lexList->data);
    free(lexList);
}