#pragma once
#include "TransactionList.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

class IStatistics
{
protected:
	virtual double getSum() = 0;
	virtual double getMedian() = 0;
	virtual double getMean() = 0;
	virtual double getStDev() = 0;
	virtual void print() = 0;
	virtual void countSum(TransactionNode*) = 0;
	virtual void countSum(TransactionNode*, Member member) = 0;
	virtual void countSum(TransactionNode*, Member member, Date start, Date end) = 0;
	virtual void countSum(TransactionNode*, Date start, Date end) = 0;
	virtual void countMedian(TransactionNode*)=0;
	virtual void countMedian(TransactionNode*, Member member) = 0;
	virtual void countMedian(TransactionNode*, Member member, Date start, Date end) = 0;
	virtual void countMedian(TransactionNode*, Date start, Date end) = 0;
	virtual void countMean(TransactionNode*) = 0;
	virtual void countMean(TransactionNode*, Member member) = 0;
	virtual void countMean(TransactionNode*, Member member, Date start, Date end) = 0;
	virtual void countMean(TransactionNode*, Date start, Date end) = 0;
	virtual void countStandardDeviation(TransactionNode*) = 0;
	virtual void countStandardDeviation(TransactionNode*, Member member) = 0;
	virtual void countStandardDeviation(TransactionNode*, Member member, Date start, Date end) = 0;
	virtual void countStandardDeviation(TransactionNode*, Date start, Date end) = 0;
};
