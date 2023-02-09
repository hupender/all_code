// void solve() {
//     int n;
//     cin>>n;
//     int a[n];
//     set<pair<int,int>> s;
//     for(int i=0;i<n;i++) {
//         cin>>a[i];
//         s.insert({a[i],i});
//     }
//     unordered_map<int,int> m;
//     for(int i=0;i<n-1;i++) {
//         m[abs(a[i+1]-a[i])]++;
//     }
//     for(int i=0;i<n-2;i++) {
//         if(a[i]>a[i+1]) {
//             auto it1=s.find({a[i+1],i+1});
//             auto it2=s.find({a[i],i});
//             it1++;
//             while(it1!=it2) {
//                 if(it1->first==a[i]) {
//                     m[0]++;
//                     break;
//                 }
//                 else {
//                     m[abs(it1->first-a[i])]++;
//                 }
//                 it1++;
//             }
//         }
//         else if(a[i]==a[i+1]) {
//             m[0]++;
//         }
//     }
//     cout<<m.size()<<endl;
// }