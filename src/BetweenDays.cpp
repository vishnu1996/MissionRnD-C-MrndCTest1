/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head)
{
	int d1,d2,m1,m2,y1,y2;
	if (date1head == NULL || date2head == NULL)
		return -1;
	d1 = 10 * (date1head->data) + date1head->next->data;
	d2 = 10 * (date2head->data) + date2head->next->data;
	date1head = date1head->next->next;
	date2head = date2head->next->next;
	m1 = 10 * (date1head->data) + date1head->next->data;
	m2 = 10 * (date2head->data) + date2head->next->data;
	date1head = date1head->next->next;
	date2head = date2head->next->next;
	y1 = 1000 * (date1head->data) + 100 * (date1head->next->data) + 10 * (date1head->next->next->data) + (date1head->next->next->next->data);
	y2 = 1000 * (date2head->data) + 100 * (date2head->next->data) + 10 * (date2head->next->next->data) + (date2head->next->next->next->data);
	if (y1 == y2)
	{
		if (m1 == m2)
		{
			if (d1 > d2)
				return d1 - d2;
			else if (d1 < d2)
				return d2 - d1;
			else 
				return 0;
		}
		else if (m1 > m2)
		{
			if (d1 > d2)
				return (m1-m2)*30+d1 - d2;
			else if (d1 < d2)
				return (m1 - m2) * 30+d2 - d1;
			else
				return (m1 - m2) * 30;
		}
		else
			if (d1 > d2)
				return (m2 - m1) * 30 + d1 - d2;
			else if (d1 < d2)
				return (m2 - m1) * 30 + d2 - d1;
			else
				return (m2 - m1) * 30;
	}
	else if (y1>y2)
	{
		if (m1 == m2)
		{
			if (d1 > d2)
				return  365 * (y1 - y2) + d1 - d2;
			else if (d1 < d2)
				return  365 * (y1 - y2) + d2 - d1;
			else
				return  365 * (y1 - y2);
		}
		else if (m1 > m2)
		{
			if (d1 > d2)
				return 365*(y1-y2)+(m1 - m2) * 30 + d1 - d2;
			else if (d1 < d2)
				return 365 * (y1 - y2) + (m1 - m2) * 30 + d2 - d1;
			else
				return 365 * (y1 - y2) + (m1 - m2) * 30;
		}
		else
			if (d1 > d2)
				return 365-(m2 - m1) * 30 + d1 - d2;
			else if (d1 < d2)
				return 365-(m2 - m1) * 30 + d2 - d1;
			else
				return 365-(m2 - m1) * 30;
	}
	else
	{
		if (m1 == m2)
		{
			if (d1 > d2)
				return  365 * (y2 - y1) + d1 - d2;
			else if (d1 < d2)
				return  365 * (y2 - y1) + d2 - d1;
			else
				return  365 * (y2 - y1);
		}
		else if (m1 > m2)
		{
			if (d1 > d2)
				return 365 - (m1 - m2) * 30 + d1 - d2;
			else if (d1 < d2)
				return 365 - (m1 - m2) * 30 + d2 - d1;
			else
				return 365 - (m1 - m2) * 30;
		}
		else
			if (d1 > d2)
				return 365 * (y2 - y1) + (m2 - m1) * 30 + d1 - d2;
			else if (d1 < d2)
				return 365 * (y2 - y1) + (m2 - m1) * 30 + d2 - d1;
			else
				return 365 * (y2 - y1) + (m2 - m1) * 30;
	}
}