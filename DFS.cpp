#include<iostream>
#include<list>
using namespace std;

//图的类定义
class Graph{

private:

	//图的顶点数目
	int V;
	//图的边表顶点
	list<int> *adj;
	//深度优先遍历的方法
	void DFSUtil(int v, bool visited[]);

public:
	//构造方法
	Graph(int V);
	//添加一条边
	void addEdge(int v, int w);
	//深度优先遍历
	void DFS();
};

Graph::Graph(int V){

	this->V = V;
	adj = new list<int>[V];
}
//图中添加一条边
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}
//进行深度优先遍历
void Graph::DFSUtil(int v, bool visited[]){

	visited[v] = true;
	cout << v << ";";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end();++i)
	     if (!visited[*i])
		      DFSUtil(*i, visited);

}
//深度优先遍历方法定义
void Graph::DFS(){

	bool *visited = new bool[V];
	//初始化visited的集合，false代表还未被访问
	for (int i = 0; i < V; i++)
		visited[i] = false;

	//从每一个顶点出发，开始遍历，防止非联通图的出现
	for (int i = 0; i < V; i++){
		//如果还没被访问
		if (visited[i] == false)
             DFSUtil(i, visited);
	}
}

int  main(){

	Graph g(5);

	//向图中添加边
	g.addEdge(0,1);
	g.addEdge(0,2);

	g.addEdge(1,0);
	g.addEdge(1,4);

	g.addEdge(2,0);
	g.addEdge(2,3);

	g.addEdge(3,2);
	g.addEdge(3,4);

	g.addEdge(4,3);
	g.addEdge(4,1);
	

	cout << "深度优先遍历的结果\n";
	g.DFS();


	cout << endl;
	system("pause");
	return 0;
}