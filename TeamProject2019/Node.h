#pragma once
#include <list>
#include <string>

//Šî–{‚·‚×‚Ä‚ÌƒNƒ‰ƒX‚Í‚±‚ê‚ğŒp³‚µ‚Ä‚­‚¾‚³‚¢
class Node
{
private:
	std::list<Node*> children;
	Node* parent;
	bool kill = false; //true‚¾‚ÆÁ‹‚³‚ê‚é
	std::string name = "node";

public:

	Node();
	~Node();

	virtual void load(){}
	virtual void update() {}
	virtual void draw() {}

	void forUpdate(); //XV‚ğ–Ø‘S‘Ì‚ÉÀs(•—Dæ’Tõ)
	void forDraw(); //•`‰æ‚ğ–Ø‘S‘Ì‚ÉÀs(•—Dæ’Tõ)

	Node* addChild(Node* child);
	Node* addChildTo(Node* parent);


	std::list<Node*> getChildren() { return children; }
	Node* getParent() { return parent; }
	std::string getName{ return name; }
};

