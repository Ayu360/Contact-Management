#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<cmath>
using namespace std;
typedef long long int ll;

void Functionalities(){
    cout<<"Select the function that you want : \n";
    cout<<"Type add to create a contact\n";
    cout<<"Type find to search a contact\n";
    cout<<"Type delete to remove a contact\n";
    cout<<"Type edit to change a contact\n";
    cout<<"Type show to see all contact\n";
    cout<<"Type exit to exit\n";
}

int main()
{
    ifstream fin;
    fin.open("contacts.txt");
    unordered_map<string, ll> mp, func;
    while(!fin.eof()){
        string str;
        fin>>str;
        ll n;
        fin>>n;
        mp[str]=n;
    }
    fin.close();


    func.insert({"add",1});
    func.insert({"find",2});
    func.insert({"delete",3});
    func.insert({"edit",4});
    func.insert({"show",5});
    func.insert({"exit",6});

    Functionalities();
    bool flag=true;
    while(flag)
    {   
        string function;
        while (flag)
        {
            cin>>function;
            if(func.find(function)==func.end()){
                cout<<"Please enter the correct string. \n";
            }
            else
            {
                int x;
                x=func[function];
                
                string temp;
                switch (x)
                {
                    case 1:
                        cout<<"Enter the name of the contact :\n";
                        cin>>temp;
                        if(mp.find(temp)!=mp.end()){
                            cout<<"contact named "<<temp<<" already exist please try saving with some differnt name\n";
                        }else{
                            ll num=0;
                            label: 
                            cout<<"Enter the Phone Number : \n";
                            cin>>num;
                            short count=floor(log10(num) + 1);
                            if(count==10)
                            mp[temp]=num;
                            else{
                                cout<<"Enter a ten digit number\n";
                                goto label;
                            }
                        }
                        break;
                    case 2:
                        cout<<"Enter the contact name to be searched :\n";
                        cin>>temp;
                        if(mp.find(temp)==mp.end()){
                            cout<<"contact named "<<temp<<" does'nt exist please try with some differnt name\n";
                        }else
                            cout<<"Contact number of "<<temp<<" is "<<mp[temp]<<endl;
                        break;
                    case 3:
                        cout<<"Enter the contact name to be deleted :\n";
                        cin>>temp;
                        if(mp.find(temp)==mp.end()){
                            cout<<"contact named "<<temp<<" does'nt exist please try with some differnt name\n";
                        }else{
                            mp.erase(temp);
                            cout<<"Contact named "<<temp<<" is now removed from contact book";
                        }
                        break;
                    case 4:
                        cout<<"Enter the contact name to be edited :\n";
                        cin>>temp;

                        bool y;
                        cout<<"Enter 0 if want to edit name else 1 if want to edit contact number : \n";
                        cin>>y;
                        if(y){
                            int s;
                            cout<<"Enter new number :\n";
                            cin>>s;
                            mp[temp]=s;
                            cout<<"Contact named "<<temp<<" is updated to "<<s<<endl;
                        }else{
                            if(mp.find(temp)==mp.end()){
                                cout<<"contact named "<<temp<<" does'nt exist please try with some differnt name\n";
                            }else{
                                ll con=mp[temp];
                                mp.erase(temp);
                                string s;
                                cout<<"Enter new name :\n";
                                cin>>s;
                                mp[s]=con;
                                cout<<"Contact name is updated to "<<s<<endl;
                            }
                        }
                        break;
                    case 5:
                        cout<<"All contacts are as follows :"<<endl;
                        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
                            cout<<"-> "<<itr->first<<" : "<<itr->second<<endl;
                        }
                        break;
                    case 6:
                        cout<<"Program terminated.......";
                        flag=false;
                        break;
                    default:
                        cout<<"please enter the valid details."<<endl;
                        break;
                }
            }
        }
        
    }
    ofstream fout;
    fout.open("contacts.txt", ios::in);
    for(auto itr=mp.begin(); itr!=mp.end(); itr++){
        string str1=itr->first;
        ll num=itr->second;
        str1+=" ";
        fout<<str1;
        fout<<num;
        fout<<"\n";
    }
    fout.close();
        
}
    
    

