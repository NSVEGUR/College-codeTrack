//Name: V Nagasai
//Roll No: CS20B1016

#include <stdio.h>

FILE *file = NULL;
FILE *write = NULL;
int lineC = 0, t = 0, charC = 0;
char ch[32][32] = {"break", "case", "char",
                   "const", "continue", "default",
                   "do", "double", "auto",
                   "else", "enum", "extern",
                   "float", "for", "goto",
                   "if", "int", "long",
                   "register", "return", "short",
                   "signed", "sizeof", "static",
                   "struct", "switch", "typedef",
                   "union", "unsigned", "void",
                   "volatile", "while"};

char op[7][5] = {"+", "-", "*", "/", ">", "<", "="};

char sc[19][5] = {"~", "`", "@", "#", "$", "%", "^", "&", "(", ")", "{", "}", "[", "]", "|", ":", ".", "?", "/"};

int printWord(const char word[]) {
    printf("%s", word);
    return 0;
}

int compare(const char a[], const char b[]) {
    int flag = 0, i = 0;
    while (a[i] != '\0') {
        if (b[i] != '\0') {
            if (a[i] != b[i]) {
                flag = 1;
                break;
            }
        } else {
            flag = 1;
            break;
        }
        i++;
    }
    if (a[i] == '\0') {
        if (b[i] != '\0') { flag = 1; }
    }
    if (flag == 0) {
        return 0;
    } else return 1;
}

int writeToFile(int c) {
    int a = c;
    charC++;
    fputc(a, write);
    //printf("%c" , a) ;
    return 0;
}

void removeExtras() {
    char str[1000] = "";
    int a;
    while ((a = fgetc(file)) != EOF) {
        if (a == 35) {   // remove directories
            fgets(str, 100, file);
            continue;
        }
        if (a == 10 || a == 32) { // remove spaces lines
            int temp = a;
            while ((a = fgetc(file)) != EOF) {
                if (a != 10 && a != 32) { break; }
            }
            if (charC > 0)
                writeToFile(temp);
        }
        if (a == 34) {           //escape strings
            do {
                writeToFile(a);
                if ((a = fgetc(file)) != EOF) {}
                else { return; }
            } while (a != 34);
            writeToFile(a);
            continue;
        }

        if (a == 47) {           //remove comments
            if ((a = fgetc(file)) != EOF) {
                if (a == 47) {
                    fgets(str, 100, file);
                    continue;
                } else if (a == 42) {
                    int temp = 0;
                    do {
                        if (temp == 0) {
                            if ((a = fgetc(file)) != EOF) {
                                temp = a;
                                if ((a = fgetc(file)) != EOF) {}
                                else return;
                            } else return;
                            continue;
                        }

                        if (temp == 42) {
                            if (a == 47) {
                                break;
                            }
                        }
                        temp = a;
                        if ((a = fgetc(file)) != EOF) {

                        } else return;
                    } while (t == 0);
                    continue;
                }
            } else return;
        }
        if (a != EOF)
            writeToFile(a);
        else return;
    }
}


void tokenize() {
    file = fopen("Output.c", "r");
    int a = 99;
    char str[1000] = "";
    if (file == NULL) {
        printf("file not found / an error occurred \n");
        return;
    } else {
        int state = 0;
        a = fgetc(file);
        while ((a) != EOF) {
            char temp = a;
            char m[] = {temp};
            if (state == 0) {
                if (((a > 64 && a < 91) || (a > 96 && a < 123))) {
                    state = 1;
                } else if (a > 47 && a < 58) {
                    state = 2;
                } else if (a == 34) {
                    state = 3;
                } else {
                    state = 6;
                    for (int k = 0; k < 7; ++k) {
                        if (compare(m, op[k]) == 0) {
                            state = 4;
                            break;
                        }
                    }
                    for (int j = 0; j < 19; ++j) {
                        if (compare(m, sc[j]) == 0) {
                            state = 5;
                            break;
                        }
                    }
                }
            }
            switch (state) {
                case 1: {
                    int i = 0;
                    char word[100] = "";
                    word[i++] = a;
                    while ((a = fgetc(file)) != EOF) {
                        if (((a > 64 && a < 91) || (a > 96 && a < 123))){
                            word[i++] = a;
                        } else
                            break;
                    }
                    int check = 1;
                    for (int j = 0; j < 32; ++j) {
                        if (compare(word, ch[j]) == 0) {
                            check = 0;
                            printf("KeyWord : ");
                            printWord(word);
                            printf("\t STATE 1 \n");
                            break;
                        }
                    }
                    if (compare(word, "NULL") == 0) {
                        check = 0;
                        printf("NoValue : ");
                        printWord(word);
                        printf("\t STATE 1 \n");
                    }
                    if (check == 1) {
                        printf("Identifier : ");
                        printWord(word);
                        printf("\t STATE 1 \n");
                    }
                    state = 0;
                    if (a == EOF) {
                        state = -1;
                    }
                    break;
                }
                case 2: {
                    int numCheck = 1;
                    int hro = 0;
                    int end = 0;
                    char num[100] = "";
                    int p = 0;
                    num[p++] = a;
                    if (a == 48) {
                        if ((a = fgetc(file)) != EOF) {
                            if (a > 47 && a < 58) {
                                hro = 1;
                                num[p++] = a;
                            } else if (a == 88 || a == 120) {
                                num[p++] = a;
                                if ((a = fgetc(file)) != EOF) {
                                    if (a > 47 && a < 58) {
                                        num[p++] = a;
                                        hro = -1;
                                    } else if (((a > 64 && a < 91) || (a > 96 && a < 123))) {
                                        num[p++] = a;
                                        numCheck = -1;
                                    } else {
                                        numCheck = -1;
                                        end = 1;
                                    }
                                } else return;
                            } else if (((a > 64 && a < 91) || (a > 96 && a < 123))) {
                                numCheck = -1;
                                num[p++] = a;
                            } else { end = 1; }
                        }
                    }
                    if (end == 0)
                        while ((a = fgetc(file)) != EOF) {
                            if (a > 47 && a < 58) { num[p++] = a; }
                            else if (((a > 64 && a < 91) || (a > 96 && a < 123))) {
                                num[p++] = a;
                                numCheck = -1;
                            } else {
                                end = 1 ;
                                break;
                            }
                        }

                    if (numCheck == -1) {
                        printf("undefined identifier : ");
                        printWord(num);
                        printf("\t STATE 2 \n");
                    }
                    if (numCheck == 1) {
                        if (hro == -1) {
                            printf("HEX value : ");
                            printWord(num);
                            printf("\t STATE 2 \n");
                        } else if (hro == 1) {
                            printf("OCTET value : ");
                            printWord(num);
                            printf("\t STATE 2 \n");
                        } else {
                            printf("Real value : ");
                            printWord(num);
                            printf("\t STATE 2 \n");
                        }
                    }
                    state = 0;
                    break;
                }
                case 3 : {
                    printf("String : ");
                    do {
                        printf("%c", a);
                        if ((a = fgetc(file)) != EOF) {}
                        else { state = -1; }
                    } while (a != 34);
                    printf("%c", a);
                    printf("\t STATE 3 \n");
                    a = fgetc(file) ;
                    state = 0;
                    break;
                }
                case 4 : {
                    printf("Operator : ");
                    printWord(m);
                    char n[2]  ;
                    n[1] = '\0' ;
                    while ((a = fgetc(file)) != EOF) {
                        temp = a;
                        n[0] = temp ;
                        int check = 1 ;
                        for (int k = 0; k < 7; ++k) {
                            if (compare(n, op[k]) == 0) {
                                printWord(n);
                                check = 0 ;
                                break;
                            }
                        }
                        if(check == 1){
                            break;
                        }
                    }
                    printf("\t STATE 4 \n");
                    state = 0;
                    break;
                }
                case 5 : {
                    printf("Special Characters : ");
                    printWord(m);
                    printf("\t STATE 5 \n");
                    state = 0;
                    a = fgetc(file);
                    break;
                }
                default: {
                    a = fgetc(file);
                    state = 0;
                }
            }

        }
    }
}

int main(int argc, char *argsV[]) {
    if (argc == 2) {
        file = fopen(argsV[1], "r");
        write = fopen("Output.c", "w");
        if (file == NULL && write == NULL) {
            printf("file not found / an error occurred \n");
            return 0;
        } else {
            removeExtras();
            fclose(file);
            fclose(write);
            tokenize();
            fclose(file);
        }
    } else
        printf("Error! \n");
    return 0;
}