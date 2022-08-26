//
// Created by jpalb on 26.10.2021.
//

#ifndef EXPRESSIONPARSING_AND_EVALUATION_PARSER_H
#define EXPRESSIONPARSING_AND_EVALUATION_PARSER_H
using namespace std;

int parseSum(char *x);
int parseProduct(char *x);
int parseFactor(char *x);
int NotEmpty(char *x);
char Nextchar(char *x);



char Nextchar(char *x){
    x++;
    return *x;
}


int NotEmpty(char *x){
    if(*x != '\0'){
        return true;
    }
    else return false;
}

int parseSum(char *x){
    int pro1 = parseProduct(x);
    while (*x == '+' || *x == '-'){
        if(*x == '+'){
            x++;
            int pro2 = parseProduct(x);
            pro1 = pro1 + pro2;
        }
        else{
            x++;
            int pro2 = parseProduct(x);
            pro1 = pro1 - pro2;
        }



    }
    return pro1;
}



int parseProduct(char *x){
    int fac1 = parseFactor(x);
    while (*x == '*' || *x == '/'){
        if(*x == '*'){
            x++;
            int fac2 = parseFactor(x);
            fac1 = fac1 * fac2;
        }
        else{
            x++;
            int fac2 = parseFactor(x);
            fac1 = fac1 / fac2;
        }

    }
    return fac1;
}


int parseFactor(char *x){
    if(*x >= '0' && *x <= '9'){
        int number = 0;
        while (*x >= '0' && *x <= '9'){
            number = number * 10;
            number = number + *x - '0';
            x++;
        }
        return number;
    }
    else if(*x == '('){
        x++;
        int sum = parseSum(x);
        if(*x != ')'){
            cout << "Expected ) but found " << *x << endl;
            return -1;
        }
        x++;
        return sum;
    }
    else{
        cout << "Expected digit but found " << *x << endl;
        return -1;
    }
}


#endif //EXPRESSIONPARSING_AND_EVALUATION_PARSER_H
