#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <math.h>
#include <iomanip>

using namespace std;

#include "extra_credit.h"

void parseset::create_problem(string filename)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            confusion_matrix_count[i][j]=0;
        }
    }
    fstream f;
    f.open(filename);

    if(f.fail())
    {
        cerr<<"Failed to open file\n";
        exit(0);
    }
    string line;
    int labelval;

    scispacesize=0;
    compsyssize=0;
    recsportbaseballsize=0;
    compwindowssize=0;
    talkpoliticssize=0;
    miscforsalesize=0;
    recsporthockeysize=0;
    compgraphicssize=0;

    int linecount = 1;
    while(getline(f,line))
    {
        // cout<<"Hello 1"<<endl;
        //cout<<linecount<<endl;
        //linecount++;
        labelval = line[0];
        labelval = labelval%48;

         //cout<<"Labeval is "<<labelval<<endl;
        if(labelval==0)
            {
                (scispacesize)++;
            }
        else if(labelval==1)
            {
                (compsyssize)++;
            }
        else if(labelval==2)
            {
                (recsportbaseballsize)++;
            }
        else if(labelval==3)
            {
                (compwindowssize)++;
            }
        else if(labelval==4)
            {
                (talkpoliticssize)++;
            }
        else if(labelval==5)
            {
                (miscforsalesize)++;
            }
        else if(labelval==6)
            {
                (recsporthockeysize)++;
            }
        else
            {
                (compgraphicssize)++;
            }

        string word="";
        // cout<<"Hello 2"<<endl;
        //int startpoint;
        // if(labelval==1)
        //     startpoint=2;
        // else
        //     startpoint=3;
        for(int i=2; i<line.size();i++)
        {
            // cout<<"Hello 3"<<endl;
            if(line[i]==':' || line[i]==' ')
            {

            }
            else if(int(line[i]) >= 48 && int(line[i]) <= 57)
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

                if(labelval==0)
                {
                    if(scispace.find(word)==scispace.end())
                        {
                            scispace.insert(make_pair(word, finalval));
                        }
                    else
                    {
                        scispace.find(word)->second += finalval;
                        // newval = newval +finalval;
                        // spamvalues.insert(make_pair(word, newval));
                    }  
                    if(scispacenextcount.find(word) == scispacenextcount.end())
                    {
                        scispacenextcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        scispacenextcount.find(word)->second++;
                    }
                }
                else if(labelval==1)
                {
                    if(compsys.find(word)==compsys.end())
                        compsys.insert(make_pair(word, finalval));
                    else
                    {
                        compsys.find(word)->second += finalval;
                        // newval = newval +occurencecount;
                        // normalvalues.insert(make_pair(word, newval));
                    }   
                    if(compsysnextcount.find(word) == compsysnextcount.end())
                    {
                        compsysnextcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        compsysnextcount.find(word)->second++;
                    } 
                }
                else if(labelval==2)
                {
                    if(recsportbaseball.find(word)==recsportbaseball.end())
                        {
                            recsportbaseball.insert(make_pair(word, finalval));
                        }
                    else
                    {
                        recsportbaseball.find(word)->second += finalval;
                        // newval = newval +finalval;
                        // spamvalues.insert(make_pair(word, newval));
                    }  
                    if(recsportbaseballnextcount.find(word) == recsportbaseballnextcount.end())
                    {
                        recsportbaseballnextcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        recsportbaseballnextcount.find(word)->second++;
                    }
                }
                else if(labelval==3)
                {
                    if(compwindows.find(word)==compwindows.end())
                        compwindows.insert(make_pair(word, finalval));
                    else
                    {
                        compwindows.find(word)->second += finalval;
                        // newval = newval +occurencecount;
                        // normalvalues.insert(make_pair(word, newval));
                    }   
                    if(compwindowsnextcount.find(word) == compwindowsnextcount.end())
                    {
                        compwindowsnextcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        compwindowsnextcount.find(word)->second++;
                    } 
                }
                else if(labelval==4)
                {
                    if(talkpolitics.find(word)==talkpolitics.end())
                        {
                            talkpolitics.insert(make_pair(word, finalval));
                        }
                    else
                    {
                        talkpolitics.find(word)->second += finalval;
                        // newval = newval +finalval;
                        // spamvalues.insert(make_pair(word, newval));
                    }  
                    if(talkpoliticsnextcount.find(word) == talkpoliticsnextcount.end())
                    {
                        talkpoliticsnextcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        talkpoliticsnextcount.find(word)->second++;
                    }
                }
                else if(labelval==5)
                {
                    if(miscforsale.find(word)==miscforsale.end())
                        miscforsale.insert(make_pair(word, finalval));
                    else
                    {
                        miscforsale.find(word)->second += finalval;
                        // newval = newval +occurencecount;
                        // normalvalues.insert(make_pair(word, newval));
                    }   
                    if(miscforsalenextcount.find(word) == miscforsalenextcount.end())
                    {
                        miscforsalenextcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        miscforsalenextcount.find(word)->second++;
                    } 
                }
                else if(labelval==6)
                {
                    if(recsporthockey.find(word)==recsporthockey.end())
                        {
                            recsporthockey.insert(make_pair(word, finalval));
                        }
                    else
                    {
                        recsporthockey.find(word)->second += finalval;
                        // newval = newval +finalval;
                        // spamvalues.insert(make_pair(word, newval));
                    }  
                    if(recsporthockeynextcount.find(word) == recsporthockeynextcount.end())
                    {
                        recsporthockeynextcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        recsporthockeynextcount.find(word)->second++;
                    }
                }
                else if(labelval==7)
                {
                    if(compgraphics.find(word)==compgraphics.end())
                        compgraphics.insert(make_pair(word, finalval));
                    else
                    {
                        compgraphics.find(word)->second += finalval;
                        // newval = newval +occurencecount;
                        // normalvalues.insert(make_pair(word, newval));
                    }   
                    if(compgraphicsnextcount.find(word) == compgraphicsnextcount.end())
                    {
                        compgraphicsnextcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        compgraphicsnextcount.find(word)->second++;
                    } 
                }
                //cout<<"Hello 6"<<endl;

                word.clear();
            }
            else
            {
                word.push_back(line[i]);
                //cout<<"Word so far is "<<word<<endl;
            }    

        }
    }

}


void parseset::calculatetotals()
{
    for (auto it=scispace.begin(); it!=scispace.end(); ++it)
    {
        totalscispacewords += it->second;
    }
    cout<<totalscispacewords<<endl;

    for (auto it=compsys.begin(); it!=compsys.end(); ++it)
    {
        totalcompsyswords += it->second;
    }
    cout<<totalcompsyswords<<endl;

    for (auto it=recsportbaseball.begin(); it!=recsportbaseball.end(); ++it)
    {
        totalrecsportbaseballwords += it->second;
    }
    cout<<totalrecsportbaseballwords<<endl;

    for (auto it=compwindows.begin(); it!=compwindows.end(); ++it)
    {
        totalcompwindowswords += it->second;
    }
    cout<<totalcompwindowswords<<endl;

    for (auto it=talkpolitics.begin(); it!=talkpolitics.end(); ++it)
    {
        totaltalkpoliticswords += it->second;
    }
    cout<<totaltalkpoliticswords<<endl;

    for (auto it=miscforsale.begin(); it!=miscforsale.end(); ++it)
    {
        totalmiscforsalewords += it->second;
    }
    cout<<totalmiscforsalewords<<endl;

    for (auto it=recsporthockey.begin(); it!=recsporthockey.end(); ++it)
    {
        totalrecsporthockeywords += it->second;
    }
    cout<<totalrecsporthockeywords<<endl;

    for (auto it=compgraphics.begin(); it!=compgraphics.end(); ++it)
    {
        totalcompgraphicswords += it->second;
    }
    cout<<totalcompgraphicswords<<endl;

    totalwords = totalscispacewords + totalcompsyswords + totalrecsportbaseballwords + totalcompwindowswords + totaltalkpoliticswords + totalmiscforsalewords + totalrecsporthockeywords + totalcompgraphicswords; 
}


void parseset::calculateMultiProbability()
{
    int k = 0; //laplace smoothening factor
    int sizeofscispaceprobtop = 0;
    for (auto it=scispace.begin(); it!=scispace.end(); ++it)
    {
        double currprob = ((it->second)+k)/(scispacesize + 2*k);
        scispaceprob.insert(make_pair(it->first, currprob));
        scispaceprobtop.insert(make_pair(currprob, it->first));
        sizeofscispaceprobtop++;
    }
    int sizeofcompsysprobtop =0;
    for (auto it=compsys.begin(); it!=compsys.end(); ++it)
    {
        double currprob = ((it->second) + k)/(compsyssize + 2*k);
        compsysprob.insert(make_pair(it->first, currprob));
        compsysprobtop.insert(make_pair(currprob, it->first));
        sizeofcompsysprobtop++;
    }
    int sizeofrecsportbaseballprobtop = 0;
    for (auto it=recsportbaseball.begin(); it!=recsportbaseball.end(); ++it)
    {
        double currprob = ((it->second)+k)/(recsportbaseballsize + 2*k);
        recsportbaseballprob.insert(make_pair(it->first, currprob));
        recsportbaseballprobtop.insert(make_pair(currprob, it->first));
        sizeofrecsportbaseballprobtop++;
    }
    int sizeofcompwindowsprobtop =0;
    for (auto it=compwindows.begin(); it!=compwindows.end(); ++it)
    {
        double currprob = ((it->second) + k)/(compwindowssize + 2*k);
        compwindowsprob.insert(make_pair(it->first, currprob));
        compwindowsprobtop.insert(make_pair(currprob, it->first));
        sizeofcompwindowsprobtop++;
    }
    int sizeoftalkpoliticsprobtop = 0;
    for (auto it=talkpolitics.begin(); it!=talkpolitics.end(); ++it)
    {
        double currprob = ((it->second)+k)/(talkpoliticssize + 2*k);
        talkpoliticsprob.insert(make_pair(it->first, currprob));
        talkpoliticsprobtop.insert(make_pair(currprob, it->first));
        sizeoftalkpoliticsprobtop++;
    }
    int sizeofmiscforsaleprobtop =0;
    for (auto it=miscforsale.begin(); it!=miscforsale.end(); ++it)
    {
        double currprob = ((it->second) + k)/(miscforsalesize + 2*k);
        miscforsaleprob.insert(make_pair(it->first, currprob));
        miscforsaleprobtop.insert(make_pair(currprob, it->first));
        sizeofmiscforsaleprobtop++;
    }
    int sizeofrecsporthockeyprobtop = 0;
    for (auto it=recsporthockey.begin(); it!=recsporthockey.end(); ++it)
    {
        double currprob = ((it->second)+k)/(recsporthockeysize + 2*k);
        recsporthockeyprob.insert(make_pair(it->first, currprob));
        recsporthockeyprobtop.insert(make_pair(currprob, it->first));
        sizeofrecsporthockeyprobtop++;
    }
    int sizeofcompgraphicsprobtop =0;
    for (auto it=compgraphics.begin(); it!=compgraphics.end(); ++it)
    {
        double currprob = ((it->second) + k)/(compgraphicssize + 2*k);
        compgraphicsprob.insert(make_pair(it->first, currprob));
        compgraphicsprobtop.insert(make_pair(currprob, it->first));
        sizeofcompgraphicsprobtop++;
    }
    cout<<"****************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in Sci.Space dataset are:"<<endl;
    cout<<"****************************************************************************************************"<<endl;
    int ct=0;
    for(auto it = scispaceprobtop.begin(); it!=scispaceprobtop.end(); ++it)
    {
        if(ct>=sizeofscispaceprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"*********************************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in comp.sys.ibm.pc.hardware dataset are:"<<endl;
    cout<<"*********************************************************************************************************************"<<endl;
    ct=0;
    for(auto it = compsysprobtop.begin(); it!=compsysprobtop.end(); ++it)
    {
        if(ct>=sizeofcompsysprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"***************************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in rec.sport.baseball dataset are:"<<endl;
    cout<<"***************************************************************************************************************"<<endl;
    ct=0;
    for(auto it = recsportbaseballprobtop.begin(); it!=recsportbaseballprobtop.end(); ++it)
    {
        if(ct>=sizeofrecsportbaseballprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"**********************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in comp.windows.x dataset are:"<<endl;
    cout<<"**********************************************************************************************************"<<endl;
    ct=0;
    for(auto it = compwindowsprobtop.begin(); it!=compwindowsprobtop.end(); ++it)
    {
        if(ct>=sizeofcompwindowsprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"***************************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in talk.politics.misc dataset are:"<<endl;
    cout<<"***************************************************************************************************************"<<endl;
    ct=0;
    for(auto it = talkpoliticsprobtop.begin(); it!=talkpoliticsprobtop.end(); ++it)
    {
        if(ct>=sizeoftalkpoliticsprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"*********************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in misc.forsale dataset are:"<<endl;
    cout<<"*********************************************************************************************************"<<endl;
    ct=0;
    for(auto it = miscforsaleprobtop.begin(); it!=miscforsaleprobtop.end(); ++it)
    {
        if(ct>=sizeofmiscforsaleprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"*************************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in rec.sport.hockey dataset are:"<<endl;
    cout<<"*************************************************************************************************************"<<endl;
    ct=0;
    for(auto it = recsporthockeyprobtop.begin(); it!=recsporthockeyprobtop.end(); ++it)
    {
        if(ct>=sizeofrecsporthockeyprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"**********************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in comp.graphics dataset are:"<<endl;
    cout<<"**********************************************************************************************************"<<endl;
    ct=0;
    for(auto it = compgraphicsprobtop.begin(); it!=compgraphicsprobtop.end(); ++it)
    {
        if(ct>=sizeofcompgraphicsprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
}


void parseset::calculateBernoProbability()
{
    int k = 0; //laplace smoothening factor
    int sizeofscispacenextcountprobtop=0;
    for (auto it=scispacenextcount.begin(); it!=scispacenextcount.end(); ++it)
    {
        double currprob = ((it->second)+k)/(scispacesize + 2*k);
        scispacenextcountprob.insert(make_pair(it->first, currprob));
        scispacenextcountprobtop.insert(make_pair(currprob, it->first));
        sizeofscispacenextcountprobtop++;
    }
    int sizeofcompsysnextcountprobtop=0;
    for (auto it=compsysnextcount.begin(); it!=compsysnextcount.end(); ++it)
    {
        double currprob = ((it->second) + k)/(compsyssize + 2*k);
        compsysnextcountprob.insert(make_pair(it->first, currprob));
        compsysnextcountprobtop.insert(make_pair(currprob, it->first));
        sizeofcompsysnextcountprobtop++;
    }
    int sizeofrecsportbaseballnextcountprobtop=0;
    for (auto it=recsportbaseballnextcount.begin(); it!=recsportbaseballnextcount.end(); ++it)
    {
        double currprob = ((it->second)+k)/(recsportbaseballsize + 2*k);
        recsportbaseballnextcountprob.insert(make_pair(it->first, currprob));
        recsportbaseballnextcountprobtop.insert(make_pair(currprob, it->first));
        sizeofrecsportbaseballnextcountprobtop++;
    }
    int sizeofcompwindowsnextcountprobtop=0;
    for (auto it=compwindowsnextcount.begin(); it!=compwindowsnextcount.end(); ++it)
    {
        double currprob = ((it->second) + k)/(compwindowssize + 2*k);
        compwindowsnextcountprob.insert(make_pair(it->first, currprob));
        compwindowsnextcountprobtop.insert(make_pair(currprob, it->first));
        sizeofcompwindowsnextcountprobtop++;
    }
    int sizeoftalkpoliticsnextcountprobtop=0;
    for (auto it=talkpoliticsnextcount.begin(); it!=talkpoliticsnextcount.end(); ++it)
    {
        double currprob = ((it->second)+k)/(talkpoliticssize + 2*k);
        talkpoliticsnextcountprob.insert(make_pair(it->first, currprob));
        talkpoliticsnextcountprobtop.insert(make_pair(currprob, it->first));
        sizeoftalkpoliticsnextcountprobtop++;
    }
    int sizeofmiscforsalenextcountprobtop=0;
    for (auto it=miscforsalenextcount.begin(); it!=miscforsalenextcount.end(); ++it)
    {
        double currprob = ((it->second) + k)/(miscforsalesize + 2*k);
        miscforsalenextcountprob.insert(make_pair(it->first, currprob));
        miscforsalenextcountprobtop.insert(make_pair(currprob, it->first));
        sizeofmiscforsalenextcountprobtop++;
    }
    int sizeofrecsporthockeynextcountprobtop=0;
    for (auto it=recsporthockeynextcount.begin(); it!=recsporthockeynextcount.end(); ++it)
    {
        double currprob = ((it->second)+k)/(recsporthockeysize + 2*k);
        recsporthockeynextcountprob.insert(make_pair(it->first, currprob));
        recsporthockeynextcountprobtop.insert(make_pair(currprob, it->first));
        sizeofrecsporthockeynextcountprobtop++;
    }
    int sizeofcompgraphicsnextcountprobtop=0;
    for (auto it=compgraphicsnextcount.begin(); it!=compgraphicsnextcount.end(); ++it)
    {
        double currprob = ((it->second) + k)/(compgraphicssize + 2*k);
        compgraphicsnextcountprob.insert(make_pair(it->first, currprob));
        compgraphicsnextcountprobtop.insert(make_pair(currprob, it->first));
        sizeofcompgraphicsnextcountprobtop++;
    }

    cout<<"****************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in Sci.Space dataset are:"<<endl;
    cout<<"****************************************************************************************************"<<endl;
    int ct=0;
    for(auto it = scispacenextcountprobtop.begin(); it!=scispacenextcountprobtop.end(); ++it)
    {
        if(ct>=sizeofscispacenextcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"*******************************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in comp.sys.ibm.pc.hardware dataset are:"<<endl;
    cout<<"*******************************************************************************************************************"<<endl;
    ct=0;
    for(auto it = compsysnextcountprobtop.begin(); it!=compsysnextcountprobtop.end(); ++it)
    {
        if(ct>=sizeofcompsysnextcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"*************************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in rec.sport.baseball dataset are:"<<endl;
    cout<<"*************************************************************************************************************"<<endl;
    ct=0;
    for(auto it = recsportbaseballnextcountprobtop.begin(); it!=recsportbaseballnextcountprobtop.end(); ++it)
    {
        if(ct>=sizeofrecsportbaseballnextcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"*********************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in comp.windows.x dataset are:"<<endl;
    cout<<"*********************************************************************************************************"<<endl;
    ct=0;
    for(auto it = compwindowsnextcountprobtop.begin(); it!=compwindowsnextcountprobtop.end(); ++it)
    {
        if(ct>=sizeofcompwindowsnextcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"*************************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in talk.politics.misc dataset are:"<<endl;
    cout<<"*************************************************************************************************************"<<endl;
    ct=0;
    for(auto it = talkpoliticsnextcountprobtop.begin(); it!=talkpoliticsnextcountprobtop.end(); ++it)
    {
        if(ct>=sizeoftalkpoliticsnextcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"*******************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in misc.forsale dataset are:"<<endl;
    cout<<"*******************************************************************************************************"<<endl;
    ct=0;
    for(auto it = miscforsalenextcountprobtop.begin(); it!=miscforsalenextcountprobtop.end(); ++it)
    {
        if(ct>=sizeofmiscforsalenextcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"***********************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in rec.sport.hockey dataset are:"<<endl;
    cout<<"***********************************************************************************************************"<<endl;
    ct=0;
    for(auto it = recsporthockeynextcountprobtop.begin(); it!=recsporthockeynextcountprobtop.end(); ++it)
    {
        if(ct>=sizeofrecsporthockeynextcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"********************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in comp.graphics dataset are:"<<endl;
    cout<<"********************************************************************************************************"<<endl;
    ct=0;
    for(auto it = compgraphicsnextcountprobtop.begin(); it!=compgraphicsnextcountprobtop.end(); ++it)
    {
        if(ct>=sizeofcompgraphicsnextcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }

}


void parseset::classifyspam(string filename)
{
    double correct = 0;
    double wrong = 0;

    fstream file;
    file.open(filename);
    string currunit;
    double temparray[8];
    while(getline(file,currunit))
    {
        int labelofconcern;
        parsedunit curr;
        curr.initialize(currunit);
        double scispaceval = 0;
        double compsysval = 0;
        double recsportbaseballval =0;
        double compwindowsval=0;
        double talkpoliticsval=0;
        double miscforsaleval=0;
        double recsporthockeyval=0;
        double compgraphicsval=0;

        /********************MULTI****************/
        for (auto it=curr.wordscount.begin(); it!=curr.wordscount.end(); ++it)
        {
            for(int j = 0; j<int(it->second); j++)
            {
                    if(scispaceprob.find(it->first) != scispaceprob.end())
                    scispaceval += log((scispaceprob.find(it->first))->second);
                    else
                        scispaceval += log(1/totalwords);
                    if(compsysprob.find(it->first) != compsysprob.end())
                    compsysval += log((compsysprob.find(it->first))->second);
                else
                        compsysval += log(1/totalwords);
                    if(recsportbaseballprob.find(it->first) != recsportbaseballprob.end() )
                    recsportbaseballval += log((recsportbaseballprob.find(it->first))->second);
                else
                        recsportbaseballval += log(1/totalwords);
                    if(compwindowsprob.find(it->first) != compwindowsprob.end())
                    compwindowsval += log((compwindowsprob.find(it->first))->second);
                else
                        compwindowsval += log(1/totalwords);
                    if(talkpoliticsprob.find(it->first) != talkpoliticsprob.end() )
                    talkpoliticsval += log((talkpoliticsprob.find(it->first))->second);
                else
                        talkpoliticsval += log(1/totalwords);
                    if(miscforsaleprob.find(it->first) != miscforsaleprob.end())
                    miscforsaleval += log((miscforsaleprob.find(it->first))->second);
                else
                        miscforsaleval += log(1/totalwords);
                    if(recsporthockeyprob.find(it->first) != recsporthockeyprob.end())
                    recsporthockeyval += log((recsporthockeyprob.find(it->first))->second);
                else
                        recsporthockeyval += log(1/totalwords);
                    if(compgraphicsprob.find(it->first) != compgraphicsprob.end())
                    compgraphicsval += log((compgraphicsprob.find(it->first))->second);
                else
                        compgraphicsval += log(1/totalwords);
            }
        }
        // /********************BERNO****************/
        // for (auto it=curr.wordscount.begin(); it!=curr.wordscount.end(); ++it)
        // {
        //     for(int j = 0; j<int(it->second); j++)
        //     {
        //         if(scispacenextcountprob.find(it->first) != scispacenextcountprob.end())
        //             scispaceval += log((scispacenextcountprob.find(it->first))->second);
        //         else
        //                 scispaceval += log(1/totalwords);
        //         if(compsysnextcountprob.find(it->first) != compsysnextcountprob.end())
        //             compsysval += log((compsysnextcountprob.find(it->first))->second);
        //         else
        //                 compsysval += log(1/totalwords);
        //         if(recsportbaseballnextcountprob.find(it->first) != recsportbaseballnextcountprob.end() )
        //             recsportbaseballval += log((recsportbaseballnextcountprob.find(it->first))->second);
        //         else
        //                 recsportbaseballval += log(1/totalwords);
        //         if(compwindowsnextcountprob.find(it->first) != compwindowsnextcountprob.end())
        //             compwindowsval += log((compwindowsnextcountprob.find(it->first))->second);
        //         else
        //                 compwindowsval += log(1/totalwords);
        //         if(talkpoliticsnextcountprob.find(it->first) != talkpoliticsnextcountprob.end() )
        //             talkpoliticsval += log((talkpoliticsnextcountprob.find(it->first))->second);
        //         else
        //                 talkpoliticsval += log(1/totalwords);
        //         if(miscforsalenextcountprob.find(it->first) != miscforsalenextcountprob.end())
        //             miscforsaleval += log((miscforsalenextcountprob.find(it->first))->second);
        //         else
        //                 miscforsaleval += log(1/totalwords);
        //         if(recsporthockeynextcountprob.find(it->first) != recsporthockeynextcountprob.end())
        //             recsporthockeyval += log((recsporthockeynextcountprob.find(it->first))->second);
        //         else
        //                 recsporthockeyval += log(1/totalwords);
        //         if(compgraphicsnextcountprob.find(it->first) != compgraphicsnextcountprob.end())
        //             compgraphicsval += log((compgraphicsnextcountprob.find(it->first))->second);
        //         else
        //                 compgraphicsval += log(1/totalwords);
        //     }
        // }

        scispaceval += log(scispacesize / (scispacesize+compsyssize+recsportbaseballsize + compwindowssize + talkpoliticssize + miscforsalesize + recsporthockeysize + compgraphicssize));
        compsysval += log(compsyssize / (scispacesize+compsyssize+recsportbaseballsize + compwindowssize + talkpoliticssize + miscforsalesize + recsporthockeysize + compgraphicssize));
        recsportbaseballval += log(recsportbaseballsize / (scispacesize+compsyssize+recsportbaseballsize + compwindowssize + talkpoliticssize + miscforsalesize + recsporthockeysize + compgraphicssize));
        compwindowsval += log(compwindowssize / (scispacesize+compsyssize+recsportbaseballsize + compwindowssize + talkpoliticssize + miscforsalesize + recsporthockeysize + compgraphicssize));
        talkpoliticsval += log(talkpoliticssize / (scispacesize+compsyssize+recsportbaseballsize + compwindowssize + talkpoliticssize + miscforsalesize + recsporthockeysize + compgraphicssize));
        miscforsaleval += log(miscforsalesize / (scispacesize+compsyssize+recsportbaseballsize + compwindowssize + talkpoliticssize + miscforsalesize + recsporthockeysize + compgraphicssize));
        recsporthockeyval += log(recsporthockeysize / (scispacesize+compsyssize+recsportbaseballsize + compwindowssize + talkpoliticssize + miscforsalesize + recsporthockeysize + compgraphicssize));
        compgraphicsval += log(compgraphicssize / (scispacesize+compsyssize+recsportbaseballsize + compwindowssize + talkpoliticssize + miscforsalesize + recsporthockeysize + compgraphicssize));


        temparray[0] = scispaceval;
        temparray[1] = compsysval;
        temparray[2] = recsportbaseballval;
        temparray[3] = compwindowsval;
        temparray[4] = talkpoliticsval;
        temparray[5] = miscforsaleval;
        temparray[6] = recsporthockeyval;
        temparray[7] = compgraphicsval;

        sort(temparray, temparray+8);

        if(temparray[7] == scispaceval)
            labelofconcern = 0;
        else if(temparray[7] == compsysval)
            labelofconcern = 1;
        else if(temparray[7] == recsportbaseballval)
            labelofconcern = 2;
        else if(temparray[7] == compwindowsval)
            labelofconcern = 3;
        else if(temparray[7] == talkpoliticsval)
            labelofconcern = 4;
        else if(temparray[7] == miscforsaleval)
            labelofconcern = 5;
        else if(temparray[7] == recsporthockeyval)
            labelofconcern = 6;
        else
            labelofconcern = 7;



        if(labelofconcern == curr.truespamornot)
        {
            correct++;
        }
        else
        {
            wrong++;
        }

        confusion_matrix_count[labelofconcern][curr.truespamornot]++;

        //int pos1, pos2;
        // if(spam == -1 || spam == 0)
        // {
        //     pos1= 1;
        // }
        // else
        //     pos1 = 0;

        // if(curr.truespamornot == -1 || curr.truespamornot == 0)
        // {
        //     pos2 = 1;
        // }
        // else
        //     pos2 = 0;
        // confusion_matrix_count[pos1][pos2]++;
    }

    cout<<"CORRECT Detection of the right Newsgroup = "<<(correct/(correct+wrong))*100<<" %"<<endl;
    cout<<"WRONG Detection of the right Newsgroup = "<<(wrong/(correct+wrong))*100<<" %"<<endl;
}


void parseset::calcConfusion()
{
    // int spamct = confusion_matrix_count[0][0] + confusion_matrix_count[1][0];
    // cout<<spamct<<" <- THIS IS SPAM CT! \n";
    // int normct = confusion_matrix_count[0][1] + confusion_matrix_count[1][1];
    // cout<<normct<<" <- THIS IS NORM CT! \n";
    // confusion_matrix[0][0] = ((confusion_matrix_count[0][0])/(spamct))*100;
    // confusion_matrix[0][1] = ((confusion_matrix_count[0][1])/(normct))*100;
    // confusion_matrix[1][0] = ((confusion_matrix_count[1][0])/(spamct))*100;
    // confusion_matrix[1][1] = ((confusion_matrix_count[1][1])/(normct))*100;
    double countclass [8];

    for(int i = 0; i<8; i++)
    {
        for(int j =0; j<8; j++)
        {
            countclass[i] += confusion_matrix_count[j][i];
        }
    }

    for(int i = 0; i<8; i++)
    {
        for(int j =0; j<8; j++)
        {
            confusion_matrix[j][i] = double(confusion_matrix_count[j][i])/countclass[i];
        }
    }

    for(int i =0; i<8; i++)
    {
        for(int j =0; j<8; j++)
        {
            if(j!= 7)
                cout<<setprecision(3)<<confusion_matrix[i][j]*100<<",";
            else
                cout<<setprecision(3)<<confusion_matrix[i][j]*100;
        }
        cout<<endl;
    }
    
}

int main()
{
     parseset p1;
     //p1.create_problem_movieset("rt-train.txt");
     p1.create_problem("8category.training.txt");
    // for(auto local_it = p1.spamvalues.begin(); local_it!=p1.spamvalues.end(); ++local_it)
    // {
    //     cout<<local_it->first<<" -> "<<local_it->second;
    // }
    // cout<<endl;
    // for(auto local_it = p1.normalvalues.begin();local_it!=p1.normalvalues.end(); ++local_it)
    // {
    //     cout<<local_it->first<<" -> "<<local_it->second;
    // }


    p1.calculatetotals();
    p1.calculateMultiProbability();
    //p1.calculateBernoProbability();
    p1.classifyspam("8category.testing.txt");
    p1.calcConfusion();
    return 0;

}