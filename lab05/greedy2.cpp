
#include<iostream>
using namespace std;





void displayArray(int S[],int n){
    for(int i=0;i<n;i++){

    cout<<S[i]<<" ,";
    }
   cout<<endl;
}


int main(){
int profit[]={60,100,120};
int weight[]={10,20,30};
int weight_level=50;
int profit_len = sizeof(profit)/sizeof(profit[0]);
int weight_len = sizeof(weight)/sizeof(weight[0]);
int total_profit=0;

int profit_ratio[profit_len];


    for(int i=0;i<profit_len;i++){
        profit_ratio[i]=profit[i]/weight[i];
    }

    for(int i=0;i<profit_len;i++){

        for(int j=i;j<profit_len;j++){
            if(profit_ratio[i]< profit_ratio[j]){
                swap(profit_ratio[i],profit_ratio[j]);
                swap(profit[i],weight[j]);
                swap(weight[i],weight[j]);
            }
        }
    }

  //displayArray(profit_ratio,profit_len);

    int temp_weight=weight[0];
   for(int i=0;i<profit_len;i++){

       if(temp_weight<weight_level){
            total_profit += profit[i];
            temp_weight += weight[i+1];
            continue;
        }
        temp_weight -= weight[i];
        int atLestW=weight_level - temp_weight;

         total_profit = total_profit + ((profit[i]*atLestW)/weight[i]);

        if(!(temp_weight<weight_level)){
            break;
        }
        continue;

   cout<<temp_weight<<endl;
   }
cout<<total_profit<<endl;
return 0;
}
