#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <math.h>
#include <iomanip>

using namespace std;

#include "parse_set.h"

void parseset::create_problem(string filename)
{
    confusion_matrix_count[0][0] = 0; confusion_matrix_count[0][1] = 0; confusion_matrix_count[1][0] = 0; confusion_matrix_count[1][1] = 0;
    fstream f;
    f.open(filename);

    if(f.fail())
    {
        cerr<<"Failed to open file\n";
        exit(0);
    }
    string line;
    int labelval;
    spamsize=0;
    normalsize=0;

    int linecount = 1;
    while(getline(f,line))
    {
        // cout<<"Hello 1"<<endl;
        //cout<<linecount<<endl;
        //linecount++;
        labelval = line[0];
        labelval = labelval%48;

         //cout<<"Labeval is "<<labelval<<endl;
        if(labelval==1)
            {
                (spamsize)++;
            }
        else
            {
                (normalsize)++;
            }

        string word="";
        // cout<<"Hello 2"<<endl;
        int startpoint;
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

                if(labelval==1)
                {
                    if(spamvalues.find(word)==spamvalues.end())
                        {
                            spamvalues.insert(make_pair(word, finalval));
                        }
                    else
                    {
                        spamvalues.find(word)->second += finalval;
                        // newval = newval +finalval;
                        // spamvalues.insert(make_pair(word, newval));
                    }  
                    if(spamemailcount.find(word) == spamemailcount.end())
                    {
                        spamemailcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        spamemailcount.find(word)->second++;
                    }
                }
                else
                {
                    if(normalvalues.find(word)==normalvalues.end())
                        normalvalues.insert(make_pair(word, finalval));
                    else
                    {
                        normalvalues.find(word)->second += finalval;
                        // newval = newval +occurencecount;
                        // normalvalues.insert(make_pair(word, newval));
                    }   
                    if(normalemailcount.find(word) == normalemailcount.end())
                    {
                        normalemailcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        normalemailcount.find(word)->second++;
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


void parseset::create_problem_movieset(string filename)
{
    confusion_matrix_count[0][0] = 0; confusion_matrix_count[0][1] = 0; confusion_matrix_count[1][0] = 0; confusion_matrix_count[1][1] = 0;
    fstream f;
    f.open(filename);

    if(f.fail())
    {
        cerr<<"Failed to open file\n";
        exit(0);
    }
    string line;
    int labelval;
    spamsize=0;
    normalsize=0;

    int linecount = 1;
    while(getline(f,line))
    {
        // cout<<"Hello 1"<<endl;
        //cout<<linecount<<endl;
        //linecount++;
        labelval = line[0];
        labelval = labelval%48;
        if(labelval!=1)
            labelval=-1;
         //cout<<"Labeval is "<<labelval<<endl;
        if(labelval==1)
            {
                (spamsize)++;
            }
        else
            {
                (normalsize)++;
            }

        string word="";
        // cout<<"Hello 2"<<endl;
        int startpoint;
        if(labelval==1)
            startpoint=2;
        else
            startpoint=3;
        for(int i=startpoint; i<line.size();i++)
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

                if(labelval==1)
                {
                    if(spamvalues.find(word)==spamvalues.end())
                        {
                            spamvalues.insert(make_pair(word, finalval));
                        }
                    else
                    {
                        spamvalues.find(word)->second += finalval;
                        // newval = newval +finalval;
                        // spamvalues.insert(make_pair(word, newval));
                    }  
                    if(spamemailcount.find(word) == spamemailcount.end())
                    {
                        spamemailcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        spamemailcount.find(word)->second++;
                    }
                }
                else
                {
                    if(normalvalues.find(word)==normalvalues.end())
                        normalvalues.insert(make_pair(word, finalval));
                    else
                    {
                        normalvalues.find(word)->second += finalval;
                        // newval = newval +occurencecount;
                        // normalvalues.insert(make_pair(word, newval));
                    }   
                    if(normalemailcount.find(word) == normalemailcount.end())
                    {
                        normalemailcount.insert(make_pair(word,1));
                    }  
                    else
                    {
                        normalemailcount.find(word)->second++;
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
    for (auto it=normalvalues.begin(); it!=normalvalues.end(); ++it)
    {
        totalnormalwords += it->second;
    }
    cout<<totalnormalwords<<endl;

    for (auto it=spamvalues.begin(); it!=spamvalues.end(); ++it)
    {
        totalspamwords += it->second;
    }
    cout<<totalspamwords<<endl;
}


void parseset::calculateMultiProbability()
{
    int k = 0; //laplace smoothening factor
    int sizeofnormalvaluesprotop = 0;
    for (auto it=normalvalues.begin(); it!=normalvalues.end(); ++it)
    {
        double currprob = ((it->second)+k)/(normalsize + 2*k);
        normalvaluesprob.insert(make_pair(it->first, currprob));
        normalvaluesprobtop.insert(make_pair(currprob, it->first));
        sizeofnormalvaluesprotop++;
    }
    int sizeofspamvaluesprobtop =0;
    for (auto it=spamvalues.begin(); it!=spamvalues.end(); ++it)
    {
        double currprob = ((it->second) + k)/(spamsize + 2*k);
        spamvaluesprob.insert(make_pair(it->first, currprob));
        spamvaluesprobtop.insert(make_pair(currprob, it->first));
        sizeofspamvaluesprobtop++;
    }
    cout<<"****************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in Negative Review dataset are:"<<endl;
    cout<<"****************************************************************************************************"<<endl;
    int ct=0;
    for(auto it = normalvaluesprobtop.begin(); it!=normalvaluesprobtop.end(); ++it)
    {
        if(ct>=sizeofnormalvaluesprotop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"****************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Multinomial Naive Bayes) of occuring in Positive Review dataset are:"<<endl;
    cout<<"****************************************************************************************************"<<endl;
    ct=0;
    for(auto it = spamvaluesprobtop.begin(); it!=spamvaluesprobtop.end(); ++it)
    {
        if(ct>=sizeofspamvaluesprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
}


void parseset::calculateBernoProbability()
{
    int k = 0; //laplace smoothening factor
    int sizeofnormalemailcountprobtop=0;
    for (auto it=normalemailcount.begin(); it!=normalemailcount.end(); ++it)
    {
        double currprob = ((it->second)+k)/(normalsize + 2*k);
        normalemailcountprob.insert(make_pair(it->first, currprob));
        normalemailcountprobtop.insert(make_pair(currprob, it->first));
        sizeofnormalemailcountprobtop++;
    }
    int sizeofspamemailcountprobtop=0;
    for (auto it=spamemailcount.begin(); it!=spamemailcount.end(); ++it)
    {
        double currprob = ((it->second) + k)/(spamsize + 2*k);
        spamemailcountprob.insert(make_pair(it->first, currprob));
        spamemailcountprobtop.insert(make_pair(currprob, it->first));
        sizeofspamemailcountprobtop++;
    }
    cout<<"****************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in Negative Review dataset are:"<<endl;
    cout<<"****************************************************************************************************"<<endl;
    int ct=0;
    for(auto it = normalemailcountprobtop.begin(); it!=normalemailcountprobtop.end(); ++it)
    {
        if(ct>=sizeofnormalemailcountprobtop-20)
            cout<<it->second<<endl;
        ct++;
    }
    cout<<"****************************************************************************************************"<<endl;
    cout<<"Words that have the highest probability(Bernoulli Naive Bayes) of occuring in Positive Review dataset are:"<<endl;
    cout<<"****************************************************************************************************"<<endl;
    ct=0;
    for(auto it = spamemailcountprobtop.begin(); it!=spamemailcountprobtop.end(); ++it)
    {
        if(ct>=sizeofspamemailcountprobtop-20)
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

    while(getline(file,currunit))
    {
        int spam;
        parsedunit curr;
        curr.initialize(currunit);
        double spamval = 0;
        double normalval = 0;


        /********************MULTI****************/
        // for (auto it=curr.wordscount.begin(); it!=curr.wordscount.end(); ++it)
        // {
        //     for(int j = 0; j<int(it->second); j++)
        //     {
        //         if(spamvaluesprob.find(it->first) != spamvaluesprob.end() && normalvaluesprob.find(it->first) != normalvaluesprob.end())
        //         {
        //             spamval += log((spamvaluesprob.find(it->first))->second);
        //             normalval += log((normalvaluesprob.find(it->first))->second);
        //         }
        //     }
        // }
        /********************BERNO****************/
        for (auto it=curr.wordscount.begin(); it!=curr.wordscount.end(); ++it)
        {
            for(int j = 0; j<int(it->second); j++)
            {
                if(spamemailcountprob.find(it->first) != spamemailcountprob.end()  && normalemailcountprob.find(it->first) != normalemailcountprob.end())
                {
                    spamval += log((spamemailcountprob.find(it->first))->second);
                    normalval += log((normalemailcountprob.find(it->first))->second);
                }
            }
        }

        spamval += log(spamsize/(spamsize+normalsize));
        normalval += log(normalsize/(spamsize+normalsize));

        if(spamval >= normalval)
        {
            spam = 1;
        }
        else
        {
            spam = -1; //change to 0 if email spam case
        }
        if(spam == curr.truespamornot)
        {
            correct++;
        }
        else
        {
            wrong++;
        }
        int pos1, pos2;
        if(spam == -1 || spam == 0)
        {
            pos1= 1;
        }
        else
            pos1 = 0;

        if(curr.truespamornot == -1 || curr.truespamornot == 0)
        {
            pos2 = 1;
        }
        else
            pos2 = 0;
        confusion_matrix_count[pos1][pos2]++;
    }

    cout<<"CORRECT Detection of Positive/Negative Review = "<<(correct/(correct+wrong))*100<<" %"<<endl;
    cout<<"WRONG Detection of Positive/Negative Review = "<<(wrong/(correct+wrong))*100<<" %"<<endl;

}


void parseset::calcConfusion()
{
    int spamct = confusion_matrix_count[0][0] + confusion_matrix_count[1][0];
    cout<<spamct<<" <- THIS IS SPAM CT! \n";
    int normct = confusion_matrix_count[0][1] + confusion_matrix_count[1][1];
    cout<<normct<<" <- THIS IS NORM CT! \n";
    confusion_matrix[0][0] = ((confusion_matrix_count[0][0])/(spamct))*100;
    confusion_matrix[0][1] = ((confusion_matrix_count[0][1])/(normct))*100;
    confusion_matrix[1][0] = ((confusion_matrix_count[1][0])/(spamct))*100;
    confusion_matrix[1][1] = ((confusion_matrix_count[1][1])/(normct))*100;

    for(int i =0; i<2; i++)
    {
        for(int j =0; j<2; j++)
        {
            cout<<setprecision(3)<<confusion_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
     parseset p1;
     p1.create_problem_movieset("rt-train.txt");
     //p1.create_problem("train_email.txt");
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
    //p1.calculateMultiProbability();
    p1.calculateBernoProbability();
    p1.classifyspam("rt-test.txt");
    p1.calcConfusion();
    return 0;

}
















