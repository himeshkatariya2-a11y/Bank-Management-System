
#include<iostream>
#include<vector>
using namespace std;

struct Bank{
    private:
        string name;
        long long accountNo;    
        float balance;

    public:
        void createAccount(){
            cout<<"Enter Name :";
            cin>>name;

            cout<<"Enter Account Number :";
            cin>>accountNo;

            cout<<"Enter Initial Balance :";
            cin>>balance;
            cout<<"\n";
            
            cout<<"Account Created Successfully.";
        }

        void deposit(){
            float amount;

            cout<<"Enter Amount :";
            cin>>amount;

            balance=balance+amount;

            cout<<"\nMoney Deposited Successfully.\n";

        }

        void withdraw(){
            float amount;

            cout<<"Enter Amount :";
            cin>>amount;

            if(amount<=balance){
                balance=balance-amount;
                cout<<"\nMoney Withdrawn Successfully.\n";
            }
            else{
                cout<<"Insufficient Balance.\n";
            }
        }

        void showBalance(){

            cout<<"Name :"<<name;

            cout<<"\nRemaining Balance :"<<balance<<"\n";

        }

        long long getAccountNo(){
            return accountNo;
        }
};

int main(){
    Bank b[1000];
    int accountCount=0;
    int choice;

    do{
        cout<<"\n>>>>> Bank Management System <<<<<\n";

        cout<<"\n1. Create Account \n";
        cout<<"2. Deposit \n";
        cout<<"3. Withdraw \n";
        cout<<"4. Show Balance \n";
        cout<<"5. Exit \n";

        cout<<"\nEnter your choice :";
        cin>>choice;
        cin.clear();
        cin.ignore();

        switch(choice){
            case 1:
                if(accountCount<1000){
                    b[accountCount].createAccount();
                    accountCount++;
                }
                else{
                    cout<<"\n Account Number Space is Full !";
                    break;
                }
                break;
            
            case 2:{ 
                long long searchAccNo;
                cout<<"\nEnter Account Number :";
                cin>>searchAccNo;
                
                bool found=false;
                for(int i=0;i<accountCount;i++){
                    if(b[i].getAccountNo()==searchAccNo){
                        b[i].deposit();
                        found=true;
                        break;
                    }
                }    
                if(!found){
                    cout<<"Invalid Account Number!";
                    break;
                }
            }
            case 3:{
                long long searchAccNum;
                cout<<"\nEnter Account Number :";
                cin>>searchAccNum;
                
                bool found=false;
                for(int i=0;i<accountCount;i++){
                    if(b[i].getAccountNo()==searchAccNum){
                        b[i].withdraw();
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Invalid Account Number!";
                    break;         
                }
                break;
            }    
            case 4:{
                long long accountNo;
                cout<<"\nEnter Account Number :";
                cin>>accountNo;
                
                bool found = false;
                for(int i=0;i<accountCount;i++){
                    if(b[i].getAccountNo()==accountNo){
                        b[i].showBalance();
                        found=true;
                        break;
                    }
                }    
                if(!found){
                    cout<<"Invalid Account Number!";
                    break;    
                }
                break;
            }
            case 5:{
                cout<<"Thanks";
                break;
            }    
            default :{
                cout<<"\nInvalid Choice.";
                break;
            }   
        }
    }
    while(choice!=5);
    return 0;

}
