#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>

#include <vector>
#include <stack>

using namespace std;

class par_t {
private:
  int b_;
  int level_;
public:
    par_t(int b, int level):
    b_(b), level_(level) {}
    
    ~par_t(void) {}
    
    int get_b(void) const {return b_;}
    int get_level(void) const {return level_;}
};

class number_t
{
private:
    vector<int>  number_;
	const int    base_;
	const char*  map_ = "0123456789ABCDEF";

public:
	number_t(const int n_digit, const int base):
	number_(n_digit),
	base_(base)
	{
        reset();
	}

	virtual ~number_t(void) {}

	virtual void write(ostream& os) const {

		for(int i = n_digits() - 1; i >= 0; i --)
			os << map_[number_[i]];	
	}
	

    int decimal(void) const
    {
        int aux = 0;
        
        for(int i = n_digits() - 1; i >= 0; i--)
            aux += number_[i] * pow(base_, i);
            
        return aux;
    }
    
    void decimal(int num)
    {
        int aux = num;
        
        if (aux / pow(base_, n_digits() - 1) > base_) {
            cerr << "OVERFLOW ERROR!" << endl;
            exit(1);
        }
        
        for(int i = n_digits() - 1; i >= 0; i--) {
            number_[i] = aux / pow(base_, i);
            aux = aux % (int)(pow(base_, i));
        }
    }    
    

	int n_digits(void) const 
	{
		return number_.size();
	} 

	int base(void) const
	{
		return base_;
	}
	
	void generate_all(void)
	{
	    generate(n_digits() - 1);
	}
	
	void generate_all2(void)
	{
	    stack<par_t> Pila;
	    
	    for(int b = 0; b < base_; b++) 
	        Pila.push(par_t(b, n_digits() - 1));
	    
	    while(!Pila.empty())
	    {
	        const par_t par = Pila.top();
	        Pila.pop();
	        
	        const int b = par.get_b();
	        const int l = par.get_level();
	        
	        number_[l] = b;
	        
	        if (l <= 0) {
	            write(cout);
	            cout << endl;	            
	        } else {
	            for(int b = 0; b < base_; b++) 
	                Pila.push(par_t(b, l - 1));	            
	        }
	    }
	}
	
	void generate(int i)
	{
	    if (i < 0) {
	        
	        write(cout);
	        cout << endl;
	    }
	    else {
	        
	        for(int b = 0; b < base_; b ++){
	            number_[i] = b;
	            generate(i - 1);
	        }
	    }
	}
	
	void corrige_exceso(int i)
	{
	    if (i < n_digits())
	    {
	        if (number_[i] >= base_) {
	            
	            if(i + 1 < n_digits()) {
	                
	                number_[i] = 0;
	                number_[i + 1]++;
	                
	                corrige_exceso(i + 1);
	            }
	            else{ 
	                cerr << "OVERFLOW ERROR!!!" << endl;
	                exit(1);
	            }
	        }
	    }
	}
	
	void corrige_defecto(int i)
	{
	    if (i < n_digits())
	    {
	        if (number_[i] < 0) {
	            
	            if(i + 1 < n_digits()) {
	                
	                number_[i] = base_ - 1;
	                number_[i + 1]--;
	                
	                corrige_defecto(i + 1);
	            }
	            else{ 
	                cerr << "OVERFLOW ERROR!!!" << endl;
	                exit(1);
	            }
	        }
	    }
	}	
	
/*	void corrige_exceso(int i)
	{
	    if (i < n_digits())
	    {
	        if (number_[i] >= base_) {
	            
	            if(i + 1 < n_digits()) {
	                
	                number_[i] = 0;
	                number_[i + 1]--;
	                
	                corrige_exceso2(i + 1);
	            }
	            else 
	                reset(); 
	        }
	    }
	}
	
	void corrige_defecto(int i)
	{
	    if (i < n_digits())
	    {
	        if (number_[i] < 0) {
	            
	            if(i + 1 < n_digits()) {
	                
	                number_[i] = base_ - 1;
	                number_[i + 1]--;
	                
	                corrige_defecto(i + 1);
	            }
	            else{ 
	                set_max_val();
	            }
	        }
	    }
	}	
	
*/	

	number_t& operator++(void)
	{
        number_[0]++;
        corrige_exceso(0);
		
		return *this;
	}
	
	number_t& operator--(void)
	{
        number_[0]--;
        corrige_defecto(0);
		
		return *this;
	}	
	
    void reset(void) {

		for(int i = n_digits() - 1; i >= 0; i --)
			number_[i] = 0;        
    }
    
    void set_max_val(void)
    {
		for(int i = n_digits() - 1; i >= 0; i --)
			number_[i] = base_ - 1;        
    }
};

ostream& operator<<(ostream& os, const number_t& num)
{
    num.write(os);
    return os;
}

int main(void)
{
    number_t bin(4, 2);
    
    cout << bin << setw(6) << bin.decimal() << endl;
    
    for(int i = 0xE; i >= 0; i--){
        ++bin;
        cout << bin << setw(6) << bin.decimal() << endl;
    }

    cout << endl;

    bin.set_max_val();
    
    cout << bin << setw(6) << bin.decimal() << endl;
 
     for(int i = 0xE; i >= 0; i--){
        --bin;
        cout << bin << setw(6) << bin.decimal() << endl;
    }   
    
    cout << endl;
    
    number_t hex(4, 16);
    
    cout << hex << setw(6) << hex.decimal() << endl;
    
    for(int i = 0xE; i >= 0; i--){
        ++hex;
        cout << hex << setw(6) << hex.decimal() << endl;
    }

    cout << endl;

    hex.set_max_val();
    
    cout << hex << setw(6) << hex.decimal() << endl;
 
     for(int i = 0xE; i >= 0; i--){
        --hex;
        cout << hex << setw(6) << hex.decimal() << endl;
    }    
    
    cout << endl;
    
    bin.decimal(8);
    cout << bin << setw(6) << bin.decimal() << endl;
    
    cout << endl;
    
    bin.generate_all();
    
    cout << endl;
    
    bin.generate_all2();    
    
	return 0;
}