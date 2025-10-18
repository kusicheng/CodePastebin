#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct flight{
	int leave,arrive,destination;
};
struct bessie{
	int timemark,port;
};
vector<flight> a[200005];
queue<bessie> q;
bool visited[200005];
int currtime[200005];
int ports,flights,idxleave,idxarrive,timeleave,timearrive;
int main(){
	for (int i=2;i<200005;i++)currtime[i]=-1;
	cin>>ports>>flights;
	//leave airport, time of leave,arrive airport,time of arrive.
	for (int i=0;i<flights;i++){
		cin>>idxleave>>timeleave>>idxarrive>>timearrive;
		a[idxleave].push_back({timeleave,timearrive,idxarrive});
	}
	q.push({0,1});
	while (q.size()){
		bessie node=q.front();
		visited[node.port]=true;
		currtime[node.port]=min(currtime[node.port],node.timemark);
		for (flight i:a[node.port]){
			//cout<<!visited[i.destination]<<" | "<<i.leave<<" | "<<node.port+node.timemark<<endl;
			if (!visited[i.destination]&&i.leave>=node.port+node.timemark||i.leave>=node.port+node.timemark&&i.arrive<currtime[i.destination]){
				q.push({i.destination,i.arrive});
				cout<<"push flight ok"<<endl;
			}
			cout<<"flight processing ok"<<endl;
		}
		q.pop();
	}
	for (int i=1;i<=ports;i++)cout<<currtime[i]<<endl;
}
