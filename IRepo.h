#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class Repository {
protected:
	vector<T> elem;
public:
	Repository();
	void add(T&);
	int find(T&);
	void update(T&, T&);
	T getById(int);
	int remove(int);
	int size();
	vector<T> getAll();
};

template<class T>
inline Repository<T>::Repository()
{
}

template<class T>
inline void Repository<T>::add(T& e)
{
	elem.push_back(e);
}

template<class T>
inline int Repository<T>::find(T& e)
{
	auto it = std::find(elem.begin(), elem.end(), e);
	if (it != elem.end()) return distance(elem.begin(), it);
	return -1;
}

template<class T>
inline T Repository<T>::getById(int id)
{
	vector<T> all = getAll();
	for (T e : all)
		if (e.getId() == id)
			return e;
}

template<class T>
inline void Repository<T>::update(T& vechi, T& nou)
{
	std::replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
inline int Repository<T>::remove(int id)
{
	T found = getById(id);
	auto last = std::remove(elem.begin(), elem.end(), found);
	if (last != elem.end()) {
		elem.erase(last, elem.end());
		return 0;
	}
	return -1;
}

template<class T>
inline int Repository<T>::size()
{
	return elem.size();
}

template<class T>
inline vector<T> Repository<T>::getAll()
{
	return elem;
}