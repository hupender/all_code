#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve2(int ttt,int tt) {
    int n;
    cin>>n;
    string s1;
    cin>>s1;
    vector<int> factors;
    for(int i=1;i<=n;i++) {
        if(n%i==0) {
            factors.push_back(i);
        }
    }
    int n1=factors.size();
    int operations=INT_MAX;
    string res;
    for(int p=0;p<n1;p++) {
        int x=factors[p];
        if(n/x<=26) {
            string s=s1;
            int num_operations=0;
            map<char,int> map1;
            int n_alphabet=n/x;;  // number of different alphabets that will be present in the result with count x
            int curr_with_count_x=0;  // currently how many alphabets have count x
            for(int i=0;i<n;i++) {
                if(map1[s[i]]==x) {
                    s[i]='.';
                }
                else {
                    map1[s[i]]++;
                    if(map1[s[i]]==x) {
                        curr_with_count_x++;
                    }
                }
            }
            int remaning=n_alphabet-curr_with_count_x;
            vector<pair<int,char>> less_count;
            for(auto i:map1) {
                if(i.second<x) {
                    less_count.push_back({i.second,i.first});
                }
            }
            sort(less_count.begin(),less_count.end());
            int size_less_count=less_count.size();
            if(size_less_count<=remaning) {

                for(int i=0;i<n;i++) {
                    if(s[i]=='.') {
                        num_operations++;
                    }
                }

                for(int i=0;i<size_less_count;i++) {
                    char c=less_count[i].second;
                    int freq=less_count[i].first;
                    for(int j=0;j<n;j++) {
                        if(s[j]=='.') {
                            if(freq<x) {
                                s[j]=c;
                                freq++;
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
                int remaining_dots=remaning-size_less_count;
                map<char,int> map2;
                for(int i=0;i<n;i++) {
                    map2[s[i]]++;
                }
                char c='a';
                for(int i=0;remaining_dots && i<26;i++) {
                    if(map2[c]==0) {
                        int x1=x;
                        for(int i=0;x1 && i<n;i++) {
                            if(s[i]=='.') {
                                s[i]=c;
                                x1--;
                            }
                        }
                        remaining_dots--;
                    }
                    c++;
                }
            }
            else {
                int n1=size_less_count-remaning;
                for(int i=0;i<n1;i++) {
                    char c=less_count[i].second;
                    for(int j=0;j<n;j++) {
                        if(s[j]==c) {
                            s[j]='.';
                        }
                    }
                }

                for(int i=0;i<n;i++) {
                    if(s[i]=='.') {
                        num_operations++;
                    }
                }

                for(int i=n1;i<size_less_count;i++) {
                    char c=less_count[i].second;
                    int freq=less_count[i].first;
                    for(int j=0;j<n;j++) {
                        if(s[j]=='.') {
                            if(freq<x) {
                                s[j]=c;
                                freq++;
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
            }
            if(num_operations<operations) {
                operations=num_operations;
                res=s;
            }
        }
    }
    // if(ttt==10000 && tt==731) {
    //     cout<<s1<<endl;
    // }
    // if(ttt==4) {
    //     cout<<operations<<endl<<res<<endl;
    // }
    cout<<operations<<endl<<res<<endl;
}

void solve1() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> factors;
    for(int i=1;i<=n;i++) {
        if(n%i==0) {
            factors.push_back(i);
        }
    }
    string res;
    int dissimilarity=INT_MAX;
    for(int j=0;j<factors.size();j++) {
        int x=factors[j];
        if(n/x<=26) {
            string s1=s;
            int curr_dissimilarity=0;
            map<char,int> map;
            for(int i=0;i<n;i++) {
                map[s1[i]]++;
            }
            vector<int> index;    // store index of . which we will be inserting
            for(int i=0;i<n;i++) {
                if(map[s1[i]]>x) {
                    map[s1[i]]--;
                    s1[i]='.';
                    index.push_back(i);
                }
            }
            vector<pair<int,char>> v;   // store those character and their count whose values are less than x
            for(auto i:map) {
                if(i.second<x) {
                    v.push_back({i.second,i.first});
                }
            }
            sort(v.begin(),v.end());

            int size=v.size();
            int k=0;  // for iterating in index vector
            int size_index=index.size();
            for(int i=size-1;i>=0;i--) {
                while(v[i].first!=x && k!=size_index) {
                    s1[index[k]]=v[i].second;
                    map[s1[index[k]]]++;
                    curr_dissimilarity++;
                    v[i].first++;
                    k++;
                }
                if(v[i].first==x) {
                    v.pop_back();
                }
            }

            int number_of_alphabet=0;
            
            for(auto i:map) {
                if(i.second==x) {
                    number_of_alphabet++;
                }
            }
            int required_alphabet=n/x;
            int remaining_alphabet=required_alphabet-number_of_alphabet;

            size=v.size();  // updated size
            if(size==0) {
                if(k!=size_index) {
                    int t=size_index-k;  // number of index left which are still dot in index vector
                    int times=t/x;   // how many new alphabets should be added
                    char c='a';
                    curr_dissimilarity+=t;
                    for(int i=0;times && i<26;i++) {
                        int x1=x;
                        if(!map[c]) {
                            for(int z=0;x1 && z<n;z++) {
                                if(s1[z]=='.') {
                                    s1[z]=c;
                                    x1--;
                                }
                            }
                            times--;
                        }
                        c++;  
                    }
                }
            }
            else {
                unordered_map<char,vector<int>> m_index;
                vector<int> dot_index;
                for(int i=0;i<n;i++) {
                    m_index[s1[i]].push_back(i);
                }
                int i=0;
                for(i=0;i<size-remaining_alphabet;i++) {
                    for(auto z:m_index[v[i].second]) {
                        dot_index.push_back(z);
                        s1[z]='.';
                    }
                }
                int size1=dot_index.size();
                curr_dissimilarity+=size1;
                int ind=0;
                while(i<n) {
                    int l=v[i].first;
                    char c1=v[i].second;
                    while(l<x) {
                        s1[dot_index[ind]]=c1;
                        l++;
                    }
                }
            }
            if(curr_dissimilarity<dissimilarity) {
                dissimilarity=curr_dissimilarity;
                res=s1;
            }
        }
        cout<<res<<endl;

    }
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> factors;
    for(int i=1;i<=n;i++) {
        if(n%i==0) {
            factors.push_back(i);
        }
    }
    map<char,int> m;
    for(int i=0;i<n;i++) {
        m[s[i]]++;
    }
    vector<pair<int,char>> v1;
    for(auto i:m) {
        v1.push_back({i.second,i.first});
    }
    sort(v1.begin(),v1.end());
    int n1=factors.size();
    vector<int> v;
    // vector<string> res;
    string res;
    int operation=INT_MAX;
    for(int i=0;i<n1;i++) {
        int x=factors[i];
        int low=0;
        int high=v1.size()-1;
        string s1=s;
        int num_operation=0;
        int flag=1;
        while(low<high) {
            char c1=v1[low].second;
            char c2=v1[high].second;
            int count1=v1[low].first;
            int count2=v1[high].first;
            if(count2<=x) {
                if(count2==x) {
                    high--;
                }
                else if(count1==x) {
                    low++;
                }
                else if(count2<x) {
                    num_operation+=count1;
                    if(count1+count2<=x) {
                        for(int i=0;i<n;i++) {
                            if(s1[i]==c1) {
                                s1[i]=c2;
                            }
                        }
                        low++;
                    }
                    else {
                        int p=x-count2;
                        num_operation+=p;
                        v1[low].first-=p;
                        v1[high].first=x;
                        for(int i=0;p && i<n;i++) {
                            if(s1[i]==c1) {
                                s1[i]=c2;
                                p--;
                            }
                        }
                        high--;
                    }
                }
            }
            else {
                if(count1==x) {
                    low++;
                }
                else if(count2==x) {
                    high--;
                }
                else if(count1+count2>2*x) {
                    // fulfill the need of low
                    int p=x-count1;
                    v1[high].first-=p;
                    num_operation+=p;
                    for(int i=0;p && i<n;i++) {
                        if(s1[i]==c2) {
                            s1[i]=c1;
                            p--;
                        }
                    }
                    low++;
                }
                else {
                    // fulfill yourself and give the rest to low
                    int p=count2-x;
                    v1[high].first=x;
                    num_operation+=p;
                    for(int i=0;p && i<n;i++) {
                        if(s1[i]==c2) {
                            s1[i]=c1;
                            p--;
                        }
                    }
                    high--;
                }
            }
        }
        if(flag) {
            if(v1[low].first==x) {
                if(num_operation<operation) {
                    operation=num_operation;
                    res=s1;
                }
            }
            else {
                char c1=v1[low].second;
                int p=v1[low].first-x;
                int times=p/x;
                num_operation+=p;
                if(m.size()+times<=26) {
                    char c='a';
                    for(int i=0;times && i<26;i++) {
                        if(m[c]>0) {
                            c++;
                        }
                        else {
                            int x1=x;
                            for(int i=0;x1 && i<n;i++) {
                                if(s1[i]==c1) {
                                    s1[i]=c;
                                    x1--;
                                }
                            }
                            times--;
                        }
                    }
                }
                if(num_operation<operation) {
                    operation=num_operation;
                    res=s1;
                }
            }  
        }
    }
    cout<<res<<endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        solve2(t,i);
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}