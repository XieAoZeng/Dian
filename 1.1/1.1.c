#include <stdio.h>;
#include <string.h>;

typedef struct {
    char name[100];
    char number[100];
    double price;
} goods;
//初始化货物清单
goods list[]={
    {"cola","001",3.50},
    {"Lollipop","002",0.50},
    {"noodles","003",6.00},
};
int count = sizeof (list)/sizeof(list[0]);
//程序需要查找列表中的输入量
void searchgood(char *input){
    for (int i=0;i < count ; i++){
        if(strcmp (list[i].number , input )==0){
            printf ("%s\t%f\n",list[i].name , list[i].price);
            return ;
        }
    printf ("not find\n");
    }
}


int main(){
    char input[100];

    while(1){
        printf(">");
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")]='\n';

        if (strcmp(input,"quit")==0  || strcmp(input,"exit")==0){
            break;
        }
        else if(strcmp(input,"prices")==0){
            printall();  //输出全部货物，应在开始补充一个新函数
        }
        else {
            char *take =strtok(input ," ");
            while (take != NULL){
                
            }
        }
    }
}