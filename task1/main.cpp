#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

#define MAX_SIZE 100
#define randint(a, b) (int)round(((float)rand() / RAND_MAX) * (b - a) + a)

//int, char, float, double, char*

char select_type(){
    printf("Select type\n1 ---int\n\
2 --- char\n\
3 --- float\n\
4 --- double\n\
5 --- char*\n");
    printf(">>");
    return getchar();
}

int get_value(){ 
    int ans;
    printf("Value to find: ");
    scanf("%d", &ans);
    return ans;
}

void display_help(){
    printf("1 --- Display collection\n\
2 --- Find element\n\
3 --- Display help\n");
}

template<typename T>
T *init_collection(int size){
    T *collection = new T[size];
    for(int i = 0; i < size; i++){
        collection[i] = (T)randint(0, 100);
    }
    return collection;
} 

template<typename T>
void find(T collection[MAX_SIZE], int size, T what){
    for(int i = 0; i < size; i++){
        if(collection[i] == what){
            printf(">>Index of element: %d\n", i);
            return;
        }
    }
    throw runtime_error("No such element in collection!");
}

template<typename T>
void process(T collection[], int size){
    while(1){
        char c = getchar();
        if(c == '\n')
            printf(">>");
        if(c == '1'){
            printf("[");
            for(int i = 0; i < size; i++){
                printf("%d ", collection[i]);
            }
            printf("]\n");
        }else if(c == '2'){
            find<T>(collection, size, (T)get_value());
        }else if(c == '3'){
            display_help();
        } 
    }
}

int main(){
    char *p = (char *)10;
    printf("%d\n", p);
    char t = select_type();
    int size = randint(30, MAX_SIZE);

    srand(time(NULL));

    if(t == '1'){
        int *collection = init_collection<int>(size);
        process<int>(collection, size);
    }else if(t == '2'){
        char *collection = init_collection<char>(size);
        process<char>(collection, size);
    }else if(t == '3'){
        float *collection = init_collection<float>(size);
        process<float>(collection, size);
    }else if(t == '4'){
        double *collection = init_collection<double>(size);
        process<double>(collection, size);
    }else if(t == '5'){
        char **collection = init_collection<char*>(size);
        process<char*>(collection, size);
    }else{
        throw runtime_error("No such option!");
    }


    return 0;
}

