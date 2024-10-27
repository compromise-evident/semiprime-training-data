// semiprime-training-data 5.1.2 - generates any semiprimes labeled as          Run it: "apt install g++ geany libgmp-dev". Open the .cpp in Geany.
//                                 the first digit of their smaller             Append "-lgmp" to Geany's compile & build commands. Hit F9 once. F5 to run.
//                                 factor. Get also primes & composites,
//                                 and semiprimes with expanding factors.
//                                 Creates raw, and tokenized for ML.py.

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
	
	//                               Semiprimes+factors
	int                           p_length =    10; //50k  max
	int                           q_length =    10; //50k  max
	int                          pq_length =    20; //100k max
	int             semiprimes_for_testing = 10000; //2B   max
	int            semiprimes_for_training = 90000; //2B   max
	
	//                               Primes+composites
	int         prime_and_composite_length =    20; //50k  max
	int  primes_and_composites_for_testing = 10000; //2B   max
	int primes_and_composites_for_training = 90000; //2B   max
	
	//                                    Tokenize
	char               tokenized_digit_0[] = {"@-----------"};
	char               tokenized_digit_1[] = {"@-@---------"};
	char               tokenized_digit_2[] = {"@-@@--------"};
	char               tokenized_digit_3[] = {"@-@@@-------"};
	char               tokenized_digit_4[] = {"@-@@@@------"};
	char               tokenized_digit_5[] = {"@-@@@@@-----"};
	char               tokenized_digit_6[] = {"@-@@@@@@----"};
	char               tokenized_digit_7[] = {"@-@@@@@@@---"};
	char               tokenized_digit_8[] = {"@-@@@@@@@@--"};
	char               tokenized_digit_9[] = {"@-@@@@@@@@@-"};
	bool   mask_end_of_final_string_with_one_at_symbol = true;
	
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
	
	ifstream in_stream;
	ofstream out_stream;
	
	cout << "\n(1) Generate new semiprimes labeled as the first digit of their smaller factor."
	     << "\n(2) Generate new primes and composites labeled as 1 = prime, 0 = composite."
	     << "\n(3) Generate new semiprimes followed by more and more digits of their"
	     << "\n    smaller factor, labeled as the next digit of that same factor."
	
	     << "\n\nOption: ";
	
	int user_option; cin >> user_option; if((user_option != 1) && (user_option != 2) && (user_option != 3)) {cout << "\nInvalid.\n"; return 0;}
	system("mkdir training-data     -p");
	system("mkdir training-data/raw -p");
	
	
	
	
	
	//_____________________________________________________Semiprimes_________________________________________________//
	if(user_option == 1)
	{	srand(time(0));
		char  p[ 50001] = {'\0'};
		char  q[ 50001] = {'\0'};
		char pq[200001] = {'\0'};
		mpz_t randomness; mpz_init(randomness);
		mpz_t prime_p   ; mpz_init(prime_p   );
		mpz_t prime_q   ; mpz_init(prime_q   );
		mpz_t product   ; mpz_init(product   );
		int one_to_nine =  ((rand() % 9) + 49);
		
		//Testing-data.
		cout << "\nGenerating testing-data...\n";
		out_stream.open("training-data/raw/test.txt");
		for(int loops = 0; loops < semiprimes_for_testing;)
		{	for(int a = 0; a < p_length; a++) {p[a] = ((rand() % 10) + 48);}     if(p[0] == '0') {p[0] = '1';} //Random p.
			for(int a = 0; a < q_length; a++) {q[a] = ((rand() % 10) + 48);}     if(q[0] == '0') {q[0] = '9';} //Random q.
			mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str( p, 10, prime_p);  //p made prime.
			mpz_set_str(randomness, q, 10); mpz_nextprime(prime_q, randomness); mpz_get_str( q, 10, prime_q);  //q made prime.
			mpz_mul(product, prime_p, prime_q);                                 mpz_get_str(pq, 10, product);  //pq made.
			int length = 0; for(int a = 0; pq[a] != '\0'; a++) {length++;} if(length != pq_length) {continue;} //Restarts if pq not pq_length.
			
			//Restarts if label not distributed 1-9.
			char label;
			int prime_comparison = mpz_cmp(prime_p, prime_q);
			if(prime_comparison < 0) {label = p[0];}
			else                     {label = q[0];}
			if(label != one_to_nine) {continue;}
			one_to_nine = ((rand() % 9) + 49);
			
			//Saves to file.
			out_stream << label << " " << pq << "\n"; //Label then semiprime.
			
			loops++; cout << loops << " of " << semiprimes_for_testing << "\n";
		}
		out_stream.close();
		
		//Training-data (ditto but unique items.)
		cout << "\nGenerating training-data...\n";
		out_stream.open("training-data/raw/train.txt");
		for(int loops = 0; loops < semiprimes_for_training;)
		{	for(int a = 0; a < p_length; a++) {p[a] = ((rand() % 10) + 48);}     if(p[0] == '0') {p[0] = '1';} //Random p.
			for(int a = 0; a < q_length; a++) {q[a] = ((rand() % 10) + 48);}     if(q[0] == '0') {q[0] = '9';} //Random q.
			mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str( p, 10, prime_p);  //p made prime.
			mpz_set_str(randomness, q, 10); mpz_nextprime(prime_q, randomness); mpz_get_str( q, 10, prime_q);  //q made prime.
			mpz_mul(product, prime_p, prime_q);                                 mpz_get_str(pq, 10, product);  //pq made.
			int length = 0; for(int a = 0; pq[a] != '\0'; a++) {length++;} if(length != pq_length) {continue;} //Restarts if pq not pq_length.
			
			//Restarts if label not distributed 1-9.
			char label;
			int prime_comparison = mpz_cmp(prime_p, prime_q);
			if(prime_comparison < 0) {label = p[0];}
			else                     {label = q[0];}
			if(label != one_to_nine) {continue;}
			one_to_nine = ((rand() % 9) + 49);
			
			//Saves to file.
			out_stream << label << " " << pq << "\n"; //Label then semiprime.
			
			loops++; cout << loops << " of " << semiprimes_for_training << "\n";
		}
		out_stream.close();
	}
	
	
	
	
	
	//________________________________________________Primes_composites_______________________________________________//
	if(user_option == 2)
	{	srand(time(0));
		char p[50001] = {'\0'};
		char q[50001] = {'\0'};
		mpz_t randomness; mpz_init(randomness);
		mpz_t prime_p   ; mpz_init(prime_p   );
		
		//Testing-data.
		cout << "\nGenerating testing-data...\n";
		out_stream.open("training-data/raw/test.txt");
		for(int loops = 0; loops < primes_and_composites_for_testing;)
		{	int which_one = (rand() % 2);
			if(which_one == 0)
			{	for(int a = 0; a < prime_and_composite_length; a++) {p[a] = ((rand() % 10) + 48);}     if(p[0] == '0') {p[0] = '1';}     //Random p.
				mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str(p, 10, prime_p);                         //p made prime.
				out_stream << "1 " << p << "\n"; //Saves to file: label, prime.
			}
			else
			{	for(int compositeness = 1; compositeness != 0;)
				{	for(int a = 0; a < prime_and_composite_length; a++) {q[a] = ((rand() % 10) + 48);}     if(q[0] == '0') {q[0] = '1';} //Random q.
					mpz_set_str(randomness, q, 10); compositeness = mpz_probab_prime_p(randomness, 100);                                 //q used if composite.
				}
				mpz_get_str(q, 10, randomness);
				out_stream << "0 " << q << "\n"; //Saves to file: label, composite.
			}
			
			loops++; cout << loops << " of " << primes_and_composites_for_testing << "\n";
		}
		out_stream.close();
		
		//Training-data (ditto but unique items.)
		cout << "\nGenerating training-data...\n";
		out_stream.open("training-data/raw/train.txt");
		for(int loops = 0; loops < primes_and_composites_for_training;)
		{	int which_one = (rand() % 2);
			if(which_one == 0)
			{	for(int a = 0; a < prime_and_composite_length; a++) {p[a] = ((rand() % 10) + 48);}     if(p[0] == '0') {p[0] = '1';}     //Random p.
				mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str(p, 10, prime_p);                         //p made prime.
				out_stream << "1 " << p << "\n"; //Saves to file: label, prime.
			}
			else
			{	for(int compositeness = 1; compositeness != 0;)
				{	for(int a = 0; a < prime_and_composite_length; a++) {q[a] = ((rand() % 10) + 48);}     if(q[0] == '0') {q[0] = '1';} //Random q.
					mpz_set_str(randomness, q, 10); compositeness = mpz_probab_prime_p(randomness, 100);                                 //q used if composite.
				}
				mpz_get_str(q, 10, randomness);
				out_stream << "0 " << q << "\n"; //Saves to file: label, composite.
			}
			
			loops++; cout << loops << " of " << primes_and_composites_for_training << "\n";
		}
		out_stream.close();
	}
	
	
	
	
	
	//__________________________________________Semiprimes_expanding_factors__________________________________________//
	if(user_option == 3)
	{	srand(time(0));
		char  p[ 50001] = {'\0'};
		char  q[ 50001] = {'\0'};
		char pq[200001] = {'\0'};
		mpz_t randomness; mpz_init(randomness);
		mpz_t prime_p   ; mpz_init(prime_p   );
		mpz_t prime_q   ; mpz_init(prime_q   );
		mpz_t product   ; mpz_init(product   );
		
		//Testing-data.
		cout << "\nGenerating testing-data...\n";
		out_stream.open("training-data/raw/test.txt");
		for(int loops = 0; loops < semiprimes_for_testing;)
		{	for(int a = 0; a < p_length; a++) {p[a] = ((rand() % 10) + 48);}     if(p[0] == '0') {p[0] = '1';} //Random p.
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
			
			//Saves to file.
			for(int pq_read_bookmark = pq_length; pq[pq_read_bookmark] != '\0'; pq_read_bookmark++)
			{	out_stream << pq[pq_read_bookmark] << " "; //Label first.
				for(int a = 0; a < pq_read_bookmark; a++) {out_stream << pq[a];} //The rest.
				out_stream << "\n";
			}
			
			loops++; cout << loops << " of " << semiprimes_for_testing << "\n";
		}
		out_stream.close();
		
		//Training-data (ditto but unique items.)
		cout << "\nGenerating training-data...\n";
		out_stream.open("training-data/raw/train.txt");
		for(int loops = 0; loops < semiprimes_for_training;)
		{	for(int a = 0; a < p_length; a++) {p[a] = ((rand() % 10) + 48);}     if(p[0] == '0') {p[0] = '1';} //Random p.
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
			
			//Saves to file.
			for(int pq_read_bookmark = pq_length; pq[pq_read_bookmark] != '\0'; pq_read_bookmark++)
			{	out_stream << pq[pq_read_bookmark] << " "; //Label first.
				for(int a = 0; a < pq_read_bookmark; a++) {out_stream << pq[a];} //The rest.
				out_stream << "\n";
			}
			
			loops++; cout << loops << " of " << semiprimes_for_training << "\n";
		}
		out_stream.close();
	}
	
	
	
	
	
	//____________________________________________________Tokenize____________________________________________________//
	cout << "\nCreating tokenized versions of the raw test.txt and train.txt...\n";
	char file_byte;
	in_stream.open("training-data/raw/test.txt");
	out_stream.open("training-data/test.txt");
	in_stream.get(file_byte);
	for(; in_stream.eof() == false;)
	{	out_stream.put(file_byte); out_stream << " "; in_stream.get(file_byte); in_stream.get(file_byte);
		for(; file_byte != '\n';)
		{	if     (file_byte == '0') {out_stream << tokenized_digit_0;}
			else if(file_byte == '1') {out_stream << tokenized_digit_1;}
			else if(file_byte == '2') {out_stream << tokenized_digit_2;}
			else if(file_byte == '3') {out_stream << tokenized_digit_3;}
			else if(file_byte == '4') {out_stream << tokenized_digit_4;}
			else if(file_byte == '5') {out_stream << tokenized_digit_5;}
			else if(file_byte == '6') {out_stream << tokenized_digit_6;}
			else if(file_byte == '7') {out_stream << tokenized_digit_7;}
			else if(file_byte == '8') {out_stream << tokenized_digit_8;}
			else if(file_byte == '9') {out_stream << tokenized_digit_9;}
			else                      {cout << "\n\nError: non-digits present.\n\n"; return 0;}
			
			in_stream.get(file_byte);
		}
		if(mask_end_of_final_string_with_one_at_symbol == true) {out_stream << "@";}
		out_stream << "\n";
		in_stream.get(file_byte);
	}
	in_stream.close();
	out_stream.close();
	
	in_stream.open("training-data/raw/train.txt");
	out_stream.open("training-data/train.txt");
	in_stream.get(file_byte);
	for(; in_stream.eof() == false;)
	{	out_stream.put(file_byte); out_stream << " "; in_stream.get(file_byte); in_stream.get(file_byte);
		for(; file_byte != '\n';)
		{	if     (file_byte == '0') {out_stream << tokenized_digit_0;}
			else if(file_byte == '1') {out_stream << tokenized_digit_1;}
			else if(file_byte == '2') {out_stream << tokenized_digit_2;}
			else if(file_byte == '3') {out_stream << tokenized_digit_3;}
			else if(file_byte == '4') {out_stream << tokenized_digit_4;}
			else if(file_byte == '5') {out_stream << tokenized_digit_5;}
			else if(file_byte == '6') {out_stream << tokenized_digit_6;}
			else if(file_byte == '7') {out_stream << tokenized_digit_7;}
			else if(file_byte == '8') {out_stream << tokenized_digit_8;}
			else if(file_byte == '9') {out_stream << tokenized_digit_9;}
			else                      {cout << "\n\nError: non-digits present.\n\n"; return 0;}
			
			in_stream.get(file_byte);
		}
		if(mask_end_of_final_string_with_one_at_symbol == true) {out_stream << "@";}
		out_stream << "\n";
		in_stream.get(file_byte);
	}
	in_stream.close();
	out_stream.close();
}
