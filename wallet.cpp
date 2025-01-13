#include<iostream>
using namespace std;
class Wallet{
private:
int wallet_id;
float balance;
int user_id;
public:
int getwallet_id(){
    return wallet_id;
}
float getBalance(){
        return balance;
}
int getusert_id(){
return user_id;
}

void setWalletId(int wallet_id){
    this->wallet_id=wallet_id;
}
void setBlance(float balance){
    this->balance=balance;
}
void setUserId(int user_id){
    this->user_id=user_id;
}

void showbalance(){
           system("cls");
        cout<<"---------------------------------------------------------\n";
        cout<<"|                     My Wallet                         |\n";
        cout<<"---------------------------------------------------------\n";
        cout << "Your Balance Is : " << balance << endl;
}

};
void function(Wallet& w);//class object is passed 


int main(){

}

float deposit(){
cout<<"Enter "
}
float withdraw(){
}
void function(Wallet& w){
int wallet_choice;
cout<<"Press 0 to go back to Home page."<<endl;
cout<<"Press 1 to Deposit an Amount: "<<endl;
cout<<"Press 2 to Withdraw an Amount: "<<endl;
cin>>wallet_choice;
bool walletch=false;
do{
cin>>wallet_choice;
switch (wallet_choice)
{
case 0:
//displayhomepage();
walletch=true;
    break;
case 1:
deposit();
walletch=true;
    break;

 case 2:
 withdraw();
 walletch=true;
    break;

default:
cout<<"Invalid choice."<<endl;
    break;
}
}
while(!walletch);
}