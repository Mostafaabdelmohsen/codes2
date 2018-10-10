#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int x = 1000;

int main()
{
    cout<<"welcome!!\n\n";
 while(1){
       cout <<"1- search for a name \n2- end the program \n";
       int m;
       cin>>m;
  if(m==1){
    string name;
    ifstream momofile;
    bool Boy = false;
    bool Girl = false;

    cout << "\n Enter name (capitalize first letter): " << endl;
    cin >> name;
    momofile.open("1000 baby's names.txt");

    if (momofile.fail())
    {
        cout << "Failed to open the Text file" << endl;
//        exit(1);
    }
    for (int i = 0; i < x ; i++)
    {
        int rank;
        string BN;
        string GN;
        momofile >> rank;
        momofile >> BN;
        momofile >> GN;

        if (name == BN)
        {
            Boy = true;
            cout << name << " is ranked " << rank << " in popularity among boys." << endl;
        }
        if (name == GN)
        {
            Girl = true;
            cout<< name << " is ranked " << rank << " in popularity among girls.\n" << endl;
        }
    }
    if (!Boy)
        cout << name << " is not ranked among the top 1000 names for boys." << endl;
    if (!Girl)
        cout << name << " is not ranked among the top 1000 names for girls.\n" << endl;
    momofile.close();
    }

  else if (m==2){
        cout<<"program ended....\n" ;
        break;}
    }
    return 0;
}
