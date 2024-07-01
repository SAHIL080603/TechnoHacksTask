#include <bits/stdc++.h>
using namespace std;
string arr[9]={"ROCK","PAPER","SCISSOR","ROCK","PAPER","SCISSOR","ROCK","PAPER","SCISSOR"};

string BotSelection()
{
    int bot = rand() % 9;
    return arr[bot];
}
bool WinAndLoss(string bot, string user){
    if(bot == "ROCK" && user == "PAPER" || bot == "PAPER" && user == "SCISSOR" || bot=="SCISSOR" && user =="ROCK"){
        return true;
    }
    return false;
}

int main(){
    srand(time(NULL));
    cout<<"Welcome to Rock,PaperScissor game\nBelow are some Instructions\n";
    cout<<"1=ROCK\n2=PAPER\n3=SCISSOR\n";
    cout<<"Above desciption shows which numerical selection denotes which object that you need input when prompted\nAnyways Happy Playing :) !!\n\n";
    int n=1,score=0;
    cout<<"Enter number of rounds you want to play = ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string bot = BotSelection();
        string user;
        int u;
        cout<<"\n\nRound "<<i+1<<":\n";
        cout<<"Enter your choice (from 1,2,3)= ";
        cin>>u;
        if(u==1||u==2||u==3){
            user=arr[u-1];
            cout<<"Bot Selection : "<<bot<<endl;
            cout<<"Your Selection : "<<user<<endl;
            if(bot==user){
                cout<<"Tie\n";
                continue;
            }
            if(WinAndLoss(bot,user)){
                cout<<"You win\n";
                score++;
            }else{
                cout<<"You lose\n";

            }
        }else{
            cout<<"Invalid input\n";
        }
    }
    cout<<"\n\nYour Final Score = "<<score<<endl;
    system("PAUSE");
    return 0;
}
