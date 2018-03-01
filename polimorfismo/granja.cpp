#include <iostream>

#include <cstring>

// More details on the code at:

// https://www.youtube.com/watch?v=LIWbUjHZFTw

#define N_HABITANTS 5

using namespace std;

namespace AED {

	class Old_McDonals_farm_habitant_t

	{

	private:

		char name_[80];

	public:

		Old_McDonals_farm_habitant_t(const char* name):

		name_()

		{

			strcpy(name_, name);

		}

		virtual ~Old_McDonals_farm_habitant_t(void)

		{}

		ostream& say_hello(ostream& os) const

		{

			os << "Hello!! ";

			os << "I'm a ";

			what_I_am(os);

			os << ", my name is ";

			os << name_;

			os << ", and I say ";

			talk(os); 

			os << endl;

			return os;

		}

		virtual ostream& what_I_am(ostream& os) const = 0;

		virtual ostream& talk(ostream& os) const = 0;

	}; 

	class ground_animal_t: public Old_McDonals_farm_habitant_t

	{

	protected:

		int n_paw_;

	public:

		ground_animal_t(const char* name, int n_paw):

		Old_McDonals_farm_habitant_t(name),

		n_paw_(n_paw) {}

		virtual ~ground_animal_t(void){}	

	};

	class water_animal_t: public Old_McDonals_farm_habitant_t

	{

	public:

		water_animal_t(const char* name):

		Old_McDonals_farm_habitant_t(name) {}

		virtual ~water_animal_t(void){}

		virtual ostream& talk(ostream& os) const

		{

			os << "glub, glub, ...";

			return os;

		}			

	};

	class cow_t: public ground_animal_t

	{

	public:

		cow_t(const char* name):

		ground_animal_t(name, 4){}

		virtual ~cow_t(void) {}

		virtual ostream& talk(ostream& os) const 

		{

			os << "muuuuuu, muuuuuuu, ...";

			return os;

		}

		virtual ostream& what_I_am(ostream& os) const

		{

			os << "black and white cow with "<< n_paw_ << " paws" ;

			return os;

		}		

	};

	class chicken_t: public ground_animal_t

	{

	public:

		chicken_t(const char* name):

		ground_animal_t(name, 2){}

		virtual ~chicken_t(void) {}

		virtual ostream& talk(ostream& os) const

		{

			os << "pio, pio, ...";

			return os;

		}

		virtual ostream& what_I_am(ostream& os) const 

		{

			os << "yellow chicken with "<< n_paw_ << " paws" ;

			return os;

		}		

	};

	class whale_t: public water_animal_t

	{

	public:

		whale_t(const char* name):

		water_animal_t(name){}

		virtual ~whale_t(void) {}

		virtual ostream& what_I_am(ostream& os) const 

		{

			os << "huge whale" ;

			return os;

		}		

	};

	class shark_t: public water_animal_t

	{

	public:

		shark_t(const char* name):

		water_animal_t(name){}

		virtual ~shark_t(void) {}

		virtual ostream& what_I_am(ostream& os) const

		{

			os << "hungry shark" ;

			return os;

		}

		virtual ostream& talk(ostream& os) const

		{

			os << "ñam, ñam, ...";

			return os;

		}		

	};

}

int main(void)

{

	AED::Old_McDonals_farm_habitant_t* Old_McDonals_farm[N_HABITANTS];

	Old_McDonals_farm[0] = new AED::cow_t("Clotilda");

	Old_McDonals_farm[1] = new AED::chicken_t("Chispa");

	Old_McDonals_farm[2] = new AED::whale_t("Moby Dick");

	Old_McDonals_farm[3] = new AED::shark_t("Dentudo");

	Old_McDonals_farm[4] = new AED::cow_t("Blanquita");

	for(int i = 0; i < N_HABITANTS; i++)

		Old_McDonals_farm[i]->say_hello(cout);

	for(int i = 0; i < N_HABITANTS; i++)

		if (Old_McDonals_farm[i] != NULL) {

			delete Old_McDonals_farm[i];

			Old_McDonals_farm[i]= NULL;

		}

	return 0;

}
