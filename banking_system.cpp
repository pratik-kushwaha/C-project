/* Bank ATM system */
#include <iostream>
using namespace std;
class RBI{
    public:
        int choice,withdrawLimit,depositLimit,amount,balance;
        char ch;
    RBI(){      //setting upperbound & intial amount for all banks under RBI
        withdrawLimit=20000;
        depositLimit=25000;
        balance=0;
    }
    public:
        void depositMoney(){    //to deposit money to bank
            cout<<"\nEnter amount to be deposited to your bank account: ";
            cin>>amount;
            if(amount<=depositLimit && amount>0){
                balance+=amount;    //updating balance
                cout<<"\n"<<amount<<" has been added successfuly to your account!";
                cout<<"\nDo you want to check your balance?(y/n): ";
                cin>>ch;
                if(ch=='y' || ch=='Y')
                    showBalance();
            }
            else if(amount<1){
                cout<<"\nEnter a valid amount!";
            }
            else{   //when entered amount is greater than deposit limit
                cout<<"\nDeposit limit exceeds";
                cout<<"\nRange is 0-"<<depositLimit;
            }
        }
        void withdrawMoney(){   //to withdraw money from bank
            cout<<"\nEnter amount to be withdraw from your bank account: ";
            cin>>amount;
            if(amount<=balance && amount>0 && amount<=withdrawLimit){
                balance-=amount;    //updating balance
                cout<<"\n"<<amount<<" has been deducted successfuly from your account!";
                cout<<"\nDo you want to check your balance?(y/n): ";
                cin>>ch;
                if(ch=='y' || ch=='Y')
                    showBalance();
            }
            else if(amount<1){
                cout<<"\nEnter a valid amount!";
            }
            else if(amount>withdrawLimit){      //when entered amount is greater than withdraw limit
                cout<<"\nWithdraw limit exceeds";
                cout<<"\nRange is 0-"<<withdrawLimit;
            }
            else{
                cout<<"\nInsufficient balance!";
            }

        }
        void showBalance(){     //to show bank account balance
            cout<<"\nBank balance is "<<balance<<" rs.";
        }
        virtual void welcomeNote()=0;
};
class SBI: public RBI{
    public:
        SBI(){
            withdrawLimit=15000,depositLimit=20000;     //SBI sets its ATM limits
        }
        void welcomeNote(){
            cout<<"\n*** Welcome to State Bank of India ATM ***";
        }
};
class BOB: public RBI{
    public:
        BOB(){
            withdrawLimit=12000,depositLimit=25000;     //SBI sets its ATM limits
        }
        void welcomeNote(){
            cout<<"\n*** Welcome to Bank of Baroda ATM ***";
        }
};
class BOI: public RBI{
    public:
        BOI(){
            withdrawLimit=10000,depositLimit=15000;     //SBI sets its ATM limits
        }
        void welcomeNote(){
            cout<<"\n*** Welcome to Bank of India ATM ***";
        }
};
int main()
{
    int choice;
    char ch;
    /* Withdrawl & deposit amount vary from one bank's ATM to another */
    cout<<"\nSelect a bank ATM for any transaction";
    cout<<"\n1. Bank of Baroda\n2. State Bank of India\n3. Bank of India";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:     //Bank of India bank's ATM
        {
            BOB b;
            b.welcomeNote();
            do
            {
                cout<<"\n1. Deposit\n2. Withdraw\n3. Balance enquiry";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        b.depositMoney();
                        break;
                    case 2:
                        b.withdrawMoney();
                        break;
                    case 3:
                        b.showBalance();
                        break;
                    default:
                        cout<<"\nEnter a valid choice!";
                }
                cout<<"\nDo you want to continue?(y/n): ";
                cin>>ch;
            }while(ch=='y' || ch=='Y');
            break;
        }
        case 2:     //SBI bank's ATM
        {
            SBI s;
            s.welcomeNote();
            do
            {
                cout<<"\n1. Deposit\n2. Withdraw\n3. Balance enquiry";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        s.depositMoney();
                        break;
                    case 2:
                        s.withdrawMoney();
                        break;
                    case 3:
                        s.showBalance();
                        break;
                    default:
                        cout<<"\nEnter a valid choice!";
                }
                cout<<"\nDo you want to continue?(y/n): ";
                cin>>ch;
            }while(ch=='y' || ch=='Y');
            break;
        }
        case 3:     //Bank of India bank's ATM
        {
            BOI B;
            B.welcomeNote();
            do
            {
                cout<<"\n1. Deposit\n2. Withdraw\n3. Balance enquiry";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        B.depositMoney();
                        break;
                    case 2:
                        B.withdrawMoney();
                        break;
                    case 3:
                        B.showBalance();
                        break;
                    default:
                        cout<<"\nEnter a valid choice!";
                }
                cout<<"\nDo you want to continue?(y/n): ";
                cin>>ch;
            }while(ch=='y' || ch=='Y');
            break;
        }
        default:
            cout<<"\nEnter a valid choice!";
    }
    return 0;
}
