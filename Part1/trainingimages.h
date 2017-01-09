#ifndef TRAININGIMAGES_H
#define TRAININGIMAGES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>  

using namespace std;

class matrix
{
public:
	double num[28][28];
	matrix()
	{
		for(int i =0; i <28; i++)
		{
			for(int j =0; j< 28; j++)
			{
				num[i][j] = 0;
			}
		}
	}

	~matrix()
	{
		
	}


};



class SetClass
{
public:
	vector<matrix> numbers;
	vector<double> count_numbers;

	vector<matrix> pixelprobabilities;
	vector<double> classprobability;
	double confusion_matrix[10][10];

	vector<vector<string>> highestpp;
	vector<vector<string>>lowestpp;
	vector<double> highval;
	vector<double> lowval;

	void populate(string imagefile, string answerfile);
	SetClass();
	void calculate_training_probability();
	int findmaxposition(vector<double> mapval);
	void classify_test_numbers(string testfile, string testanswerfile);
	void convertconfusiontoprobability();
	void oddratios(int actual, int confused);
	void printhighestlowest();

};


#endif