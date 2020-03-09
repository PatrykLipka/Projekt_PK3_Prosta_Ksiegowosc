#include "Statistics.h"


double Statistics::getMedian()
{
	return this->median;
}

double Statistics::getMean()
{
	return this->mean;
}


double Statistics::getStDev()
{
	return this->stdev;
}

double Statistics::getSum()
{
	return this->sum;
}

void Statistics::print()
{
	std::cout << "Sum: " << getSum() << std::endl << "Mean: " << getMean() << std::endl << "Median: " << getMedian() 
		<< std::endl << "Standard deviation: " << getStDev() << std::endl;
}

void Statistics::countSum(TransactionNode* pHead)
{

	int amount = 0;
	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		amount++;
		prices.push_back(tempHead->getNode().getPrice());
		tempHead = tempHead->getNext();
	}

	if (amount == 0)
	{
		this->sum = 0;
	}
	else {
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		this->sum = sum;
	}
}

void Statistics::countSum(TransactionNode* pHead, Member member)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getMember() == member)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}

	if (amount == 0)
	{
		this->sum = 0;
	}
	else {
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		this->sum = sum;
	}
}

void Statistics::countSum(TransactionNode* pHead, Member member, Date start, Date end)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getMember() == member && tempHead->getNode().getDate() >= start && tempHead->getNode().getDate() <= end)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}
	if (amount == 0)
	{
		this->sum = 0;
	}
	else {
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		this->sum = sum;
	}
}

void Statistics::countSum(TransactionNode* pHead, Date start, Date end)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getDate() >= start && tempHead->getNode().getDate() <= end)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}
	if (amount == 0)
	{
		this->sum = 0;
	}
	else {
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		this->sum = sum;
	}
}

void Statistics::countMedian(TransactionNode* pHead)
{
	int amount = 0;
	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		amount++;
		prices.push_back(tempHead->getNode().getPrice());
		tempHead = tempHead->getNext();
	}

	sort(prices.begin(), prices.end());

	double median;
	if (amount == 0)
	{
		this->median = 0;
	}
	else
	{
		if (amount % 2 == 0)
		{
			median = (prices[prices.size() / 2 - 1] + prices[prices.size() / 2]) / 2;
			this->median = median;
		}
		else
		{
			median = prices[prices.size() / 2];
			this->median = median;
		}
	}
}


void Statistics::countMedian(TransactionNode* pHead, Member member)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if(tempHead->getNode().getMember()==member)
		{ 
		amount++;
		prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}

	sort(prices.begin(), prices.end());

	double median;
	if (amount == 0)
	{
		this->median = 0;
	}
	else 
	{
		if (amount % 2 == 0)
		{
			median = (prices[prices.size() / 2 - 1] + prices[prices.size() / 2]) / 2;
			this->median = median;
		}
		else
		{
			median = prices[prices.size() / 2];
			this->median = median;
		}
	}
}
void Statistics::countMedian(TransactionNode* pHead, Member member, Date start, Date end)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getMember() == member && tempHead->getNode().getDate()>=start && tempHead->getNode().getDate() <= end)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}

	sort(prices.begin(), prices.end());

	double median;
	if (amount == 0)
	{
		this->median = 0;
	}
	else
	{
		if (amount % 2 == 0)
		{
			median = (prices[prices.size() / 2 - 1] + prices[prices.size() / 2]) / 2;
			this->median = median;
		}
		else
		{
			median = prices[prices.size() / 2];
			this->median = median;
		}
	}
}

void Statistics::countMedian(TransactionNode* pHead, Date start, Date end)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getDate() >= start && tempHead->getNode().getDate() <= end)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}

	sort(prices.begin(), prices.end());

	double median;
	if (amount == 0)
	{
		this->median = 0;
	}
	else
	{
		if (amount % 2 == 0)
		{
			median = (prices[prices.size() / 2 - 1] + prices[prices.size() / 2]) / 2;
			this->median = median;
		}
		else
		{
			median = prices[prices.size() / 2];
			this->median = median;
		}
	}

	
}

void Statistics::countMean(TransactionNode* pHead)
{

	int amount = 0;
	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		amount++;
		prices.push_back(tempHead->getNode().getPrice());
		tempHead = tempHead->getNext();
	}

	if (amount == 0)
	{
		this->mean = 0;
	}
	else {
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		double mean = sum / prices.size();
		this->mean = mean;
	}
}

void Statistics::countMean(TransactionNode* pHead, Member member)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getMember() == member)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}

	if (amount == 0)
	{
		this->mean = 0;
	}
	else {
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		double mean = sum / prices.size();
		this->mean = mean;
	}
}

void Statistics::countMean(TransactionNode* pHead, Member member, Date start, Date end)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getMember() == member && tempHead->getNode().getDate() >= start && tempHead->getNode().getDate() <= end)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}
	if (amount == 0)
	{
		this->mean = 0;
	}
	else {
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		double mean = sum / prices.size();
		this->mean = mean;
	}
}

void Statistics::countMean(TransactionNode* pHead , Date start, Date end)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getDate() >= start && tempHead->getNode().getDate() <= end)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}
	if (amount == 0)
	{
		this->mean = 0;
	}
	else {
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		double mean = sum / prices.size();
		this->mean = mean;
	}
}

void Statistics::countStandardDeviation(TransactionNode* pHead)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		amount++;
		prices.push_back(tempHead->getNode().getPrice());
		tempHead = tempHead->getNext();
	}

	if (amount == 0)
	{
		this->stdev = 0;
	}
	else
	{
	double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
	double mean = sum / prices.size();

	std::vector<double> diff(prices.size());

	std::transform(prices.begin(), prices.end(), diff.begin(), [mean](double x) { return x - mean; });
	double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
	double stdev = std::sqrt(sq_sum / prices.size());

	this->stdev = stdev;
	}
}

void Statistics::countStandardDeviation(TransactionNode* pHead, Member member)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getMember() == member)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}
	if (amount == 0)
	{
		this->stdev = 0;
	}
	else
	{
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		double mean = sum / prices.size();

		std::vector<double> diff(prices.size());

		std::transform(prices.begin(), prices.end(), diff.begin(), [mean](double x) { return x - mean; });
		double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
		double stdev = std::sqrt(sq_sum / prices.size());

		this->stdev = stdev;
	}
}

void Statistics::countStandardDeviation(TransactionNode* pHead, Member member, Date start, Date end)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if (tempHead->getNode().getMember() == member && tempHead->getNode().getDate() >= start && tempHead->getNode().getDate() <= end)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}
	if (amount == 0)
	{
		this->stdev = 0;
	}
	else
	{
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		double mean = sum / prices.size();

		std::vector<double> diff(prices.size());

		std::transform(prices.begin(), prices.end(), diff.begin(), [mean](double x) { return x - mean; });
		double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
		double stdev = std::sqrt(sq_sum / prices.size());

		this->stdev = stdev;
	}
}

void Statistics::countStandardDeviation(TransactionNode* pHead, Date start, Date end)
{
	int amount = 0;

	TransactionNode* tempHead = pHead;

	std::vector<double> prices;
	while (tempHead)
	{
		if ( tempHead->getNode().getDate() >= start && tempHead->getNode().getDate() <= end)
		{
			amount++;
			prices.push_back(tempHead->getNode().getPrice());
		}
		tempHead = tempHead->getNext();
	}
	if (amount == 0)
	{
		this->stdev = 0;
	}
	else
	{
		double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
		double mean = sum / prices.size();

		std::vector<double> diff(prices.size());

		std::transform(prices.begin(), prices.end(), diff.begin(), [mean](double x) { return x - mean; });
		double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
		double stdev = std::sqrt(sq_sum / prices.size());

		this->stdev = stdev;
	}
}