#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct NODE{
    int value;
    struct NODE *next;
} Node;
typedef struct LIST{
    char name[10];
    int length;
    struct NODE *head;
    struct NODE *tail;
    struct LIST *next;
} List;
typedef struct MAINLIST{
    int length;
    struct LIST *head;
    struct LIST *tail;
} MainList;

// function for List
List* searchList(MainList mainList, List **prevList, char name[]);
void appendList(MainList *mainList, char name[]);
bool deleteList(MainList *mainList, char name[]);
bool nameList(MainList mainList, char name[], char newName[]);
bool sort(MainList mainList, char name[]);
bool merge(List *target, List *data);
bool reverse(MainList *mainList, char name[]);

// function for Node
Node* newNode(int value, Node *next);
Node* searchNode(List *list, Node **prevNode, int target);
Node* maxNode(List *list);
Node* minNode(List *list);
bool print(List *list);
bool append(List *list, Node *node);
bool update(List *list, int target, int value);
bool insert(List *list, int target, int value);
bool delete(List *list, int target);
bool clearAllNode(List *list);

// ohters
bool strIsNum(char str[]);
bool isValidName(char name[]);

int main(){
    MainList mainList = {0, NULL, NULL};

    char command[1001];
    const char delim[] = " \n\t\r";
    while(fgets(command, 1001, stdin) != NULL){

        char *token = strtok(command, delim);
        if (token == NULL) {
            continue;
        }
        // appendList name
        if(strcmp(token, "appendList") == 0){
            char *name = strtok(NULL, delim);
            if(name == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 1 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            appendList(&mainList, name);
            printf("appendList_SUCC\n");
        }
        // deleteList name
        else if(strcmp(token, "deleteList") == 0){
            char *name = strtok(NULL, delim);
            if(name == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 1 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (deleteList(&mainList, name)) {
                printf("deleteList_SUCC\n");
            }
        }
        // nameList name newName
        else if(strcmp(token, "nameList") == 0){
            char *name = strtok(NULL, delim);
            char *newName = strtok(NULL, delim);
            if(newName == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 2 parameters\n");
                continue;
            }
            if (!isValidName(name) || !isValidName(newName)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10 || strlen(newName) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (nameList(mainList, name, newName)) {
                printf("nameList_SUCC\n");
            }
        }
        // sort name
        else if(strcmp(token, "sort") == 0){
            char *name = strtok(NULL, delim);
            if(name == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 1 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (sort(mainList, name)) {
                printf("sort_SUCC\n");
            }
        }
        // merge targetName dataName
        else if(strcmp(token, "merge") == 0){
            // get the parameter and check parameter number
            char *targetName = strtok(NULL, delim);
            char *dataName = strtok(NULL, delim);
            if(dataName == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 2 parameters\n");
                continue;
            }
            if (!isValidName(targetName) || !isValidName(dataName)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(targetName) > 10 || strlen(dataName) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (merge(searchList(mainList, NULL, targetName), searchList(mainList, NULL, dataName)) && deleteList(&mainList, dataName)) {
                printf("merge_SUCC\n");
            }
        }
        // reverse name
        else if(strcmp(token, "reverse") == 0){
            char *name = strtok(NULL, delim);
            if(name == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 1 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (reverse(&mainList, name)) {
                printf("reverse_SUCC\n");
            }
        }
        // print name
        else if(strcmp(token, "print") == 0){
            char *name = strtok(NULL, delim);
            if(name == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 1 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (searchList(mainList, NULL, name) != NULL) {
                print(searchList(mainList, NULL, name));
            }
        }
        // append name data
        else if(strcmp(token, "append") == 0){
            char *name = strtok(NULL, delim);
            char *dataChar = strtok(NULL, delim);
            if(dataChar == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 2 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (!strIsNum(dataChar)) {
                printf("TypeError : It should be 'int'");
                continue;
            }
            long long data = atoll(dataChar);
            if (data > INT_MAX || data < INT_MIN) {
                printf("%s", "RangeError : Out of INT range (-2,147,483,648 to 2,147,483,647)\n");
                continue;
            }
            if (append(searchList(mainList, NULL, name), newNode((int)data, NULL))) {
                printf("append_SUCC\n");
            }
        }
        // update name target data
        else if(strcmp(token, "update") == 0){
            char *name = strtok(NULL, delim);
            char *targetChar = strtok(NULL, delim);
            char *dataChar = strtok(NULL, delim);
            if(dataChar == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 3 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (!strIsNum(targetChar) || !strIsNum(dataChar)) {
                printf("TypeError : It should be 'int'");
                continue;
            }
            long long target = atoll(targetChar);
            long long data = atoll(dataChar);
            if (target > INT_MAX || target < INT_MIN || data > INT_MAX || data < INT_MIN) {
                printf("%s", "RangeError : Out of INT range (-2,147,483,648 to 2,147,483,647)\n");
                continue;
            }
            if (update(searchList(mainList, NULL, name), target, data)) {
                printf("update_SUCC\n");
            }
        }
        // insert name target data
        else if(strcmp(token, "insert") == 0){
            char *name = strtok(NULL, delim);
            char *targetChar = strtok(NULL, delim);
            char *dataChar = strtok(NULL, delim);
            if(dataChar == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 3 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (!strIsNum(targetChar) || !strIsNum(dataChar)) {
                printf("TypeError : It should be 'int'");
                continue;
            }
            long long target = atoll(targetChar);
            long long data = atoll(dataChar);
            if (target > INT_MAX || target < INT_MIN || data > INT_MAX || data < INT_MIN) {
                printf("%s", "RangeError : Out of INT range (-2,147,483,648 to 2,147,483,647)\n");
                continue;
            }
            if (insert(searchList(mainList, NULL, name), target, data)) {
                printf("insert_SUCC\n");
            }
        }
        // delete name target
        else if(strcmp(token, "delete") == 0){
            char *name = strtok(NULL, delim);
            char *targetChar = strtok(NULL, delim);
            if(targetChar == NULL || strtok(NULL, delim) != NULL) {
                printf("ParameterError : The command should have 2 parameters\n");
                continue;
            }
            if (!isValidName(name)) {
                printf("TypeError : Name must start with _ or letter and include only _, letter, or number");
                continue;
            }
            if (strlen(name) > 10) {
                printf("RangeError : The length must less then or equal to 10\n");
                continue;
            }
            if (!strIsNum(targetChar)) {
                printf("TypeError : It should be 'int'");
                continue;
            }
            long long target = atoll(targetChar);
            if (target > INT_MAX || target< INT_MIN) {
                printf("%s", "RangeError : Out of INT range (-2,147,483,648 to 2,147,483,647)\n");
                continue;
            }
            if (delete(searchList(mainList, NULL, name), target)) {
                printf("delete_SUCC\n");
            }
        }
        else{
            printf("SyntaxError : The command does not exist\n");
        }
    }
}

List* searchList(MainList mainList, List **prevList, char name[]) {
    List *list = mainList.head;
    while (list != NULL) {
        if (strcmp(list->name, name) == 0) {
            return list;
        }
        if (prevList != NULL) {
            *prevList = list;
        }
        list = list->next;
    }
    printf("NameError : %s does not exist", name);
    return NULL;
}

void appendList(MainList *mainList, char name[]){
    List *list = (List*)malloc(sizeof(List));
    strcpy(list->name, name);
    list->head = NULL;
    list->tail = NULL;
    list->next = NULL;
    list->length = 0;
    if (mainList->length == 0) {
        mainList->head = list;
    } else {
        mainList->tail->next = list;
    }
    mainList->tail = list;
    mainList->length++;
}

bool deleteList(MainList *mainList, char name[]){
    List *prev = NULL, *list = searchList(*mainList, &prev, name);
    if (list == NULL) {
        return false;
    }
    if (list == mainList->tail) {
        mainList->tail = prev;
    }
    if (list == mainList->head) {
        mainList->head = list->next;
    } else {
        prev->next = list->next;
    }
    clearAllNode(list);
    free(list);
    mainList->length--;
    return true;
}

bool nameList(MainList mainList, char name[], char newName[]){
    List *list = searchList(mainList, NULL, name);
    if (list == NULL) {
        return false;
    }
    strcpy(list->name, newName);
    return true;
}

bool sort(MainList mainList, char name[]){
    List *list = searchList(mainList, NULL, name), bukkit[256], plus = {"", 0, NULL, NULL, NULL}, minus = {"", 0, NULL, NULL, NULL};
    if (list == NULL) {
        return false;
    }
    Node *node = list->head, *next;
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    while (node != NULL) {
        next = node->next;
        if (node->value < 0) {
            append(&minus, node);
        } else {
            append(&plus, node);
        }
        node = next;
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 256; j++) {
            bukkit[j].length = 0;
            bukkit[j].head = NULL;
            bukkit[j].tail = NULL;
        }
        node = plus.head;
        plus.length = 0;
        plus.head = NULL;
        plus.tail = NULL;
        while (node != NULL) {
            next = node->next;
            append(&bukkit[(node->value >> (8 * i)) & 0xff], node);  
            // (node->value >> (8 * i)) & 0xff ä½???¨ç?ºå??value??¤ä»¥256???iæ¬¡æ?¹å??mod 256ï¼????éº¼å????¯å????ºä????????ç®?æ¯??????????ç®?å¿?
            // ç­????ç®?å¼?ï¼?(value / pow(256, i)) % 256
            node = next;
        }
        for (int j = 0; j < 256; j++) {
            merge(&plus, &bukkit[j]);
        }
        for (int j = 0; j < 256; j++) {
            bukkit[j].length = 0;
            bukkit[j].head = NULL;
            bukkit[j].tail = NULL;
        }
        node = minus.head;
        minus.length = 0;
        minus.head = NULL;
        minus.tail = NULL;
        while (node != NULL) {
            next = node->next;
            append(&bukkit[((node->value ^ INT_MIN) >> (8 * i)) & 0xff], node);  
            // (node->value >> (8 * i)) & 0xff ä½???¨ç?ºå??value + 2???31æ¬¡æ?¹å????¤ä»¥256???iæ¬¡æ?¹å??mod 256ï¼????éº¼å????¯å????ºä????????ç®?æ¯??????????ç®?å¿?
            // INT_MIN???-2^31ï¼?äº???²å?¶è¡¨ç¤ºç?ºç¬¦???ä½???ºä??ï¼??????¸å?¼ä????¨ç??0ï¼?å°?ä»???°æ?????è®????å°???¼è?????0ï¼?-1è®???ºæ??å¤§å?¼ï??å¤§å?????ä¿?ä¸?è®?ï¼????æ­???¸å?¨é??ç®????ä¸?å®¹æ????????é¡?
            // ç­????ç®?å¼?ï¼?((value + 2147483648) / pow(256, i)) % 256
            node = next;
        }
        for (int j = 0; j < 256; j++) {
            merge(&minus, &bukkit[j]);
        }
    }
    merge(list, &minus);
    merge(list, &plus);
    return true;
}

bool merge(List *target, List *data){
    if (target == NULL || data == NULL) {
        return false;
    }
    if (data->head == NULL) {
        return true;
    }
    if (target->head == NULL) {
        target->head = data->head;
    } else {
        target->tail->next = data->head;
    }
    target->tail = data->tail;
    target->length += data->length;
    return true;
}

bool reverse(MainList *mainList, char name[]){
    List *list = searchList(*mainList, NULL, name);
    if (list == NULL) {
        return false;
    }
    Node *node = list->head, *next;
    list->tail = list->head;
    list->head = NULL;
    while (node != NULL) {
        next = node->next;
        node->next = list->head;
        list->head = node;
        node = next;
    }
    return true;
}

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// function for Node
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

Node* newNode(int value, Node *next){
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

Node* searchNode(List *list, Node **prevNode, int target){
    if (list == NULL) {
        return NULL;
    }
    Node *node = list->head;
    while (node != NULL) {
        if (node->value == target) {
            return node;
        }
        if (prevNode != NULL) {
            *prevNode = node;
        }
        node = node->next;
    }
    printf("ValueError : %d does not exist\n", target);
    return NULL;
}

Node *maxNode(List *list){
    if (list == NULL) {
        return NULL;
    }
    Node *node = list->head, *maxNode;
    int maxNum = INT_MIN;
    while (node != NULL) {
        if (node->value > maxNum) {
            maxNum = node->value;
            maxNode = node;
        }
        node = node->next;
    }
    return maxNode;
}

Node *minNode(List *list){
    if (list == NULL) {
        return false;
    }
    Node *node = list->head, *minNode;
    int minNum = INT_MAX;
    while (node != NULL) {
        if (node->value < minNum) {
            minNum = node->value;
            minNode = node;
        }
        node = node->next;
    }
    return minNode;
}

bool print(List *list){
    if (list == NULL) {
        return false;
    }
    Node *node = list->head;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
    return true;
}

bool append(List *list, Node *node){
    if (list == NULL) {
        return false;
    }
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->length++;
    return true;
}

bool update(List *list, int target, int value){
    if (list == NULL) {
        return false;
    }
    Node *node = searchNode(list, NULL, target);
    if (node == NULL) {
        return false;
    }
    node->value = value;
    return true;
}

bool insert(List *list, int target, int value){
    if (list == NULL) {
        return false;
    }
    Node *prev = NULL, *next = searchNode(list, &prev, target);
    if (next == NULL) {
        return false;
    }
    Node *node = newNode(value, next);
    if (prev == NULL) {
        list->head = node;
    } else {
        prev->next = node;
    }
    list->length++;
    return true;
}

bool delete(List *list, int target){
    if (list == NULL) {
        return false;
    }
    Node *prev = NULL, *node = searchNode(list, &prev, target);
    if (node == NULL) {
        return false;
    }
    if (node->next == NULL) {
        list->tail = prev;
    }
    if (prev == NULL) {
        list->head = node->next;
    } else {
        prev->next = node->next;
    }
    free(node);
    list->length--;
    return true;
}

bool clearAllNode(List *list){
    if (list == NULL) {
        return false;
    }
    Node *node = list->head, *next;
    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return true;
}

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// others
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

bool strIsNum(char str[]){
    if (!(isdigit(str[0]) || str[0] == '-')) {
        return false;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool isValidName(char name[]){
    if (!(isalpha(name[0]) || name[0] == '_')) {
        return false;
    }
    for (int i = 1; name[i] != '\0'; i++) {
        if (!(isalnum(name[i]) || name[0] == '_')) {
            return false;
        }
    }
    return true;
}