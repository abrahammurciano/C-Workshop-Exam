#include <stdio.h>
#include <string.h>
#include "String.h"

bool TestNullConstructor()
{
    bool result = true;
    String *str1 = CreateString(NULL);
    String *str2 = CreateString("");

    if (CompareString(str1, str2) != 0)
    {
        printf("Error: CreateString(NULL) did not create an empty string.");
        result = false;
    }

    DeleteString(str1);
    DeleteString(str2);
    return result;
}

bool TestConstructor()
{
    bool result = true;
    String *str1 = CreateString("Hello World!");

    if (strcmp(GetString(str1), "Hello World!") != 0)
    {
        printf("Error: CreateString did not create the correct string.");
        result = false;
    }

    DeleteString(str1);
    return result;
}

bool TestGetStringLength()
{
    bool result = true;
    const char *hello = "Hello World!";
    String *str1 = CreateString(hello);
    if (strlen(hello) != GetStringLength(str1))
    {
        printf("Error: GetStringLength returned the wrong length.");
        result = false;
    }
    DeleteString(str1);
    return result;
}

bool TestIsEmpty()
{
    bool result = true;
    String *str1 = CreateString("");
    String *str2 = CreateString("Hello World");
    if (!IsEmpty(str1))
    {
        printf("Error: Empty string not recognised as empty.");
        result = false;
    }
    if (IsEmpty(str2))
    {
        printf("Error: Non empty string recognised as empty.");
    }
    DeleteString(str1);
    DeleteString(str2);
    return result;
}

bool TestCompareString()
{
    bool result = true;
    String *str1 = CreateString("Alice");
    String *str2 = CreateString("Bob");
    String *str3 = CreateString("Alice in wonderland");
    String *str4 = CreateString("");
    String *str5 = CreateString("Alice");
    if (CompareString(str1, str2) >= 0 || CompareString(str1, str3) >= 0 || CompareString(str1, str4) <= 0 || CompareString(str1, str5) != 0)
    {
        printf("Error: CompareString failed.");
        result = false;
    }
    DeleteString(str1);
    DeleteString(str2);
    DeleteString(str3);
    DeleteString(str4);
    DeleteString(str5);
    return result;
}

bool TestCopyString()
{
    bool result = true;
    String *str1 = CreateString("");
    String *str2 = CreateString("Hello World");
    String *str3 = CreateString("Hello World");
    CopyString(str1, str2);
    if (CompareString(str1, str3) != 0)
    {
        printf("Error: CopyString failed.");
        result = false;
    }
    DeleteString(str1);
    DeleteString(str2);
    DeleteString(str3);
    return result;
}

bool TestAppendString()
{
    bool result = true;
    String *str1 = CreateString("Hello ");
    String *str2 = CreateString("World!");
    String *str3 = CreateString("Hello World!");
    AppendString(str1, str2);
    if (CompareString(str1, str3) != 0)
    {
        printf("Error: AppendString failed.");
        result = false;
    }
    DeleteString(str1);
    DeleteString(str2);
    DeleteString(str3);
    return result;
}

int main(int argc, char **argv)
{
    bool result = true;
    result = result && TestNullConstructor();
    result = result && TestConstructor();
    result = result && TestGetStringLength();
    result = result && TestIsEmpty();
    result = result && TestCompareString();
    result = result && TestCopyString();
    result = result && TestAppendString();
    return result ? 0 : -1;
}