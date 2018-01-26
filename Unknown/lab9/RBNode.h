#include <iostream>

using namespace std;


template<class Item>
class RBNode {
protected:
	Item data_field;
	RBNode* left_field;
	RBNode* right_field;
	RBNode* parent_field;
	enum Color { RED, BLACK };
	Color color_field;
public:
	RBNode(const Item& init_data = Item(), RBNode* init_left = NULL,
			RBNode* init_right = NULL, Color init_color = RED, RBNode* init_parent = NULL) {
		data_field = init_data;
		left_field = init_left;
		right_field = init_right;
		color_field = init_color;
		parent_field = init_parent;
	}
	// ACCESSOR & MUTATOR
	Item& data();
	RBNode*& left();
	RBNode*& right();
	Color color();
	RBNode*& parent();
	void set_data(const Item& new_data);
	void set_left(RBNode* new_left);
	void set_right(RBNode* new_right);
	void set_color(Color new_color);
	void set_parent(RBNode* new_parent);
	const Item& data() const;
	const RBNode* left() const;
	const RBNode* right() const;
	const Color color() const;
	const RBNode* parent() const;
	bool is_leaf() const;
	friend class RBTree;
};

template<class Item>
Item& RBNode<Item>::data() {
	return data_field;
}

template<class Item>
RBNode<Item>*& RBNode<Item>::left() {
	return left_field;
}

template<class Item>
RBNode<Item>*& RBNode<Item>::right() {
	return right_field;
}

template<class Item>
typename RBNode<Item>::Color RBNode<Item>::color() {
	return color_field;
}

template<class Item>
RBNode<Item>*& RBNode<Item>::parent() {
	return parent_field;
}

template<class Item>
void RBNode<Item>::set_data(const Item& new_data) {
	data_field = new_data;
}

template<class Item>
void RBNode<Item>::set_left(RBNode* new_left) {
	left_field = new_left;
}

template<class Item>
void RBNode<Item>::set_right(RBNode* new_right) {
	right_field = new_right;
}

template<class Item>
void RBNode<Item>::set_color(Color new_color) {
	color_field = new_color;
}

template<class Item>
void RBNode<Item>::set_parent(RBNode* new_parent) {
	parent_field = new_parent;
}

template<class Item>
const Item& RBNode<Item>::data() const {
	return data_field;
}

template<class Item>
const RBNode<Item>* RBNode<Item>::left() const {
	return left_field;
}

template<class Item>
const RBNode<Item>* RBNode<Item>::right() const {
	return right_field;
}

template<class Item>
const typename RBNode<Item>::Color RBNode<Item>::color() const {
	return color_field;
}

template<class Item>
const RBNode<Item>* RBNode<Item>::parent() const {
	return parent_field;
}

template<class Item>
bool RBNode<Item>::is_leaf() const {
	return (left_field == NULL) && (right_field == NULL);
}
