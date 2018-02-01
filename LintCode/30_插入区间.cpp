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
		if (newInterval.start <= it.end && newInterval.end >= it.start) {//newInterval与区间交叉，取并集；
			newInterval.start = min(newInterval.start, it.start);
			newInterval.end = max(newInterval.end, it.end);
		}
		else {
			if (!merged && newInterval.end < it.start) {
				res.push_back(newInterval);//newInterval与区间不交叉，插入此区间之前；
				merged = true;
			}
			res.push_back(it);//插入此区间；
		}
	}
	if (!merged)//没有插入区间，newInterval放在最后；
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
* 总结：
* 问题不难，第一天陷入了多情况讨论，第二天写出来；
* 原因是：没有理清思路，要考虑多种情况的相似，合并。
* 主要思路是，设置两个游标，即要插入的区间的左值右值；
* 分区间和区间之间，区间内 两种情况去判断游标的位置。
*/