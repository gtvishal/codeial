#include<bits/stdc++.h>
using namespace std;
void print(int** edges,int n,int sv,int* visited)

{
 cout<<sv<<endl;
 visited[sv]=1;
    for(int i=0;i<n;i++)
    {
	   if(sv==i)
		   continue;
	   if(edges[sv][i]==1)
	   {
		   if(visited[i])
		   continue;
		   print(edges,n,i,visited);
	   }
    }

}
void printBFS(int** edges,int n,int sv)
{
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	queue<int>pendingVertices;
	pendingVertices.push(sv);
	visited[sv]=true;
	while(!pendingVertices.empty())
     	{
          int currentVertex=pendingVertices.front();
	  cout<<currentVertex<<endl;
	  pendingVertices.pop();
	  for(int i=0;i<n;i++)
	  {
		  if(i==currentVertex)
			  continue;
		  if(edges[currentVertex][i]==1 && !visited[i])
		  {
			  pendingVertices.push(i);
			  visited[i]=true;
		  }
	  }

	}
    delete [] visited;

}
int main()
{
	int e,n;
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	int* visited = new int[n];
	cout<<"DFS"<<endl;
	print(edges,n,0,visited);
	cout<<"BFS"<<endl;
        printBFS(edges,n,0);
	for(int i=0;i<n;i++)
	{
		delete [] edges[i];
	}
	delete [] edges;

}
