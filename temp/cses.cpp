
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvlli;
typedef vector<vector<bool>> vvb;
 
#define endl "\n"
#define pb push_back
#define mod7 1000000007
#define mod9 1000000009
#define all(v) v.begin(),v.end() 
 
#define trace1(x)       if(dm) cout<<(#x)<<" "<<(x)<<endl
#define trace2(x,y)     if(dm) cout<<(#x)<<" "<<(x)<<", "<<(#y)<<" "<<(y)<<endl
#define trace3(x,y,z)   if(dm) cout<<(#x)<<" "<<(x)<<", "<<(#y)<<" "<<(y)<<", "<<(#z)<<" "<<(z)<<endl
 
#define min3(x,y,z) min(x,min(y,z))
#define max3(x,y,z) max(x,max(y,z))
 
template <typename T> inline void sortv        (vector<T> &vec)            { sort(vec.begin(), vec.end() ) ; }
template <typename T> inline void rsortv       (vector<T> &vec)            { sort(vec.begin(), vec.end(), greater<T>()) ; }
int dm = 0;
void fastio(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
void fileio() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
}
 
 
 
void bell_ford(vector<vector<pii>>& adj, int src, vlli& dist, vb& nodist, bool& neg_cycle, vi& cycle, bool& high_score)
{
    int n = adj.size();
    // vertices 0,1,....n-1
    dist = vlli(n, 0);
    nodist = vb(n, true);
    
    vi distpar(n, -1);
    
    // first for adj
    
    dist[src] = 0;
    nodist[src] = false;
    distpar[src] = -1;
    
    
    for(int iter=0; iter<n; iter++){
        
        bool change = false;
            
        for(int v=0; v<n; v++){
            
            if(nodist[v]){
                continue;
            }
            // relax from v
            for(pii pu : adj[v]){
                int u = pu.first;
                int d = pu.second;
                
                // v->u
                if(nodist[u] || dist[u] > dist[v] + d){
                    dist[u] = dist[v] + d;
                    distpar[u] = v;
                    nodist[u] = false;
                    change = true;
                }
                
            }
        }
        if(!change) break;
    }
    
    if(dm){
        for(int v=0; v<n; v++){
            trace3(v, dist[v], nodist[v]);
        }
    }
    
    
    // check if neg cycle exists
    // run one more iteration of the algo
    
    vb is_part_of_neg_cycle(n, false);
    
    for(int v=0; v<n; v++){
        if(nodist[v]) continue;
        
        for(pii pu : adj[v]){
            
            int u = pu.first;
            int d = pu.second;
            
            // v->u is edge
            // check if src->v -> u is better than src->u
            
            // v is reachable
            assert(!nodist[u]);
            if(dist[v]+d < dist[u]){
                // there is a neg cycle
                neg_cycle = true;
                
                // and from that cycle you can reach v
                // move up from 'v'  n times. you will reach a vertex 'st'
                // that comes in neg_cycle
                // Then you move up 'st' till you reach 'st' back again
                // all those are part of negative  cycles
                
                // Then you have all the vertexes that are part of 
                // negative cycles
                
                int st = v;
                
                if(is_part_of_neg_cycle[st]){
                    // already saw this one 
                    continue;
                }
                
                for(int i=0; i<n; i++){
                    st = distpar[st];
                }
                
                if(is_part_of_neg_cycle[st]){
                    // already saw this one 
                    continue;
                }
                
                vi cur_cycle;
                cur_cycle.pb(st);
                
                trace3(v, u, st);
                
                is_part_of_neg_cycle[st] = true;
                int cur = st;
            
                
                while(distpar[cur]!=st){
                	
                    trace2(cur, distpar[cur]);
                    cur = distpar[cur]; 
                    cur_cycle.pb(cur);   
                    is_part_of_neg_cycle[cur] = true;
                    
                    // 1-> cur and cur->n-1 means done
                    
                    //trace3(cur,reachable[1][cur],reachable[cur][n-1] );
                    
              
                }
                
                if(1 || cur_cycle.size()>1){
                	cur_cycle.pb(st);
                }
                
                cycle = cur_cycle;
                
                
                return;
                    
                
            }
            
        }
    }
    
/*
 
5 6
1 2 -1
2 1 -1
2 3 -4
3 4 -4
4 2 10
1 5 -5
 
ans = -1
 
6 6
1 3 -2
3 2 -2
2 4 -2
3 5 -2
5 6 -2
6 3 8
2->4 being relaxed in n+1 th iteration ever though not being part of cycle
 
 
*/
 
}
 
 
int main(){
    #ifndef ONLINE_JUDGE
        dm = 1;
	#endif
    if(!dm)fastio();
    fileio();
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<pii>> adj(n+1);
    
    vvi		-+
    
    
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        
        
        // Mistake 0 : forgot to change -c from here
        adj[a].pb({b,c});
        
    }
    
    vector<lli> dist(n+1,0);
    vector<bool> nodist(n+1, true);
    bool neg_cycle = false;
    bool high_score = true;
    vi cycle;
    
    // Mistake 1 : didn't used pseudo vertex
    for(int v=1; v<=n; v++){
    	adj[0].pb({v, 0});	
    }
    // Mistake 1 : didn't started with vertex 0
    bell_ford(adj, 0, dist, nodist, neg_cycle, cycle, high_score);
    
    
    if(neg_cycle){
    	cout << "YES" << endl;	
    	
    	lli cw = 0;
    	
    	for(int i=0; i<cycle.size() - 1; i++){
    		
    	}
    	
    	for(int i : cycle){
    		cout << i << " ";
    	}
    }
    else{
        cout << "NO" << endl;
    }
    
          
    
    return 0 ;
 
}
