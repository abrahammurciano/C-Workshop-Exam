/**
 * @file String.h
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief A library containing a more advanced string class.
 * @details Unless otehrwise specified, any parameters of pointer types which recieve NULL cause the behaviour of their function to be undefined.
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef String_h
#define String_h

#include <stdlib.h>
#include <stdbool.h>

 /**
  * @brief Represents a string of characters.
  */
typedef struct String
{
    char *chars;
    size_t size;
} String;

/**
 * @brief Create a String object.
 *
 * @param src The character array containing the C-style string to use to construct our string. If src is NULL, an empty string will be created. The contents of the source are copied, so feel free to free the source if it's dynamically allocated after calling this function.
 * @return String* A pointer to the newly created string, or NULL if the necessary memory could not be allocated.
 */
String *CreateString(const char *src);

/**
 * @brief Delete a string object.
 *
 * @param str A pointer to the String object to delete.
 * @return true.
 */
bool DeleteString(String *str);

/**
 * @brief Get the C-style string from the String object.
 *
 * @param str A pointer to the String object from which to get the C-style string.
 * @return const char* The C-style string stored in the String object.
 */
const char *GetString(const String *str);

/**
 * @brief Get number of characters in the string.
 *
 * @param str A pointer to the String object
 * @return size_t The number of characters in the string.
 */
size_t GetStringLength(const String *str);

/**
 * @brief Check if the given String object is the empty string.
 *
 * @param str A pointer to the String object to check.
 * @return true if the str is empty, false otherwise.
 */
bool IsEmpty(const String *str);

/**
 * @brief Compare two strings according to the order of characters in the ASCII table.
 *
 * @param str1 A pointer to the first string to compare.
 * @param str2 A pointer to the second string to compare.
 * @return int The result of the comparison. It will be negative if str1 comes before str2, zero if they are the same string, or positive if str1 comes after str2.
 */
int CompareString(const String *str1, const String *str2);

/**
 * @brief Copy the value of the source string into the destination string.
 *
 * @param dst A pointer to the destination string. This value must be one previously returned by a call to CreateString.
 * @param src A pointer to the source string.
 * @return true if the operation completed successfully, false otherwise.
 */
bool CopyString(String *dst, const String *src);

/**
 * @brief Copy the value of a C-style string into the destination string.
 *
 * @param dst A pointer to the destination string. This value must be one previously returned by a call to CreateString.
 * @param src A C-style string to copy from.
 * @return true if the operation completed successfully, false otherwise.
 */
bool CopyCString(String *dst, const char *src);

/**
 * @brief Append a source string to the destination string.
 *
 * @param dst A pointer to the destination string which will be appended to.
 * @param src A pointer to the source string.
 * @return true if the operation completed successfully, false otherwise.
 */
bool AppendString(String *dst, const String *src);

/**
 * @brief  Append a C-style source string to the destination string.
 *
 * @param dst A pointer to the destination string which will be appended to.
 * @param src A pointer to the C-style source string.
 * @return true if the operation completed successfully, false otherwise.
 */
bool AppendCString(String *dst, const char *src);

#endif