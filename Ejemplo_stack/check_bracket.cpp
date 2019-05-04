#include <iostream>
#include <stack>

using namespace std;

#define NTOKENS 4                 // Número de tokens
const string tokens = "({[<)}]>"; // Lista de posibles tokens
                                  // Por qué están en este orden?

bool check_bracket(const string& s)
{
    const int sz = s.size();
    bool check = true;
    int i = 0;
    stack<int> pila;
    
    // Mientras no termine de recorrer la cadena
    // y mientras esté equilibrada ...
    
    while ((i < sz) && (check == true)) 
    {
        const char c   = s[i];
        const int  pos = tokens.find(c);
        
        if (pos < NTOKENS)             // Qué significa esto?
            pila.push(pos + NTOKENS);  // Y esto?
        else {
            if (pos == pila.top())     // Qué significa esta condición?
                pila.pop();
            else
                check = false;
        }
        
        i++;
    }
    
    if (pila.empty() == false)  // Qué sudece si la pila no está
        check = false;          // vacía en este punto?
        
    return check;
}

int main(void)
{
    {
        const string entrada = "(({()}<()>))";
        const bool check = check_bracket(entrada);
        
        cout << "Cadena: " << entrada << " está ";
        if (check == true)
            cout << "equilibrada" << endl;
        else    
            cout << "desequilibrada" << endl;
    }
    
    {
        const string entrada = "(({)(}<()>))";
        const bool check = check_bracket(entrada); 
        
        cout << "Cadena: " << entrada << " está ";
        if (check == true)
            cout << "equilibrada" << endl;
        else    
            cout << "desequilibrada" << endl;    
    }
    
    return 0;
}