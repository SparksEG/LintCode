//20180129
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

////answer by me
//vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
//	// write your code here
//	vector<Interval> newintervals;
//	if (intervals.empty()) {
//		newintervals.push_back(newInterval);
//		return newintervals;
//	}
//
//	vector<Interval>::iterator iterbegin = intervals.begin();
//	int forward = INT_MAX, backward = INT_MAX;
//	for (auto iter = iterbegin; iter != intervals.end(); iter++) {
//		if (forward == INT_MAX && newInterval.start < (*iter).start) {
//			forward = newInterval.start;
//		}
//		if (forward == INT_MAX && newInterval.start >= (*iter).start && newInterval.start <= (*iter).end) {
//			forward = (*iter).start;
//		}
//		if (backward == INT_MAX && newInterval.end < (*iter).start) {
//			backward = newInterval.end;
//			Interval tmp(forward, backward);
//			newintervals.push_back(tmp);
//		}
//		if (backward == INT_MAX && newInterval.end >= (*iter).start && newInterval.end <= (*iter).end) {
//			backward = (*iter).end;
//			Interval tmp(forward, backward);
//			newintervals.push_back(tmp);
//			continue;
//		}
//		if (forward != INT_MAX && backward == INT_MAX) {
//			;
//		}
//		else {
//			newintervals.push_back(*iter);
//		}
//	}
//	if (newInterval.end > intervals.back().end) {
//		backward = newInterval.end;
//		if (forward == INT_MAX) {
//			forward = newInterval.start;
//		}
//		Interval tmp(forward, backward);
//		newintervals.push_back(tmp);
//	}
//	return newintervals;
//}


//answer from OJ.net
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	// write your code here
	vector<Interval> res;
	bool merged = false;
	for (Interval it : intervals) {
		if (newInterval.start <= it.end && newInterval.end >= it.start) {//newInterval�����佻�棬ȡ������
			newInterval.start = min(newInterval.start, it.start);
			newInterval.end = max(newInterval.end, it.end);
		}
		else {
			if (!merged && newInterval.end < it.start) {
				res.push_back(newInterval);//newInterval�����䲻���棬���������֮ǰ��
				merged = true;
			}
			res.push_back(it);//��������䣻
		}
	}
	if (!merged)//û�в������䣬newInterval�������
		res.push_back(newInterval);
	return res;
}


int main() {
	Interval a1(1, 3);
	Interval a2(5, 7);
	Interval a3(9, 11);
	Interval a4(13, 15);
	Interval a5(17, 19);
	Interval tmp(2,8);
	vector<Interval> intervals{ a1, a2, a3, a4, a5 };
	vector<Interval> newintervals = insert(intervals, tmp);
	for (auto i : newintervals)
		cout << "start:" << i.start << "  " << "end:" << i.end << endl;
	system("pause");
}


/*
* �ܽ᣺
* ���ⲻ�ѣ���һ�������˶�������ۣ��ڶ���д������
* ԭ���ǣ�û������˼·��Ҫ���Ƕ�����������ƣ��ϲ���
* ��Ҫ˼·�ǣ����������α꣬��Ҫ������������ֵ��ֵ��
* �����������֮�䣬������ �������ȥ�ж��α��λ�á�
*/