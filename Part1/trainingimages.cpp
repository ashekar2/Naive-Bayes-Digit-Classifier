#include "trainingimages.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>  
#include <iomanip> 
using namespace std;


SetClass::SetClass()
{

	matrix a;
	vector<string> b;
	for(int i = 0; i <28; i++)
	{
		for(int j =0; j<28; j++)
		{
			string temp ="";
			b.push_back(temp);
		}
		highestpp.push_back(b);
		lowestpp.push_back(b);
		b.clear();
	}

	for(int i =0; i<10; i++)
	{
		numbers.push_back(a);
		pixelprobabilities.push_back(a);
		count_numbers.push_back(0);
		classprobability.push_back(0);
		highval.push_back(INT_MIN);
		lowval.push_back(INT_MAX);
	}

	for(int i =0; i<10; i++)
	{
		for(int j = 0; j<10; j++)
		{
			confusion_matrix[i][j] = 0;
		}
	}

}

void SetClass::populate(string imagefile, string answerfile)
{

	fstream images, answers;
	images.open(imagefile);
	answers.open(answerfile);

	int linecount = 0;
	int singleimagecount = 0;
	vector<string> singlenumber;

	while(linecount <= 140000)
	{	
		string t;
		getline(images,t);
		linecount++;
		singlenumber.push_back(t);
		//cout<<t<<endl;
		singleimagecount++;
		

		if(singleimagecount == 28)
		{
			singleimagecount = 0;
			string imageanswer;
			getline(answers, imageanswer); // stores what the current image represents
			int numans = imageanswer[0] % 48;
			for(int i =0; i<28; i++)
			{
				for(int j = 0; j<28; j++)
				{
					if(singlenumber[i][j] != ' ')
					{
						(numbers[numans]).num[i][j]++;
					}
				}
			}
			count_numbers[numans]++;
			singlenumber.clear();

		}

		
	}

	images.close();
	answers.close();
}

void SetClass::calculate_training_probability()
{
	int k = 1; //Laplace Smoothing!
	for(int i =0; i<10; i++)
	{
		for(int j = 0; j<28; j++)
		{
			for(int l = 0; l<28; l++)
			{
				(pixelprobabilities[i]).num[j][l] = ((numbers[i]).num[j][l]+k)/(count_numbers[i] + 2*k);
			}
		}
	}

	double totalcount = 0;
	for(int i =0; i<10; i++)
	{
		cout<<count_numbers[i]<<endl;
		totalcount += count_numbers[i]; 
	}

	cout<<endl<<endl;
	for(int i =0; i<10; i++)
	{
		double temp = (count_numbers[i] / totalcount);
		classprobability[i] = temp ;
		cout<<classprobability[i];
	}
	cout<<endl;
}

void SetClass::classify_test_numbers(string testfile, string testanswerfile)
{
	fstream testimages, testanswers;
	testimages.open(testfile);
	testanswers.open(testanswerfile);

	vector<string> currentnumber;
	int twentyeight = 0;
	string currline;
	

	double correct = 0;
	double wrong = 0;
	while(getline(testimages, currline))
	{
		twentyeight++;
		currentnumber.push_back(currline);
		if(twentyeight == 28)
		{
			vector<double> mapval;
			for(int i =0; i<10; i++)
			{
				mapval.push_back(0);
			}
			twentyeight = 0;
			for(int l = 0; l<10; l++)
			{
				for(int i =0; i< 28; i++)
				{
					for(int j = 0; j< 28; j++)
					{
						if((currentnumber[i])[j] != ' ')
						{
								mapval[l] += log((pixelprobabilities[l]).num[i][j]);
						}
						else
						{							
							mapval[l] = mapval[l] + log(1 - (pixelprobabilities[l]).num[i][j]);								
						}
					}
				}
			}	

			for(int i = 0; i<10 ; i++)
			{
				mapval[i] += log(classprobability[i]);
			}	

			int numwithmaxprob = findmaxposition(mapval);
			int prob = mapval[numwithmaxprob];
			string t;
			getline(testanswers,t);
			int correctans = t[0] %48;
			cout<<correctans<<"	|	"<<numwithmaxprob<<endl;
			if(correctans == numwithmaxprob)
			{
				correct++;
			}
			else
			{
				wrong++;
			}
			if(highval[correctans] < prob)
			{
				highval[correctans] = prob;
				highestpp[correctans] = currentnumber;
			}
			if(lowval[correctans] > prob)
			{
				lowval[correctans] = prob;
				lowestpp[correctans] = currentnumber;
			}

			currentnumber.clear();
			confusion_matrix[correctans][numwithmaxprob]++;
		}
	}
	double correctpercent = ((correct)/(correct+ wrong)) * 100;
	cout<<"_______________________\n Correct Percentage = "<<correctpercent<<"\n"<<"_______________________________\n";

}

int SetClass::findmaxposition(vector<double> mapval)
{
	double currmax = mapval[0];
	int currmaxpos = 0;
	for(int i =1; i < mapval.size(); i++)
	{
		if(mapval[i] > currmax)
		{
			currmax = mapval[i];
			currmaxpos = i;
		}
	}

	return currmaxpos;
}


void SetClass::convertconfusiontoprobability()
{

	vector<double> classcount;
	for(int i = 0; i<10; i++)
	{
		classcount.push_back(0);
	}
	for(int i = 0; i<10; i++)
	{
		for(int j =0; j< 10; j++)
		{
			classcount[i] += confusion_matrix[j][i];
		}
	}

	for(int i = 0; i<10; i++)
	{
		for(int j =0; j< 10; j++)
		{
			confusion_matrix[j][i] = (confusion_matrix[j][i]/classcount[i])*100;
		}
	}
}


void SetClass::oddratios(int actual, int confused)
{
	double oddratiomatrix[28][28];
	for(int i =0; i<28; i++)
	{
		for(int j = 0; j<28; j++)
		{
			if(pixelprobabilities[actual].num[i][j] > 0.5)
			{
				cout<<"#";
			}
			else
				cout<<" ";
			oddratiomatrix[i][j] = log((pixelprobabilities[actual]).num[i][j])-log((pixelprobabilities[confused]).num[i][j]);
		}
		cout<<endl;
	}


	for(int i =0; i<28; i++)
	{
		for(int j = 0; j<28; j++)
		{
			if(pixelprobabilities[confused].num[i][j] > 0.5)
			{
				cout<<"#";
			}
			else 
				cout<<" ";
		}
		cout<<endl;
	}


	for(int i =0; i<28; i++)
	{
		for(int j =0; j<28; j++)
		{
			if(oddratiomatrix[i][j] > 1.5)
			{
				cout<<"+";
			}
			else if(oddratiomatrix[i][j] < -1.5)
			{
				cout<<"-";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}


	for(int i =0; i<28; i++)
	{
		for(int j =0; j<28; j++)
		{
			if(j!=27)
				cout<<oddratiomatrix[i][j]<<",";
			else
				cout<<oddratiomatrix[i][j];
		}
		cout<<endl;
	}
}

void SetClass::printhighestlowest()
{
	for(int i =0; i<10; i++)
	{
		cout<<"HIGHVAL:\n";
		for(int j = 0;j <28; j++)
		{
			cout<<highestpp[i][j]<<endl;
		}
		cout<<"LOWVAL:\n";
		for(int j = 0;j <28; j++)
		{
			cout<<lowestpp[i][j]<<endl;
		}

		cout<<"___________________________\n";
	}
}


int main()
{

	SetClass object;
	object.populate("trainingimages.txt", "traininglabels.txt");
	object.calculate_training_probability();


	// for(int i =0; i<10; i++)
	// {
	// 	for(int j = 0; j<28; j++)
	// 	{
	// 		for(int k =0; k<28; k++)
	// 		{
	// 			cout<<setprecision(2)<<object.pixelprobabilities[i].num[j][k]<<" ";
	// 		}
	// 		cout<<endl;
	// 	}

	// 	cout<<endl<<endl;
	// }

	// for(int i =0; i<object.count_numbers.size(); i++)
	// {
	// 	cout<<object.count_numbers[i]<<"	";
	// }
	// cout<<endl;



	object.classify_test_numbers("testimages.txt", "testlabels.txt");
	object.convertconfusiontoprobability();

	for(int i = 0; i<10; i++)
	{
		for(int j =0; j< 10; j++)
		{
			if(j!=9)
				cout<<setprecision(3)<<object.confusion_matrix[i][j]<<",";
			else
				cout<<setprecision(3)<<object.confusion_matrix[i][j];
		}
		cout<<endl;
	}


	cout<<endl<<endl<<endl;
	object.oddratios(9,7);
	cout<<endl<<endl<<endl;
	object.oddratios(4,9);

	cout<<endl<<endl<<endl;
	object.oddratios(9,8);

	cout<<endl<<endl<<endl;
	object.oddratios(1,8);
	cout<<endl<<endl<<endl;

	object.printhighestlowest();


	for(int i = 0; i<10; i++)
	{
		cout<<i<<"  ------>  "<<object.confusion_matrix[i][i];
		cout<<endl;
	}
	return -1;
}





