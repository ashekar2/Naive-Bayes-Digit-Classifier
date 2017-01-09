
#ifndef EXTRA_CREDIT_H
#define EXTRA_CREDIT_H


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
	        truespamornot = labelval;

	        // cout<<"Labeval is "<<labelval<<endl;
	        string word="";
	        // cout<<"Hello 2"<<endl;
	        
	        for(int i=3; i<line.size();i++)
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
        double scispacesize;
        double compsyssize;
        double recsportbaseballsize;
        double compwindowssize;
        double talkpoliticssize;
        double miscforsalesize;
        double recsporthockeysize;
        double compgraphicssize;

        unordered_map<string, double> scispace;
        unordered_map<string, double> compsys;
        unordered_map<string, double> recsportbaseball;
        unordered_map<string, double> compwindows;
        unordered_map<string, double> talkpolitics;
        unordered_map<string, double> miscforsale;
        unordered_map<string, double> recsporthockey;
        unordered_map<string, double> compgraphics;


        unordered_map<string, double> scispaceprob; // probabilities for multi
        multimap<double, string> scispaceprobtop;

        unordered_map<string, double> compsysprob;	// probabilities
        multimap<double, string> compsysprobtop;

        unordered_map<string, double> recsportbaseballprob;	// probabilities
        multimap<double, string> recsportbaseballprobtop;

        unordered_map<string, double> compwindowsprob;	// probabilities
        multimap<double, string> compwindowsprobtop;

        unordered_map<string, double> talkpoliticsprob;	// probabilities
        multimap<double, string> talkpoliticsprobtop;

        unordered_map<string, double> miscforsaleprob;	// probabilities
        multimap<double, string> miscforsaleprobtop;

        unordered_map<string, double> recsporthockeyprob;	// probabilities
        multimap<double, string> recsporthockeyprobtop;

        unordered_map<string, double> compgraphicsprob;	// probabilities
        multimap<double, string> compgraphicsprobtop;

		void create_problem(string filename);
		double confusion_matrix_count[8][8];
		double confusion_matrix[8][8]; 


        double totalscispacewords;
        double totalcompsyswords;
        double totalrecsportbaseballwords;
        double totalcompwindowswords;
        double totaltalkpoliticswords;
        double totalmiscforsalewords;
        double totalrecsporthockeywords;
        double totalcompgraphicswords;
        double totalwords;

        unordered_map<string, double> scispacenextcount;
        unordered_map<string, double> compsysnextcount;
        unordered_map<string, double> recsportbaseballnextcount;
        unordered_map<string, double> compwindowsnextcount;
        unordered_map<string, double> talkpoliticsnextcount;
        unordered_map<string, double> miscforsalenextcount;
        unordered_map<string, double> recsporthockeynextcount;
        unordered_map<string, double> compgraphicsnextcount;

        unordered_map<string, double> scispacenextcountprob;    // probabilities for berno
        multimap<double,string> scispacenextcountprobtop;

        unordered_map<string, double> compsysnextcountprob;
        multimap<double, string> compsysnextcountprobtop;

        unordered_map<string, double> recsportbaseballnextcountprob;    // probabilities for berno
        multimap<double,string> recsportbaseballnextcountprobtop;

        unordered_map<string, double> compwindowsnextcountprob;
        multimap<double, string> compwindowsnextcountprobtop;

        unordered_map<string, double> talkpoliticsnextcountprob;    // probabilities for berno
        multimap<double,string> talkpoliticsnextcountprobtop;

        unordered_map<string, double> miscforsalenextcountprob;
        multimap<double, string> miscforsalenextcountprobtop;

        unordered_map<string, double> recsporthockeynextcountprob;    // probabilities for berno
        multimap<double,string> recsporthockeynextcountprobtop;

        unordered_map<string, double> compgraphicsnextcountprob;
        multimap<double, string> compgraphicsnextcountprobtop;

        void calculatetotals();
        void calculateMultiProbability();
        void calculateBernoProbability();
        void classifyspam(string filename);
        void calcConfusion();

};

#endif