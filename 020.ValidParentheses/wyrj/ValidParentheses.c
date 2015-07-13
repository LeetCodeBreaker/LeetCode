/* 0ms */
bool isValid(char* s) {
    char stack[1000];
    int index = 0, i;
    for (i = 0; i < strlen(s); i++) {
        switch(s[i]) {
            case '(':
            case '{':
            case '[':
                stack[index++] = s[i];
            break;
            case ')':
                if ('(' != stack[--index]) {
                    return false;
                }
            break;
            case ']':
                if ('[' != stack[--index]) {
                    return false;
                }
            break;
            case '}':
                if ('{' != stack[--index]) {
                    return false;
                }
            break;
        }
    }
    return (0 == index) ? true : false;
}