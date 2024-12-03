Run it: ```apt install g++ geany libgmp-dev```. Open the .cpp in Geany.<br>
Append ```-lgmp``` to Geany's compile & build commands. Hit F9 once. F5 to run.

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/semiprime-training-data/refs/heads/main/Other/Terminal_3f59fe6f0e3b24ba417a8b069353f78e.png">
</p>

<br>
<br>

### train.txt & test.txt are the same but of unique items

```text

                                           true factors, for you
   label    semiprime      false factor     (tokenizer ignores)
     |          |               |                    |

     1 50595454897434471649_8090636973   (6470808299 * 7819031651)
     1 14217322442983560689_8253236055   (1732904837 * 8204329597)
     0 12838375796012324917_2623370731   (3246313991 * 3954754787)
     1 28177707768929488327_8304614793   (3151708799 * 8940454073)
     1 55938578832010782067_8339552859   (7384502207 * 7575131981)
     0 52894306672212980131_3742226275   (5498452853 * 9619852727)
     0 54147410130923732419_5438088670   (7247812807 * 7470862117)
     0 69542353788107851103_2974522934   (7140389281 * 9739294463)
     0 34836055341598523681_4965517903   (5758918877 * 6049061653)
     0 91308379530317368361_5116292898   (9201092081 * 9923645881)
     0 29304742580756900443_1470211500   (4924724801 * 5950534043)
     1 34079593063132551811_7570812514   (3729493121 * 9137861891)
     1 14129185742227422277_3205955743   (1828809263 * 7725893579)
     0 90971655860835947039_6706014935   (9215017991 * 9872108329)
     1 41883272092202642897_7999703416   (5121200951 * 8178408247)
     0 66311492839101139823_5961527465   (7727999449 * 8580680327)
     0 33950772509989264999_1554826574   (5641531607 * 6018006257)
     0 79375103950158249341_5353735312   (8607852137 * 9221243893)
     0 29969026688938139981_2382687430   (4311297517 * 6951277793)
     0 61793662362610401887_1913948910   (7138518523 * 8656370669)
     1 29681436545615157859_9440936827   (3550017371 * 8360927129)
     0 45907932140894010779_1351546148   (4927159891 * 9317321369)
     0 64163865539095601459_2765545179   (7486742509 * 8570331551)
     1 40771011249824317271_6811677104   (4651194227 * 8765708173)
     0 17040186351474636043_1156415245   (3127247891 * 5448940073)
     1 25259931870927563479_4678221768   (2691435349 * 9385301371)
     1 15026379638863865219_7039083259   (2244309061 * 6695325479)
     0 19092782381088375383_2935143480   (3246897839 * 5880315097)
     1 18998005253561229089_6197603161   (2032613519 * 9346590031)
     1 19789440258119977877_6901535288   (2015248853 * 9819849409)
     1 48123752063154694981_7016179818   (6506223121 * 7396572661)
     1 40480057581589202783_7701340522   (4658590033 * 8689336751)
     0 70896229865423423569_5541593746   (8102971291 * 8749411459)
     0 34245013387229839303_4605966432   (4885903361 * 7008942023)
     0 65105262135372272617_4467690603   (7309191653 * 8907313589)
     0 75466431708634444507_7426248236   (8078758939 * 9341339713)
     1 50149583937621478727_6716559278   (5963378527 * 8409592601)
     1 27717731412977169581_3503053443   (3235006429 * 8568060689)
     0 31567983323468781913_1369684131   (4672879609 * 6755573857)
     1 11287448557384747997_3934941918   (1486575019 * 7592922263)
                                   .
                                   .
                                   .

```

<br>
<br>

### Tokenized versions of train.txt & test.txt

```text

   label    semiprime                                                                                                                                                                                                                                    underscore means separation              false factor
     |          |                                                                                                                                                                                                                                                     |                                |

     1 @-@@@@@-----@-----------@-@@@@@-----@-@@@@@@@@@-@-@@@@@-----@-@@@@------@-@@@@@-----@-@@@@------@-@@@@@@@@--@-@@@@@@@@@-@-@@@@@@@---@-@@@@------@-@@@-------@-@@@@------@-@@@@------@-@@@@@@@---@-@---------@-@@@@@@----@-@@@@------@-@@@@@@@@@-@-----------------------------@-@@@@@@@@--@-----------@-@@@@@@@@@-@-----------@-@@@@@@----@-@@@-------@-@@@@@@----@-@@@@@@@@@-@-@@@@@@@---@-@@@-------@
     1 @-@---------@-@@@@------@-@@--------@-@---------@-@@@@@@@---@-@@@-------@-@@--------@-@@--------@-@@@@------@-@@@@------@-@@--------@-@@@@@@@@@-@-@@@@@@@@--@-@@@-------@-@@@@@-----@-@@@@@@----@-----------@-@@@@@@----@-@@@@@@@@--@-@@@@@@@@@-@-----------------------------@-@@@@@@@@--@-@@--------@-@@@@@-----@-@@@-------@-@@--------@-@@@-------@-@@@@@@----@-----------@-@@@@@-----@-@@@@@-----@
     0 @-@---------@-@@--------@-@@@@@@@@--@-@@@-------@-@@@@@@@@--@-@@@-------@-@@@@@@@---@-@@@@@-----@-@@@@@@@---@-@@@@@@@@@-@-@@@@@@----@-----------@-@---------@-@@--------@-@@@-------@-@@--------@-@@@@------@-@@@@@@@@@-@-@---------@-@@@@@@@---@-----------------------------@-@@--------@-@@@@@@----@-@@--------@-@@@-------@-@@@-------@-@@@@@@@---@-----------@-@@@@@@@---@-@@@-------@-@---------@
     1 @-@@--------@-@@@@@@@@--@-@---------@-@@@@@@@---@-@@@@@@@---@-@@@@@@@---@-----------@-@@@@@@@---@-@@@@@@@---@-@@@@@@----@-@@@@@@@@--@-@@@@@@@@@-@-@@--------@-@@@@@@@@@-@-@@@@------@-@@@@@@@@--@-@@@@@@@@--@-@@@-------@-@@--------@-@@@@@@@---@-----------------------------@-@@@@@@@@--@-@@@-------@-----------@-@@@@------@-@@@@@@----@-@---------@-@@@@------@-@@@@@@@---@-@@@@@@@@@-@-@@@-------@
     1 @-@@@@@-----@-@@@@@-----@-@@@@@@@@@-@-@@@-------@-@@@@@@@@--@-@@@@@-----@-@@@@@@@---@-@@@@@@@@--@-@@@@@@@@--@-@@@-------@-@@--------@-----------@-@---------@-----------@-@@@@@@@---@-@@@@@@@@--@-@@--------@-----------@-@@@@@@----@-@@@@@@@---@-----------------------------@-@@@@@@@@--@-@@@-------@-@@@-------@-@@@@@@@@@-@-@@@@@-----@-@@@@@-----@-@@--------@-@@@@@@@@--@-@@@@@-----@-@@@@@@@@@-@
     0 @-@@@@@-----@-@@--------@-@@@@@@@@--@-@@@@@@@@@-@-@@@@------@-@@@-------@-----------@-@@@@@@----@-@@@@@@----@-@@@@@@@---@-@@--------@-@@--------@-@---------@-@@--------@-@@@@@@@@@-@-@@@@@@@@--@-----------@-@---------@-@@@-------@-@---------@-----------------------------@-@@@-------@-@@@@@@@---@-@@@@------@-@@--------@-@@--------@-@@--------@-@@@@@@----@-@@--------@-@@@@@@@---@-@@@@@-----@
     0 @-@@@@@-----@-@@@@------@-@---------@-@@@@------@-@@@@@@@---@-@@@@------@-@---------@-----------@-@---------@-@@@-------@-----------@-@@@@@@@@@-@-@@--------@-@@@-------@-@@@@@@@---@-@@@-------@-@@--------@-@@@@------@-@---------@-@@@@@@@@@-@-----------------------------@-@@@@@-----@-@@@@------@-@@@-------@-@@@@@@@@--@-----------@-@@@@@@@@--@-@@@@@@@@--@-@@@@@@----@-@@@@@@@---@-----------@
     0 @-@@@@@@----@-@@@@@@@@@-@-@@@@@-----@-@@@@------@-@@--------@-@@@-------@-@@@@@-----@-@@@-------@-@@@@@@@---@-@@@@@@@@--@-@@@@@@@@--@-@---------@-----------@-@@@@@@@---@-@@@@@@@@--@-@@@@@-----@-@---------@-@---------@-----------@-@@@-------@-----------------------------@-@@--------@-@@@@@@@@@-@-@@@@@@@---@-@@@@------@-@@@@@-----@-@@--------@-@@--------@-@@@@@@@@@-@-@@@-------@-@@@@------@
     0 @-@@@-------@-@@@@------@-@@@@@@@@--@-@@@-------@-@@@@@@----@-----------@-@@@@@-----@-@@@@@-----@-@@@-------@-@@@@------@-@---------@-@@@@@-----@-@@@@@@@@@-@-@@@@@@@@--@-@@@@@-----@-@@--------@-@@@-------@-@@@@@@----@-@@@@@@@@--@-@---------@-----------------------------@-@@@@------@-@@@@@@@@@-@-@@@@@@----@-@@@@@-----@-@@@@@-----@-@---------@-@@@@@@@---@-@@@@@@@@@-@-----------@-@@@-------@
     0 @-@@@@@@@@@-@-@---------@-@@@-------@-----------@-@@@@@@@@--@-@@@-------@-@@@@@@@---@-@@@@@@@@@-@-@@@@@-----@-@@@-------@-----------@-@@@-------@-@---------@-@@@@@@@---@-@@@-------@-@@@@@@----@-@@@@@@@@--@-@@@-------@-@@@@@@----@-@---------@-----------------------------@-@@@@@-----@-@---------@-@---------@-@@@@@@----@-@@--------@-@@@@@@@@@-@-@@--------@-@@@@@@@@--@-@@@@@@@@@-@-@@@@@@@@--@
     0 @-@@--------@-@@@@@@@@@-@-@@@-------@-----------@-@@@@------@-@@@@@@@---@-@@@@------@-@@--------@-@@@@@-----@-@@@@@@@@--@-----------@-@@@@@@@---@-@@@@@-----@-@@@@@@----@-@@@@@@@@@-@-----------@-----------@-@@@@------@-@@@@------@-@@@-------@-----------------------------@-@---------@-@@@@------@-@@@@@@@---@-----------@-@@--------@-@---------@-@---------@-@@@@@-----@-----------@-----------@
     1 @-@@@-------@-@@@@------@-----------@-@@@@@@@---@-@@@@@@@@@-@-@@@@@-----@-@@@@@@@@@-@-@@@-------@-----------@-@@@@@@----@-@@@-------@-@---------@-@@@-------@-@@--------@-@@@@@-----@-@@@@@-----@-@---------@-@@@@@@@@--@-@---------@-@---------@-----------------------------@-@@@@@@@---@-@@@@@-----@-@@@@@@@---@-----------@-@@@@@@@@--@-@---------@-@@--------@-@@@@@-----@-@---------@-@@@@------@
     1 @-@---------@-@@@@------@-@---------@-@@--------@-@@@@@@@@@-@-@---------@-@@@@@@@@--@-@@@@@-----@-@@@@@@@---@-@@@@------@-@@--------@-@@--------@-@@--------@-@@@@@@@---@-@@@@------@-@@--------@-@@--------@-@@--------@-@@@@@@@---@-@@@@@@@---@-----------------------------@-@@@-------@-@@--------@-----------@-@@@@@-----@-@@@@@@@@@-@-@@@@@-----@-@@@@@-----@-@@@@@@@---@-@@@@------@-@@@-------@
     0 @-@@@@@@@@@-@-----------@-@@@@@@@@@-@-@@@@@@@---@-@---------@-@@@@@@----@-@@@@@-----@-@@@@@-----@-@@@@@@@@--@-@@@@@@----@-----------@-@@@@@@@@--@-@@@-------@-@@@@@-----@-@@@@@@@@@-@-@@@@------@-@@@@@@@---@-----------@-@@@-------@-@@@@@@@@@-@-----------------------------@-@@@@@@----@-@@@@@@@---@-----------@-@@@@@@----@-----------@-@---------@-@@@@------@-@@@@@@@@@-@-@@@-------@-@@@@@-----@
     1 @-@@@@------@-@---------@-@@@@@@@@--@-@@@@@@@@--@-@@@-------@-@@--------@-@@@@@@@---@-@@--------@-----------@-@@@@@@@@@-@-@@--------@-@@--------@-----------@-@@--------@-@@@@@@----@-@@@@------@-@@--------@-@@@@@@@@--@-@@@@@@@@@-@-@@@@@@@---@-----------------------------@-@@@@@@@---@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@@---@-----------@-@@@-------@-@@@@------@-@---------@-@@@@@@----@
     0 @-@@@@@@----@-@@@@@@----@-@@@-------@-@---------@-@---------@-@@@@------@-@@@@@@@@@-@-@@--------@-@@@@@@@@--@-@@@-------@-@@@@@@@@@-@-@---------@-----------@-@---------@-@---------@-@@@-------@-@@@@@@@@@-@-@@@@@@@@--@-@@--------@-@@@-------@-----------------------------@-@@@@@-----@-@@@@@@@@@-@-@@@@@@----@-@---------@-@@@@@-----@-@@--------@-@@@@@@@---@-@@@@------@-@@@@@@----@-@@@@@-----@
     0 @-@@@-------@-@@@-------@-@@@@@@@@@-@-@@@@@-----@-----------@-@@@@@@@---@-@@@@@@@---@-@@--------@-@@@@@-----@-----------@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@@@--@-@@@@@@@@@-@-@@--------@-@@@@@@----@-@@@@------@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@@@@-@-----------------------------@-@---------@-@@@@@-----@-@@@@@-----@-@@@@------@-@@@@@@@@--@-@@--------@-@@@@@@----@-@@@@@-----@-@@@@@@@---@-@@@@------@
     0 @-@@@@@@@---@-@@@@@@@@@-@-@@@-------@-@@@@@@@---@-@@@@@-----@-@---------@-----------@-@@@-------@-@@@@@@@@@-@-@@@@@-----@-----------@-@---------@-@@@@@-----@-@@@@@@@@--@-@@--------@-@@@@------@-@@@@@@@@@-@-@@@-------@-@@@@------@-@---------@-----------------------------@-@@@@@-----@-@@@-------@-@@@@@-----@-@@@-------@-@@@@@@@---@-@@@-------@-@@@@@-----@-@@@-------@-@---------@-@@--------@
     0 @-@@--------@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@----@-@@@@@@@@@-@-----------@-@@--------@-@@@@@@----@-@@@@@@----@-@@@@@@@@--@-@@@@@@@@--@-@@@@@@@@@-@-@@@-------@-@@@@@@@@--@-@---------@-@@@-------@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@@@--@-@---------@-----------------------------@-@@--------@-@@@-------@-@@@@@@@@--@-@@--------@-@@@@@@----@-@@@@@@@@--@-@@@@@@@---@-@@@@------@-@@@-------@-----------@
     0 @-@@@@@@----@-@---------@-@@@@@@@---@-@@@@@@@@@-@-@@@-------@-@@@@@@----@-@@@@@@----@-@@--------@-@@@-------@-@@@@@@----@-@@--------@-@@@@@@----@-@---------@-----------@-@@@@------@-----------@-@---------@-@@@@@@@@--@-@@@@@@@@--@-@@@@@@@---@-----------------------------@-@---------@-@@@@@@@@@-@-@---------@-@@@-------@-@@@@@@@@@-@-@@@@------@-@@@@@@@@--@-@@@@@@@@@-@-@---------@-----------@
     1 @-@@--------@-@@@@@@@@@-@-@@@@@@----@-@@@@@@@@--@-@---------@-@@@@------@-@@@-------@-@@@@@@----@-@@@@@-----@-@@@@------@-@@@@@-----@-@@@@@@----@-@---------@-@@@@@-----@-@---------@-@@@@@-----@-@@@@@@@---@-@@@@@@@@--@-@@@@@-----@-@@@@@@@@@-@-----------------------------@-@@@@@@@@@-@-@@@@------@-@@@@------@-----------@-@@@@@@@@@-@-@@@-------@-@@@@@@----@-@@@@@@@@--@-@@--------@-@@@@@@@---@
     0 @-@@@@------@-@@@@@-----@-@@@@@@@@@-@-----------@-@@@@@@@---@-@@@@@@@@@-@-@@@-------@-@@--------@-@---------@-@@@@------@-----------@-@@@@@@@@--@-@@@@@@@@@-@-@@@@------@-----------@-@---------@-----------@-@@@@@@@---@-@@@@@@@---@-@@@@@@@@@-@-----------------------------@-@---------@-@@@-------@-@@@@@-----@-@---------@-@@@@@-----@-@@@@------@-@@@@@@----@-@---------@-@@@@------@-@@@@@@@@--@
     0 @-@@@@@@----@-@@@@------@-@---------@-@@@@@@----@-@@@-------@-@@@@@@@@--@-@@@@@@----@-@@@@@-----@-@@@@@-----@-@@@-------@-@@@@@@@@@-@-----------@-@@@@@@@@@-@-@@@@@-----@-@@@@@@----@-----------@-@---------@-@@@@------@-@@@@@-----@-@@@@@@@@@-@-----------------------------@-@@--------@-@@@@@@@---@-@@@@@@----@-@@@@@-----@-@@@@@-----@-@@@@------@-@@@@@-----@-@---------@-@@@@@@@---@-@@@@@@@@@-@
     1 @-@@@@------@-----------@-@@@@@@@---@-@@@@@@@---@-@---------@-----------@-@---------@-@---------@-@@--------@-@@@@------@-@@@@@@@@@-@-@@@@@@@@--@-@@--------@-@@@@------@-@@@-------@-@---------@-@@@@@@@---@-@@--------@-@@@@@@@---@-@---------@-----------------------------@-@@@@@@----@-@@@@@@@@--@-@---------@-@---------@-@@@@@@----@-@@@@@@@---@-@@@@@@@---@-@---------@-----------@-@@@@------@
     0 @-@---------@-@@@@@@@---@-----------@-@@@@------@-----------@-@---------@-@@@@@@@@--@-@@@@@@----@-@@@-------@-@@@@@-----@-@---------@-@@@@------@-@@@@@@@---@-@@@@------@-@@@@@@----@-@@@-------@-@@@@@@----@-----------@-@@@@------@-@@@-------@-----------------------------@-@---------@-@---------@-@@@@@-----@-@@@@@@----@-@@@@------@-@---------@-@@@@@-----@-@@--------@-@@@@------@-@@@@@-----@
     1 @-@@--------@-@@@@@-----@-@@--------@-@@@@@-----@-@@@@@@@@@-@-@@@@@@@@@-@-@@@-------@-@---------@-@@@@@@@@--@-@@@@@@@---@-----------@-@@@@@@@@@-@-@@--------@-@@@@@@@---@-@@@@@-----@-@@@@@@----@-@@@-------@-@@@@------@-@@@@@@@---@-@@@@@@@@@-@-----------------------------@-@@@@------@-@@@@@@----@-@@@@@@@---@-@@@@@@@@--@-@@--------@-@@--------@-@---------@-@@@@@@@---@-@@@@@@----@-@@@@@@@@--@
     1 @-@---------@-@@@@@-----@-----------@-@@--------@-@@@@@@----@-@@@-------@-@@@@@@@---@-@@@@@@@@@-@-@@@@@@----@-@@@-------@-@@@@@@@@--@-@@@@@@@@--@-@@@@@@----@-@@@-------@-@@@@@@@@--@-@@@@@@----@-@@@@@-----@-@@--------@-@---------@-@@@@@@@@@-@-----------------------------@-@@@@@@@---@-----------@-@@@-------@-@@@@@@@@@-@-----------@-@@@@@@@@--@-@@@-------@-@@--------@-@@@@@-----@-@@@@@@@@@-@
     0 @-@---------@-@@@@@@@@@-@-----------@-@@@@@@@@@-@-@@--------@-@@@@@@@---@-@@@@@@@@--@-@@--------@-@@@-------@-@@@@@@@@--@-@---------@-----------@-@@@@@@@@--@-@@@@@@@@--@-@@@-------@-@@@@@@@---@-@@@@@-----@-@@@-------@-@@@@@@@@--@-@@@-------@-----------------------------@-@@--------@-@@@@@@@@@-@-@@@-------@-@@@@@-----@-@---------@-@@@@------@-@@@-------@-@@@@------@-@@@@@@@@--@-----------@
     1 @-@---------@-@@@@@@@@--@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@@@--@-----------@-----------@-@@@@@-----@-@@--------@-@@@@@-----@-@@@-------@-@@@@@-----@-@@@@@@----@-@---------@-@@--------@-@@--------@-@@@@@@@@@-@-----------@-@@@@@@@@--@-@@@@@@@@@-@-----------------------------@-@@@@@@----@-@---------@-@@@@@@@@@-@-@@@@@@@---@-@@@@@@----@-----------@-@@@-------@-@---------@-@@@@@@----@-@---------@
     1 @-@---------@-@@@@@@@@@-@-@@@@@@@---@-@@@@@@@@--@-@@@@@@@@@-@-@@@@------@-@@@@------@-----------@-@@--------@-@@@@@-----@-@@@@@@@@--@-@---------@-@---------@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@@---@-@@@@@@@---@-@@@@@@@@--@-@@@@@@@---@-@@@@@@@---@-----------------------------@-@@@@@@----@-@@@@@@@@@-@-----------@-@---------@-@@@@@-----@-@@@-------@-@@@@@-----@-@@--------@-@@@@@@@@--@-@@@@@@@@--@
     1 @-@@@@------@-@@@@@@@@--@-@---------@-@@--------@-@@@-------@-@@@@@@@---@-@@@@@-----@-@@--------@-----------@-@@@@@@----@-@@@-------@-@---------@-@@@@@-----@-@@@@------@-@@@@@@----@-@@@@@@@@@-@-@@@@------@-@@@@@@@@@-@-@@@@@@@@--@-@---------@-----------------------------@-@@@@@@@---@-----------@-@---------@-@@@@@@----@-@---------@-@@@@@@@---@-@@@@@@@@@-@-@@@@@@@@--@-@---------@-@@@@@@@@--@
     1 @-@@@@------@-----------@-@@@@------@-@@@@@@@@--@-----------@-----------@-@@@@@-----@-@@@@@@@---@-@@@@@-----@-@@@@@@@@--@-@---------@-@@@@@-----@-@@@@@@@@--@-@@@@@@@@@-@-@@--------@-----------@-@@--------@-@@@@@@@---@-@@@@@@@@--@-@@@-------@-----------------------------@-@@@@@@@---@-@@@@@@@---@-----------@-@---------@-@@@-------@-@@@@------@-----------@-@@@@@-----@-@@--------@-@@--------@
     0 @-@@@@@@@---@-----------@-@@@@@@@@--@-@@@@@@@@@-@-@@@@@@----@-@@--------@-@@--------@-@@@@@@@@@-@-@@@@@@@@--@-@@@@@@----@-@@@@@-----@-@@@@------@-@@--------@-@@@-------@-@@@@------@-@@--------@-@@@-------@-@@@@@-----@-@@@@@@----@-@@@@@@@@@-@-----------------------------@-@@@@@-----@-@@@@@-----@-@@@@------@-@---------@-@@@@@-----@-@@@@@@@@@-@-@@@-------@-@@@@@@@---@-@@@@------@-@@@@@@----@
     0 @-@@@-------@-@@@@------@-@@--------@-@@@@------@-@@@@@-----@-----------@-@---------@-@@@-------@-@@@-------@-@@@@@@@@--@-@@@@@@@---@-@@--------@-@@--------@-@@@@@@@@@-@-@@@@@@@@--@-@@@-------@-@@@@@@@@@-@-@@@-------@-----------@-@@@-------@-----------------------------@-@@@@------@-@@@@@@----@-----------@-@@@@@-----@-@@@@@@@@@-@-@@@@@@----@-@@@@@@----@-@@@@------@-@@@-------@-@@--------@
     0 @-@@@@@@----@-@@@@@-----@-@---------@-----------@-@@@@@-----@-@@--------@-@@@@@@----@-@@--------@-@---------@-@@@-------@-@@@@@-----@-@@@-------@-@@@@@@@---@-@@--------@-@@--------@-@@@@@@@---@-@@--------@-@@@@@@----@-@---------@-@@@@@@@---@-----------------------------@-@@@@------@-@@@@------@-@@@@@@----@-@@@@@@@---@-@@@@@@----@-@@@@@@@@@-@-----------@-@@@@@@----@-----------@-@@@-------@
     0 @-@@@@@@@---@-@@@@@-----@-@@@@------@-@@@@@@----@-@@@@@@----@-@@@@------@-@@@-------@-@---------@-@@@@@@@---@-----------@-@@@@@@@@--@-@@@@@@----@-@@@-------@-@@@@------@-@@@@------@-@@@@------@-@@@@------@-@@@@@-----@-----------@-@@@@@@@---@-----------------------------@-@@@@@@@---@-@@@@------@-@@--------@-@@@@@@----@-@@--------@-@@@@------@-@@@@@@@@--@-@@--------@-@@@-------@-@@@@@@----@
     1 @-@@@@@-----@-----------@-@---------@-@@@@------@-@@@@@@@@@-@-@@@@@-----@-@@@@@@@@--@-@@@-------@-@@@@@@@@@-@-@@@-------@-@@@@@@@---@-@@@@@@----@-@@--------@-@---------@-@@@@------@-@@@@@@@---@-@@@@@@@@--@-@@@@@@@---@-@@--------@-@@@@@@@---@-----------------------------@-@@@@@@----@-@@@@@@@---@-@---------@-@@@@@@----@-@@@@@-----@-@@@@@-----@-@@@@@@@@@-@-@@--------@-@@@@@@@---@-@@@@@@@@--@
     1 @-@@--------@-@@@@@@@---@-@@@@@@@---@-@---------@-@@@@@@@---@-@@@@@@@---@-@@@-------@-@---------@-@@@@------@-@---------@-@@--------@-@@@@@@@@@-@-@@@@@@@---@-@@@@@@@---@-@---------@-@@@@@@----@-@@@@@@@@@-@-@@@@@-----@-@@@@@@@@--@-@---------@-----------------------------@-@@@-------@-@@@@@-----@-----------@-@@@-------@-----------@-@@@@@-----@-@@@-------@-@@@@------@-@@@@------@-@@@-------@
     0 @-@@@-------@-@---------@-@@@@@-----@-@@@@@@----@-@@@@@@@---@-@@@@@@@@@-@-@@@@@@@@--@-@@@-------@-@@@-------@-@@--------@-@@@-------@-@@@@------@-@@@@@@----@-@@@@@@@@--@-@@@@@@@---@-@@@@@@@@--@-@---------@-@@@@@@@@@-@-@---------@-@@@-------@-----------------------------@-@---------@-@@@-------@-@@@@@@----@-@@@@@@@@@-@-@@@@@@----@-@@@@@@@@--@-@@@@------@-@---------@-@@@-------@-@---------@
     1 @-@---------@-@---------@-@@--------@-@@@@@@@@--@-@@@@@@@---@-@@@@------@-@@@@------@-@@@@@@@@--@-@@@@@-----@-@@@@@-----@-@@@@@@@---@-@@@-------@-@@@@@@@@--@-@@@@------@-@@@@@@@---@-@@@@------@-@@@@@@@---@-@@@@@@@@@-@-@@@@@@@@@-@-@@@@@@@---@-----------------------------@-@@@-------@-@@@@@@@@@-@-@@@-------@-@@@@------@-@@@@@@@@@-@-@@@@------@-@---------@-@@@@@@@@@-@-@---------@-@@@@@@@@--@
                                   .
                                   .
                                   .

```

<br>
<br>

### ML report: 94.76%, and 98.425% if test.txt r[0] != p[0]

<br>
<br>

<p align="center"><sub>Nomenclature: p & q are prime, p × q is semiprime (denoted pq.) p & q are factors of pq. Given only pq, it's statistically hard to find p & q.<sub/></p>
<p align="center"><sub>RSA uses p & q of equal length. pq is then twice the length but not always. "pq_length = 40" discards any pq not 40 digits.<sub/></p>
