#include<bits/stdc++.h>
using namespace std;

string Random(int n){
    string pass="";
    while(pass.length()!=n){
        int r=rand()%3;
        if(r==0){
            int number=rand()%10;
            pass+=to_string(number);
        }else if(r==1){
            int ascii=rand()%2;
            if(ascii==0){
                //capital (65–90)
                ascii=rand()%(90-65+1)+65;
            }else{
                //small (97–122)
                ascii=rand()%(122-97+1)+97;
            }
            pass+=static_cast<char>(ascii);
        }else{
            //special characters Special Characters(32–47 && 58–64 && 91–96 && 123–126)
            int c=rand()%4;
            int ascii=32;
            switch(c){
                case 0:
                    ascii=rand()%(47-32+1)+32;
                    break;
                case 1:
                    ascii=rand()%(64-58+1)+58;
                    break;
                case 2:
                    ascii=rand()%(96-91+1)+91;
                    break;
                case 3:
                    ascii=rand()%(126-123+1)+123;
            }
            pass+=static_cast<char>(ascii);
        }
    }
    return pass;
}

int main(){
    srand(time(0));
    int n;
    cout<<"Enter the length of password you want to generate = ";
    cin>>n;
    if(n<6){
        cout<<"Password length should be greater than or equal to 6"<<endl;
    }else{
        string password = Random(n);
        cout<<"Computer generated password of given length : "<<password<<endl;
    }
    return 0;
}