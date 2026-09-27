#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>

class  Pile {

  private :
      T *items ;
      int sommet  ;
      int size  ;



  public:
      Pile( int s = 5 ){
          size = s ;
          items = new T[size];
          sommet = -1 ;

      };

      ~Pile() {
        delete[] items;
              }
        void afficher(){
        cout <<"la taille de pile est : "<< sommet+1 << endl   ;
            for(int i = 0 ; i <= sommet ; i++ ){
             cout<< items[i] << endl ; 
                
            } 
        }

      T popPile(){
      T supp ;
      if( sommet == -1   ){
        cout << "la Pile est Vide ! " << endl ;
          return (T) 0 ; 
      }
         supp = items [sommet] ;
         sommet-- ;
         return supp ;
        }

       bool estVide(){
           return (sommet == -1) ? true : false  ; 
       }



        void pushPile(T n ){
          if(sommet + 1 == size  ){
          size = size *  2 ;

            items = (T*) realloc(items, size * sizeof(T));
          }
          items[++sommet]= n ;


        }

    


 };
bool correspond(char ouvrant, char fermant) {
    if (ouvrant == '(' && fermant == ')') return true;
    if (ouvrant == '{' && fermant == '}') return true;
    if (ouvrant == '[' && fermant == ']') return true;
    return false;
}



  bool Tester_Exp( const string& exp ) {
      Pile <char> P(10); 

    
    
 for (char c : exp) {
    

       if (c == '(' || c == '{' || c == '[' )
          {

                    P.pushPile(c);  
          }

    if (c == ')' || c == '}' || c == ']' )
         {
                if (P.estVide()) {
                     return false ;  
                                 }
             char dernierOuvrant = P.popPile();
            if (!correspond(dernierOuvrant, c)) {
              return false ;
            }
       }
        


        
    }

      
       return P.estVide();
 
}










int main()
{
       
     
   string expression;
    bool res ;
    cout << "Entrez une expression mathematique : ";
    getline(cin, expression);
    res = Tester_Exp(expression);
    
    if(res){
        cout<<"Expresion valider "; 
    }else {
         cout<<"Expresion invalider "; 
    }

 

     

    
    
    return 0;
}