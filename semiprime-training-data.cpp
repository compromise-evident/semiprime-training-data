/// semiprime-training-data - generates any training-data &                     Run it: "apt install g++ geany libgmp-dev". Append "-lgmp" to Geany's compile & build
///                           testing-data which is semiprimes                  commands. Open this in Geany. Hit F9 once. F5 to run. Or compile: g++ /this.cpp -lgmp
///                           followed by more and more digits
///                           of the smaller factor (all preceded by
///                           one label digit, as text, padded, unpadded.)


// Version 3.0.0
#include <fstream>
#include <gmp.h>
#include <iostream>
using namespace std;
int main()
{	/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  /////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    ////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\      ///////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\        //////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\            ////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\              ///////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\       your       /////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\       controls       ///////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\                              ///////////////////////
	\\\\\\\\\\\\\\\\\\                                        ////////////////*/
	
	int                        p_length =    20; //50k  max
	int                        q_length =    20; //50k  max
	int                       pq_length =    40; //100k max
	int               padding_character =    48; //0 to 255
	int          semiprimes_for_testing =  1000; //2B   max
	int         semiprimes_for_training = 50000; //2B   max
	
	/*////////////////                                        \\\\\\\\\\\\\\\\\\
	///////////////////////                              \\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////                      \\\\\\\\\\\\\\\\\\\\\\\\\\\
	/////////////////////////////                  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////////              \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	////////////////////////////////            \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//////////////////////////////////        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////////////      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	////////////////////////////////////    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	/////////////////////////////////////  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	
	ofstream out_stream;
	
	srand(time(0));
	char  p[ 50001] = {'\0'};
	char  q[ 50001] = {'\0'};
	char pq[200001] = {'\0'};
	mpz_t randomness; mpz_init(randomness);
	mpz_t prime_p   ; mpz_init(prime_p   );
	mpz_t prime_q   ; mpz_init(prime_q   );
	mpz_t product   ; mpz_init(product   );
	system("mkdir padded");
	out_stream.open(               "test.txt"); out_stream.close();
	out_stream.open(              "train.txt"); out_stream.close();
	out_stream.open( "padded/test-padded.txt"); out_stream.close();
	out_stream.open("padded/train-padded.txt"); out_stream.close();
	
	//Testing-data.
	cout << "\nGenerating testing-data...\n";
	for(int loops = 0; loops < semiprimes_for_testing;)
	{	for(int a = 0; a < p_length; a++) {p[a] = ((rand() % 10) + 48);}     if(p[0] == '0') {p[0] = '9';} //Random p.
		for(int a = 0; a < q_length; a++) {q[a] = ((rand() % 10) + 48);}     if(q[0] == '0') {q[0] = '9';} //Random q.
		mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str( p, 10, prime_p);  //p made prime.
		mpz_set_str(randomness, q, 10); mpz_nextprime(prime_q, randomness); mpz_get_str( q, 10, prime_q);  //q made prime.
		mpz_mul(product, prime_p, prime_q);                                 mpz_get_str(pq, 10, product);  //pq made.
		int length = 0; for(int a = 0; pq[a] != '\0'; a++) {length++;} if(length != pq_length) {continue;} //Restarts if pq not pq_length.
		
		//Appends smaller prime to pq[].
		int prime_comparison = mpz_cmp(prime_p, prime_q);
		int pq_write_bookmark = pq_length;
		if(prime_comparison < 0) {for(int a = 0; a < p_length; a++) {pq[pq_write_bookmark] = p[a]; pq_write_bookmark++;}}
		else                     {for(int a = 0; a < q_length; a++) {pq[pq_write_bookmark] = q[a]; pq_write_bookmark++;}}
		
		//Saves padded to file.
		out_stream.open("padded/test-padded.txt", ios::app);
		for(int pq_read_bookmark = pq_length; pq[pq_read_bookmark] != '\0'; pq_read_bookmark++)
		{	out_stream << pq[pq_read_bookmark] << " "; //Label first.
			for(int a = pq_read_bookmark + 1; pq[a] != '\0'; a++) {out_stream.put(padding_character);} //Padding.
			for(int a = 0; a < pq_read_bookmark; a++) {out_stream << pq[a];} //The rest.
			out_stream << "\n";
		}
		out_stream.close();
		
		//Saves unpadded to file.
		out_stream.open("test.txt", ios::app);
		for(int pq_read_bookmark = pq_length; pq[pq_read_bookmark] != '\0'; pq_read_bookmark++)
		{	out_stream << pq[pq_read_bookmark] << " "; //Label first.
			for(int a = 0; a < pq_read_bookmark; a++) {out_stream << pq[a];} //The rest.
			out_stream << "\n";
		}
		out_stream.close();
		
		loops++; cout << loops << " of " << semiprimes_for_testing << "\n";
	}
	
	//Training-data (ditto but unique items.)
	cout << "\nGenerating training-data...\n";
	for(int loops = 0; loops < semiprimes_for_training;)
	{	for(int a = 0; a < p_length; a++) {p[a] = ((rand() % 10) + 48);}     if(p[0] == '0') {p[0] = '9';} //Random p.
		for(int a = 0; a < q_length; a++) {q[a] = ((rand() % 10) + 48);}     if(q[0] == '0') {q[0] = '9';} //Random q.
		mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str( p, 10, prime_p);  //p made prime.
		mpz_set_str(randomness, q, 10); mpz_nextprime(prime_q, randomness); mpz_get_str( q, 10, prime_q);  //q made prime.
		mpz_mul(product, prime_p, prime_q);                                 mpz_get_str(pq, 10, product);  //pq made.
		int length = 0; for(int a = 0; pq[a] != '\0'; a++) {length++;} if(length != pq_length) {continue;} //Restarts if pq not pq_length.
		
		//Appends smaller prime to pq[].
		int prime_comparison = mpz_cmp(prime_p, prime_q);
		int pq_write_bookmark = pq_length;
		if(prime_comparison < 0) {for(int a = 0; a < p_length; a++) {pq[pq_write_bookmark] = p[a]; pq_write_bookmark++;}}
		else                     {for(int a = 0; a < q_length; a++) {pq[pq_write_bookmark] = q[a]; pq_write_bookmark++;}}
		
		//Saves padded to file.
		out_stream.open("padded/train-padded.txt", ios::app);
		for(int pq_read_bookmark = pq_length; pq[pq_read_bookmark] != '\0'; pq_read_bookmark++)
		{	out_stream << pq[pq_read_bookmark] << " "; //Label first.
			for(int a = pq_read_bookmark + 1; pq[a] != '\0'; a++) {out_stream.put(padding_character);} //Padding.
			for(int a = 0; a < pq_read_bookmark; a++) {out_stream << pq[a];} //The rest.
			out_stream << "\n";
		}
		out_stream.close();
		
		//Saves unpadded to file.
		out_stream.open("train.txt", ios::app);
		for(int pq_read_bookmark = pq_length; pq[pq_read_bookmark] != '\0'; pq_read_bookmark++)
		{	out_stream << pq[pq_read_bookmark] << " "; //Label first.
			for(int a = 0; a < pq_read_bookmark; a++) {out_stream << pq[a];} //The rest.
			out_stream << "\n";
		}
		out_stream.close();
		
		loops++; cout << loops << " of " << semiprimes_for_training << "\n";
	}
}
