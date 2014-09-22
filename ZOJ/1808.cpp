/*
#Problem ID: 1808
#Submit Time: 2012-06-14 09:41:16
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<string> tabby;
    string input;
    int count=1;
    bool status = false;
    while(cin >> input)
    {
        if(input=="9")
        {
            if(status==false)
                cout << "Set " << count << " is immediately decodable" << endl;
            else
                cout << "Set " << count << " is not immediately decodable" << endl;
            tabby.clear();
            count++;
            status = false;
        }
        else
        {
            if(status==false)
            {
                for(int i=0; i<tabby.size(); i++)
                {
                    if(input.find(tabby[i])==0)
                    {
                        status = true;
                        break;
                    }
                }
                tabby.push_back(input);
            }
        }
    }
//    string s;
//    map<string, int> m;
//    bool flag = false;
//    int CASE = 1;
//
//    while(cin>>s){
//        if(s=="9"){
//            if(flag)
//                cout<<"Set "<<CASE<<" is not immediately decodable\n";
//            else
//                cout<<"Set "<<CASE<<" is immediately decodable\n";
//            CASE++;
//            m.clear();
//            flag = false;
//        }
//        else{
//            for(int i = s.size()-1; i >0; --i)
//                if(s[i]=='0') s.erase(i);
//                else break;
//
//            map<string, int>::iterator iter;
//            iter = m.find(s);
//            if(iter!=m.end()) flag = true;
//
//            m[s] = 1;
//        }
//    }


    return 0;
}
