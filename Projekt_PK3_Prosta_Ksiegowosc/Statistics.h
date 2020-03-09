#pragma once
#include "IStatistics.h"

class Statistics: public IStatistics
{
private:
	double sum = 0;
	double median=0;
	double mean=0;
	double stdev=0;
public:
	double getSum();
	double getMedian();
	double getMean();
	double getStDev();
	void print();
	void countSum(TransactionNode*);
	void countSum(TransactionNode*, Member member);
	void countSum(TransactionNode*, Member member, Date start, Date end);
	void countSum(TransactionNode*, Date start, Date end);
	void countMedian(TransactionNode*);
	void countMedian(TransactionNode*, Member member);
	void countMedian(TransactionNode*, Member member, Date start, Date end);
	void countMedian(TransactionNode*, Date start, Date end);
	void countMean(TransactionNode*);
	void countMean(TransactionNode*, Member member);
	void countMean(TransactionNode*, Member member, Date start, Date end);
	void countMean(TransactionNode*, Date start, Date end);
	void countStandardDeviation(TransactionNode*);
	void countStandardDeviation(TransactionNode*, Member member);
	void countStandardDeviation(TransactionNode*, Member member, Date start, Date end);
	void countStandardDeviation(TransactionNode*, Date start, Date end);
};
