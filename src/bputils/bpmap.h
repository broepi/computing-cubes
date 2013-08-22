
#ifndef BPLIST_H
#define BPLIST_H

#include <memory.h>

template <typename K, typename V>
struct BPMapNode {
	BPMapNode (K, V*);

	K key;
	V *value;
	BPMapNode<K,V> *next;
};

template <typename K, typename V>
struct BPMap {
	BPMap ();
	BPMapNode<K,V> *set (K, V*);
	BPMapNode<K,V> *last ();
	BPMapNode<K,V> *get (K);
	V *get_value (K);
	//void del (K);
	//void del_all ();

	BPMapNode<K,V> *first;
	unsigned long count;
};

template <typename K, typename V>
BPMapNode<K,V>::BPMapNode (K key, V *value = 0)
{
	this->key = key;
	this->value = value;
	this->next = 0;
}

template <typename K, typename V>
BPMap<K,V>::BPMap ()
{
	first = 0;
	count = 0;
}

template <typename K, typename V>
BPMapNode<K,V> *BPMap<K,V>::set (K key, V *value = 0)
{
	BPMapNode<K,V> *cur = this->get (key);
	
	if (cur) {
		if (cur->value)
			delete cur->value;
		cur->value = value;
		return cur;
	}
	else {
		BPMapNode<K,V> *last = this->last ();
		count ++;
		if (last) {
			last->next = new BPMapNode<K,V> (key, value);
			return last->next;
		}
		else {
			this->first = new BPMapNode<K,V> (key, value);
			return this->first;
		}
	}
}

template <typename K, typename V>
BPMapNode<K,V> *BPMap<K,V>::last ()
{
	BPMapNode<K,V> *res;

	res = this->first;
	while (res && res->next) res = res->next;

	return res;
}

/*
	Get(index)
	index - zwischen -1 und count-1
*/

template <typename K, typename V>
BPMapNode<K,V> *BPMap<K,V>::get (K key)
{
	BPMapNode<K,V> *res;
	
	res = this->first;
	while (res && res->key != key) {
		res = res->next;
	}

	return res;
}

template <typename K, typename V>
V *BPMap<K,V>::get_value (K key)
{
	BPMapNode<K,V> *res = this->get(key);
	if (res)
		return res->value;
	else
		return 0;
}

/*
	Del(index)
	index - zwischen 0 und count-1
*/

/*
template <typename K, typename V>
void BPMap<K,V>::del (K key)
{
	BPMapNode<K,V> *node, *prev, *next;
	int index = 0;
	
	if (index==0) {
		if (!first) return;
		next = first->next;
		if (first->data)
			delete first->data;
		delete first;
		first = next;
	}
	else if (index > 0) {
		prev = this->get (index-1);
		if (!prev) return;
		node = prev->next;
		if (!node) return;
		next = node->next;
		if (node->data)
			delete node->data;
		delete node;
		prev->next = next;
	}
	count --;
}

template <typename K, typename V>
void BPMap<K,V>::del_all ()
{
	while (count)
		del (0);
}
*/

#endif // BPLIST_H

