#include "Node.h"
#include <queue>

Node::Node()
{
}


Node::~Node()
{
}

void Node::forUpdate() {
	//•—Dæ’Tõ
	std::queue<Node*> q;
	q.push(this);
	while (!q.empty()) {
		Node* val = q.front();
		q.pop();
		val->update();
		for (auto itr = val->children.begin(); itr != val->children.end();) {
			if ((*itr)->kill == false) {
				q.push(*itr);
				++itr;
			}
			else {
				delete *itr;
				*itr = nullptr;
				itr = val->children.erase(itr);
			}
		}
	}
}

void Node::forDraw() {
	//•—Dæ’Tõ
	std::queue<Node*> q;
	q.push(this);
	while (!q.empty()) {
		Node* val = q.front();
		q.pop();
		val->draw();
		for (auto itr = val->children.begin(); itr != val->children.end();) {
			if ((*itr)->kill == false) {
				q.push(*itr);
				++itr;
			}
			else {
				delete *itr;
				*itr = nullptr;
				itr = val->children.erase(itr);
			}
		}
	}
}

Node* Node::addChild(Node* child) {
	children.push_back(child);
	child->parent = this;
	return this;
}

Node* Node::addChildTo(Node* parent) {
	parent->addChild(this);
	return this;
}