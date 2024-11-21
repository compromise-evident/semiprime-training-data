// semiprime-training-data 6.0.1 - generates any semiprimes labeled 1 or 0,             Run it: "apt install g++ geany libgmp-dev". Open the .cpp in Geany.
//                                 depending on if what follows the semiprime           Append "-lgmp" to Geany's compile & build commands. Hit F9 once. F5 to run.
//                                 is too big or too small to be the smaller
//                                 factor. Creates raw, and tokenized for
//                                 ML.py & ML-GPU.py.

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
	
	//                                  Semiprimes
	int                             p_length =    10; //50k  max
	int                             q_length =    10; //50k  max
	int                            pq_length =    20; //100k max
	int               semiprimes_for_testing = 10000; //2B   max
	int              semiprimes_for_training = 90000; //2B   max
	
	//                                   Tokenize
	char                 tokenized_digit_0[] = {"@-----------"};
	char                 tokenized_digit_1[] = {"@-@---------"};
	char                 tokenized_digit_2[] = {"@-@@--------"};
	char                 tokenized_digit_3[] = {"@-@@@-------"};
	char                 tokenized_digit_4[] = {"@-@@@@------"};
	char                 tokenized_digit_5[] = {"@-@@@@@-----"};
	char                 tokenized_digit_6[] = {"@-@@@@@@----"};
	char                 tokenized_digit_7[] = {"@-@@@@@@@---"};
	char                 tokenized_digit_8[] = {"@-@@@@@@@@--"};
	char                 tokenized_digit_9[] = {"@-@@@@@@@@@-"};
	char tokenized_underscore_as_separator[] = {"@-----------------------------"};
	bool mask_end_of_final_string_with_one_at_symbol = true;
	
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
	char  p[ 50001] = {'\0'};
	char  q[ 50001] = {'\0'};
	char  r[ 50001] = {'\0'};
	char pq[200001] = {'\0'};
	mpz_t randomness; mpz_init(randomness);
	mpz_t prime_p   ; mpz_init(prime_p   );
	mpz_t prime_q   ; mpz_init(prime_q   );
	mpz_t false_r   ; mpz_init(false_r   );
	mpz_t product   ; mpz_init(product   );
	int r_length = p_length; if(q_length < p_length) {r_length = q_length;}
	
	//Testing-data.
	cout << "\nGenerating testing-data...\n";
	out_stream.open("training-data/raw/test.txt");
	for(int loops = 0; loops < semiprimes_for_testing;)
	{	
		
		
		
		
		//AFTER MODIFYING THIS BLOCK, COPY IT AND PASTE IT OVER THE SAME BLOCK IN THE SECTION BELOW!
		//############################################################################################################################################
		p[0] = ((rand() % 9) + 49); for(int a = 1; a < p_length; a++) {p[a] = ((rand() % 10) + 48);}          //Random p.
		mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str( p, 10, prime_p);     //p made prime (the smaller one.)
		if(p[p_length] != '\0') {p[p_length] = '\0'; continue;}                                               //Restarts if p too long.
		for(;;)
		{	q[0] = ((rand() % 9) + 49); for(; q[0] < p[0];) {q[0] = ((rand() % 9) + 49);}                     //q digit 1 >= p digit 1.
			for(int a = 1; a < q_length; a++) {q[a] = ((rand() % 10) + 48);}                                  //Random q.
			mpz_set_str(randomness, q, 10); mpz_nextprime(prime_q, randomness); mpz_get_str( q, 10, prime_q); //q made prime.
			if(q[q_length] != '\0') {q[q_length] = '\0'; continue;} else {break;}                             //Restarts locally if q too long.
		}
		if(mpz_cmp(prime_p, prime_q) != -1) {continue;}                                                       //Restarts if q <= p.
		mpz_mul(product, prime_p, prime_q); mpz_get_str(pq, 10, product);                                     //pq made.
		int length = 0; for(int a = 0; pq[a] != '\0'; a++) {length++;} if(length != pq_length) {continue;}    //Restarts if pq not pq_length.
		r[0] = ((rand() % 9) + 49); for(int a = 1; a < r_length; a++) {r[a] = ((rand() % 10) + 48);}          //Random r.
		mpz_set_str(false_r, r, 10); int label = mpz_cmp(false_r, prime_p);                                   //Gets label; r vs p size.
		if(label == 0) {continue;} if(label == -1) {label++;}                                                 //Restarts if r = p.
		//Saves to file: label, semiprime, break, false candidate, (p * q) reference ignored by tokenizer.
		//Modify this, but each output text line must be: label of any kind & length without spaces,
		//space, digits/underscores, then new line (or then space then whatever then new line.)
		out_stream << label << " " << pq << "_" << r << "   (" << p << " * " << q << ")\n";
		//############################################################################################################################################
		
		
		
		
		
		loops++; cout << loops << " of " << semiprimes_for_testing << "\n";
	}
	out_stream.close();
	
	//Training-data.
	cout << "\nGenerating training-data...\n";
	out_stream.open("training-data/raw/train.txt");
	for(int loops = 0; loops < semiprimes_for_training;)
	{	
		
		
		
		
		//############################################################################################################################################
		p[0] = ((rand() % 9) + 49); for(int a = 1; a < p_length; a++) {p[a] = ((rand() % 10) + 48);}          //Random p.
		mpz_set_str(randomness, p, 10); mpz_nextprime(prime_p, randomness); mpz_get_str( p, 10, prime_p);     //p made prime (the smaller one.)
		if(p[p_length] != '\0') {p[p_length] = '\0'; continue;}                                               //Restarts if p too long.
		for(;;)
		{	q[0] = ((rand() % 9) + 49); for(; q[0] < p[0];) {q[0] = ((rand() % 9) + 49);}                     //q digit 1 >= p digit 1.
			for(int a = 1; a < q_length; a++) {q[a] = ((rand() % 10) + 48);}                                  //Random q.
			mpz_set_str(randomness, q, 10); mpz_nextprime(prime_q, randomness); mpz_get_str( q, 10, prime_q); //q made prime.
			if(q[q_length] != '\0') {q[q_length] = '\0'; continue;} else {break;}                             //Restarts locally if q too long.
		}
		if(mpz_cmp(prime_p, prime_q) != -1) {continue;}                                                       //Restarts if q <= p.
		mpz_mul(product, prime_p, prime_q); mpz_get_str(pq, 10, product);                                     //pq made.
		int length = 0; for(int a = 0; pq[a] != '\0'; a++) {length++;} if(length != pq_length) {continue;}    //Restarts if pq not pq_length.
		r[0] = ((rand() % 9) + 49); for(int a = 1; a < r_length; a++) {r[a] = ((rand() % 10) + 48);}          //Random r.
		mpz_set_str(false_r, r, 10); int label = mpz_cmp(false_r, prime_p);                                   //Gets label; r vs p size.
		if(label == 0) {continue;} if(label == -1) {label++;}                                                 //Restarts if r = p.
		//Saves to file: label, semiprime, break, false candidate, (p * q) reference ignored by tokenizer.
		//Modify this, but each output text line must be: label of any kind & length without spaces,
		//space, digits/underscores, then new line (or then space then whatever then new line.)
		out_stream << label << " " << pq << "_" << r << "   (" << p << " * " << q << ")\n";
		//############################################################################################################################################
		
		
		
		
		
		loops++; cout << loops << " of " << semiprimes_for_training << "\n";
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
		
		for(; file_byte != ' ';)
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
			else if(file_byte == '_') {out_stream << tokenized_underscore_as_separator;}
			else if(file_byte =='\n') {break                                          ;}
			else                      {cout << "\n\nError: non-digits present.\n\n"; in_stream.close(); out_stream.close(); return 0;}
			in_stream.get(file_byte);
		}
		
		if(mask_end_of_final_string_with_one_at_symbol == true) {out_stream << "@";}
		out_stream << "\n";
		for(; file_byte != '\n';) {in_stream.get(file_byte);}
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
		
		for(; file_byte != ' ';)
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
			else if(file_byte == '_') {out_stream << tokenized_underscore_as_separator;}
			else if(file_byte =='\n') {break                                          ;}
			else                      {cout << "\n\nError: non-digits present.\n\n"; in_stream.close(); out_stream.close(); return 0;}
			in_stream.get(file_byte);
		}
		
		if(mask_end_of_final_string_with_one_at_symbol == true) {out_stream << "@";}
		out_stream << "\n";
		for(; file_byte != '\n';) {in_stream.get(file_byte);}
		in_stream.get(file_byte);
	}
	in_stream.close();
	out_stream.close();
}
