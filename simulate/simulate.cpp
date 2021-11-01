#include"tactics.h"
#include"tactics.cpp"
ifstream in("info.txt");
ofstream out("simulate.txt");
string show(int x)
{   
   if(x == 0)return "3 ";
   if(x == 1)return "4 ";
   if(x == 2)return "5 ";
   if(x == 3)return "6 ";
   if(x == 4)return "7 ";
   if(x == 5)return "8 ";
   if(x == 6)return "9 ";
   if(x == 7)return "10 ";
   if(x == 8)return "J ";
   if(x == 9)return "Q ";
   if(x == 10)return "K ";
   if(x == 11)return "A ";
   if(x == 12)return "2 ";
   if(x == 13)return "JokerA ";
   if(x == 14)return "JokerB ";
   else return "U";
}
void PrintP(struct play_pokers S)
{   
    if(S.number == 0)out<<"ybq ";
    for(int i = 0;i<=14;i++)
    {
        if(S.poker[i]>0)
        {
            for(int j=0; j<=S.poker[i]-1;j++)
            {
                out<<show(i)<<" ";
            }
        }   
    }
    out<<endl;
}
void PrintS(tactics S)
{  out<<S.name<<endl;
   for(int i = 0;i<=14;i++)
    {
        if(S.poker[i]>0)
        {
            for(int j=0; j<=S.poker[i]-1;j++)
            {
                out<<show(i)<<" ";
            }
        }   
    }
    out<<endl;
    out<<"poker_number"<<S.poker_num<<endl;
    for(int i = 0; i<=3;i++)
    {    
        out<<i+1<<":  ";
        for(int j = 0; j<S.poker_another_repre[i].size();j++)
        {
            out<<show(S.poker_another_repre[i][j])<<" ";
        }
        out<<endl;
    }
}
int main()
{
   int a[15],b[15];
   for(int i = 0; i<=14;i++)
   {
       in>>a[i];
   }
   for(int i = 0; i<=14;i++)
   {
       in>>b[i];
   }
   tactics A(a,"Alice");
   tactics B(b,"Bob");
   PrintS(A);
   PrintS(B);
   struct play_pokers X,Y;
   X.main_card = -1;
   X.number = 0;
   X.pt = Unknown;
   for(int i = 0; i<=14; i++)
   {
       X.poker[i] = 0;
   }
   Y.main_card = -1;
   Y.number = 0;
   Y.pt = Unknown;
   for(int i = 0; i<=14; i++)
   {
       Y.poker[i] = 0;
   }
   bool Aw = false;
   bool Bw = false;
   //PrintP(X);
   //PrintS(A);
   /*for(int j = 0; j<=A.poker_another_repre[2].size()-1;j++)
        {
            cout<<A.poker_another_repre[2][j]<<" ";
        }*/
   Aw = A.methods(&X,&Y,true);
   out <<"Alice:  ";
   PrintP(Y);
   PrintS(A);
   PrintS(B);
  while(true)
   {
     if(Aw){out << "Alice win"<<endl;break;}
     if(Y.pt == Unknown)
     {
         Bw = B.methods(&Y,&X,true);
         out <<"Bob:  ";
         PrintP(X);
         PrintS(A);
         PrintS(B);
         if(Bw){out<< "Bob win"<<endl;break;}
     }
     else
     {
         Bw = B.methods(&Y,&X,false);
         out <<"Bob:  ";
         PrintP(X);
         PrintS(A);
         PrintS(B);
         if(Bw){out<< "Bob win"<<endl;break;}
     }
     if(X.pt == Unknown)
     {
         Aw = A.methods(&X,&Y,true);
         out <<"Alice:  ";
         PrintP(Y);
         PrintS(A);
         PrintS(B);
         if(Aw){out << "Alice win"<<endl;break;}
     }
     else 
     {
         Aw = A.methods(&X,&Y,false);
         out <<"Alice:  ";
         PrintP(Y);
         PrintS(A);
         PrintS(B);
         if(Aw){out << "Alice win"<<endl;break;}
     }
   }

   
return 0;
}