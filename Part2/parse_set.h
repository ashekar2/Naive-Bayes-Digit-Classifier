
#ifndef PARSE_SET_H
#define PARSE_SET_H


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;


class parsedunit
{
public:
	unordered_map<string, double> wordscount;
	int truespamornot;

	void initialize(string line)
	{
	    	int labelval;

	        // cout<<"Hello 1"<<endl;
	        labelval = line[0];
	        labelval = labelval%48;
	        if(labelval!=1)
            	labelval=-1;
	        truespamornot = labelval;

	        // cout<<"Labeval is "<<labelval<<endl;
	        string word="";
	        // cout<<"Hello 2"<<endl;
	        int startpoint;
        	if(labelval==1 || labelval==0)
            	startpoint=2;
        	else
            	startpoint=3;
	        for(int i=startpoint; i<line.size();i++)
	        {
	            // cout<<"Hello 3"<<endl;
	            if(line[i]==':' || line[i]==' ')
	            {

	            }
	            else if(isdigit(line[i]))
	            {
	                int j=i;
	                string number= "";

	                while(j<line.size() && line[j]!=' ')
	                {
	                    number.push_back(line[j]);
	                    j++;
	                }
	                i=j;
	                int multiplier = 1;
	                int finalval = 0;
	                //cout<<"Hello 4"<<endl;
	                for(int k=number.size()-1;k>=0;k--)
	                {
	                    int mynum = number[k];
	                    mynum = mynum%48;
	                    finalval = finalval + (multiplier*mynum);
	                    multiplier*=10;
	                }
	                //cout<<"finalval is "<<finalval<<endl;
	                //cout<<"Hello 5"<<endl;
	                //cout<<"Hello 6"<<endl;
	                wordscount.insert(make_pair(word, finalval));
	                word.clear();
	            }
	            else
	            {
	                word.push_back(line[i]);
	            }    

	        }
	}
};


class parseset{
    public:
        double spamsize;
        double normalsize;

        unordered_map<string, double> normalvalues;
        unordered_map<string, double> spamvalues;
        unordered_map<string, double> normalvaluesprob; // probabilities for multi
        multimap<double, string> normalvaluesprobtop;
        unordered_map<string, double> spamvaluesprob;	// probabilities
        multimap<double, string> spamvaluesprobtop;
		void create_problem(string filename);
		void create_problem_movieset(string filename);
		double confusion_matrix_count[2][2];
		double confusion_matrix[2][2]; 


        double totalspamwords;
        double totalnormalwords;
        double totalsize;


        unordered_map<string, double> spamemailcount;
        unordered_map<string, double> normalemailcount;
        unordered_map<string, double> spamemailcountprob;    // probabilities for berno
        multimap<double,string> spamemailcountprobtop;
        unordered_map<string, double> normalemailcountprob;
        multimap<double, string> normalemailcountprobtop;
        void calculatetotals();
        void calculateMultiProbability();
        void calculateBernoProbability();
        void classifyspam(string filename);
        void calcConfusion();

};

#endif