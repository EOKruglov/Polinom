#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

template <class T>
struct TLink {
	T value;
	TLink* pNext;
};

template <class T>
class TList {
protected:
	TLink <T> *pFirst, *pLast, *pPrev, *pCurr, *pStop;
	int size, pos;
public:
	TList() {
		pFirst = pLast = pPrev = pCurr = pStop = NULL;
		size = 0;
		pos = -1;
	}

	virtual void InsFirst(T el) {
		TLink<T> *tmp = new TLink<T>;
		tmp->value = el;
		if (size == 0) {
			pFirst = pLast = pCurr = tmp;
			tmp->pNext = pStop;
		}
		else {
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		pos++;
		size++;
	}

	virtual void InsCurr(T el) {
		if (pFirst == pCurr)
			InsFirst(el);
		else {
			TLink <T> *tmp = new TLink<T>;
			tmp->value = el;
			tmp->pNext = pCurr;
			pPrev->pNext = tmp;
			pCurr = tmp;
			size++;
		}
	}

	virtual void InsLast(T el) {
		if (pFirst == pStop)
			InsFirst(el);
		else {
			TLink<T> *tmp = new TLink<T>;
			tmp->value = el;
			pLast->pNext = tmp;
			tmp->pNext = pStop;
			pLast = tmp;
			size++;
		}
	}

	T GetEl() {
		return pCurr->value;
	}

	void reset() {
		pCurr = pFirst;
		pos = 0;
		pPrev = pStop;
	}

	void goNext() {
		if (pFirst->pNext == pStop)
			pPrev = pFirst;
		else {
			pPrev = pCurr;
			pCurr = pCurr->pNext;
			pos++;
		}
	}

	virtual void DelFirst() {
		if (size == 1) {
			delete pFirst;
			pFirst = pLast = pPrev = pCurr = pStop;
		}
		else
		{
			TLink<T> *tmp = pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
		}
		size--;
		pos--;

	}

	virtual void DelCurr() {
		if (pCurr == pFirst)
			DelFirst();
		else {
			pCurr = pCurr->pNext;
			delete pPrev->pNext;
			pPrev->pNext = pCurr;
			size--;
		}
	}

	virtual void DelLast() {
		if (pLast == pFirst)
			DelFirst();
		else {
			for (reset(); !(pCurr->pNext == pStop); goNext()) {}
			delete pLast;
			pLast = pCurr = pPrev;
			reset();
			size--;
			pos--;
		}
	}

	bool IsEnd() {
		return pCurr == pStop;
	}

	bool IsEmpty() {
		return pFirst == pStop;
	}

	T operator[](int poz) {
		for (reset(); !IsEnd(); goNext()) {
			if (pos == m - 1)
				return pCurr->value;
		}
	}

	void Sort(T el) {
		if (pFirst == pStop || el < pFirst->value) {
			InsFirst(el);
			return;
		}
		if (el >= pLast->value) {
			InsLast(el);
			return;
		}
		for (reset(); !IsEnd(); goNext()) {
			if (pCurr->value > el) {
				InsCurr(el);
				return;
			}
		}
	}

};

struct TMonom {
	double coeff;
	int x, y, z;
};

bool operator <(const TMonom& t1, const TMonom& t2) {
	if (t1.x < t2.x)
		return true;
	if (t1.x > t2.x)
		return false;
	if (t1.x == t2.x) {
		if (t1.y < t2.y)
			return true;
		if (t1.y > t2.y)
			return false;
		if (t1.y == t2.y) {
			if (t1.z < t2.z)
				return true;
			if (t1.z >= t2.z)
				return false;
		}
	}
}


bool operator >(const TMonom& t1, const TMonom& t2) {
	if (t1.x < t2.x)
		return false;
	if (t1.x > t2.x)
		return true;
	if (t1.x == t2.x) {
		if (t1.y < t2.y)
			return false;
		if (t1.y > t2.y)
			return true;
		if (t1.y == t2.y) {
			if (t1.z <= t2.z)
				return false;
			if (t1.z > t2.z)
				return true;
		}
	}
}

bool operator ==(const TMonom& t1, const TMonom& t2) {
	if (t1.x == t2.x)
		if (t1.y == t2.y)
			if (t1.z == t2.z)
				return true;
			else
				return false;
		else
			return false;
	else
		return false;
}

bool operator !=(const TMonom& t1, const TMonom& t2) {
	if (t1.x == t2.x)
		if (t1.y == t2.y)
			if (t1.z == t2.z)
				return false;
			else
				return true;
		else
			return true;
	else
		return true;
}



template <class T>
class THeadList :public TList<T> {
protected:
	TLink<T> *pHead;
public:
	THeadList() :TList() {
		pHead = new TLink<T>;
		pStop = pHead;
		pHead->pNext = pHead;
	}

	~THeadList() {
		TList::~TList();
		delete pHead;
	}

	void InsFirst(T a) {
		TList::InsFirst(a);
		pHead->pNext = pFirst;
	}

	void DelFirst() {
		pHead->pNext = pFirst;
	}
};

class TPolinom :public THeadList<TMonom> {
public:
	TPolinom() :THeadList() {
		pHead->value.coeff = 0;
		pHead->value.z = 1;
	}

	TPolinom(TMonom *tm, int size) :THeadList() {
		pHead->value.coeff = 0;
		pHead->value.z = 1;
		for (int i = 0; i < size; i++)
			InsLast(tm[i]);
	}

	void InsByOrder(const TMonom& tm) {
		if (pFirst == pCurr)
			InsFirst(tm);
		for (reset(); !IsEnd(); goNext()) {
			if (this->pCurr->value == tm) {
				this->pCurr->value.coeff += tm.coeff;
				if (this->pCurr->value.coeff == 0)
					DelCurr();
				return;
			}
			if (this->pCurr->value < tm) {
				InsCurr(tm);
				return;
			}
		}
		InsLast(tm);
	}

	void operator+=(TPolinom& q) {
		q.reset();
		reset();
		while (!q.IsEnd() || !IsEnd()) {
			if (pCurr->value == q.pCurr->value) {
				pCurr->value.coeff += q.pCurr->value.coeff;
				if (pCurr->value.coeff == 0) {
					DelCurr();
					q.goNext();
				}
				else {
					goNext();
					q.goNext();
				}
			}
			else
				if (pCurr->value < q.pCurr->value) {
					InsCurr(q.pCurr->value);
					q.goNext();
				}
				else
					goNext();
		}
	}

	void operator*= (const int& n) {
		if (n == 0)
			for (reset(); !IsEnd(); goNext())
				DelCurr();
		for (reset(); !IsEnd(); goNext())
			this->pCurr->value.coeff *= n;
	}

	void operator*= (const double& n) {
		if (n == 0)
			for (reset(); !IsEnd(); goNext())
				DelCurr();
		for (reset(); !IsEnd(); goNext())
			this->pCurr->value.coeff *= n;
	}

	void operator*= (const TMonom& tm) {
		for (reset(); !IsEnd(); goNext()) {
			this->pCurr->value.coeff *= tm.coeff;
			this->pCurr->value.x += tm.x;
			this->pCurr->value.y += tm.y;
			this->pCurr->value.y += tm.y;
		}
	}

	void operator*= (TPolinom& tm) {
		for (tm.reset(); !tm.IsEnd(); tm.goNext())
			*this *= tm.pCurr->value;
	}

	bool operator==(TPolinom& tp) {
		if (this->size != tp.size)
			return false;
		tp.reset();
		reset();
		while (!IsEnd()) {
			if (this->pCurr->value != tp.pCurr->value)
				return false;
			goNext();
			tp.goNext();
		}
		return true;
	}

	 string TPrint(TMonom& tm) {

		int _x, _y, _z;
		double _coeff;
		string print;

		_x = tm.x;
		_y = tm.y;
		_z = tm.z;
		_coeff = tm.coeff;

		
		print = to_string(_coeff);
		print += " * x^";
		print += to_string(_x);
		print += " * y^";
		print += to_string(_y);
		print += " * z^";
		print += to_string(_z);

		return print;

	}


	string TPrint(TPolinom& tp)
	{
		string tprint;

		for (tp.reset(); !tp.IsEnd(); tp.goNext())
		{
			tprint += TPrint(tp.pCurr->value);
		}
		
		return tprint;
	}




};
