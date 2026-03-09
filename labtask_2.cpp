#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

bool isKeyword(string w)
{
    string key[] = {"int","float","char","if","else","for","while","return","void","main"};

    for(int i=0;i<10;i++)
        if(w == key[i])
            return true;

    return false;
}

int main()
{
    ifstream file("demo.txt");
    if(!file)
    {
        cout<<"File not found!";
        return 0;
    }

    string line, word;

    while(getline(file,line))
    {

        if(line.find("//") != string::npos)
        {
            cout<<line<<" --- Comment"<<endl;
            continue;
        }

        word="";

        for(int i=0;i<line.length();i++)
        {
            char ch = line[i];

            if(isalnum(ch) || ch=='_')
            {
                word += ch;
            }
            else
            {
                if(word!="")
                {
                    if(isKeyword(word))
                        cout<<word<<" --- Keyword"<<endl;

                    else if(isdigit(word[0]))
                        cout<<word<<" --- Constant"<<endl;

                    else
                        cout<<word<<" --- Identifier"<<endl;

                    word="";
                }

                if(ch=='+'||ch=='-'||ch=='*'||ch=='/'|| ch=='='||ch=='<'||ch=='>')
                    cout<<ch<<" --- Operator"<<endl;

                else if(ch=='('||ch==')'||ch=='{'||ch=='}'|| ch==';'||ch==','||ch=='['||ch==']')
                    cout<<ch<<" --- Punctuator"<<endl;
            }
        }

        if(word!="")
        {
            if(isKeyword(word))
                cout<<word<<" --- Keyword"<<endl;
            else if(isdigit(word[0]))
                cout<<word<<" --- Constant"<<endl;
            else
                cout<<word<<" --- Identifier"<<endl;
        }
    }

    file.close();
    return 0;
}
