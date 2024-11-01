// Generates primes & composites labeled 1 = prime                              Run it: "apt install g++ geany libgmp-dev". Open the .cpp in Geany.
// and 0 = composite. Creates raw and tokenized.                                Append "-lgmp" to Geany's compile & build commands. Hit F9 once. F5 to run.

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
	
	//                            Primes+composites
	int         prime_and_composite_length =    20; //50k  max
	int  primes_and_composites_for_testing = 10000; //2B   max
	int primes_and_composites_for_training = 90000; //2B   max
	
	//                                 Tokenize
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
	
	system("mkdir training-data     -p");
	system("mkdir training-data/raw -p");
	
	srand(time(0));
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
		{	p[0] = ((rand() % 9) + 49); for(int a = 1; a < prime_and_composite_length; a++) {p[a] = ((rand() % 10) + 48);}     //Random p.
			mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str(p, 10, prime_p);                   //p made prime.
			if(p[prime_and_composite_length] != '\0') {p[prime_and_composite_length] = '\0'; continue;}                        //Restarts if p too long.
			out_stream << "1 " << p << "\n"; //Saves to file: label, prime.
		}
		else
		{	for(int compositeness = 1; compositeness != 0;)
			{	q[0] = ((rand() % 9) + 49); for(int a = 1; a < prime_and_composite_length; a++) {q[a] = ((rand() % 10) + 48);} //Random q.
				mpz_set_str(randomness, q, 10); compositeness = mpz_probab_prime_p(randomness, 100);                           //q used if composite.
			}
			mpz_get_str(q, 10, randomness);
			out_stream << "0 " << q << "\n"; //Saves to file: label, composite.
		}
		
		loops++; cout << loops << " of " << primes_and_composites_for_testing << "\n";
	}
	out_stream.close();
	
	//Training-data (ditto except paths.)
	cout << "\nGenerating training-data...\n";
	out_stream.open("training-data/raw/train.txt");
	for(int loops = 0; loops < primes_and_composites_for_training;)
	{	int which_one = (rand() % 2);
		if(which_one == 0)
		{	p[0] = ((rand() % 9) + 49); for(int a = 1; a < prime_and_composite_length; a++) {p[a] = ((rand() % 10) + 48);}     //Random p.
			mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str(p, 10, prime_p);                   //p made prime.
			if(p[prime_and_composite_length] != '\0') {p[prime_and_composite_length] = '\0'; continue;}                        //Restarts if p too long.
			out_stream << "1 " << p << "\n"; //Saves to file: label, prime.
		}
		else
		{	for(int compositeness = 1; compositeness != 0;)
			{	q[0] = ((rand() % 9) + 49); for(int a = 1; a < prime_and_composite_length; a++) {q[a] = ((rand() % 10) + 48);} //Random q.
				mpz_set_str(randomness, q, 10); compositeness = mpz_probab_prime_p(randomness, 100);                           //q used if composite.
			}
			mpz_get_str(q, 10, randomness);
			out_stream << "0 " << q << "\n"; //Saves to file: label, composite.
		}
		
		loops++; cout << loops << " of " << primes_and_composites_for_training << "\n";
	}
	out_stream.close();
	
	
	
	
	
	//Tokenize test.txt.
	cout << "\nCreating tokenized versions of the raw test.txt and train.txt...\n";
	char file_byte;
	in_stream.open("training-data/raw/test.txt");
	out_stream.open("training-data/test.txt");
	in_stream.get(file_byte);
	for(; in_stream.eof() == false;)
	{	for(; file_byte != ' ';) {out_stream.put(file_byte); in_stream.get(file_byte);}
		out_stream << " "; in_stream.get(file_byte);
		
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
			else                      {cout << "\n\nError: non-digits present.\n\n"; in_stream.close(); out_stream.close(); return 0;}
			in_stream.get(file_byte);
		}
		
		if(mask_end_of_final_string_with_one_at_symbol == true) {out_stream << "@";}
		out_stream << "\n";
		in_stream.get(file_byte);
	}
	in_stream.close();
	out_stream.close();
	
	//Tokenize train.txt (ditto except paths.)
	in_stream.open("training-data/raw/train.txt");
	out_stream.open("training-data/train.txt");
	in_stream.get(file_byte);
	for(; in_stream.eof() == false;)
	{	for(; file_byte != ' ';) {out_stream.put(file_byte); in_stream.get(file_byte);}
		out_stream << " "; in_stream.get(file_byte);
		
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
			else                      {cout << "\n\nError: non-digits present.\n\n"; in_stream.close(); out_stream.close(); return 0;}
			in_stream.get(file_byte);
		}
		
		if(mask_end_of_final_string_with_one_at_symbol == true) {out_stream << "@";}
		out_stream << "\n";
		in_stream.get(file_byte);
	}
	in_stream.close();
	out_stream.close();
}
