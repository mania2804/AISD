#include <fstream>
#include <iostream>

using namespace std;


bool czy_zawiera(string gdzie, string co)
{
    int counter=0;
    for(int i=0; i<gdzie.length(); i++)
    {
       
        if(gdzie[i]==co[counter])
            counter++;
        else
            counter=0;
            
        if (counter == co.length())
            return true;
        
    }
  return false;  
}

string tab[]={"ski","wski","cki"}

int policz_wyrazy (Pacjent * pacjenci, int n) //n-liczba pacjentów
{
    int ile=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            if( czy_zawiera(pacjenci[i].nazwisko, tab[j]))
        
             ile++;
        break;
       }
        
     return ile;   
        
        
}


int main(){
    
    
    return 0;
}
