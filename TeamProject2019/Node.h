#pragma once
#include <list>

//基本すべてのクラスはこれを継承してください
class Node
{
private:
	std::list<Node*> children;
	Node* parent;
	bool kill = false; //trueだと消去される

public:

	Node();
	~Node();

	virtual void load(){}
	virtual void update() {}
	virtual void draw() {}

	void forUpdate(); //更新を木全体に実行(幅優先探索)
	void forDraw(); //描画を木全体に実行(幅優先探索)

	Node* addChild(Node* child);
	Node* addChildTo(Node* parent);


	std::list<Node*> getChildren() { return children; }
	Node* getParent() { return parent; }
};

