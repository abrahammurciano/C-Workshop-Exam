#include "String.h"
#include <string.h>

String *CreateString(const char *src)
{
    String *str = malloc(sizeof(String));
    if (str == NULL)
    {
        return NULL;
    }
    if (src == NULL)
    {
        src = "";
    }
    return CopyCString(str, src) ? str : NULL;
}

bool DeleteString(String *str)
{
    free(str->chars);
    free(str);
    return true;
}

const char *GetString(const String *str)
{
    return str->chars;
}

size_t GetStringLength(const String *str)
{
    return str->size;
}

bool IsEmpty(const String *str)
{
    return str->size == 0;
}

int CompareString(const String *str1, const String *str2)
{
    if (str1 == str2)
    {
        return 0;
    }
    return strcmp(str1->chars, str2->chars);
}

// size is the number of characters not including '\0'
bool CopyCStringGivenSize(String *dst, const char *src, size_t size)
{
    free(dst->chars);
    dst->size = size;
    dst->chars = malloc(size + 1);

    if (dst->chars == NULL)
    {
        return false; // coudn't allocate inner chars array
    }

    strcpy(dst->chars, src);
    return true;
}

bool CopyString(String *dst, const String *src)
{
    return CopyCStringGivenSize(dst, src->chars, src->size);
}

bool CopyCString(String *dst, const char *src)
{
    return CopyCStringGivenSize(dst, src, strlen(src));
}

bool AppendCStringGivenSize(String *dst, const char *src, size_t size)
{
    dst->size += size + 1;
    dst->chars = realloc(dst->chars, dst->size);
    if (dst->chars == NULL)
    {
        return false; // could not reallocate
    }
    strcat(dst->chars, src);
    return true;
}

bool AppendString(String *dst, const String *src)
{
    return AppendCStringGivenSize(dst, src->chars, src->size);
}

bool AppendCString(String *dst, const char *src)
{
    return AppendCStringGivenSize(dst, src, strlen(src));
}