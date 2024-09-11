Requirement: GNU Multiple Precision Arithmetic Library.
Just do ```apt install libgmp-dev``` then append "-lgmp" to both compile & build
commands in Geany, or then compile using ```g++ /path_to_this.cpp -lgmp```

<br>
<br>

## Prove RSA is cracked when a model aces your generated testing-data

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/semiprime-training-data/main/Other/Configurable.png">
</p>

<br>
<br>

## Training-data & testing-data are the same but of unique semiprimes

See that first semiprime of 40 digits? It must be classified under the label "2"
because "2" is the first digit of that semiprime's smaller factor.
The second line has "2" appended to the semiprime. This second line must be
classified under "9" because "9" is the second digit of that semiprime's
smaller factor. And so on.

Testing-data is the same but of unique semiprimes. For example,
if this was testing-data, your model cracked RSA if it can classify
every string under the preceding label digit.
Want evidence that these are semiprimes?
Go to wolframalpha.com and say
"factor 1415020064050850383861594463040864050023".

```text

2 1415020064050850383861594463040864050023
9 14150200640508503838615944630408640500232
8 141502006405085038386159446304086405002329
8 1415020064050850383861594463040864050023298
0 14150200640508503838615944630408640500232988
8 141502006405085038386159446304086405002329880
7 1415020064050850383861594463040864050023298808
1 14150200640508503838615944630408640500232988087
2 141502006405085038386159446304086405002329880871
6 1415020064050850383861594463040864050023298808712
5 14150200640508503838615944630408640500232988087126
1 141502006405085038386159446304086405002329880871265
0 1415020064050850383861594463040864050023298808712651
2 14150200640508503838615944630408640500232988087126510
3 141502006405085038386159446304086405002329880871265102
3 1415020064050850383861594463040864050023298808712651023
4 14150200640508503838615944630408640500232988087126510233
9 141502006405085038386159446304086405002329880871265102334
9 1415020064050850383861594463040864050023298808712651023349
1 14150200640508503838615944630408640500232988087126510233499
3 2866077218153534768796439686488146568071
3 28660772181535347687964396864881465680713
3 286607721815353476879643968648814656807133
3 2866077218153534768796439686488146568071333
7 28660772181535347687964396864881465680713333
7 286607721815353476879643968648814656807133337
6 2866077218153534768796439686488146568071333377
4 28660772181535347687964396864881465680713333776
2 286607721815353476879643968648814656807133337764
2 2866077218153534768796439686488146568071333377642
9 28660772181535347687964396864881465680713333776422
5 286607721815353476879643968648814656807133337764229
4 2866077218153534768796439686488146568071333377642295
7 28660772181535347687964396864881465680713333776422954
5 286607721815353476879643968648814656807133337764229547
2 2866077218153534768796439686488146568071333377642295475
1 28660772181535347687964396864881465680713333776422954752
0 286607721815353476879643968648814656807133337764229547521
1 2866077218153534768796439686488146568071333377642295475210
3 28660772181535347687964396864881465680713333776422954752101
.
.
.
.
.

```

## Generates also padded with 0 (choose your padding_character)

```text

2 00000000000000000001415020064050850383861594463040864050023
9 00000000000000000014150200640508503838615944630408640500232
8 00000000000000000141502006405085038386159446304086405002329
8 00000000000000001415020064050850383861594463040864050023298
0 00000000000000014150200640508503838615944630408640500232988
8 00000000000000141502006405085038386159446304086405002329880
7 00000000000001415020064050850383861594463040864050023298808
1 00000000000014150200640508503838615944630408640500232988087
2 00000000000141502006405085038386159446304086405002329880871
6 00000000001415020064050850383861594463040864050023298808712
5 00000000014150200640508503838615944630408640500232988087126
1 00000000141502006405085038386159446304086405002329880871265
0 00000001415020064050850383861594463040864050023298808712651
2 00000014150200640508503838615944630408640500232988087126510
3 00000141502006405085038386159446304086405002329880871265102
3 00001415020064050850383861594463040864050023298808712651023
4 00014150200640508503838615944630408640500232988087126510233
9 00141502006405085038386159446304086405002329880871265102334
9 01415020064050850383861594463040864050023298808712651023349
1 14150200640508503838615944630408640500232988087126510233499
3 00000000000000000002866077218153534768796439686488146568071
3 00000000000000000028660772181535347687964396864881465680713
3 00000000000000000286607721815353476879643968648814656807133
3 00000000000000002866077218153534768796439686488146568071333
7 00000000000000028660772181535347687964396864881465680713333
7 00000000000000286607721815353476879643968648814656807133337
6 00000000000002866077218153534768796439686488146568071333377
4 00000000000028660772181535347687964396864881465680713333776
2 00000000000286607721815353476879643968648814656807133337764
2 00000000002866077218153534768796439686488146568071333377642
9 00000000028660772181535347687964396864881465680713333776422
5 00000000286607721815353476879643968648814656807133337764229
4 00000002866077218153534768796439686488146568071333377642295
7 00000028660772181535347687964396864881465680713333776422954
5 00000286607721815353476879643968648814656807133337764229547
2 00002866077218153534768796439686488146568071333377642295475
1 00028660772181535347687964396864881465680713333776422954752
0 00286607721815353476879643968648814656807133337764229547521
1 02866077218153534768796439686488146568071333377642295475210
3 28660772181535347687964396864881465680713333776422954752101
.
.
.
.
.

```

<br>
<br>

<p align="center"><sub>Nomenclature: p & q are prime, p × q is semiprime (denoted pq.) p & q are factors of pq. Given only pq, it's statistically hard to find p & q.<sub/></p>
<p align="center"><sub>RSA uses p and q of equal and nearly equal length. Resulting pq is twice the length, hence these 40-digit samples have factors of 20 digits.<sub/></p>
<p align="center"><sub>Not all p and q of equal lengths result in pq of exactly twice the length, hence "pq_length" can be set as needed.<sub/></p>
