Run it: ```apt install g++ geany libgmp-dev```. Open the .cpp in Geany.<br>
Append ```-lgmp``` to Geany's compile & build commands. Hit F9 once. F5 to run.

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/semiprime-training-data/main/Other/Terminal_baa56c42a4f58b5fcc4aca2d732f28d7.png">
</p>

<br>
<br>

## Prove RSA is cracked when a model aces your generated test.txt

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/semiprime-training-data/main/Other/Configurable_781a1d3c777505b1a23134b891a80d30.png">
</p>

<br>
<br>

## train.txt & test.txt are the same but of unique items

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

   label               semiprime                      factor
     |                     |                            |

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

```

## Or generate primes+composites: 1=prime 0=composite

```text

     1 17164184922853302484208055506689526034648845387725175172833
     0 13565380747751401184813632827370948677961858199329910275659
     0 19503483371677598421512759336297169720259327078930083250303
     0 54983055071015934747947484435930648946475798402876783623167
     1 52036822699280230619517879107085288091370498543707758658193
     0 98849948075247013683371146007057961057075599410770308432244
     1 61959274973652796795046881225644939979576931313902508306623
     1 95600798645350693986358109953094756747531269548848476316479
     0 20397974847295149923993544204377636545932651165179660924344
     1 94959713328793821530607719175874462335887756259624696368533
     0 74630865356023969023692328398807261469194728135257518061892
     1 92831997019503538073036855156346821131834904460287782697179
     0 69563778051474012260039210220528474941769026459677771822847
     1 19178565931034689766556858254185092960453756136235100788747
     0 41040457414792525450180178941595691739670069432099007124130
     1 89150345224440495815915849283423540596038675634335848425383
     1 95451422345105880226900863329600365510944575265207000186503
     0 91549310316786404044956986849890155106339027897414001729303
     0 82509219944067868709119203333604964887093402188171094234579
     0 50546956856318538665976310769674821636333174949726415146132
     1 22606970705232749831675189913235627214416239605518976414561
     1 41525359910633726379366909662466729376269445747596423345299
     1 68332489007162646515269593235601457895718424890662188359771
     1 46501280071836227383522577455091771891118494028776140399507
     1 54121533644704318187911260195692325490986456007018709848079
     0 28950620618275195898880085881555553735708746455167965064762
     1 30387660352239894512229847214619658534691016916469891998753
     0 91288233812025618475366757740691949985576978550327073841517
     0 99915813360079047089806393666646538011579696791401303252521
     0 95058079128207087329689006458588085884019859867712680702349
     1 27448058650557755627007077433377312137104379167639530269541
     0 69413646358996104887743989921399330624472371183561557858960
     1 99244406174301439707052059845877911354061493736828554959953
     1 33324559978217503387152779962547889457564388158609336613783
     1 76976111887227232112247828200329116729008952877208622435617
     0 97640533445450840562335678315087951905461036210279502289232
     0 31626848384487231378220661704990064848699359072120164421513
     0 13139645606531560795933478729032376432914570846137830177941
     0 65302147368017021635510647563799221668514517319694157132080
     0 59593871623286010999636361770927897406569017710929082749038
                                   .
                                   .
                                   .

```

<br>
<br>

<p align="center"><sub>Nomenclature: p & q are prime, p × q is semiprime (denoted pq.) p & q are factors of pq. Given only pq, it's statistically hard to find p & q.<sub/></p>
<p align="center"><sub>RSA uses p & q of equal length. pq is then twice the length but not always. "pq_length = 40" discards any pq not 40 digits.<sub/></p>
<p align="center"><sub>Here, 40-digit samples have two factors of 20 digits each, but you can set each length.<sub/></p>
