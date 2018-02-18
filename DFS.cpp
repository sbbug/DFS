#include<iostream>
#include<list>
using namespace std;

//ͼ���ඨ��
class Graph{

private:

	//ͼ�Ķ�����Ŀ
	int V;
	//ͼ�ı߱���
	list<int> *adj;
	//������ȱ����ķ���
	void DFSUtil(int v, bool visited[]);

public:
	//���췽��
	Graph(int V);
	//���һ����
	void addEdge(int v, int w);
	//������ȱ���
	void DFS();
};

Graph::Graph(int V){

	this->V = V;
	adj = new list<int>[V];
}
//ͼ�����һ����
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}
//����������ȱ���
void Graph::DFSUtil(int v, bool visited[]){

	visited[v] = true;
	cout << v << ";";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end();++i)
	     if (!visited[*i])
		      DFSUtil(*i, visited);

}
//������ȱ�����������
void Graph::DFS(){

	bool *visited = new bool[V];
	//��ʼ��visited�ļ��ϣ�false����δ������
	for (int i = 0; i < V; i++)
		visited[i] = false;

	//��ÿһ�������������ʼ��������ֹ����ͨͼ�ĳ���
	for (int i = 0; i < V; i++){
		//�����û������
		if (visited[i] == false)
             DFSUtil(i, visited);
	}
}

int  main(){

	Graph g(5);

	//��ͼ����ӱ�
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
	

	cout << "������ȱ����Ľ��\n";
	g.DFS();


	cout << endl;
	system("pause");
	return 0;
}