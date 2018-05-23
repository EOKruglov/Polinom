#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

template <class T>
struct TLink {
	T val;
	TLink *pNext;
};
template <class T>
class TList {
protected:
	TLink<T> *pFirst, *pLast, *pPrev, *pCurr, *pStop;
	int size, pos;
public:
	TList()
	{
		pFirst = pLast = pCurr = pStop = NULL;
		size = 0;
		pos = -1;
	}
	void sortInput(T a)
	{
		if (pFirst == pStop || a<pFirst->val)
		{
			addFirst(a);
			pCurr = pPrev = pFirst;
			return;
		}

		if (a >= pLast->val)
		{
			addLast(a);
			for (reset(); !(pCurr->pNext == pStop); goNext()) {}
			return;
		}
		for (reset(); !isEnd(); goNext()) {
			if (pCurr->val>a) { addCurr(a); return; }
		}



	}

	virtual void addFirst(T a)
	{
		TLink<T> *tmp = new TLink <T>;

		tmp->val = a;

		if (size == 0)
		{
			pFirst = pLast = pCurr = tmp;
			tmp->pNext = pStop;
		}
		else
		{
			tmp->pNext = pFirst;
			pFirst = tmp;
			if (size == 1) pPrev = pFirst;
		}

		pos++;
		size++;
	}

	void addCurr(T a)
	{
		if (pFirst == pCurr) addFirst(a);
		else
		{

			TLink<T> *tmp = new TLink<T>;
			tmp->val = a;
			tmp->pNext = pCurr;
			pPrev->pNext = tmp;
			pCurr = tmp;
			size++;
		}

	}

	void addLast(T a)
	{
		if (pFirst == NULL) addFirst(a);
		else {
			TLink<T> *tmp = new TLink<T>;
			tmp->val = a;
			pLast->pNext = tmp;
			tmp->pNext = pStop;
			pLast = tmp;
			size++;
		}

	}

	T getElem()
	{
		if (pCurr != 0)
			return pCurr->val;
	}

	void delFirst()
	{
		if (size == 1)
		{
			delete pFirst;
			pFirst = pLast = pPrev = pCurr = pStop = NULL;
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

	void delCurr()
	{
		if (pCurr == pFirst)

			delFirst();

		else
		{
			pCurr = pCurr->pNext;
			delete pPrev->pNext;
			pPrev->pNext = pCurr;
			size--;

		}
	}

	void delLast()
	{
		if (pLast == pFirst) delFirst();
		else
		{
			for (reset(); !(pCurr == pLast); goNext()) {}
			delete pLast;
			pLast = pCurr = pPrev;
			pLast->pNext = pStop;
			size--;
			pos--;
		}
	}

	void reset()
	{
		pPrev = pCurr = pFirst;
		pos = 0;
	}

	void goNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;

	}

	bool isEnd()
	{
		return pCurr == pStop;
	}

	bool isStart()
	{
		return pCurr == pFirst;
	}

	bool isEmpty()
	{
		return pFirst == NULL;
	}

	T operator[](int m)
	{
		for (reset(); !isEnd(); goNext()) {
			if (pos == m - 1)
				return pCurr->val;
		}
	}

	~TList()
	{
		int listsize = size;
		for (int i = 0; i<listsize; i++)
			delFirst();
	}
};


template <class T>
class THeadList :public TList<T> {
protected: TLink<T> *pHead;
public:
	THeadList() :TList()
	{
		TLink<T> *tmp = new TLink<T>;

		pHead = tmp;
		pStop = tmp;
		tmp->pNext = pStop;
		size = 0;
	}
	~THeadList()
	{
		TList<T>::~TList();
		delete pHead;
	}
	void clearList()
	{
		TList<T>::~TList();
	}
	virtual void delFirst()
	{
		if (size == 1)
		{
			delete pFirst;
			pFirst = pLast = pPrev = pCurr = NULL;
			pHead->pNext = pStop;
		}
		else
		{
			TLink<T> *tmp = pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
			pHead->pNext = pFirst;
		}
		size--;
		pos--;
	}
	virtual void addFirst(T a)
	{
		TLink<T> *tmp = new TLink<T>;

		tmp->val = a;

		if (pFirst == NULL) {
			tmp->pNext = pStop;
			pFirst = pLast = tmp;
			pos = 0;
		}
		else {
			tmp->pNext = pFirst;
			pFirst = tmp;
			pos++;
		}

		size++;
		pHead->pNext = pFirst;
	}



};



struct TMonom {
	double coeff;
	int x, y, z;

	bool operator<(const TMonom &q) {
		return ((x * 100 + y * 10 + z)<(q.x * 100 + q.y * 10 + q.z));
	}

	bool operator>(const TMonom &q) {
		return ((x * 100 + y * 10 + z)>(q.x * 100 + q.y * 10 + q.z));
	}

	bool operator!=(const TMonom &q) {
		if ((x * 100 + y * 10 + z) == (q.x * 100 + q.y * 10 + q.z))
			return (coeff != q.coeff);
		else return true;
	}

	bool EqualDegrees(const TMonom &q) {
		return ((x * 100 + y * 10 + z) == (q.x * 100 + q.y * 10 + q.z));
	}

	bool operator==(const TMonom &q) {
		if ((x * 100 + y * 10 + z) == (q.x * 100 + q.y * 10 + q.z))
			return (coeff == q.coeff);
		else return false;
	}

	TMonom operator*(const TMonom &q) {
		TMonom tmp;
		tmp.x = q.x + x;
		tmp.y = q.y + y;
		tmp.z = q.z + z;
		tmp.coeff = q.coeff*coeff;
		return tmp;
	}

	TMonom& operator=(const TMonom &q) {
		coeff = q.coeff;
		x = q.x;
		y = q.y;
		z = q.z;
		return *this;
	}
};

ostream& operator<<(ostream& os, const TMonom& m) {
	if (!m.coeff) { os << "0"; return os; }
	os << m.coeff;
	if (m.x) if (m.x>1) os << "x^" << m.x;
	else  os << "x";
	if (m.y) if (m.y>1) os << "y^" << m.y;
	else  os << "y";
	if (m.z) if (m.z>1) os << "z^" << m.z;
	else  os << "z";
	return os;
}

class TPolynom : public THeadList<TMonom> {
public:

	TPolynom() :THeadList() {
		pHead->val.coeff = 0;
		pHead->val.x = -1;
	}

	TPolynom(TPolynom &p) :THeadList()
	{
		pHead->val.coeff = 0;
		pHead->val.x = -1;

		if (p.size)
		{
			TLink<TMonom> *tmp1 = new TLink<TMonom>;
			pHead->pNext = tmp1;
			pFirst = pCurr = tmp1;

			for (p.reset(); !p.isEnd(); p.goNext())
			{
				TLink<TMonom> *tmp2 = new TLink<TMonom>;
				pCurr->val = p.pCurr->val;
				if (p.pos == p.size - 1) { pLast = pCurr; pLast->pNext = pStop; size = p.size; break; }
				pCurr->pNext = tmp2;
				goNext();

			}
		}

	}

	TPolynom(const TMonom &m) :THeadList()
	{
		TLink<TMonom> *tmp = new TLink<TMonom>;

		tmp->pNext = pStop;
		tmp->val = m;
		pHead->pNext = tmp;
		pFirst = pLast = pCurr = tmp;
	}

	void sortInput(TMonom a)
	{
		if (!size) { addFirst(a); return; }
		for (reset(); !isEnd(); goNext()) {
			if (pCurr->val.EqualDegrees(a)) {
				pCurr->val.coeff += a.coeff;
				if (!pCurr->val.coeff) delCurr();
				return;
			}
			else  if (pCurr->val<a) {
				addCurr(a);
				return;
			}
		}
		addLast(a);
	}

	TPolynom(TMonom *mas, int size) :THeadList()
	{
		pHead->val.coeff = 0;
		pHead->val.x = -1;

		for (int i = 0; i<size; i++)
			sortInput(mas[i]);
	}

	TPolynom operator+(TPolynom &p)
	{
		TPolynom tmp(*this);
		p.reset();

		for (reset(); !isEnd(); goNext())
		{
			for (p.pCurr; (p.pCurr->val>pCurr->val && !p.isEnd()); p.goNext())
			{
				tmp.sortInput(p.pCurr->val);
			}
		}

		if (isEnd() && !p.isEnd())
			for (p.pCurr; !p.isEnd(); p.goNext())
				tmp.sortInput(p.pCurr->val);

		return tmp;
	}

	void operator += (TPolynom TM)
	{
		TM.reset();
		reset();

		while (!isEnd() || !TM.isEnd())
		{
			if (pCurr->val == TM.pCurr->val)
			{
				pCurr->val.coeff += TM.pCurr->val.coeff;
				if (pCurr->val.coeff == 0)
				{
					delCurr();
					TM.goNext();
				}
				else
				{
					goNext();
					TM.goNext();
				}
			}
			else
				if (pCurr->val < TM.pCurr->val)
				{
					addCurr(TM.pCurr->val);
					TM.goNext();
				}
				else
					goNext();
		}
	}

	TPolynom operator-(TPolynom &p)
	{
		TPolynom tmp(*this), tmp2(p);
		tmp2 *= -1;
		tmp2.reset();

		for (reset(); !isEnd(); goNext())
		{
			for (tmp2.pCurr; (tmp2.pCurr->val>pCurr->val && !tmp2.isEnd()); tmp2.goNext())
			{
				tmp.sortInput(tmp2.pCurr->val);
			}
		}

		if (isEnd() && !tmp2.isEnd())
			for (tmp2.pCurr; !tmp2.isEnd(); tmp2.goNext())
				tmp.sortInput(tmp2.pCurr->val);

		return tmp;
	}

	void operator -= (TPolynom TM)
	{
		TM.reset();
		reset();

		while (!isEnd() || !TM.isEnd())
		{
			if (pCurr->val == TM.pCurr->val)
			{
				pCurr->val.coeff -= TM.pCurr->val.coeff;
				if (pCurr->val.coeff == 0)
				{
					delCurr();
					TM.goNext();
				}
				else
				{
					goNext();
					TM.goNext();
				}
			}
			else
				if (pCurr->val < TM.pCurr->val)
				{
					addCurr(TM.pCurr->val);
					TM.goNext();
				}
				else
					goNext();
		}
	}

	TPolynom& operator=(TPolynom &p)
	{
		pHead->val.coeff = 0;
		pHead->val.x = -1;

		if (p.size)
		{
			TLink<TMonom> *tmp1 = new TLink<TMonom>;
			pHead->pNext = tmp1;
			pFirst = pCurr = tmp1;

			for (p.reset(); !p.isEnd(); p.goNext())
			{
				TLink<TMonom> *tmp2 = new TLink<TMonom>;

				pCurr->val = p.pCurr->val;

				if (p.pos == p.size - 1)
				{
					pLast = pCurr;
					pLast->pNext = pStop;
					size = p.size;
					break;
				}

				pCurr->pNext = tmp2;
				goNext();
			}
			return *this;
		}
	}

	TPolynom operator*(TPolynom &p)
	{
		TPolynom tmp;

		for (p.reset(); !p.isEnd(); p.goNext())
			for (reset(); !isEnd(); goNext()) {
				tmp.sortInput(pCurr->val*p.pCurr->val);
			}

		return tmp;
	}

	void operator*=(double a)
	{
		for (reset(); !isEnd(); goNext())
			pCurr->val.coeff *= a;
	}

	TPolynom operator*(double a)
	{
		TPolynom tmp(*this);
		for (reset(); !isEnd(); goNext())
			tmp.pCurr->val.coeff *= a;
		return tmp;
	}

	double getCoeff()
	{
		return pCurr->val.coeff;
	}

	int getX()
	{
		return pCurr->val.x;
	}

	int getY()
	{
		return pCurr->val.y;
	}

	int getZ()
	{
		return pCurr->val.z;
	}

	bool isLast()
	{
		return pCurr->pNext == pStop;
	}

	friend ostream& operator<<(ostream& os, TPolynom &p)
	{
		if (p.size == 0)
		{
			os << "0";
			return os;
		}

		for (p.reset(); !p.isEnd(); p.goNext())
		{
			if (!p.pos) os << p.pCurr->val;
			else
				if (p.pCurr->val.coeff>0) os << "+ " << p.pCurr->val;
				else os << p.pCurr->val;
		}
		return os;
	}
	
	void InsByOrder(const TMonom &tm)
	{
		if (pFirst == NULL)
		{
			addFirst(tm);
			return;
		}
		for (reset(); !isEnd(); goNext())
		{
			if ((this->pCurr->val == tm) || (this->pCurr->val.x == tm.x)&&
				(this->pCurr->val.y == tm.y) && (this->pCurr->val.z == tm.z))
			{
				this->pCurr->val.coeff += tm.coeff;
				if (this->pCurr->val.coeff == 0)
					delCurr();
				return;
			}
			if (this->pCurr->val < tm)
			{
				addCurr(tm);
				return;
			}
		}
		addLast(tm);
	}
};
