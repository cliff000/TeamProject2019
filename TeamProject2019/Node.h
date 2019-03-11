#pragma once
#include <list>
#include <string>

//��{���ׂẴN���X�͂�����p�����Ă�������
class Node
{
private:
	std::list<Node*> children;
	Node* parent;
	bool kill = false; //true���Ə��������
	std::string name = "node";

public:

	Node();
	~Node();

	virtual void load(){}
	virtual void update() {}
	virtual void draw() {}

	void forUpdate(); //�X�V��ؑS�̂Ɏ��s(���D��T��)
	void forDraw(); //�`���ؑS�̂Ɏ��s(���D��T��)

	Node* addChild(Node* child);
	Node* addChildTo(Node* parent);


	std::list<Node*> getChildren() { return children; }
	Node* getParent() { return parent; }
	std::string getName{ return name; }
};

