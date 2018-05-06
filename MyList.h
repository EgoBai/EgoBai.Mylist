#pragma once

#include<list>

template<class T>
struct __ListNode {
	__ListNode<T>* _next;
	__ListNode<T>* _prev;
	T _data;

	__ListNode(const T& x)
		:_data(x)
		,_next(NULL)
		,_prev(NULL)
	{}
};


template<class T,class Ref,class Ptr>
struct __ListIterator {
	typedef __ListNode<T> Node;
	typedef __ListIterator<T, Ref, Ptr> Self;
	Node* _node;
	__ListIterator(Node* x)
		:_node(x)
	{}

	Ref operator*(){
		return _node->_data;
	}

	Ptr operator->() {
		// return &_node->_data;
		return &(operator*());
	}

	bool operator!= (const Self& s){
		return _node != s._node;
	}

	bool operator==(const Self& s) {
		return _node == s._node;
	}
	
	Self& operator ++(){
		_node = _node->_next;
		return *this;
	}
	//后置++
	Self operator++(int){
		Self tmp(*this);
		_node = _node->_next;
	}

	Self operator--() {
		_node = _node->_prev;
		return *tihs;
	}
	//后置--
	Self operator--(int) {
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}
};

template<class T>
class List
{
	typedef __ListNode<T> Node;
public:
	typedef __ListIterator<T, T&, T*> Iterator;
	typedef __ListIterator<T, const T&,const T*> ConstIterator;

	List(){
		_head = new Node(T());
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List(){
		Clear();
		delete _head;
		_head = NULL;
	}
	void Clear() {
		Iterator it = Begin();
		while (it != End()) {
		Node* del = it._node;
		++it;
		delete del;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

	Iterator Begin() {
		return _head->_next;
	}

	Iterator End() {
		return _head;
	}

	ConstIterator Begin() const {
		return _head->_next;
	}
	ConstIterator End() const {
		return _head;
	}
	
	void PushBack(const T& x) {
		Insert(End(), x);
	}

	void PushFront(const T& x) {
		Insert(Begin(), x);
	}

	void PopBack() {
		Erase(--End());
	}
	void PushFront() {
		Erase(Begin());
	}
	void Insert(Iterator pos, const T& x) {
		Node* cur = pos._node;
		Node* prev = cur->_prev;

		Node* tmp = new Node(x);

		prev->_next = tmp;
		tmp->_prev = prev;

		tmp->_next = cur;
		cur->_prev = tmp;
	}

	Iterator Erase(Iterator& pos) {
		assert(pos->_node != _head);

		Node* cur = pos->_node;
		Node*  prev = cur->_prev;
		Node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;
		delete cur;

		pos = prev;
		
		return next;
	}

	void Assign(size_t n, const T& val) {
		Clear();
		for (size_t i = 0;i<n;++i)
		{
			PushBack(val);
		}
	}

	template<class InputIterator>
	void Assign (InputIterator first,InputIterator last ){
		Clear();
		while (first != last) {
			PushBack(*first);
			++first;
		}
	}

	protected:
	Node * _head;
};


struct AA {
	int _a1;
	int _a2;
};

void PrintList(const List<int>& l)
{
	List<int>::ConstIterator it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void print_list(const list<int>& l)
{
	list<int>::const_iterator it1 = l.begin();
	while (it1 != l.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

void TestList() {
	List<int> l;
	l.PushBack(123);
	l.PushBack(456);
	l.PushBack(789);
	l.PushBack(10);

	PrintList(l);
}



//void Testlist2()
//{
//	list<int> l2;
//	l2.push_back(30);
//	l2.push_back(30);
//	l2.push_back(10);
//	l2.push_back(20);
//	l2.push_back(30);
//	l2.push_back(30);
//	l2.push_back(30);
//	l2.push_back(40);
//	l2.push_back(40);
//	l2.push_back(40);
//	print_list(l2);
//	list<int>::iterator pos = find(l2.begin(), l2.end(), 400);
//	if (pos != l2.end())
//	{
//		l2.erase(pos);
//	}
//
//	l2.remove(30);
//
//
//	l2.sort();
//	l2.unique();
//
//	print_list(l2);
//}
//	


	void Testlist3()
	{
		list<int> l2;
		l2.push_back(10);
		l2.push_back(20);
		l2.push_back(30);
		l2.push_back(40);
		print_list(l2);
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
	
		print_list(l1);
	
		string s1("hello");
		l1.assign(10, 1);
		/*l1.assign(++l2.begin(), --l2.end());
		l1.assign(s1.begin(), s1.end());*/
		l1.resize(5);
	
		print_list(l1);
	}

