# LexMath: A lexer/tokenizer for mathematical expressions

## Installation
- Go to the [latest release](https://github.com/AaravMalani/lexmath/releases/latest)
- Download the RPM file for Red-Hat based Linux Systems, DEB file for Debian based systems, the DLL or LIB file for Windows, or the PKG file for MacOS
```sh
# Ubuntu/Debian
sudo dpkg -i <file>.deb

# RedHat Based Linux
sudo rpm -i <file>.rpm

# MacOS
installer -pkg <file>.pkg -target /
```
For Windows, you have to link it into the Visual Studio Project using the Linker menu in the Properties of the Project.
Then download the [`lexmath.h`](https://raw.githubusercontent.com/AaravMalani/lexmath/main/include/lexmath.h) file and include that as a header file.

## Usage
```c
#include <lexmath.h>

const char* lexList[9] = {
    "LEX_ADD", // + token
    "LEX_DIV", // / token
    "LEX_MUL", // * token
    "LEX_BRAC_START", // ( token
    "LEX_BRAC_END", // ) token
    "LEX_EXP", // ^ token
    "LEX_SUB", // - token
    "LEX_NAME", // list of characters from a-z
    "LEX_NUM" // A number (floating point included)
};

int main() {
    struct LexList* list = lex("1+sin(2x) * 1+3+3^3"); // List of tokens
    struct LexToken* lst = list->data; // The pointer to the tokens
    for (size_t i = 0; i < list->length; i++){ // Iterate over the tokens
        printf("Type: %s (%d)\n", lexList[lst[i].type], lst[i].type); // Print the Type
        if (lst[i].data){ // If there is data to print
            printf("Value: %s\n", lst[i].data); // Print the data
        }
        printf("\n"); // Print a new line
    }
    free_lex(list); // Free the tokens
    
}



```
### OUTPUT
```
Type: LEX_NUM (8)
Value: 1

Type: LEX_ADD (0)

Type: LEX_NAME (7)
Value: sin

Type: LEX_BRAC_START (3)

Type: LEX_NUM (8)
Value: 2

Type: LEX_NAME (7)
Value: x

Type: LEX_BRAC_END (4)

Type: LEX_MUL (2)

Type: LEX_NUM (8)
Value: 1

Type: LEX_ADD (0)

Type: LEX_NUM (8)
Value: 3

Type: LEX_ADD (0)

Type: LEX_NUM (8)
Value: 3

Type: LEX_EXP (5)

Type: LEX_NUM (8)
Value: 3

```

## Credits
- [avighnac](https://github.com/avighnac) who introduced the idea of making a mathematical expression parser.
  




