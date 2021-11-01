#include"tactics.h"

tactics::tactics(int* pokers,string s)
{   
    poker_another_repre.resize(4);
    poker_num = 0;
    name = s;
    for(int i = 0; i<= 14;i++)
    {   
       
        poker[i] = pokers[i];
        if(poker[i] == 1)
        {
           poker_another_repre[0].push_back(i);
           poker_num++;
           enemy_poker_num++;
        }
        if(poker[i] == 2)
        {
            poker_another_repre[1].push_back(i);
            poker_num+=2;
            enemy_poker_num+=2;
        }
        if(poker[i] == 3)
        {
            poker_another_repre[2].push_back(i);
            poker_num+=3;
            enemy_poker_num+=3;
        }
        if(poker[i] == 4)
        {
            poker_another_repre[3].push_back(i);
            poker_num+=4;
            enemy_poker_num+=4;
        }
    }
    for(int i = 0; i<=12;i++)
    {
        enemy_upperbound[i] = 4 - poker[i];
    }
    for(int i = 0; i<=3;i++)
    {
        sort(poker_another_repre[i].begin(),poker_another_repre[i].end(),greater<int>());
    }
}

bool tactics::methods(struct play_pokers* in, struct play_pokers* out, bool randoms)
{   
    out->number = 0;
    out->main_card = -1;
    out->pt = Unknown;
    for(int i = 0; i<=14;i++)
    {
        out->poker[i] = 0;
    }
    if(randoms == true)
    {  int xmin = 0;
       for(int i = 0; i<=14;i++)
       {
          if(poker[i] > 0)
          {
              xmin = i;
              break;
          }
       }
       int count = 0;
       int split = 0;
       bool has = false;
       if(poker[xmin] == 1)
       {  
          if(xmin+4<=12 && poker[xmin+1] > 0 && poker[xmin+2] > 0 && poker[xmin+3] > 0 && poker[xmin+4] > 0)
          {
              int sum = 0;
              for(int g = xmin;g<=xmin+4;g++)
              {
                  if(poker[g] == 1)sum++;
              }
              if(sum >= 3)
              {
                  
                  
                  poker_num-=5;
               for(int i = xmin; i<=xmin+4;i++)
        {    
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[i]-1].begin(),poker_another_repre[poker[i]-1].end(),i);
            if(pos!= poker_another_repre[poker[i]-1].end())
            {
                poker_another_repre[poker[i]-1].erase(pos);
            }
             poker[i]-=1;
             if(poker[i]>0)
               {
                   poker_another_repre[poker[i]-1].push_back(i);
                   sort(poker_another_repre[poker[i]-1].begin(),poker_another_repre[poker[i]-1].end(),greater<int>());
               }
               out->poker[i] = 1;

        }
                  out->length = 5;
                  out->number = 5;
                  out->multi=1;
                  out->main_card=xmin;
                  out->itv=1;
                  out->pt = shunzi;
                  goto End;
              }
          }
          out->poker[xmin] = 1;
          out->pt = one;
          out->number = 1;
          out->main_card = xmin;
          poker[xmin] = 0;
          poker_another_repre[0].pop_back();
          poker_num--;
          goto End;
       }
       if(poker[xmin] == 2)
       {
          out->poker[xmin] = 2;
          out->pt = two;
          out->number = 2;
          out->main_card = xmin;
          poker[xmin] = 0;
          poker_another_repre[1].pop_back();
          poker_num-=2;
          goto End;
       }
       if(poker[xmin] == 3)
       {  
          if(poker_another_repre[0].size()>0)
          {
              int x = poker_another_repre[0][poker_another_repre[0].size()-1];
              out->poker[xmin] = 3;
              out->poker[x] = 1;
              out->pt = three_one;
              out->main_card=xmin;
              out->number =4;
              poker[xmin] = 0;
              poker[x] = 0;
              poker_another_repre[0].pop_back();
              poker_another_repre[2].pop_back();
              poker_num -=4;
              goto End;
          }
          if(poker_another_repre[1].size()>0)
          {
              int x = poker_another_repre[1][poker_another_repre[1].size()-1];
              out->poker[xmin] = 3;
              out->poker[x] = 2;
              out->pt = three_two;
              out->main_card=xmin;
              out->number =5;
              poker[xmin] = 0;
              poker[x] = 0;
              poker_another_repre[1].pop_back();
              poker_another_repre[2].pop_back();
              poker_num -=5;
              goto End;
          }
          out->poker[xmin] = 3;
          out->pt = three;
          out->number = 3;
          out->main_card = xmin;
          poker[xmin] = 0;
          poker_another_repre[2].pop_back();
          poker_num-=3;
          goto End;
       }
        if(poker[xmin] == 4)
       {  
           if(poker_another_repre[0].size()>1)
          {
              int x = poker_another_repre[0][poker_another_repre[0].size()-1];
              int y = poker_another_repre[0][poker_another_repre[0].size()-2];
              out->poker[xmin] = 4;
              out->poker[x] = 1;
              out->poker[y] = 1;
              out->pt = four_one_one;
              out->main_card=xmin;
              out->number =6;
              poker[xmin] = 0;
              poker[y] = 0;
              poker[x] = 0;
              poker_another_repre[0].pop_back();
              poker_another_repre[0].pop_back();
              poker_another_repre[3].pop_back();
              poker_num -=6;
              goto End;
          }
          if(poker_another_repre[1].size()>1)
          {
              int x = poker_another_repre[1][poker_another_repre[1].size()-1];
              int y = poker_another_repre[1][poker_another_repre[1].size()-2];
              out->poker[xmin] = 4;
              out->poker[x] = 2;
              out->poker[y] = 2;
              out->pt = four_two_two;
              out->main_card=xmin;
              out->number =8;
              poker[xmin] = 0;
              poker[y] = 0;
              poker[x] = 0;
              poker_another_repre[1].pop_back();
              poker_another_repre[1].pop_back();
              poker_another_repre[3].pop_back();
              poker_num -=8;
              goto End;
          }
          out->poker[xmin] = 4;
          out->pt = four;
          out->number = 4;
          out->main_card = xmin;
          poker[xmin] = 0;
          poker_another_repre[3].pop_back();
          poker_num-=4;
          goto End;
       }
    }
   else
   {   
       if(in->pt == one)
       {     
              int x = -1;
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 1)
                   {x=i;
                   goto Chupai1;}
               }
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 2)
                   {x=i;
                   goto Chupai1;}
               }
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 3)
                   {x=i;
                   goto Chupai1;}
               }
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 4)
                   {x=i;
                   goto Chupai1;}
               }

  Chupai1:     
               if(x==-1)goto End;
               //cout<<"x: "<<x<<" "<<poker[x]<<endl;
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),x);
            if(pos!= poker_another_repre[poker[x]-1].end())
            {
                poker_another_repre[poker[x]-1].erase(pos);
            }
               
               poker[x]--;
               if(poker[x]>0)
               {
                   poker_another_repre[poker[x]-1].push_back(x);
                   sort(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),greater<int>());
               }
               poker_num--;
               out->poker[x] = 1;
               out->pt = one;
               out->number=1;
               out->main_card=x;
               goto End;
           
       }
       if(in->pt == two)
       {
               
               int x = -1;
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 2)
                   {x=i;
                   goto Chupai2;}
               }
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 3)
                   {x=i;
                   goto Chupai2;}
               }
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 4)
                   {x=i;
                   goto Chupai2;}
               }
  Chupai2:     
            if(x==-1)goto End; 
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),x);
            if(pos!= poker_another_repre[poker[x]-1].end())
            {
                poker_another_repre[poker[x]-1].erase(pos);
            }  
              
               poker[x]-=2;
               if(poker[x]>0)
               {
                   poker_another_repre[poker[x]-1].push_back(x);
                   sort(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),greater<int>());
               }
               poker_num-=2;
               out->poker[x] = 2;
               out->pt = two;
               out->number=2;
               out->main_card=x;
               goto End;
           
       }
       if(in->pt == three)
       {
           
               int x = -1;
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 3)
                   {x=i;
                   goto Chupai3;}
               }
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 4)
                   {x=i;
                   goto Chupai3;}
               }
  Chupai3:     
               if(x == -1)goto End;   
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),x);
            if(pos!= poker_another_repre[poker[x]-1].end())
            {
                poker_another_repre[poker[x]-1].erase(pos);
            }   
              
               poker[x]-=3;
               if(poker[x]>0)
               {
                   poker_another_repre[poker[x]-1].push_back(x);
                   sort(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),greater<int>());
               }
               poker_num-=3;
               out->poker[x] = 3;
               out->pt = three;
               out->number=3;
               out->main_card=x;
               goto End;
           
       }
       if(in->pt == four)
       {
           
               int x = -1;
               for(int i = in->main_card+1;i<=14;i++)
               {
                   if(poker[i] == 4)
                   {x=i;
                   goto Chupai4;}
               }
               
  Chupai4:     
               if(x==-1)goto End;
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),x);
            if(pos!= poker_another_repre[poker[x]-1].end())
            {
                poker_another_repre[poker[x]-1].erase(pos);
            }    
               
               poker[x]-=4;
               if(poker[x]>0)
               {
                   poker_another_repre[poker[x]-1].push_back(x);
                   sort(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),greater<int>());
               }
               poker_num-=4;
               out->poker[x] = 4;
               out->pt = four;
               out->number=4;
               out->main_card=x;
               goto End;
       }
       if(in->pt == three_one)
       {   
           int x = -1;
           for(int i=in->main_card+1; i<=14;i++)
           {
               if(poker[i] == 3)
               {
                   x = i;
                   goto Selectone;
               }
           }
           for(int i=in->main_card+1; i<=14;i++)
           {
               if(poker[i] == 4)
               {
                   x = i;
                   goto Selectone;
               }
           }
Selectone:
            int y = -1;
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 1 && x!=i)
                {
                    y = i;
                    goto Chupai5;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 2 && x!=i)
                {
                    y = i;
                    goto Chupai5;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 3 && x!=i)
                {
                    y = i;
                    goto Chupai5;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 4 && x!=i)
                {
                    y = i;
                    goto Chupai5;
                }
            }

Chupai5:  
            if(x==-1||y==-1)goto End;
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),x);
            if(pos!= poker_another_repre[poker[x]-1].end())
            {
                poker_another_repre[poker[x]-1].erase(pos);
            }
            pos = find(poker_another_repre[poker[y]-1].begin(),poker_another_repre[poker[y]-1].end(),y);
            if(pos!= poker_another_repre[poker[y]-1].end())
            {
                poker_another_repre[poker[y]-1].erase(pos);
            }
               poker[x]-=3;
               poker[y]-=1;
               if(poker[x]>0)
               {
                   poker_another_repre[poker[x]-1].push_back(x);
                   sort(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),greater<int>());
               }
               if(poker[y]>0)
               {
                   poker_another_repre[poker[y]-1].push_back(y);
                   sort(poker_another_repre[poker[y]-1].begin(),poker_another_repre[poker[y]-1].end(),greater<int>());
               }
               poker_num-=4;
               out->poker[x] = 3;
               out->poker[y] = 1;
               out->pt = three_one;
               out->number=4;
               out->main_card=x;
               goto End;

       }
       if(in->pt == three_two)
       {   
           int x = -1;
           for(int i=in->main_card+1; i<=14;i++)
           {
               if(poker[i] == 3)
               {
                   x = i;
                   goto Selecttwo;
               }
           }
           for(int i=in->main_card+1; i<=14;i++)
           {
               if(poker[i] == 4)
               {
                   x = i;
                   goto Selecttwo;
               }
           }
Selecttwo:
            int y = -1;
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 2 && x!=i)
                {
                    y = i;
                    goto Chupai6;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 3 && x!=i)
                {
                    y = i;
                    goto Chupai6;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 4 && x!=i)
                {
                    y = i;
                    goto Chupai6;
                }
            }
Chupai6:    
            //cout<<x<<" "<<y<<endl;
            if(x==-1||y==-1)goto End;
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),x);
            if(pos!= poker_another_repre[poker[x]-1].end())
            {
                poker_another_repre[poker[x]-1].erase(pos);
            }
            pos = find(poker_another_repre[poker[y]-1].begin(),poker_another_repre[poker[y]-1].end(),y);
            if(pos!= poker_another_repre[poker[y]-1].end())
            {
                poker_another_repre[poker[y]-1].erase(pos);
            }
               poker[x]-=3;
               poker[y]-=2;
               if(poker[x]>0)
               {
                   poker_another_repre[poker[x]-1].push_back(x);
                   sort(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),greater<int>());
               }
               if(poker[y]>0)
               {
                   poker_another_repre[poker[y]-1].push_back(y);
                   sort(poker_another_repre[poker[y]-1].begin(),poker_another_repre[poker[y]-1].end(),greater<int>());
               }
               poker_num-=5;
               out->poker[x] = 3;
               out->poker[y] = 2;
               out->pt = three_one;
               out->number=5;
               out->main_card=x;
               goto End;

       }
       if(in->pt == four_two_two)
       {   
           int x = -1;
           for(int i=in->main_card+1; i<=14;i++)
           {
               if(poker[i] == 4)
               {
                   x = i;
                   goto Selecttwo1;
               }
           }
Selecttwo1:
            int y = -1;
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 2 && x!=i)
                {
                    y = i;
                    goto Selecttwo2;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 3 && x!=i)
                {
                    y = i;
                    goto Selecttwo2;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 4 && x!=i)
                {
                    y = i;
                    goto Selecttwo2;
                }
            }

Selecttwo2:
           int z = -1;
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 2 && x!=i && y!=i)
                {
                    z = i;
                    goto Chupai7;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 3 && x!=i && y!=i)
                {
                    z = i;
                    goto Chupai7;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 4 && x!=i && y!=i)
                {
                    z = i;
                    goto Chupai7;
                }
            }
Chupai7:  
            if(x==-1||y==-1 || z==-1)goto End;
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),x);
            if(pos!= poker_another_repre[poker[x]-1].end())
            {
                poker_another_repre[poker[x]-1].erase(pos);
            }
            pos = find(poker_another_repre[poker[y]-1].begin(),poker_another_repre[poker[y]-1].end(),y);
            if(pos!= poker_another_repre[poker[y]-1].end())
            {
                poker_another_repre[poker[y]-1].erase(pos);
            }
            pos = find(poker_another_repre[poker[z]-1].begin(),poker_another_repre[poker[z]-1].end(),z);
            if(pos!= poker_another_repre[poker[z]-1].end())
            {
                poker_another_repre[poker[z]-1].erase(pos);
            }
               poker[x]-=4;
               poker[y]-=2;
               poker[z]-=2;
               if(poker[x]>0)
               {
                   poker_another_repre[poker[x]-1].push_back(x);
                   sort(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),greater<int>());
               }
               if(poker[y]>0)
               {
                   poker_another_repre[poker[y]-1].push_back(y);
                   sort(poker_another_repre[poker[y]-1].begin(),poker_another_repre[poker[y]-1].end(),greater<int>());
               }
               if(poker[z]>0)
               {
                   poker_another_repre[poker[z]-1].push_back(z);
                   sort(poker_another_repre[poker[z]-1].begin(),poker_another_repre[poker[z]-1].end(),greater<int>());
               }
               poker_num-=8;
               out->poker[x] = 4;
               out->poker[y] = 2;
               out->poker[z] = 2;
               out->pt = four_two_two;
               out->number=8;
               out->main_card=x;
               goto End;

       }
       if(in->pt == four_one_one)
       {   
           int x = -1;
           for(int i=in->main_card+1; i<=14;i++)
           {
               if(poker[i] == 4)
               {
                   x = i;
                   goto Selectone1;
               }
           }
Selectone1:
            int y = -1;
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 1 && x!=i)
                {
                    y = i;
                    goto Selectone2;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 2 && x!=i)
                {
                    y = i;
                    goto Selectone2;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 3 && x!=i)
                {
                    y = i;
                    goto Selectone2;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 4 && x!=i)
                {
                    y = i;
                    goto Selectone2;
                }
            }

Selectone2:
           int z = -1;
           for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 1 && x!=i && y!=i)
                {
                    z = i;
                    goto Chupai8;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 2 && x!=i && y!=i)
                {
                    z = i;
                    goto Chupai8;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 3 && x!=i && y!=i)
                {
                    z = i;
                    goto Chupai8;
                }
            }
            for(int i = 0; i<=14;i++)
            {
                if(poker[i] == 4 && x!=i && y!=i)
                {
                    z = i;
                    goto Chupai8;
                }
            }
Chupai8:  
            if(x==-1||y==-1 || z==-1)goto End;
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),x);
            if(pos!= poker_another_repre[poker[x]-1].end())
            {
                poker_another_repre[poker[x]-1].erase(pos);
            }
            pos = find(poker_another_repre[poker[y]-1].begin(),poker_another_repre[poker[y]-1].end(),y);
            if(pos!= poker_another_repre[poker[y]-1].end())
            {
                poker_another_repre[poker[y]-1].erase(pos);
            }
            pos = find(poker_another_repre[poker[z]-1].begin(),poker_another_repre[poker[z]-1].end(),z);
            if(pos!= poker_another_repre[poker[z]-1].end())
            {
                poker_another_repre[poker[z]-1].erase(pos);
            }
               poker[x]-=4;
               poker[y]-=1;
               poker[z]-=1;
               if(poker[x]>0)
               {
                   poker_another_repre[poker[x]-1].push_back(x);
                   sort(poker_another_repre[poker[x]-1].begin(),poker_another_repre[poker[x]-1].end(),greater<int>());
               }
               if(poker[y]>0)
               {
                   poker_another_repre[poker[y]-1].push_back(y);
                   sort(poker_another_repre[poker[y]-1].begin(),poker_another_repre[poker[y]-1].end(),greater<int>());
               }
               if(poker[z]>0)
               {
                   poker_another_repre[poker[z]-1].push_back(z);
                   sort(poker_another_repre[poker[z]-1].begin(),poker_another_repre[poker[z]-1].end(),greater<int>());
               }
               poker_num-=6;
               out->poker[x] = 4;
               out->poker[y] = 1;
               out->poker[z] = 1;
               out->pt = four_one_one;
               out->number=6;
               out->main_card=x;
               goto End;

       }
       if(in->pt == shunzi)
       {   
           //cout<<1<<endl;
           int x = -1;
           for(int i = in->main_card+1;i<=11;i++)
           {   
               bool flag = true;
               for(int j=i;j<=i+(in->length-1)*(in->itv);j+=in->itv)
               {
                   if(j>=12 || poker[j]  < in->multi)
                   {
                        flag = false;
                        break;
                   }
               }
               if(flag == true)
               {
                   x = i;
                   //cout<<x<<endl;
                   goto Chupai9;
               }
           }
Chupai9: 
        if(x == -1)goto End;
        for(int i = x; i<=x+(in->length-1)*(in->itv);i+=in->itv)
        {    
            std::vector<int>::iterator pos;
            pos = find(poker_another_repre[poker[i]-1].begin(),poker_another_repre[poker[i]-1].end(),i);
            if(pos!= poker_another_repre[poker[i]-1].end())
            {
                poker_another_repre[poker[i]-1].erase(pos);
            }
             poker[i]-=in->multi;
             if(poker[i]>0)
               {
                   poker_another_repre[poker[i]-1].push_back(i);
                   sort(poker_another_repre[poker[i]-1].begin(),poker_another_repre[poker[i]-1].end(),greater<int>());
               }
               out->poker[i] = in->multi;

        }
        poker_num -= in->number;
        out->pt=shunzi;
        out->number = in->number;
        out->main_card =x;
        out->length = in->length;
        out->itv = in->itv;
        out->multi = in->multi;
        goto End;
       }
   }
   
End: 
     if(poker_num == 0) return true;
     else return false;       
}