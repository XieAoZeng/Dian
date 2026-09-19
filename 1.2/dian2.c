#include <stdio.h>
#include <string.h>

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

//输出全部货物
void printall(){
    printf("Item\tNo.\tPri.\n");
    printf("-----------------\n");
    for(int i=0 ; i<count ; i++){
        printf("%s\t%s\t%.2f\n",list[i].name,list[i].number,list[i].price);
    }
}

//需要实现的功能:1.添加or减少商品数目,并且显示价格  2.打印小票   3.清空记录   4.结账

void drop();   /* 清空购物车 */
void print();  /*打印小票*/
void checkout();  /*结账,打印小票并清空记录*/

//添加一个购物车来记录客户所选择的商品
typedef struct {
    goods choose;   //表示已选择的商品
    int  buycount;    //表示购买数量
}cartitem;

cartitem cart[100];
int cartsize=0 ;  //记录购物车中货物种类


int findgoodsindex(char *id){   //在商品列表中查找输入的商品是否存在
    for(int i=0 ;i < count ;i++){
        if(strcmp(list[i].number,id)==0){
            return i;
        }
    }
    return -1;
}

int findcartindex(char *id){   //在购物车列表中查找输入的商品是否存在
    for(int i=0 ;i < cartsize ;i++){
        if(strcmp(cart[i].choose.number,id)==0){
            return i;
        }
    }
    return -1;
}

//增减购物车内的商品
void addgoods(char *id, int delta){
    int goodsinlist = findgoodsindex(id);
    if(goodsinlist==-1){
        printf("未找到该商品:%s",id);
        return ;
    }

    int goodsincart = findcartindex(id);
    if( goodsincart == -1){//表明购物车里没有该商品
        if(delta == -1){
            printf("未将此物品加入购物车，无法减少其数目");
            return;
        }
        else{
            cart[cartsize].choose = list[goodsinlist];
            cart[cartsize].buycount =1  ;
            cartsize++;
        }
    }
    else{//购物车内有该商品，要进行处理
      if(delta == -1){
        if (cart[goodsincart].buycount == 1){
            for(int i = goodsincart ; i < cartsize-1 ; i++){
                cart[i]=cart[i+1];
            }
            cartsize --;
        }
        else {        
            cart[goodsincart].buycount += delta ;
        }
      }
      else{
        cart[goodsincart].buycount += delta;
      }
    }
    //输出当前购物车内商品以及价格等
}

int main(){
    char input[100];

    while(1){
        printf(">");
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")]='\0';

        if (strcmp(input,"quit")==0  || strcmp(input,"exit")==0){
            break;
        }
        else if(strcmp(input,"prices")==0){
            printall();  //输出全部货物，应在开始补充一个新函数
        }
        else if(strcmp(input,"drop")==0){
            drop();
        }
        else if(strcmp(input,"print")==0){
            print();
        }
        else if(strcmp(input,"checkout")==0){
            checkout();
        }
        else {          /*需实现：添加或减少商品数目*/
            char *take =strtok(input ," ");
            while (take != NULL){
                int delta=1;
                char id[50];
                if(take[0]=="-"){
                    delta=-1;
                    strcpy(id,take+1);
                }
                else{
                    strcpy(id,take);
                }
                addgoods(id , delta );
                take = strtok(NULL ," ");
            }
        }
    }
}

